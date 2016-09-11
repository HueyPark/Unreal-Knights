from config import PASSWORD_LENGTH
from database.model import User
from database.session import Session
import random
import string


class UserLogic:
    @classmethod
    def create(cls) -> User:
        session = Session()

        user = User(cls.__generate_password())
        session.add(user)

        session.commit()

        return user

    @staticmethod
    def read(user_id: int) -> User:
        session = Session()

        user = session.query(User).filter(User.id == user_id).first()

        return user

    @staticmethod
    def __generate_password() -> str:
        return ''.join(random.choice(string.ascii_letters + string.digits) for _ in range(PASSWORD_LENGTH))
