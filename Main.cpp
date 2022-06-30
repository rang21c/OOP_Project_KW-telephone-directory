#include <iostream>
#include "DepartmentList Class.h"
#include "NameList class.h"
#include "GradeList class.h"
#include "StudentIDList class.h"
#include "ContactList class.h"
#include "Manager.h"
#include <fstream>
#include <string>
#include <crtdbg.h>
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�޸𸮴��� üũ
	//_CrtSetBreakAlloc(1181);

	//��ũ�帮��Ʈ�� ���� Ŭ�������� ����
	DepartmentList d;
	NameList n;
	GradeList g;
	StudentIDList s;
	ContactList c;
	Manager m;

	ifstream in("Command.txt");//�ؽ�Ʈ���� �о����
	ofstream log("LOG.txt");//�ؽ�Ʈ���� ������������ ����
	char com[300];//���ٴ� �о�� ���� �迭

	while (!in.eof())
	{
		in.getline(com, 300);//���پ� �о����
		char *token;
		token = strtok(com, " ");//����������� ��ū ����
		if (strcmp(token, "LOAD") == 0)
		{//LOAD
			m.LOAD(token, d, n, g, s, c);
		}
		else if (strcmp(token, "ADD") == 0)
		{//ADD
			m.ADD(token, d, n, g, s, c);
		}
		else if (strcmp(token, "UPDATE") == 0)
		{//UPDATE
			m.UPDATE(token, d, n, g, s, c);
		}
		else if (strcmp(token, "MODIFY_DEPARTMENT") == 0)
		{//MODIFY_DEPARTMENT
			char* token1 = strtok(NULL, " ");//������ �а��� ��ū
			char* token2 = strtok(NULL, " ");//�ٲ� �а��� ��ū
			m.MODIFY_DEPARTMENT(token1, token2, d, n, g, s, c);
		}
		else if (strcmp(token, "DELETE_DEPARTMENT") == 0)
		{//DELETE_DEPARTMENT
			char* token1 = strtok(NULL, " ");//������ �а��� ��ū
			m.DELETE_DEPARTMENT(token1, d, n, g, s, c);
		}
		else if (strcmp(token, "PRINT") == 0)
		{//PRINT
			char* token1 = strtok(NULL, " ");//����� �а��� ��ū
			m.PRINT(token1, d);
		}
		else if (strcmp(token, "PRINT_STUDENT_ID") == 0)
		{//PRINT_STUDENT_ID
			m.PRINT_STUDENT_ID(d, n, s);
		}
		else if (strcmp(token, "PRINT_CONTACT") == 0)
		{//PRINT_CONTACT
			m.PRINT_CONTACT(d);
		}
		else if (strcmp(token, "FIND_NAME") == 0)
		{//FIND_NAME
			ofstream log("LOG.txt", ios::app);
			char* token1 = strtok(NULL, " ");//ã�� �̸� �Ǵ� �� ��ū
			cout << "[FIND_NAME]" << endl;
			log << "[FIND_NAME]" << endl;
			m.FIND_NAME(token1, d, n);
		}
		else if (strcmp(token, "SAVE") == 0)
		{//SAVE
			char* token1 = strtok(NULL, " ");//������ ���ϸ� ��ū
			m.SAVE(token1, d, n, g, s, c);
		}
		else if (strcmp(token, "EXIT") == 0)
		{//EXIT
			ofstream log("LOG.txt", ios::app);
			log << "[EXIT]" << endl << endl << endl;
			cout << "[EXIT]" << endl << endl << endl;
			return 0;//���α׷� ����
		}
		else
		{//�ش� ��ɾ �������� �ʴ°�� �����ڵ� ���
			ofstream log("LOG.txt", ios::app);
			log << "Error code : 000" << endl << endl << endl;
			cout << "Error code : 000" << endl << endl << endl;
		}
	}
	return 0;
}