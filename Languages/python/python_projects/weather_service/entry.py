import requests

response = requests.get('http://localhost:5000/weather/NewYork')
weather_data = response.json()

print(weather_data)