from flask import Flask
from view.user import UserView
from view.fight import read

app = Flask(__name__, static_url_path='/static')

app.add_url_rule('/users', 'user_create', UserView.create, methods=['POST'])
app.add_url_rule('/users/<int:user_id>', 'user_read', UserView.read, methods=['GET'])

# app.add_url_rule('/fights/<user_id>', view_func=read, methods=['GET'])

if __name__ == '__main__':
    app.run()
