/**
 * File Name: second_2.cpp
 * Author: liMengTing
 * Created Time: 2017年04月11日 星期二 23时08分52秒
 */

#include<iostream>
using namespace std;

//This class is not thread safe.
class Set
{
	private:
		//the internal array
		int* arr;
		//the length of this set
		int len;
		//current position
		int pos;
		//the first element
		int* first;

		void doubleLen(int n) {

			int* newArr = new int[n];
			//just for memory 
			int* temp = newArr;
			//just for delete
			int* oldFirst = first;

			int i = 0;
			//copy value to the new array.
			while(i < len && ++i) *newArr++ = *first++;

			delete oldFirst;
			
			len = n;
			first = temp;
			arr = newArr;
		}

	public:
		Set(int length = 0): len(length) {
			//default length is 10.
			if (length <= 0) {
				this->len = 10;
			}
			pos = 0;
			this->arr = new int[this->len];
			first= this->arr;
		}
		bool isExist(int value) {
			int* iterator = first;
			int i = 0;
			while(i <= pos && ++i) return *iterator++ == value;
			return 0;
		}

		void add(int value) {
			//In the Mathematics context, a set don't have duplicate element.
			if (isExist(value)) return;
			//if current position equals length, we should chang the 
			//internal array' length to 2*len.
			if (pos >= len) {
				this->doubleLen(2*len);
			}
			*arr++ = value;
			pos++;
		}
		int removeItem(int value) {
			int* iterator = first;
			int i = 0;
			while (i <= pos && ++i) {
				if (*iterator++ == value) {
					
					return value;
				}
			}
			return -1;
		}

		void toString() {
			if (pos == 0){
				cout << "[]"<<endl;
				return;
			}
			int* tempFirst = first;
			int i = 0;
			cout << "[";
			while (i < pos -1  && ++i) cout << *tempFirst++<< ","; 
			cout <<*tempFirst<<"]"<<endl;
		}
		
};

int main()
{
	Set s(1);
	s.add(1); s.add(2); s.add(3), s.add(1);
	s.toString();
}
