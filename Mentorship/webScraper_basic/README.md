# fundamentals of web scrapping
1. sending HTTP requests 
    the process usualy starts with ending a GET request to the URL of the webpage you want to scrape 
    requests library in python is used for this purpose as it retrieves the HTML content of the webpage 

2. parsing HTML 
    once you have the HTML content, you need to parse it to extract the data that you are intrested in 
    libraries like BeautifulSoap help in parsing HTML and davigating through the document using methods like 'find', 'find_all' and css selectors 

3. Extracting data 
    after parsing, you can extract specific html content loaded via javascript of may enforce anti-scrapping measures
    handling such cases may involve using headerless browsers like selenium or analyzing network requests to simulate user interaction
