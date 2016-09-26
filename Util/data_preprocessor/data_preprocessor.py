import csv
from stringcase import constcase, pascalcase


class DataPreprocessor:
    def __init__(self, file_name, data_dir, server_data_dir):
        self.file_name = file_name
        self.data_path = data_dir + file_name + '.csv'
        self.server_data_path = server_data_dir + file_name + '_data.py'

    def preprocess(self):
        with open(self.data_path, encoding='utf-8') as file:
            reader = csv.reader(file)
            keys = next(reader)
            datas = []
            for data in reader:
                datas.append(data)

            with open(self.server_data_path, 'w', encoding='utf-8') as server_data_file:
                class_name = pascalcase(self.file_name + 'Data')

                file_string = 'class ' + class_name + ':\n'
                file_string += '    def __init__(self, '
                file_string += ', '.join(keys)
                file_string += '):\n'
                for key in keys:
                    file_string += ('        self.' + key + ' = ' + key + '\n')

                file_string += '\n'
                file_string += constcase(self.file_name + 'Data') + ' = {\n'
                for data in datas:
                    file_string += ('    ' + data[0] + ': ' + class_name + '(' + ', '.join(data) + ')\n')
                file_string += '}'

                server_data_file.write(file_string)
