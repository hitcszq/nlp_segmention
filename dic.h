#include <iostream>;
#include <string>
#include <fstream>
#include <sstream>
#include <hash_map>

#ifndef UNICODE  
#define UNICODE  
#endif  
#include <windows.h>  
#include <stdio.h>  
#include <locale>  
#include <codecvt>
#include <map>



using namespace std;
using namespace stdext;

class CDictionary
{
public:
	map<string, int> wordhash; // 用于读取词典后的哈希
	map<string, int >::iterator worditer; //
	typedef pair<string, int> sipair;

public:
	CDictionary(); //将词典文件读入并构造为一个哈希词典
	~CDictionary();
	int FindWord(string w); //在哈希词典中查找词
};

//将词典文件读入并构造为一个哈希词典
CDictionary::CDictionary()
{
	string strtmp; //读取词典的每一行
	char sentence[1500];
	const char *d = "	";
	string word;
	ifstream infile("cip-data.train"); // 打开词典
	if (!infile.is_open()) // 打开词典失败则退出程序
	{
		cerr << "Unable to open input file: " << endl; exit(-1);
	}
	while (getline(infile, strtmp)) // 读入词典的每一行并将其添加入哈希中 
	{
		//istringstream istr(strtmp);
		char *p;
		strcpy(sentence, strtmp.c_str());
		p = strtok(sentence, d);
		while (p)
		{
			word = string(p);
			cout << word << endl;
			wordhash.insert(sipair(word, 1)); //插入到哈希中
			p = strtok(NULL, d);
		}
		
		//istr >> word; //读入每行第一个词
		//wordhash.insert(sipair(word, 1)); //插入到哈希中
	}
}

CDictionary::~CDictionary()
{
}

//在哈希词典中查找词，若找到，则返回，否则返回
int CDictionary::FindWord(string w)
{
	if (wordhash.find(w) != wordhash.end())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

