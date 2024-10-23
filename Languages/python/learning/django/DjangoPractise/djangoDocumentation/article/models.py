from django.db import models

from person.models import Person

# Create your models here.
class Article(models.Model):
    pub_date = models.DateField()
    headline = models.CharField(max_length=100)
    content = models.TextField()
    reporter = models.ForeignKey(Person, on_delete=models.CASCADE)

    def __str__(self):
        return self.content