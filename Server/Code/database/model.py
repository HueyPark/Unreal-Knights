from sqlalchemy import Column, Float, Integer, BigInteger
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()


class User(Base):
    __tablename__ = 'user'

    id = Column(BigInteger, primary_key=True)

    def __init__(self, user_id: int):
        self.id = user_id
