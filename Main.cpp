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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//메모리누수 체크
	//_CrtSetBreakAlloc(1181);

	//링크드리스트를 위한 클래스변수 선언
	DepartmentList d;
	NameList n;
	GradeList g;
	StudentIDList s;
	ContactList c;
	Manager m;

	ifstream in("Command.txt");//텍스트파일 읽어오기
	ofstream log("LOG.txt");//텍스트파일 쓰기형식으로 열기
	char com[300];//한줄당 읽어올 문장 배열

	while (!in.eof())
	{
		in.getline(com, 300);//한줄씩 읽어오기
		char *token;
		token = strtok(com, " ");//공백기준으로 토큰 생성
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
			char* token1 = strtok(NULL, " ");//수정할 학과명 토큰
			char* token2 = strtok(NULL, " ");//바꿀 학과명 토큰
			m.MODIFY_DEPARTMENT(token1, token2, d, n, g, s, c);
		}
		else if (strcmp(token, "DELETE_DEPARTMENT") == 0)
		{//DELETE_DEPARTMENT
			char* token1 = strtok(NULL, " ");//삭제할 학과명 토큰
			m.DELETE_DEPARTMENT(token1, d, n, g, s, c);
		}
		else if (strcmp(token, "PRINT") == 0)
		{//PRINT
			char* token1 = strtok(NULL, " ");//출력할 학과명 토큰
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
			char* token1 = strtok(NULL, " ");//찾을 이름 또는 성 토큰
			cout << "[FIND_NAME]" << endl;
			log << "[FIND_NAME]" << endl;
			m.FIND_NAME(token1, d, n);
		}
		else if (strcmp(token, "SAVE") == 0)
		{//SAVE
			char* token1 = strtok(NULL, " ");//생성할 파일명 토큰
			m.SAVE(token1, d, n, g, s, c);
		}
		else if (strcmp(token, "EXIT") == 0)
		{//EXIT
			ofstream log("LOG.txt", ios::app);
			log << "[EXIT]" << endl << endl << endl;
			cout << "[EXIT]" << endl << endl << endl;
			return 0;//프로그램 종료
		}
		else
		{//해당 명령어가 존재하지 않는경우 에러코드 출력
			ofstream log("LOG.txt", ios::app);
			log << "Error code : 000" << endl << endl << endl;
			cout << "Error code : 000" << endl << endl << endl;
		}
	}
	return 0;
}