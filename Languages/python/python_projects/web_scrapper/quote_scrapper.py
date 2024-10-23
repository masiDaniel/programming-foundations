import requests
from bs4 import BeautifulSoup

url = 'https://quotes.toscrape.com/'

response = requests.get(url)

if response.status_code == 200:

    soup = BeautifulSoup(response.text, 'html.parser')

    quotes = soup.find_all('span', class_='text')

    for quote in quotes:
        print(quote.text)
else:
    print(f"Error: Unable to retrieve the webpage (Status code:{response.status_code})")