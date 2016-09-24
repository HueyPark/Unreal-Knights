from database.util import reset as database_reset
from logic.fight import FightLogic
from logic.user import UserLogic
from redis import StrictRedis

database_reset()
redis = StrictRedis()
redis.flushall()


def test_create():
    user = UserLogic.create()
    user_id = user.id

    fight = FightLogic.create(user_id)

    assert fight.user_id == user_id
