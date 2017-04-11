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
void setIntArray(void* arr, int num, char value) {

	char* b = static_cast<char*>(arr);

    int n = 0;
    while(n < num && ++n) *b++ = value;
}

int main()
{
    //char占一个字节
	char value = '0'; 

    //num是数组的长度
	int num = 0;

    //input two value
	cin >> value >> num;

    int* a = new int[num];

    void* b = static_cast<void*>(a);

    setIntArray(b, 4*num, value);
    
    int n = 0;
    while (n < num && ++n) cout << *a++ << endl;

}
