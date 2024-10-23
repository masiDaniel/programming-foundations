class Mapping:
    def __init__(self, iterable):
        self.items_list = []
        self.__update(iterable)

    def  update(self, iterable):
        for items in iterable:
            self.items_list.append(items)
        
    __update = update
        
class MappingSubClass(Mapping):

    def update(self, keys, values):
        for items in zip(keys, values):
            self.items_list.append(items)
            
        