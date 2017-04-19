#ifndef MYSTRING_H
#define MYSTRING_H

#include<iostream>
#include<string>
using namespace std;

class MyString
{
	private:
		const char* data;
		int len;
	public:
		MyString(); 

		MyString(string s); 

		MyString(const MyString& ms);

		MyString(char* str);

		~MyString(); 


		int Find(char c);

		MyString Mid(int start, int length);

		void print() const; 

		int length() const; 

		const char* itr() const;

		MyString operator+(const MyString& rhs);
		

		friend MyString operator+(const char* a, const MyString b);
		
		friend MyString operator+(const string a, const MyString b);

		friend ostream & operator<<(ostream & out, MyString& ms);

		MyString operator=(const MyString& rhs);
};

#endif
