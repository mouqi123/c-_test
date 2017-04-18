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
        map<int,string> params;
        int count;

    public :
        ParseSQL(char str[]): rawSql(str) {

            for (std::string::iterator it=rawSql.begin(); it!=rawSql.end(); ++it) {
                if (*it == '?') count++;
            }
        }

        void SetAttribute(int i, string value) {
            params[i] = value;
        }

        string ExecuteSQL() {
            if (params->size() != count) throw std::runtime_error(string("parameters is not equals to the count of \\'?\\'"));
            
            vector<char> v;

            for (std::string::iterator it=rawSql.begin(), int i = 1; it!=rawSql.end(); ++it) {
                if (params.find(i) 
            }
            
        }

};

int main()
{
    ParseSQL sql = "select ?, ? from student where gender = ? and height >= ? order by ?";
}

