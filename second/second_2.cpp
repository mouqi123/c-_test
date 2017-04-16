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
			//initial position is -1.
			pos = -1;
			this->arr = new int[this->len];
			first= this->arr;
		}
		bool isExist(int value) {
			int* iterator = first;
			int i = 0;
			while(i <= pos && ++i) {
				if (*iterator++ == value) return true;
			}
			return false;
		}

		void add(int value) {
			//In the Mathematics context, a set don't have duplicate element.
			if (isExist(value)) return;
			//if current position equals length - 1, we should chang the 
			//internal array' length to 2*len.
			if (pos >= len - 1) {
				this->doubleLen(2*len);
			}
			int* iterator = first;
			int i = 0;
			while (i<= pos) {
				if (*iterator > value) {
					int temp = *iterator;
					*iterator++ = value; 
					i++;
					while (i <= pos && ++i) {
						int q = *iterator;
						*iterator++ = temp;
						temp = q;
					}
					//edge case.
					*iterator = temp;
					arr++; pos++;
					return;
				}
				*iterator++;
				i++;
			}
			*arr++ = value;
			pos++;
		}
		int removeItem(int value) {
			int* iterator = first;
			int i = 0;
			while (i <= pos && ++i) {
				if (*iterator++ == value) {
					while (i <= pos && ++i) {
						*(iterator - 1) = *iterator++;
					}
					pos--;
					return 1;
				}
			}
			return 0;
		}

		int length() {
			return this->pos;
		}

		int* iterator() {
			return this->first;
		}

		void toString() {
			if (pos == -1){
				cout << "[]"<<endl;
				return;
			}
			int* tempFirst = first;
			int i = 0;
			cout << "[";
			while (i < pos  && ++i) cout << *tempFirst++<< ","; 
			cout <<*tempFirst<<"]"<<endl;
		}

		bool isEqual(Set& s) {
			if (this->length() == -1 && s.length() == -1) return true;
			if (this->length() != s.length()) return false;
	
			int* thisIterator = this->iterator();
			int* otherIterator = s.iterator();
			int i = 0;
			while(i <= this->length() && ++i) {
				if (*thisIterator++ != *otherIterator++)
					return false;
			}

			return true;
		}

		//交集
		Set& intersection(Set& s) {
			Set* intersect = new Set(this->length()+ 1);
			int i = 0;
			int* itr = this->iterator();
			while (i <= this->pos && ++i) {
				int element = *itr++;
				if (s.isExist(element)) intersect->add(element);
			}
			return *intersect;
		}

		//并集
		Set& Union(Set& s) {
			Set* u = new Set(this->length()+ s.length() + 1);
			int i = 0;
			int* itr = this->iterator();
			while (i <= this->pos && ++i) {
				u->add(*itr++);
			}
			i = 0;
			itr = s.iterator();
			while (i <= s.length() && ++i) {
				u->add(*itr++);
			}
			return *u;
		}
		
};

int main()
{
	Set s(1);
	Set s2(10);

	s.add(4); s.add(3); s.add(2), s.add(1);
	s2.add(5); s2.add(3), s2.add(4);

	cout << "s is : ";
	s.toString();

	cout << "s2 is : ";
	s2.toString();

	Set& s3 = s.intersection(s2);
	cout << "s intersect s2 is : ";
	s3.toString();

	cout<< "s is equal s2 : " << s.isEqual(s2)<<endl;
	cout<< "s union s2 is : ";
	Set& s4 = s.Union(s2);
	s4.toString();

}
