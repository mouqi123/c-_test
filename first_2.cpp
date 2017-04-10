#include<fstream>
#include<string>
#include<iostream>

using namespace std;

class WordParser
{
	private:
		string filename;
		int words_number;

	public:
		WordParser(string file) : filename(file), words_number(0) {
			ifstream is(file);
			string s;
			while (is>>s) words_number++;
		}

		int getWordNumber() {
			return this->words_number;
		}

};

int main()
{
	cout << "请输入要统计的文件名(please input the file name you want to statistics):" <<endl;

	string filename;

	cin>>filename;

	WordParser wp(filename);

	cout <<"The file " << filename << " has " << wp.getWordNumber() << " words." << endl;
}
