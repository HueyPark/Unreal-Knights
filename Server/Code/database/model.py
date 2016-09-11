from config import PASSWORD_LENGTH
from sqlalchemy import BigInteger, Column, ForeignKey, String
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()


class User(Base):
    __tablename__ = 'user'

    id = Column(BigInteger, primary_key=True, autoincrement=True)
    password = Column(String(PASSWORD_LENGTH))
    fight_id = Column(BigInteger, ForeignKey('fight.id'))

    def __init__(self, password: str):
        self.password = password


class Fight(Base):
    __tablename__ = 'fight'

    id = Column(BigInteger, primary_key=True, autoincrement=True)
    left_user_id = Column(BigInteger)
    right_user_id = Column(BigInteger)

    def __init__(self, left_user_id: int, right_user_id: int):
        self.left_user_id = left_user_id
        self.right_user_id = right_user_id
