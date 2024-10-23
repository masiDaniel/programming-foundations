import json


class FileStorage:
    __file_path = 'file.json'
    __objects = {}

    
    def all(self):
        return self.__objects
    
    def new(self, obj):
        self.__objects["{}.{}".format(obj.__class__.__name__, obj.id)] = obj

    def save(self):
        dict = {}
        for key, value in self.__objects.items():
            dict[key] = value.to_dict()
        with open(self.__file_path, 'w') as file:
            json.dump(dict, file)
