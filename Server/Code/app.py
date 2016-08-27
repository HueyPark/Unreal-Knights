from flask import Flask
from api.user import user
from api.fight import read

app = Flask(__name__, static_url_path='/static')

app.add_url_rule('/users', view_func=user.create, methods=['POST'])
app.add_url_rule('/fights/<user_id>', view_func=read, methods=['GET'])

if __name__ == '__main__':
    app.run()
