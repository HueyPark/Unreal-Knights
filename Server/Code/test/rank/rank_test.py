from logic.rank import RankLogic

USER_1_ID = 1
USER_1_RANK = 1
USER_1_RANK_POINT = 500
USER_2_ID = 2
USER_2_RANK = 2
USER_2_RANK_POINT = 300


def test_update():
    RankLogic.update(USER_1_ID, USER_1_RANK_POINT)
    RankLogic.update(USER_2_ID, USER_2_RANK_POINT)

    user_1_rank = RankLogic.read(USER_1_ID)
    assert user_1_rank == USER_1_RANK

    user_2_rank = RankLogic.read(USER_2_ID)
    assert user_2_rank == USER_2_RANK
