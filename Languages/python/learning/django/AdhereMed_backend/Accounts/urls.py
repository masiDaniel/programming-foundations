from django.urls import path
from . import views # import objects from the current package or module

urlpatterns = [
    path('', views.main, name='main'),
    path('accounts/', views.accounts, name='account'),
    path('accounts/details/<int:id>', views.details, name='details'),
    path('testing/', views.testing, name='testing'),
]