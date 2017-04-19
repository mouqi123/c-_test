#ifndef CIRCLE_H
#define CIRCLE_H

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

		MyString Mid(int start, int length) {
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

		MyString operator+(const MyString& rhs) {
			int length = this->length() + rhs.length();

			char* newStr = new char[length];
			char* itr = newStr;

			const char* firstItr = this->itr();
			const char* secondItr = rhs.itr();
			while (*firstItr != '\0') *itr++ = *firstItr++; 
			while (*secondItr != '\0') *itr++ = *secondItr++; 

			MyString* ms = new MyString(newStr);
			delete newStr;
			return *ms;
		}

		friend MyString operator+(const char* a, const MyString b) {
			const char* p = a;
			int l = 0;
			while (*p++ !='\0') l++;
			int length = l + b.length();

			char* newStr = new char[length];
			char* itr = newStr;

			const char* firstItr = a;
			const char* secondItr = b.itr();
			while (*firstItr != '\0') *itr++ = *firstItr++; 
			while (*secondItr != '\0') *itr++ = *secondItr++; 

			MyString* ms = new MyString(newStr);
			delete newStr;
			return *ms;
		}
		
		friend MyString operator+(const string a, const MyString b) {
			int length = a.length() + b.length();

			char* newStr = new char[length];
			char* itr = newStr;

			const char* firstItr = a.data();
			const char* secondItr = b.itr();
			while (*firstItr != '\0') *itr++ = *firstItr++; 
			while (*secondItr != '\0') *itr++ = *secondItr++; 

			MyString* ms = new MyString(newStr);
			delete newStr;
			return *ms;
		}

		friend ostream & operator<<(ostream & out, MyString& ms) {
			string s = ms.itr();
			out << s <<endl;
			return out;
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
#endif
