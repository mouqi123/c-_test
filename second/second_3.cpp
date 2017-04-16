/**
 * File Name: second_3.cpp
 * Author: mackie
 * Mail: mouqi562315905@qq.com 
 * Created Time: 2017年04月16日 星期日 17时25分38秒
 */

#include<iostream>
using namespace std;

class IntChar
{
	private:
		char* str;
		int value;
		char* binStr;
	public:
		IntChar(char* ptr): str(ptr) {

			while(*ptr != '\0') {
				int temp = *ptr++ ;
				value = (value << 8) + temp;
			}

			binStr = new char[32];
			//总共需要32次移位操作
			int i = 31;
			char* itr = binStr;
			for (i = 31; i >= 0; i--) {
				int temp = 1;
				temp = temp << i;
				*itr++ = (value&temp) == 0 ? '0' : '1';
			}
		}

		void ASC_Print() {
			char* itr= str;
			while(*itr != '\0')
				cout << *itr++;
			cout <<endl;
		}

		void Binary_Print() {
			char* itr= binStr;
			while(*itr != '\0')
				cout << *itr++;
			cout <<endl;
		}

		void Int_Print() {
			cout << value << endl;
		}

};

int main()
{
	IntChar IC("Love");
	IC.ASC_Print();
	IC.Binary_Print();
	IC.Int_Print();
}
