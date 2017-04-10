/**
 * File Name: first_3.cpp
 * Author: liMengTing
 * Created Time: 2017年04月10日 星期一 23时29分09秒
 */

#include<iostream>
using namespace std;

/**
 * use the value to set arr, which lenth is num.
 * @param arr the array pointer.
 * @param num the number of byte of value.
 * @param value 
 **/
void setIntArray(void* arr, int num, int value) {
	int* b = static_cast<int*>(arr);
}

int main()
{
	int value = 0; 
	int num = 0;

	cin >> value;

	int max_byte = (1 << 8) - 1;

	int temp = value;
	while (temp > max_byte) {
		
	}
}
