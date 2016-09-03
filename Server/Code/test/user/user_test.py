from database.util import reset as database_reset
from logic.user import UserLogic

database_reset()


def test_create():
    new_user = UserLogic.create()
    assert UserLogic.read(new_user.id).id == new_user.id
