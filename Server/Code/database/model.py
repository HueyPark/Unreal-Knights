from config import PASSWORD_LENGTH
from sqlalchemy import BigInteger, Column, ForeignKey, Integer, String
from sqlalchemy.orm import relationship
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
    characters = relationship('FightCharacter', backref='fight')

    def __init__(self, user_id: int):
        self.user_id = user_id


class FightCharacter(Base):
    __tablename__ = 'fight_character'

    id = Column(BigInteger, primary_key=True, autoincrement=True)
    fight_id = Column(BigInteger, ForeignKey(Fight.id))
    static_data_id = Column(Integer)

    def __init__(self, fight_id, static_data_id ):
        self.fight_id = fight_id
        self.static_data_id, static_data_id
