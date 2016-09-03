from database.model import Fight
from database.session import Session


class FightLogic:
    @staticmethod
    def create(user_id) -> Fight:
        session = Session()

        fight = Fight(user_id, 1)
        session.add(fight)

        session.commit()

        return fight

    @staticmethod
    def read(fight_id: int) -> Fight:
        session = Session()

        fight = session.query(Fight).filter(Fight.id == fight_id).first()

        return fight
