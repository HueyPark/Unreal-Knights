from flask import jsonify
from logic.user import UserLogic


class UserView:
    @staticmethod
    def create():
        new_user = UserLogic.create()

        return jsonify(id=new_user.id)

    @staticmethod
    def read(user_id: int):
        user = UserLogic.read(user_id)

        return jsonify(id=user.id)
