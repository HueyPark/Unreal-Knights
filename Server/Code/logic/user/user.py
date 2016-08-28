from database.model import User
from database.session import Session


class UserLogic:
    @staticmethod
    def create() -> User:
        session = Session()

        user = User()
        session.add(user)

        session.commit()

        return user

    @staticmethod
    def read(user_id: int) -> User:
        session = Session()

        user = session.query(User).filter(User.id == user_id).first()

        return user
