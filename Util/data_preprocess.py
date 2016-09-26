from data_preprocessor import DataPreprocessor
import os

CURRENT_DIR = os.path.dirname(os.path.abspath(__file__))
DATA_DIR = CURRENT_DIR + '/../Data/'
SERVER_DATA_DIR = CURRENT_DIR + '/../Server/Code/static_data/'

data_preprocessor = DataPreprocessor('fight', DATA_DIR, SERVER_DATA_DIR)
data_preprocessor.preprocess()
