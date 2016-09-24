from redis_client import redis_client
from redis_client.key import RANK_KEY


class RankLogic:
    @staticmethod
    def read(user_id) -> int:
        rank = redis_client.zrevrank(RANK_KEY, user_id)
        return rank + 1

    @staticmethod
    def update(user_id, score):
        redis_client.zadd(RANK_KEY, score, user_id)
