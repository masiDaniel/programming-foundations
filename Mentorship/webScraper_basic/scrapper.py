import requests
from bs4 import BeautifulSoup

url = 'https://toscrape.com/'


def scrape_website(url):
    #send a GET request to the url
    response = requests.get(url)

    #checks if the request was successful 
    if response.status_code == 200:
        #parse the HTML content of teh page
        soup = BeautifulSoup(response.content, 'html.parser')

        #example: extract all heading 1s
        headlines = soup.find_all('h1')

        #pritn out the headlines 
        for headline in headlines:
            print(headline.text)
    
    else:
        print(f"Failed to retrieve data fro {url} status code: {response.status_code}")

if __name__ == "__main__":
    url = 'https://books.toscrape.com/'
    scrape_website(url)