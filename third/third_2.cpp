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

        LINT(char* p) {
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

			cout << "new len is : " <<newLen <<endl;
            int newLen = this->length() > L.length() ? this->length() + 1 : L.length() + 1 ;
			cout << "new len is : " <<newLen <<endl;

            char* newLINT = new char[newLen];

            //this variable is used to save the overflow bit.
            int incr = 0;

            int i = newLen;

            char* thisItr = this->rItr();
            char* otherItr = L.rItr();

            while (i-- > 0) {
                if (i >= this->length()) {
                    *newLINT-- = *otherItr-- - '0' + incr;
                    incr = 0;
                }
                else if (i >= L.length()) {
                    *newLINT-- = *thisItr-- - '0' + incr;
                    incr = 0;
                } else {
                    int k = *thisItr-- + *otherItr-- - '0' - '0';
                    *newLINT-- = k/10;
                    incr = k%10;
                }
            }

            LINT result(newLINT);

            return result;
        }

		char* itr() const{
			return ptr;
		}

        char* rItr() const{
            return ptr + len - 1;
        }

		void print() const{
			char* itr = ptr;
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
    LINT l1("1111111");
	LINT l2("2222222");
	LINT l3 = l1.Add(l2);
	l3.print();
}

