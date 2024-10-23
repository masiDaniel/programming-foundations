from django.db import models

# Create your models here.

class Account(models.Model):
    firstName = models.CharField(max_length=50)
    lastName = models.CharField(max_length=50)
    phoneNumber = models.IntegerField(null=True)
    joinedDate = models.DateField(null=True)

    def __str__(self):
        return f"{self.firstName} {self.lastName}"