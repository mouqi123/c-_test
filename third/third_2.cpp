/**
 * File Name: second_1.cpp
 * Author: limengting
 * Created Time: 2017年04月12日 星期二 22时41分39秒
 */

#include<iostream>
using namespace std;

class LINT
{
    private:
        char* ptr;
        int len;

	public:

        LINT(char* p): ptr(p) {
            char* itr = p;
            while(*itr++ != '\0') len++;
        }

        LINT Add(const LINT& L) {

            int newLen = this->length() > L.length() ? this->length() + 1 : L.length() + 1 ;

            char* newLINT = new char[newLen];

            //this variable is used to save the overflow bit.
            int incr = 0;

            int i = newLen;
            while (i-- > 0) {
                if (i >= this->length()) *newLINT-- = 

            }
        }

        char* rItr() {
            char* rItr = ptr + len - 1;
        }

        int length() {
            return this->len;
        }

		~LINT() {
            delete ptr;
		}
};

int main()
{
}

