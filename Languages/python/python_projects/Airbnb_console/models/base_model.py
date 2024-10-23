from datetime import datetime 
import uuid


class BaseModel():
    #school = 'daysatr' is a class attriute
    def __init__(self, *args, **kwargs):
        # if kwargs:
        #     for key, value in kwargs.items():

        self.id = str(uuid.uuid4())
        self.created_at = datetime.now()
        self.updated_at = datetime.now()

    def __str__(self) -> str:
        return f"{self.__class__ }{self.id} {self.__dict__}"
    
    def save(self):
        self.updated_at = datetime.now()

    def to_dict(self):
        '''
        returns a dictionary containing all keys/values of __dict__ of the instance
        '''

        obj_dict = self.__dict__.copy()
        obj_dict['__class__'] = self.__class__.__name__

        obj_dict['created_at'] = self.created_at.isoformat()
        obj_dict['updated_at'] = self.updated_at.isoformat()

        return obj_dict
