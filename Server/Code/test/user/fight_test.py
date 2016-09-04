from database.util import reset as database_reset
from logic.user import FightLogic
from logic.user import UserLogic
from redis import StrictRedis

database_reset()
redis = StrictRedis()
redis.flushall()


def test_create():
    user = UserLogic.create()
    user_id1 = user.id

    user = UserLogic.create()
    user_id2 = user.id

    FightLogic.create_request(user_id1)
    FightLogic.create_request(user_id2)

    fight = FightLogic.create()

    user = UserLogic.read(user_id1)
    assert user.fight_id == fight.id

    user = UserLogic.read(user_id2)
    assert user.fight_id == fight.id
