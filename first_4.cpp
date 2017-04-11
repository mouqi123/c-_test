/**
 * File Name: first_4.cpp
 * Author: limengting
 * Created Time: 2017年04月11日 星期二 21时43分16秒
 */

#include<iostream>
#include<cmath>
using namespace std;

/**
 * Point is an immutable object, which means it's field is const when construct.
 * You can't change it's field after construct it. It also means a point object
 * have no setter method.
 **/
class Point
{
	private:
		const double x;
		const double y;
		const double R;

	public:
		Point(double i, double j, double k): x(i), y(j), R(k) {
		}

		double getX() {
			return this->x;
		}
		double getY() {
			return this->y;
		}
		double getR() {
			return this->R;
		}

		/**
		 * Notice the param is a reference. And 'this' keyword is a pointer which point this object.
		 * They use different call method.
		 * @param Point& p
		 * @return double distance beteween two point.
		 **/
		double distance(Point& p) {
			return sqrt(pow(this->getX()-p.getX(), 2) + pow(this->getY()-p.getY(), 2));
		}

		bool isIntersection(Point& p) {
			return this->distance(p) < this->getR() + p.getR();
		}

		bool isSeperation(Point& p) {
			return this->distance(p) > this->getR() + p.getR();
		}
		//no need for destructor. because the compiler will generate it automatically.
};

int main()
{
	Point p1(2.0, 1.4, 2.0);
	Point p2(3.0, 0.0, 2.0);
	
	cout << p1.distance(p2)<<endl;
	cout << p1.isIntersection(p2)<<endl;
}
