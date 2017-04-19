/**
 * File Name: test.cpp
 * Author: mackie
 * Mail: mouqi562315905@qq.com 
 * Created Time: 2017年04月19日 星期三 23时45分15秒
 */

#include<iostream>
#include "fourth_1.h"
using namespace std;
int main()
{
	MyString s1("China"), s2;

	s2 = "Love";

	cout <<"s2 is " << s2;

	//cout << "I" + s2 + s1;

	int pos = s1.Find('a');  // pos is 4, or zero if  'a'  is not found.

	int a = 1, b = 3;

	MyString my = s2.Mid(a, b);  // a represents starting position, b represents length. So Mid can get substring.
	cout <<my;
}
