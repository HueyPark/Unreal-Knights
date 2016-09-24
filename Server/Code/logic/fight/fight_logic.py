from database.model import Fight, FightCharacter
from database.session import Session


class FightLogic:
    @classmethod
    def create(cls, user_id, fight_static_data_id) -> Fight:
        session = Session()

        fight = Fight(user_id)
        session.add(fight)

        session.commit()

        fight_character = FightCharacter(fight.id, 1)
        session.add(fight_character)

        session.commit()

        return fight

