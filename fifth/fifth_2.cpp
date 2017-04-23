#ifndef STAFF_H
#define STAFF_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class student;

class teacher;

class course;

class grade;

class course
{
	public :
		string code;
		string name;
		//这个课程由哪个老师上的
		teacher& t;
		//哪些学生选了这个课程
		vector<student*> student_list;
		course(string c, string n ,teacher& tea): code(c), name(n), t(tea) {}
};

class grade
{
	public :
		student& s;
		course& c;
		int score;

		grade(student& stu, course& cor, int scor): s(stu), c(cor), score(scor) { }
};

//teacher和student的父类
class staff
{
	public :
		string name;
		string sex;
		string birthday;

		staff(): name(""), sex(""), birthday(""){ }
		staff(string n, string s, string b): name(n), sex(s), birthday(b) {}
};

class student: public staff
{
	public :
		string ID;
		//学生所选的课程成绩列表
		vector<course*> take_list;
		//所有的课程
		vector<course*> course_list;
		//学生选的课程的分数
		vector<grade*> grade_list;
		student(): ID(""){ }
		student(string n, string s, string b, string id): staff(n,s,b), ID(id) {}
		student(student& s) {
			ID = s.ID; name = s.name; sex = s.sex; birthday = s.birthday; 
			course_list = s.course_list;
			grade_list = s.grade_list;
		}

		//学生根据一个课程ID查询教师
		teacher& getTeacher(string courseID) {

			for(vector<course*>::iterator iter=course_list.begin();iter!=course_list.end();iter++) {
				course* c = *iter;
				//如果找到了这门课程，那就返回teacherID
				if (c->code == courseID) {
					return c->t;
				}
			}

			//没找到，返回空(或者抛个异常)
		}

		//学生根据课程名称查询成绩
		grade& getScore(string courseName) {
			for(vector<grade*>::iterator iter=grade_list.begin();iter!=grade_list.end();iter++) {
				grade* gra = *iter;
				if (gra->c.name == courseName) {
					return *gra;
				}
			}

		}
};

class teacher: public staff
{
	public :
		string ID;
		//教师上了哪些课程
		vector<course*> course_list;
		//所有的学生列表
		vector<student*> student_list;

		teacher(): ID(""){ }
		teacher(string n, string s, string b, string id): staff(n,s,b), ID(id) {}
		//拷贝构造函数
		teacher(teacher& t) {
			ID = t.ID; name = t.name; sex = t.sex; birthday = t.birthday; 
			course_list = t.course_list;
			student_list = t.student_list;
		}

		//这个教师要给所有他教的课程的学生打个分数
		void giveScore(string studentID, int score) {
			//迭代教师上的所有课程
			for(vector<course*>::iterator iter=course_list.begin();iter!=course_list.end();iter++){

				course* c = *iter;
				vector<student*> student_list = c->student_list;
				//迭代这门课程所有的学生
				//然后找到某个学生给他打分
				for(vector<student*>::iterator iterB=student_list.begin();iterB!=student_list.end();iterB++) {
					student* s = *iterB;
					if (studentID == s->ID) {
						grade* gra = new grade(*s, *c, score);
						s->grade_list.push_back(gra);
						return;
					}
				}
			}
		}

		//教师根据学生ID能查到学生的基本信息
		student& getStudent(string studentID) {
			for(vector<student*>::iterator iter=student_list.begin();iter!=student_list.end();iter++) {

				student* s = *iter;
				if (s->ID == studentID) {
					return *s;
				}
			}

		}
};

/*class course
{
	public :
		string code;
		string name;
		//这个课程由哪个老师上的
		teacher t;
		//哪些学生选了这个课程
		vector<student*> student_list;
		course(string c, string n ,teacher tea): code(c), name(n), t(tea) {}
};*/

/*class grade
{
	public :
		student s;
		course c;
		int score;

		grade(student stu, course cor, int scor): s(stu), c(cor), score(scor) { }
};*/

int main()
{

	//基本思路:
	//1.先构造一个vector<teacher*> 和一个vector<student*>，以及一个vector<course*>
	//然后再inject到需要这些list的对象中,也可以一个一个的push_back
	
	student* limengting = new student("李梦婷","女", "1997.10.5", "20150901");

	teacher* sunwukong = new teacher("孙悟空","男", "1950.8", "t20011211");

	course* bigdata = new course("COM016", "大数据", *sunwukong);

	limengting->course_list.push_back(bigdata);

	limengting->take_list.push_back(bigdata);

	sunwukong->course_list.push_back(bigdata);

	sunwukong->student_list.push_back(limengting);

	bigdata->student_list.push_back(limengting);

	//教师给他教的一门课程的某个学生打分
	sunwukong->giveScore("20150901", 100);

	//学生根据课程编码来查询教师姓名
	cout << limengting->getTeacher("COM016").name <<endl;

	//学生根据课程名称查询自己的分数
	cout << limengting->getScore("大数据").score <<endl;
	
	//教师通过学生ID来查看学生的基本信息
	cout << sunwukong->getStudent("20150901").name <<endl;
}


#endif
