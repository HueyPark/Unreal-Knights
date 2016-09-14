from flask import jsonify, request
from logic.auth import AuthLogic


class AuthView:
    @staticmethod
    def login():
        json = request.json
        user_id = json['id']
        password = json['password']

        jwt = AuthLogic.create_jwt(user_id, password)
        return jsonify(jwt=jwt)
