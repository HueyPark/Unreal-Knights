from flask import Flask
from api.fight import read

app = Flask(__name__, static_url_path='/static')

app.add_url_rule('/fights/<user_id>', view_func=read, methods=['GET'])

if __name__ == '__main__':
    app.run()
