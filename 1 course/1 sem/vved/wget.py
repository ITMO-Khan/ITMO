import urllib.request
from bs4 import BeautifulSoup
from google import search
import wget
import re
def download_page(url):
    headers = {}
    headers['User-Agent'] = "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2228.0 Safari/537.36"
    req = urllib.request.Request(url, headers = headers)
    response = urllib.request.urlopen(req).read()
    return response
 
 
key_word = input("What would you like to find?\n")
 
url="https://www.google.co.in/search?q="+key_word+"&source=lnms&tbm=isch"
 
page = download_page(url)
 
soup = BeautifulSoup(page, "lxml")
 
img_src = soup.find_all('img')
 
img_links = []
 
for img in img_src:
    link = img.get('data-src')
    t = str(link)
    if(t != "None"):
        img_links.append(link)
 
ans = input("Do you want to download img of " + key_word + ". \n n - no \n y - yes\n")
 
i = 0
img_name = 'img' + str(i)
while(ans != 'n'):
    src  = img_links[i]
    flname = wget.download(src, out=img_name)
    i = i + 1
    img_name='img' + str(i)
    print("\nSucess!  ")
    ans = input("\nOne more?\n")
