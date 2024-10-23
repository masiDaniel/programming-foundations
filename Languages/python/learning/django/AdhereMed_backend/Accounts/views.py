from django.http import HttpResponse
from django.template import loader
from .models import Account

# Create your views here.

def accounts(request):
    myAccounts = Account.objects.all().values()
    template = loader.get_template('allAccounts.html')
    context = {
        'myAccounts': myAccounts
    }

    return HttpResponse(template.render(context, request))

def details(request, id):
    myAccount = Account.objects.get(id = id)
    template = loader.get_template("details.html")
    context = {
        'myAccount' : myAccount,
    }

    return HttpResponse(template.render(context, request))

def main(request):
  template = loader.get_template('main.html')
  return HttpResponse(template.render())

def testing(request):
  myData = Account.objects.all()
  template = loader.get_template('template.html')
  context = {
    'myAccounts' : myData 
  }
  return HttpResponse(template.render(context, request))
