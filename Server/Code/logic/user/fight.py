from database.model import Fight
from database.session import Session


class FightLogic:
    @classmethod
    def create(cls, user_id) -> Fight:
        session = Session()

        fight = Fight(user_id, cls.__get_opponent_user_id())
        session.add(fight)

        session.commit()

        return fight

    @staticmethod
    def read(fight_id: int) -> Fight:
        session = Session()

        fight = session.query(Fight).filter(Fight.id == fight_id).first()

        return fight

    @staticmethod
    def __get_opponent_user_id():
        return 9