/**
 * File Name: second_1.cpp
 * Author: limengting
 * Created Time: 2017年04月17日 星期二 22时41分39秒
 */

#include<iostream>
#include<string>
#include <stdexcept>
#include<vector>
#include<map>

using namespace std;

class ParseSQL
{
	private :
		string rawSql;
		map<string,string> params;
		int count;

	public :
		ParseSQL(char str[]): rawSql(str), count(0) {

			for (std::string::iterator it=rawSql.begin(); it!=rawSql.end(); ++it) {
				if (*it == '?') count++;
			}
		}

		void SetAttribute(string i, string value) {
			params[i] = value;
		}

		void ExecuteSQL() {
			if (params.size() != count) throw std::runtime_error(string("1: parameters is not equals to the count of '?'"));

			vector<string> v;

			size_t start = 0, end = 0;

			for (int i = 1; i <= count && start <= rawSql.length(); ++i) {

				end = rawSql.find('?', start);

				if(end == string::npos) {
					string temp = rawSql.substr(start);
					v.push_back(temp);
					break;
				}

				std::map<string,string>::iterator it = params.find(std::to_string(i));

				string frag = rawSql.substr(start, end-start);
				v.push_back(frag);

				if (it == params.end()) throw std::runtime_error(string("2: parameters is not equals to the count of '?'"));

				v.push_back(it->second);

				start = end + 1;
			}

			for(vector<string>::iterator iter = v.begin(); iter != v.end(); ++iter) {
				cout << *iter;
			}

			cout << endl;
		}

};

int main()
{
	ParseSQL sql = "select ?, ? from student where gender = ? and height >= ? order by ?";

	sql.SetAttribute("1", "SID");

	sql.SetAttribute("2", "Name");

	sql.SetAttribute("3", "female");

	sql.SetAttribute("4", "165");

	sql.SetAttribute("5", "gender");

	sql.ExecuteSQL();
}

