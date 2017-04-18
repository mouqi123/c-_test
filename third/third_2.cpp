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

        LINT(char* p): len(0) {
            char* itr = p;
            while(*itr++ != '\0') len++;

			char* temp = new char[len];
			ptr = temp;
			itr = p;
            while(*itr != '\0') *temp++ = *itr++;
        }

		LINT(const LINT& l) {
			this->len = l.length();
			char* p = new char[this->len];
			this->ptr = p;
			char* itr = l.itr();
			while(*itr != '\0') *p++ = *itr++;
		}

        LINT Add(const LINT& L) {

            int newLen = this->length() > L.length() ? this->length() + 1 : L.length() + 1 ;

            char* newLINT = new char[newLen];

            //this variable is used to save the overflow bit.
            int incr = 0;

            int i = 0;

            char* thisItr = this->rItr();
            char* otherItr = L.rItr();

            char* newItr = &newLINT[newLen-1];

            for (i = 0; i < newLen - 1; i++) {
                if (i >= this->length()) {
                    *newItr-- = *otherItr-- + incr;
                    incr = 0;
                }
                else if (i >= L.length()) {
                    *newItr-- = *thisItr-- + incr;
                    incr = 0;
                } else {
                    int k =  (*thisItr-- - '0') + (*otherItr-- - '0') + incr;
                    *newItr-- = k%10 + '0';
                    incr = k/10;
                }
            }
            *newItr = incr + '0';

            LINT* result = new LINT(newLINT);
            delete newLINT;
            return *result;
        }

		char* itr() const{
			return ptr;
		}

        char* rItr() const{
            return &ptr[len-1];
        }

		void print() const{
			char* itr = ptr;
            while(*itr == '0' && ++itr);
			while(*itr != '\0') cout << *itr++;
			cout << endl;
		}

        int length() const{
            return this->len;
        }

		~LINT() {
            delete ptr;
		}
};

int main()
{
    LINT l1("1000000000000");
	LINT l2("2000000000000");
    l1.print(); l2.print();
	LINT l3 = l1.Add(l2);
    l3.print();
}

