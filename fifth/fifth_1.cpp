/**
 * File Name: fifth_1.cpp
 * Author: limengting
 * Created Time: 2017年04月20日
 */

#include<iostream>
#include<string>
using namespace std;

class Frame
{
    public :
        int weight;
        int ID;

        Frame(): weight(0), ID(0) {};
};

class Cardoor
{
    public :
        int number;
        string color;

        Cardoor(): number(0), color("") {};
};

class Tyre
{
    public :
        int weight;

        Tyre(): weight(0) {};
};
int main()
{
	cout << "Hello, World!" << endl;
}

