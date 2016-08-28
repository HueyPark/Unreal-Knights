from sqlalchemy import Column, BigInteger
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()


class User(Base):
    __tablename__ = 'user'

    id = Column(BigInteger, primary_key=True)

    def __init__(self):
        pass
