/**
 * File Name: second_1.cpp
 * Author: limengting
 * Created Time: 2017年04月11日 星期二 22时41分39秒
 */

#include<iostream>
using namespace std;

class Init
{
	public:
		Init() {
			cout << "Initialize" << endl;
		}

		~Init() {
			cout << "Clear up" << endl;
		}
};

static Init init;
int main()
{
	cout << "Hello, World!" << endl;
}

