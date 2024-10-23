import requests

def get_weather(api_key, city):
    base_url = 'http://api.openweathermap.org/data/2.5/weather'
    params = { 'q': city, 'appid': api_key, 'units': 'metric'}


    try:
        response = requests.get(base_url, params=params)
        response.raise_for_status()
        weather_data = response.json()
        return weather_data
    except requests.exceptions.RequestException as err:
        print(f"error: {err}")
        return None
    
def display_weather (weather_data):
    if weather_data:
        print(f"Weather in {weather_data['name']}, {weather_data['sys']['country']}:")
        print(f"Temperature: {weather_data['main']['temp']}°C")
        print(f"Condition: {weather_data['weather'][0]['description']}")
    else:
        print("Failed to retrieve weater data")


if __name__ == "__main__":
    api_key = "532e6c3d6f1ed0bed8fe7b2b75e7525f"
    city = input("enter the city name: ")


    weather_data = get_weather(api_key, city)
    display_weather(weather_data)