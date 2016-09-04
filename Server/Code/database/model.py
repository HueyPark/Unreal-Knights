from sqlalchemy import BigInteger, Column, ForeignKey
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()


class User(Base):
    __tablename__ = 'user'

    id = Column(BigInteger, primary_key=True, autoincrement=True)
    fight_id = Column(BigInteger, ForeignKey('fight.id'))

    def __init__(self):
        pass


class Fight(Base):
    __tablename__ = 'fight'

    id = Column(BigInteger, primary_key=True, autoincrement=True)
    left_user_id = Column(BigInteger)
    right_user_id = Column(BigInteger)

    def __init__(self, left_user_id: int, right_user_id: int):
        self.left_user_id = left_user_id
        self.right_user_id = right_user_id
