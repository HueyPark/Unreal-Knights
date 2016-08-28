from logic.user import UserLogic


def test_create():
    new_user = UserLogic.create()
    assert UserLogic.read(new_user.id).id == new_user.id
