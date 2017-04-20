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
			*newStr = '\0';
		}

		MyString(const MyString& ms): len(0) {
			this->len = ms.length();
			char* newStr = new char[len];
			data = newStr;
			const char* str = ms.itr();
			while(*str != '\0') *newStr++ = *str++;
			*newStr = '\0';
		}


		MyString(char* str): len(0) {
			char* itr = str;
			while(*itr++ != '\0') len++;

			char* newStr = new char[len];
			data = newStr;
			while(*str != '\0') *newStr++ = *str++;
			*newStr = '\0';
		}

		~MyString() { delete data; }


		int Find(char c) {
			int i = 0;
			for (const char* itr = data; *itr != '\0'; ++itr, ++i) {
				if (*itr == c) return i;
			}
			return -1;
		}

        int lastIndex(char c) {
            for (int i = len -1; i >=0; --i) {
                if (data[i] == c) return i;
            }
            return -1;
        }

		MyString& Mid(int start, int length) {
			if (start < 0 || start >= len - 1 || start + length  > len  )
				throw std::runtime_error(string("mystring is out of bound"));

			char* newStr = new char[length];
			char* p = newStr;
			const char* itr = &data[start];
			for (int i = 0; i < length; ++i){
				*p++ = *itr++;
			}
			*p = '\0';
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

		MyString& operator+(const MyString& rhs) {
			int length = this->length() + rhs.length();

			char* newStr = new char[length];
			char* itr = newStr;

			const char* firstItr = this->itr();
			const char* secondItr = rhs.itr();
			while (*firstItr != '\0') *itr++ = *firstItr++; 
			while (*secondItr != '\0') *itr++ = *secondItr++; 

            *itr = '\0';
			MyString* ms = new MyString(newStr);
			delete newStr;
			return *ms;
		}

        /*MyString& operator+(const char* a) {
			const char* p = a;
			int l = 0;
			while (*p++ !='\0') l++;
			int length = l + this->length();

			char* newStr = new char[length];
			char* itr = newStr;

			const char* firstItr = a;
			const char* secondItr = this->itr();
			while (*firstItr != '\0') *itr++ = *firstItr++; 
			while (*secondItr != '\0') *itr++ = *secondItr++; 

            *itr = '\0';

			MyString* ms = new MyString(newStr);
			delete newStr;
			return *ms;
		}*/
		
		friend MyString& operator+(const string a, const MyString b) {
			int length = a.length() + b.length();

			char* newStr = new char[length];
			char* itr = newStr;

			const char* firstItr = a.data();
			const char* secondItr = b.itr();
			while (*firstItr != '\0') *itr++ = *firstItr++; 
			while (*secondItr != '\0') *itr++ = *secondItr++; 

            *itr = '\0';
			MyString* ms = new MyString(newStr);
			delete newStr;
			return *ms;
		}

		friend ostream & operator<<(ostream & out, MyString& ms) {
			string s = ms.itr();
			out << s <<endl;
			return out;
		}

		MyString& operator=(const MyString& rhs) {
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

	s2 = "Love";
    cout << "last Index of "<<s2.lastIndex('e')<<endl;

    MyString s5 = "I" + s1+ s2;
    cout <<s5;
	//cout << "I" + s2 + s1;

	int pos = s1.Find('a');  // pos is 4, or zero if  'a'  is not found.

	int a = 1, b = 3;

	MyString my = s2.Mid(a, b);  // a represents starting position, b represents length. So Mid can get substring.
	cout <<my;
}

