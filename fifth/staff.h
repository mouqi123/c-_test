#ifndef STAFF_H
#define STAFF_H

#include<iostream>
#include<string>
#include<string>

using namespace std;

class student;

class teacher;

class course;

class grade;

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
		//学生选的课程列表
		vector<course*> course_list;
		student(): ID(""){ }
		student(string n, string s, string b, string id): staff(n,s,b), ID(id) {}
		student(sutdent& s) {
			ID = s.ID; name = s.name; sex = s.sex; birthday = s.birthday; 
			course_list = s.course_list;
		}
};

class teacher: public staff
{
	public :
		string ID;
		//教师上了哪些课程
		vector<course*> course_list;

		teacher(): ID(""){ }
		teacher(string n, string s, string b, string id): staff(n,s,b), ID(id) {}
		teacher(teacher& t) {
			ID = t.ID; name = t.name; sex = t.sex; birthday = t.birthday; 
			course_list = t-> course_list;
		}
}

class course
{
	public :
		string code;
		string name;
		//这个课程由哪个老师上的
		teacher t;
		//哪些学生选了这个课程
		vector<student*> student_list;
		course(string c, string n ,teacher tea vector<student*> sl): code(c), name(n), t(tea), student_list(sl) {}
}

class grade
{
	public :
		student s;
		course c;
		int score;

		grade(student stu, course cor, int scor): s(stu), c(cor), score(scor) { }
}

#endif
