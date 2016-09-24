from logic.fight import FightLogic
from logic.user import UserLogic

FIGHT_STATIC_DATA_ID = 1


def test_create():
    user = UserLogic.create()
    user_id = user.id

    fight = FightLogic.create(user_id, FIGHT_STATIC_DATA_ID)

    assert fight.user_id == user_id
