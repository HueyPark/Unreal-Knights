from api.user.user import create


def test_create():
    new_user = create()
    assert isinstance(new_user, int)
