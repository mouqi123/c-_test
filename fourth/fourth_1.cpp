/**
 * File Name: fourth_1.cpp
 * Author: limengting
 * Created Time: 2017年04月17日 星期二 21时41分39秒
 */

#include<iostream>
#include<string>
#include <stdexcept>
using namespace std;

class MyString
{
    private:
        const char* data;
        int len;
    public:
        MyString(): len(0) {
            data = new char[0];
        }

        MyString(string s): len(0) {
            len = s.length();
            char* newStr = new char[len];
            data = newStr;
            const char* str = s.data();
            while(*str != '\0') *newStr++ = *str++;
        }

        MyString(const MyString& ms): len(0) {
            this->len = ms.length();
            char* newStr = new char[len];
            data = newStr;
            const char* str = ms.itr();
            while(*str != '\0') *newStr++ = *str++;
        }


        MyString(char* str): len(0) {
            char* itr = str;
            while(*itr++ != '\0') len++;

            char* newStr = new char[len];
            data = newStr;
            while(*str != '\0') *newStr++ = *str++;
        }

        ~MyString() { delete data; }


        int Find(char c) {
            int i = 0;
            for (const char* itr = data; *itr != '\0'; ++itr, ++i) {
                if (*itr == c) return i;
            }
            return -1;
        }

        MyString Mid(int start, int length) {
            if (start < 0 || start >= len - 1 || start + length >= len )
                throw std::runtime_error(string("mystring is out of bound"));

            char* newStr = new char[length];
            char* p = newStr;
            const char* itr = &data[start];
            for (int i = 0; i < length; ++i){
                *p++ = *itr++;
            }
            MyString* ms = new MyString(newStr);
            delete newStr;
            return *ms;
        }

        void print() const {
            const char* itr = data;
            while (*itr !='\0') cout<< *itr++;
            cout <<endl;
        }

        int length() const {
            return this->len;
        }

        const char* itr() const {
            return this->data;
        }



        MyString operator+(const MyString& rhs) {
            int length = this->length() + rhs.length();

            char* newStr = new char[length];
            char* itr = newStr;

            const char* firstItr = this->itr();
            const char* secondItr = rhs.itr();
            this->print(); rhs.print();
            while (*firstItr != '\0') *itr++ = *firstItr++; 
            while (*secondItr != '\0') *itr++ = *secondItr++; 

            MyString* ms = new MyString(newStr);
            delete newStr;
            return *ms;
        }

        MyString operator+(string rhs) {
            int length = this->length() + rhs.length();

            char* newStr = new char[length];
            char* itr = newStr;

            const char* firstItr = this->itr();
            string::iterator secondItr = rhs.begin();
            while (*firstItr != '\0') *itr++ = *firstItr++; 
            while (*secondItr!= rhs.end()) *itr++ = *secondItr++; 

            MyString* ms = new MyString(newStr);
            delete newStr;
            return *ms;
        }

        MyString operator=(const MyString& rhs) {
            this->len = rhs.length();
            char* newStr = new char[len];
            this->data = newStr;
            const char* str = rhs.itr();
            while(*str != '\0') *newStr++ = *str++;

            return *this;
        }
};

int main()
{
    MyString s1("China"), s2;

    //MyString s3;
    //cout <<"s2 is " ;
    //s3.print();

    s2 = "Love";
    //cout << "print s1 "; s1.print();
    //cout << "print s2 "; s2.print();

    MyString s3 = s1+s2+"123";
    s3.print();
    //s1 + s2;
    //ms.print();
    //cout << "I" + s2 + s1;

    //int pos = s1.Find('a');  // pos is 4, or zero if  'a'  is not found.

    //int a = 1, b = 3;

    //MyString my = s2.Mid(a, b);  // a represents starting position, b represents length. So Mid can get substring.

}

