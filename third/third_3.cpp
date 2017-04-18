/**
 * File Name: second_1.cpp
 * Author: limengting
 * Created Time: 2017年04月17日 星期二 22时41分39秒
 */

#include<iostream>
#include<string>
#include<map>

using namespace std;

class ParseSQL
{
    private :
        string rawSql;
        map<int,string>* params;
        int count;

    public :
        ParseSQL(string str): rawSql(str), count(0) {
            params = new map<int,string>();

            for (std::string::iterator it=str.begin(); it!=str.end(); ++it) {
                if (*it == '?') count++;
            }
        }

        ~ParseSQL() { delete params; }

        void SetAttribute(int i, string value) {
            (*params)[i] = value;
        }

        string ExecuteSQL() {
            
        }

};

int main()
{
}

