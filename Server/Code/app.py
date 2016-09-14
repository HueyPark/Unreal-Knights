from flask import Flask
from view.auth import AuthView
from view.user import UserView

app = Flask(__name__, static_url_path='/static')

app.add_url_rule('/signup', 'signup', UserView.create, methods=['POST'])
app.add_url_rule('/login', 'login', AuthView.login, methods=['POST'])
app.add_url_rule('/users/<int:user_id>', 'user_read', UserView.read, methods=['GET'])

if __name__ == '__main__':
    app.run()
