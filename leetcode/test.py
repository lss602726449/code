import requests        #导入requests包
import urllib3
import io
import sys
from bs4 import  BeautifulSoup
import requests,json
from requests_toolbelt import MultipartEncoder
import time
from datetime import datetime
import matplotlib.pyplot as plt #引入绘图库
import numpy as np
import matplotlib.dates as mdates

sys.stdout = io.TextIOWrapper(sys.stdout.buffer,encoding='utf8') 
proxies = { "http": None, "https": None}

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

user_agent = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/110.0.0.0 Safari/537.36'
session = requests.Session()

def login(username, password):
    url = 'https://leetcode.cn'
    cookies = session.get(url, proxies=proxies).cookies
    for cookie in cookies:
        if cookie.name == 'aliyungf_tc':
            csrftoken = cookie.value
    # print(cookies)
    url = "https://leetcode.cn/accounts/login"
        
    params_data = {
        'csrfmiddlewaretoken': csrftoken,
        'login': username,
        'password':password,
        'next': 'problems'
    }
    headers = {'User-Agent': user_agent, 'Connection': 'keep-alive', 'Referer': 'https://leetcode.com/accounts/login/', "origin": "https://leetcode.cn"}
    m = MultipartEncoder(params_data)   

    headers['Content-Type'] = m.content_type
    str = session.post(url, headers = headers, proxies=proxies, data = m, timeout = 10, allow_redirects = False)
    is_login = session.cookies.get('LEETCODE_SESSION') != None
    # print(session.cookies)
    return is_login


def crawl():
    # url = 'https://leetcode.cn/contest/weekly-contest-300/ranking/'
    # str = session.get(url, headers=headers, proxies=proxies, verify=False)
    time_ = []
    user_num = []
    year = 2019
    for i in range(118,332):
        url = 'https://leetcode.cn/contest/api/info/weekly-contest-%d/' % i
        headers = {'User-Agent': user_agent, 'Connection': 'keep-alive'}
        data = requests.get(url, headers=headers, proxies=proxies)
        dict = json.loads(data.text)
        # soup=BeautifulSoup(str.text,'lxml')
        # data = soup.select('#contest-app > div > div > nav > ul > li:nth-child(6) > a')
        timestamp = dict['contest']['start_time']
        #转换成localtime
        time_local = datetime.fromtimestamp(timestamp)
        #转换成新的时间格式(2016-05-05 20:28:54)
        dt = datetime.strftime(time_local,"%Y-%m-%d")
        time_.append(dt)
        user_num.append(dict['user_num'])
        time.sleep(0.01)
        if (i-117)%52==0 :
            plt.plot(time_, user_num,label=str(year))
            time_ = []
            user_num = []
            year = year + 1
    plt.plot(time_,user_num,label=str(year))
    plt.ylabel('user_num')
    plt.xlabel('time')
    plt.title('leetcode annual user ')
    plt.legend()
    ax = plt.gca()
    ax.xaxis.set_major_locator(mdates.MonthLocator())
    plt.gcf().autofmt_xdate() 
    # my_x_ticks = np.arange(1,13)
    # plt.xticks(my_x_ticks)
    plt.savefig("test.jpg")
    plt.show()
    

# is_login =  login('15173464060','dg1597347')
# print(is_login)
crawl()