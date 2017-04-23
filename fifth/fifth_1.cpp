/**
 * File Name: fifth.cpp
 * Author: mackie
 * Mail: mouqi562315905@qq.com 
 * Created Time: 2017年04月23日 星期日 16时17分39秒
 */

#include<iostream>
using namespace std;

class Frame
{
    public :
        int weight;
        int ID;

		Frame(): weight(0), ID(0) { }

		friend istream& operator>>(istream& in, Frame* f) {
			in >> f->ID >> f->weight;
			return in;
		}
};

class Cardoor
{
    public :
        int doors;
        string color;

        Cardoor(): doors(0), color("") { };

		friend istream& operator>>(istream& in, Cardoor* c) {
			in >> c->doors>> c->color;
			return in;
		}
};

class Tyre
{
    public :
        int tyres;

        Tyre(): tyres(0) { };

		friend istream& operator>>(istream& in, Tyre* t) {
			in >> t->tyres;
			return in;
		}
}; 

class Vehicle : public Frame, public Cardoor, public Tyre
{ 
	friend ostream& operator<<(ostream& out, Vehicle& v) {
		out << "vehicle's ID is : " << v.ID <<endl;
		out << "vehicle's number of door : " << v.doors <<endl;
		out << "vehicle's number of tyres : " << v.tyres <<endl;
		return out;
	}
};

int main()
{
	Vehicle* vehicle = new Vehicle();
	Frame* frame = vehicle;
	Cardoor* cardoor = vehicle;
	Tyre* tyre = vehicle;

	cout << "please input frame's ID and weight : ";
	cin >> frame;

	cout << "please input cardoor's number and color : ";
	cin >> cardoor;

	cout << "please input number of tyres : ";
	cin >> tyre;

	cout << *vehicle;
}
