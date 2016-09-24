from config import PASSWORD_LENGTH
from sqlalchemy import BigInteger, Column, ForeignKey, String
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()


class User(Base):
    __tablename__ = 'user'

    id = Column(BigInteger, primary_key=True, autoincrement=True)
    password = Column(String(PASSWORD_LENGTH))

    def __init__(self, password: str):
        self.password = password


class Fight(Base):
    __tablename__ = 'fight'

    id = Column(BigInteger, primary_key=True, autoincrement=True)
    user_id = Column(BigInteger, ForeignKey(User.id))

    def __init__(self, user_id: int):
        self.user_id = user_id
