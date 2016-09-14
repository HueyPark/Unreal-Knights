from database.model import User
from database.session import Session
import jwt

JWT_KEY = 'secret'
USER_ID_KEY = 'user_id'


class AuthLogic:
    @staticmethod
    def create_jwt(user_id, password):
        session = Session()
        user = session.query(User).filter(User.id == user_id).filter(User.password == password).first()

        token = jwt.encode({USER_ID_KEY: user.id}, JWT_KEY)

        return token

    @staticmethod
    def get_user_id(token):
        decoded = jwt.decode(token, JWT_KEY)
        return decoded[USER_ID_KEY]
