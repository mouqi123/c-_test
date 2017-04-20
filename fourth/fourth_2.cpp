/**
 * File Name: fourth_2.cpp
 * Author: mackie
 * Mail: mouqi562315905@qq.com 
 * Created Time: 2017年04月19日 星期三 23时22分07秒
 */

#include<iostream>
#include<string>
#include "fourth_1.h"
using namespace std;

class InternetURL
{
    private :
        MyString rawURL;
        MyString country;
        MyString type;
        MyString domain;

    public :
        InternetURL(): rawURL(), country(), type(),domain() {
        }

        InternetURL(string s): rawURL(s), country(), type(), domain() {
            int pos = rawURL.Find('/');

            domain = pos == -1 ? rawURL : rawURL.Mid(0, pos);

            int lastIndex = domain.lastIndex('.');

            country = lastIndex == -1 ? domain : domain.Mid(lastIndex + 1, domain.length() - lastIndex -1);

            MyString remain = domain.Mid(0, lastIndex);

            lastIndex = remain.lastIndex('.');

            type = lastIndex == -1 ? remain : remain.Mid(lastIndex + 1, remain.length() - lastIndex -1);
        }

        MyString& getDomain() {
            return domain;
        }

        MyString& getDomainCountry() {
            return country;
        }

        MyString& getDomainType() {
            return type;
        }

};

int main()
{
    InternetURL URL("www.bit.edu.cn/jwc/080329.html"), s2;

    cout << URL.getDomain();         // The result is:  www.bit.edu.cn

    cout << URL.getDomainCountry();  // The result is:  cn

    cout << URL.getDomainType();     // The result is:  edu
}
