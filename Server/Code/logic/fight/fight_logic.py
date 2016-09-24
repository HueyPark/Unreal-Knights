from database.model import Fight, User
from database.session import Session
from redis import StrictRedis

FIGHT_KEY = 'fight_key'


class FightLogic:
    @classmethod
    def create(cls, user_id) -> Fight:
        session = Session()

        fight = Fight(user_id)
        session.add(fight)

        session.commit()

        return fight

    @staticmethod
    def read(user_id: int) -> Fight:
        session = Session()

        fight_id, = session.query(User.id).filter(User.id == user_id).first()
        if fight_id is None:
            raise Exception

        fight = session.query(Fight).filter(Fight.id == fight_id).first()

        return fight

    @staticmethod
    def __pop_user_id() -> int:
        redis = StrictRedis()

        return int(redis.blpop(FIGHT_KEY)[1])
