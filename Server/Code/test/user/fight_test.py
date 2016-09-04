from database.util import reset as database_reset
from logic.user import FightLogic
from logic.user import UserLogic

database_reset()

USER_NUM = 10


def test_create():
    for i in range(USER_NUM):
        UserLogic.create()

    user = UserLogic.create()
    fight = FightLogic.create(user.id)
    new_fight = FightLogic.read(fight.id)
    assert fight.id == new_fight.id
    assert new_fight.left_user_id == user.id
