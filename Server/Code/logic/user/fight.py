from database.model import Fight, User
from database.session import Session
from redis import StrictRedis

FIGHT_KEY = 'fight_key'


class FightLogic:
    @classmethod
    def create(cls) -> Fight:
        left_user_id = cls.__pop_user_id()
        right_user_id = cls.__pop_user_id()

        session = Session()

        fight = Fight(left_user_id, right_user_id)
        session.add(fight)

        session.commit()

        left_user = session.query(User).filter(User.id == left_user_id).first()
        left_user.fight_id = fight.id

        right_user = session.query(User).filter(User.id == right_user_id).first()
        right_user.fight_id = fight.id

        session.commit()

        return fight

    @staticmethod
    def create_request(user_id):
        redis = StrictRedis()

        redis.rpush(FIGHT_KEY, user_id)

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
