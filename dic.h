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
	map<string, int> wordhash; // ���ڶ�ȡ�ʵ��Ĺ�ϣ
	map<string, int >::iterator worditer; //
	typedef pair<string, int> sipair;

public:
	CDictionary(); //���ʵ��ļ����벢����Ϊһ����ϣ�ʵ�
	~CDictionary();
	int FindWord(string w); //�ڹ�ϣ�ʵ��в��Ҵ�
};

//���ʵ��ļ����벢����Ϊһ����ϣ�ʵ�
CDictionary::CDictionary()
{
	string strtmp; //��ȡ�ʵ��ÿһ��
	char sentence[1500];
	const char *d = "	";
	string word;
	ifstream infile("cip-data.train"); // �򿪴ʵ�
	if (!infile.is_open()) // �򿪴ʵ�ʧ�����˳�����
	{
		cerr << "Unable to open input file: " << endl; exit(-1);
	}
	while (getline(infile, strtmp)) // ����ʵ��ÿһ�в�����������ϣ�� 
	{
		//istringstream istr(strtmp);
		char *p;
		strcpy(sentence, strtmp.c_str());
		p = strtok(sentence, d);
		while (p)
		{
			word = string(p);
			cout << word << endl;
			wordhash.insert(sipair(word, 1)); //���뵽��ϣ��
			p = strtok(NULL, d);
		}
		
		//istr >> word; //����ÿ�е�һ����
		//wordhash.insert(sipair(word, 1)); //���뵽��ϣ��
	}
}

CDictionary::~CDictionary()
{
}

//�ڹ�ϣ�ʵ��в��Ҵʣ����ҵ����򷵻أ����򷵻�
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

