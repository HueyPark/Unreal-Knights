from logic.auth import AuthLogic
from logic.user import UserLogic


def test_login():
    user = UserLogic.create()

    jwt = AuthLogic.create_jwt(user.id, user.password)

    user_id = AuthLogic.get_user_id(jwt)

    assert user.id == user_id
