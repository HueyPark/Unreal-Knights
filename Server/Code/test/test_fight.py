from api.fight import read

USER_ID = 1


def test_read():
    enemy_user_id = read(1)
    assert enemy_user_id != USER_ID
