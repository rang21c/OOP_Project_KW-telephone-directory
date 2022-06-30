#pragma once
#include <iostream>
#include "DepartmentList Class.h"
#include "NameList class.h"
#include "GradeList class.h"
#include "StudentIDList class.h"
#include "ContactList class.h"
#include <fstream>
#include <string>
using namespace std;

class Manager
{//매니저 클래스
public:
	Manager() {}
	~Manager() {}
	void LOAD(char* str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c);
	void ADD(char* str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c);
	void UPDATE(char* str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c);
	void MODIFY_DEPARTMENT(char* str, char* str1, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c);
	void DELETE_DEPARTMENT(char* str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c);
	void PRINT(char* str, DepartmentList &d);
	void PRINT_STUDENT_ID(DepartmentList &d, NameList &n, StudentIDList &s);
	void PRINT_CONTACT(DepartmentList &d);
	void FIND_NAME(char* str, DepartmentList & d, NameList &n);
	void SAVE(char* str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c);
};
inline void Manager::LOAD(char* str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c)
{
	ifstream in("information.txt");//정보가 담긴 텍스트파일 열기
	ofstream log("LOG.txt", ios::app);//LOG파일을 쓰기형식으로 커서맨끝으로 이동한뒤 오픈
	if (in.is_open() == false)//파일이 열리지 않았을때
	{//에러코드 100 출력후 종료
		log << "[LOAD]"<<endl<<"Error code : 100" << endl << endl << endl;
		cout << "[LOAD]" << endl << "Error code : 100" << endl << endl << endl;
		exit(100);
	}
	char command[300];
	while (!in.eof())
	{//파일의 끝까지 반복
		in.getline(command, 300);//한줄 읽어오기
		char* token;//학과
		char* token1;//이름
		char* token2;//학년
		char* token3;//학번
		char* token4;//전화번호
		token = strtok(command, "\t");
		token1 = strtok(NULL, "\t");
		token2 = strtok(NULL, "\t");
		token3 = strtok(NULL, "\t");
		token4 = strtok(NULL, "\t");
		if (token == NULL)
			break;
		d.insert(token, token1, atoi(token2), token3, token4);//학과리스트 구성
	}
	n.insert(d.getde_head(), d.getde_size());//이름리스트 구성
	g.gradelist(n.getname_head(), n.getname_size());//학년리스트 구성
	s.idlist(n.getname_head(), n.getname_size());//학번리스트 구성
	c.contactlist(n.getname_head(), n.getname_size());//전화번호 리스트 구성
	log << "[LOAD]" << endl << "Success" << endl << endl << endl;
	cout << "[LOAD]" << endl << "Success" << endl << endl << endl;
}
inline void Manager::ADD(char* str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c)
{
	ifstream in("Add_information.txt");//정보가 담긴 텍스트파일 열기
	ofstream log("LOG.txt", ios::app);//LOG파일을 쓰기형식으로 커서맨끝으로 이동한뒤 오픈
	if (in.is_open() == false)//파일이 열리지 않았을때
	{//에러코드 200 출력
		log << "[ADD]" << endl << "Error code : 200" << endl << endl << endl;
		cout << "[ADD]" << endl << "Error code : 200" << endl << endl << endl;
	}
	char command[300];
	while (!in.eof())
	{//파일의 끝까지 반복
		in.getline(command, 300);//한줄 읽어오기
		char* token;//학과
		char* token1;//이름
		char* token2;//학년
		char* token3;//학번
		char* token4;//전화번호
		token = strtok(command, "\t");
		token1 = strtok(NULL, "\t");
		token2 = strtok(NULL, "\t");
		token3 = strtok(NULL, "\t");
		token4 = strtok(NULL, "\t");
		bool flag = 0;
		DepartmentNode* pWalk1 = d.getde_head();
		for (int i = 0; i < d.getde_size(); i++)
		{//학과리스트 끝까지반복
			NameNode* ptempWalk = (NameNode*)pWalk1->getPdown();
			while (ptempWalk != NULL)
			{//해당학과 이름 끝까지 반복
				if (strcmp(token3, ptempWalk->getPfornt()->getid()) == 0 || strcmp(token4, ptempWalk->getPright()->getcontact()) == 0)
				{//학번 또는 번호가 기존에 경우와 중복될 경우 에러코드200-1출력
					log << "[ADD]" << endl << "Error code : 200-1" << endl << endl << endl;
					cout << "[ADD]" << endl << "Error code : 200-1" << endl << endl << endl;
					flag = 1;//플래그변수 1로 설정
					break;
				}
				ptempWalk = (NameNode*)ptempWalk->getPdown();
			}
			if (flag)break;
			pWalk1 = (DepartmentNode*)pWalk1->getNext();
		}
		if (flag)continue;//플래그가 1이면 리스트에 추가하지않고 다시 반복
		d.insert(token, token1, atoi(token2), token3, token4);//학과리스트
	}
	n.clear();//리스트 초기화
	c.clear();//리스트 초기화
	g.clear();//리스트 초기화
	s.clear();//리스트 초기화
	n.insert(d.getde_head(), d.getde_size());//이름리스트
	g.gradelist(n.getname_head(), n.getname_size());//학년리스트
	s.idlist(n.getname_head(), n.getname_size());//학번리스트
	c.contactlist(n.getname_head(), n.getname_size());//전화번호리스트
	log << "[ADD]" << endl << "Success" << endl << endl << endl;
	cout << "[ADD]" << endl << "Success" << endl << endl << endl;
}
inline void Manager::UPDATE(char * str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c)
{
	ifstream in("Update_information.txt");
	ofstream log("LOG.txt", ios::app);
	if (in.is_open() == false)
	{
		log << "[UPDATE]" << endl << "Error code : 300" << endl << endl << endl;
		cout << "[UPDATE]" << endl << "Error code : 300" << endl << endl << endl;
	}
	char command[300];
	while (!in.eof())
	{//파일의 끝까지 반복
		in.getline(command, 300);//한줄 읽어오기
		char* token;//학과
		char* token1;//이름
		char* token2;//학년
		char* token3;//학번
		char* token4;//전화번호
		token = strtok(command, "\t");
		token1 = strtok(NULL, "\t");
		token2 = strtok(NULL, "\t");
		token3 = strtok(NULL, "\t");
		token4 = strtok(NULL, "\t");
		bool flag = 0;
		DepartmentNode* pWalk1 = d.getde_head();
		for (int i = 0; i < d.getde_size(); i++)
		{//학과리스트 끝까지반복
			NameNode* ptempWalk = (NameNode*)pWalk1->getPdown();
			while (ptempWalk != NULL)
			{//해당학과 이름 끝까지 반복
				if (strcmp(token1, ptempWalk->getname()) != 0 && (strcmp(token3, ptempWalk->getPfornt()->getid()) == 0 || strcmp(token4, ptempWalk->getPright()->getcontact()) == 0))
				{//학번 또는 번호가 기존에 경우와 중복될 경우 에러코드300-1출력
					log << "[UPDATE]" << endl << "Error code : 300-1" << endl << endl << endl;
					cout << "[UPDATE]" << endl << "Error code : 300-1" << endl << endl << endl;
					flag = 1;//플래그 1로 설정
					break;
				}
				ptempWalk = (NameNode*)ptempWalk->getPdown();
			}
			if (flag)break;
			pWalk1 = (DepartmentNode*)pWalk1->getNext();
		}
		if (flag)continue;//플래그가 1이면 리스트에 추가하지않고 다시 반복

		DepartmentNode* pWalk = d.getde_head();
		bool check = 0;
		for (int i = 0; i < d.getde_size(); i++)
		{
			check = 0;
			NameNode* pWalkdown = (NameNode*)pWalk->getPdown();
			while (pWalkdown != NULL)
			{
				if (strcmp(pWalkdown->getname(), token1) == 0)
				{//똑같은 이름을 찾으면 UPDATE
					check = 1;
					if (pWalkdown->getPdown() == NULL)
					{//밑의 노드가 없을때
						pWalkdown->getPup()->setPdown(pWalkdown->getPdown());
					}
					else
					{//그 이외의 경우
						pWalkdown->getPup()->setPdown(pWalkdown->getPdown());
						pWalkdown->getPdown()->setPup(pWalkdown->getPup());
					}
					delete pWalkdown->getPleft();
					delete pWalkdown->getPfornt();
					delete pWalkdown->getPright();
					delete pWalkdown;//해당 이름 삭제
					n.setname_size(n.getname_size() - 1);
					if (pWalk->getPdown() == NULL)
					{//해당 학과의 재학생이 없을경우
						pWalk->getPre()->setNext(pWalk->getNext());
						pWalk->getNext()->setPrev(pWalk->getPre());
						d.setde_size(d.getde_size() - 1);
						delete pWalk;//해당 학과 노드 삭제
					}
					d.insert(token, token1, atoi(token2), token3, token4);//삭제한 데이터를 업데이트해서 리스트에 다시 추가
					break;
				}
				pWalkdown = (NameNode*)pWalkdown->getPdown();//아래노드로 이동
			}
			if (check)break;//업데이트를 했다면 반복문 탈출
			pWalk = (DepartmentNode*)pWalk->getNext();//다음 학과로 이동
		}
		if (check == 0)
		{//기존의 information에 존재하지 않을 경우
			log << "[UPDATE]" << endl << "Error code : 300-2" << endl << endl << endl;
			cout << "[UPDATE]" << endl << "Error code : 300-2" << endl << endl << endl;
		}
	}
	n.clear();//리스트 초기화
	c.clear();//리스트 초기화
	g.clear();//리스트 초기화
	s.clear();//리스트 초기화
	n.insert(d.getde_head(), d.getde_size());//새로운 이름 리스트 구성
	g.gradelist(n.getname_head(), n.getname_size());//새로운 학년 리스트 구성
	s.idlist(n.getname_head(), n.getname_size());//새로운 학번 리스트 구성
	c.contactlist(n.getname_head(), n.getname_size());//새로운 연락처 리스트 구성
	log << "[UPDATE]" << endl << "Success" << endl << endl << endl;
	cout << "[UPDATE]" << endl << "Success" << endl << endl << endl;
}
inline void Manager::MODIFY_DEPARTMENT(char * str, char * str1, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c)
{
	ofstream log("LOG.txt", ios::app);//쓰기형식으로 파일 오픈
	if (str == NULL)
	{//입력된 학과가 존재하지 않을 경우 에러코드 400출력
		log << "[MODIFY_DEPARTMENT]" << endl << "Error code : 400" << endl;
		cout << "[MODIFY_DEPARTMENT]" << endl << "Error code : 400" << endl;
		log << "No result" << endl << endl << endl;
		cout << "No result" << endl << endl << endl;
	}
	else
	{
		DepartmentNode* pWalk = (DepartmentNode*)d.getde_head();
		for (int i = 0; i < d.getde_size() - 1; i++)
		{
			if (strcmp(pWalk->get_de(), str) == 0)
			{//일치하는 학과가 존재하면 해당학과 연결 끊기
				pWalk->getPre()->setNext(pWalk->getNext());
				pWalk->getNext()->setPrev(pWalk->getPre());
				d.setde_size(d.getde_size() - 1);
				break;
			}
			pWalk = (DepartmentNode*)pWalk->getNext();
		}
		NameNode* ptempWalk = (NameNode*)pWalk->getPdown();
		while (ptempWalk != NULL)
		{//해당 학과의 사람들을 원하는 학과로 이동하여 리스트 구성
			d.insert(str1, ptempWalk->getname(), ptempWalk->getPleft()->getgrade(), ptempWalk->getPfornt()->getid(), ptempWalk->getPright()->getcontact());
			ptempWalk = (NameNode*)ptempWalk->getPdown();
		}

		ptempWalk = (NameNode*)pWalk->getPdown();
		while (ptempWalk != NULL)
		{
			while (ptempWalk != NULL)
			{//노드 끝까지 이동
				if (ptempWalk->getPdown() == NULL)
					break;
				ptempWalk = (NameNode*)ptempWalk->getPdown();
			}
			NameNode* tempnode = (NameNode*)ptempWalk->getPup();
			NameNode* deleteWalk = ptempWalk;
			//학생 정보 삭제
			delete deleteWalk->getPleft();
			delete deleteWalk->getPfornt();
			delete deleteWalk->getPright();
			delete deleteWalk;//맨 아래노드부터 삭제
			n.setname_size(n.getname_size() - 1);
			tempnode->setPdown(NULL);
			ptempWalk = (NameNode*)pWalk->getPdown();//아래노드로 이동
		}
		delete pWalk;//해당 학과 삭제
		n.clear();//리스트 초기화
		c.clear();//리스트 초기화
		g.clear();//리스트 초기화
		s.clear();//리스트 초기화
		n.insert(d.getde_head(), d.getde_size());//새로운 이름 리스트 구성
		g.gradelist(n.getname_head(), n.getname_size());//새로운 학년 리스트 구성
		s.idlist(n.getname_head(), n.getname_size());//새로운 학번 리스트 구성
		c.contactlist(n.getname_head(), n.getname_size());//새로운 연락처 리스트 구성
		log << "[MODIFY_DEPARTMENT]" << endl << "Success" << endl << endl << endl;
		cout << "[MODIFY_DEPARTMENT]" << endl << "Success" << endl << endl << endl;
	}
}
inline void Manager::DELETE_DEPARTMENT(char * str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c)
{
	ofstream log("LOG.txt", ios::app);//쓰기형식으로 파일 오픈
	if (str == NULL)
	{//입력된 학과가 존재하지 않을 경우 에러코드 500출력
		log << "[DELETE_DEPARTMENT]" << endl << "Error code : 500" << endl;
		cout << "[DELETE_DEPARTMENT]" << endl << "Error code : 500" << endl;
		log << "No result" << endl << endl << endl;
		cout << "No result" << endl << endl << endl;
	}
	else
	{
		DepartmentNode* pWalk = (DepartmentNode*)d.getde_head();
		for (int i = 0; i < d.getde_size() - 1; i++)
		{
			if (strcmp(pWalk->get_de(), str) == 0)
			{//해당 학과명과 일치하면
				NameNode* ptempWalk = (NameNode*)pWalk->getPdown();
				while (ptempWalk != NULL)
				{//노드 끝까지 이동
					while (ptempWalk != NULL)
					{
						if (ptempWalk->getPdown() == NULL)
							break;
						ptempWalk = (NameNode*)ptempWalk->getPdown();
					}
					NameNode* tempnode = (NameNode*)ptempWalk->getPup();
					NameNode* deleteWalk = ptempWalk;
					//학생 정보 삭제
					delete deleteWalk->getPleft();
					delete deleteWalk->getPfornt();
					delete deleteWalk->getPright();
					delete deleteWalk;//해당 학생 노드 삭제
					n.setname_size(n.getname_size() - 1);
					tempnode->setPdown(NULL);
					ptempWalk = (NameNode*)pWalk->getPdown();//아래노드로 이동
				}
				pWalk->getPre()->setNext(pWalk->getNext());
				pWalk->getNext()->setPrev(pWalk->getPre());
				delete pWalk;//해당 학과 삭제
				d.setde_size(d.getde_size() - 1);
				break;
			}
			pWalk = (DepartmentNode*)pWalk->getNext();//다음 학과노드로 이동
		}
		log << "[DELETE_DEPARTMENT]" << endl << "Success" << endl << endl << endl;
		cout << "[DELETE_DEPARTMENT]" << endl << "Success" << endl << endl << endl;
		n.clear();//리스트 초기화
		c.clear();//리스트 초기화
		g.clear();//리스트 초기화
		s.clear();//리스트 초기화
		n.insert(d.getde_head(), d.getde_size());//새로운 이름 리스트 구성
		g.gradelist(n.getname_head(), n.getname_size());//새로운 학년 리스트 구성
		s.idlist(n.getname_head(), n.getname_size());//새로운 학번 리스트 구성
		c.contactlist(n.getname_head(), n.getname_size());//새로운 연락처 리스트
	}
}
inline void Manager::PRINT(char* str, DepartmentList & d)
{
	ofstream log("LOG.txt", ios::app);//쓰기형식으로 텍스트파일 열기
	log << "[PRINT]" << endl;
	cout << "[PRINT]" << endl;
	if (d.getde_head() == NULL)
	{//링크드 리스트가 존재하지 않은경우 에러코드 600-1출력
		log  << "Error code : 600-1" << endl;
		cout << "Error code : 600-1" << endl;
		log << "No result" << endl << endl << endl;
		cout << "No result" << endl << endl << endl;
	}
	if (str == NULL)
	{//학과가 입력되지 않았을 경우
		DepartmentNode* pWalk = (DepartmentNode*)d.getde_head()->getPre();
		for (int i = 0; i < d.getde_size(); i++)
		{
			NameNode* ptempWalk = (NameNode*)pWalk->getPdown();
			while (ptempWalk != NULL)
			{//정보 출력
				cout<< pWalk->get_de() << "/"
					<< ptempWalk->getname() << "/"
					<< ptempWalk->getPleft()->getgrade() << "/"
					<< ptempWalk->getPfornt()->getid() << "/"
					<< ptempWalk->getPright()->getcontact() << endl;
				log << pWalk->get_de() << "/"
					<< ptempWalk->getname() << "/"
					<< ptempWalk->getPleft()->getgrade() << "/"
					<< ptempWalk->getPfornt()->getid() << "/"
					<< ptempWalk->getPright()->getcontact() << endl;
				ptempWalk = (NameNode*)ptempWalk->getPdown();//아래노드로 이동
			}
			pWalk = (DepartmentNode*)pWalk->getPre();
		}
		log << endl << endl << endl;
		cout << endl << endl << endl;
	}
	else
	{//학과가 입력되었을경우
		bool check = 0;
		DepartmentNode* pWalk = (DepartmentNode*)d.getde_head();
		for (int i = 0; i < d.getde_size() - 1; i++)
		{
			if (strcmp(pWalk->get_de(), str) == 0)
			{//입력받은 학과와 일치하면
				check = 1;
				NameNode* ptempWalk = (NameNode*)pWalk->getPdown();
				while (ptempWalk != NULL)
				{//정보 출력
					cout<< pWalk->get_de() << "/"
						<< ptempWalk->getname() << "/"
						<< ptempWalk->getPleft()->getgrade() << "/"
						<< ptempWalk->getPfornt()->getid() << "/"
						<< ptempWalk->getPright()->getcontact() << endl;
					log << pWalk->get_de() << "/"
						<< ptempWalk->getname() << "/"
						<< ptempWalk->getPleft()->getgrade() << "/"
						<< ptempWalk->getPfornt()->getid() << "/"
						<< ptempWalk->getPright()->getcontact() << endl;
					ptempWalk = (NameNode*)ptempWalk->getPdown();//아래노드로 이동
				}
			}
			pWalk = (DepartmentNode*)pWalk->getNext();
		}
		log << endl << endl << endl;
		cout << endl << endl << endl;
		if (check == 0)
		{//해당 학과가 존재하지 않을 경우 에러코드 600-2 출력
			log << "[PRINT]" << endl << "Error code : 600-2" << endl << endl << endl;
			cout << "[PRINT]" << endl << "Error code : 600-2" << endl << endl << endl;
		}
	}
}
inline void Manager::PRINT_STUDENT_ID(DepartmentList & d, NameList &n, StudentIDList &s)
{
	ofstream log("LOG.txt", ios::app);//쓰기형식으로 파일오픈
	cout << "[PRINT_STUDENT_ID]" << endl;
	log << "[PRINT_STUDENT_ID]" << endl;
	DepartmentNode* pWalk = d.getde_head();
	if (pWalk == NULL)
	{//링크드 리스트가 존재하지 않을경우 에러코드 700출력
		log << "Error code : 700" << endl;
		cout << "Error code : 700" << endl;
		log << "No result" << endl << endl << endl;
		cout << "No result" << endl << endl << endl;
	}
	char* de[300] = { 0, };//학과 배열
	char* na[300] = { 0, };//이름 배열
	int gra[300] = { 0, };//학년 배열
	char* id[300] = { 0, };//학번 배열
	char* co[300] = { 0, };//번호 배열
	
	int k = 0;
	for (int i = 0; i < d.getde_size(); i++)
	{
		NameNode* pWalkdown = (NameNode*)pWalk->getPdown();
		while (pWalkdown != NULL)
		{//각 배열에 링크드리스트 저장
			de[k] = pWalk->get_de();
			na[k] = pWalkdown->getname();
			gra[k] = pWalkdown->getPleft()->getgrade();
			id[k] = pWalkdown->getPfornt()->getid();
			co[k] = pWalkdown->getPright()->getcontact();
			pWalkdown = (NameNode*)pWalkdown->getPdown();
			k++;
		}
		pWalk = (DepartmentNode*)pWalk->getNext();
	}
	int v = 0;
	while (id[v] != NULL)
		v++;//배열 길이 측정
	
	char* tempnode;
	int tempnode1;
	int p;
	for (int i = 0; i < v-1; i++)
	{//삽입정렬
		for(int p = i + 1; p>0; p--)
		{
			if (strcmp(id[p - 1], id[p])>0)
			{
				tempnode = co[p];
				co[p] = co[p-1];
				co[p - 1] = tempnode;
				tempnode = de[p];
				de[p] = de[p - 1];
				de[p - 1] = tempnode;
				tempnode = na[p];
				na[p] = na[p - 1];
				na[p - 1] = tempnode;
				tempnode = id[p];
				id[p] = id[p - 1];
				id[p - 1] = tempnode;
				tempnode1 = gra[p];
				gra[p] = gra[p - 1];
				gra[p - 1] = tempnode1;
			}
			else
				continue;
		}
	}
	for (int i = 0; i < v; i++)
	{//학번순으로 오름차순정렬된 배열들을 차례대로 출력
		cout << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
		log << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
	}
	log << endl << endl;
	cout << endl << endl;
}
inline void Manager::PRINT_CONTACT(DepartmentList & d)
{
	ofstream log("LOG.txt", ios::app);//쓰기형식으로 텍스트파일 열기
	cout << "[PRINT_CONTACT]" << endl;
	log << "[PRINT_CONTACT]" << endl;
	DepartmentNode* pWalk = d.getde_head();
	if (pWalk == NULL)
	{//링크드 리스트가 존재하지않을 경우 에러코드 800출력
		log << "Error code : 800" << endl;
		cout << "Error code : 800" << endl;
		log << "No result" << endl << endl << endl;
		cout << "No result" << endl << endl << endl;
	}
	char* de[300] = { 0, };//학과 배열
	char* na[300] = { 0, };//이름 배열
	int gra[300] = { 0, };//학년 배열
	char* id[300] = { 0, };//학번 배열
	char* co[300] = { 0, };//번호 배열

	int k = 0;
	for (int i = 0; i < d.getde_size(); i++)
	{
		NameNode* pWalkdown = (NameNode*)pWalk->getPdown();
		while (pWalkdown != NULL)
		{//배열에 링크드리스트 저장
			de[k] = pWalk->get_de();
			na[k] = pWalkdown->getname();
			gra[k] = pWalkdown->getPleft()->getgrade();
			id[k] = pWalkdown->getPfornt()->getid();
			co[k] = pWalkdown->getPright()->getcontact();
			pWalkdown = (NameNode*)pWalkdown->getPdown();
			k++;
		}
		pWalk = (DepartmentNode*)pWalk->getNext();
	}
	int v = 0;
	while (co[v] != NULL)
		++v;//배열 길이 측정

	char* tempnode;
	int tempnode1;
	for (int i = 0; i < v - 1; i++)
	{//선택 정렬
		int temp = i;
		for (int j = i + 1; j < v; j++)
		{
			if (strcmp((char*)co[temp], (char*)co[j]) > 0)
				temp = j;//뒤쪽에서 작은값이 발견되면 temp값 저장
		}
		tempnode = co[temp];
		co[temp] = co[i];
		co[i] = tempnode;
		tempnode = de[temp];
		de[temp] = de[i];
		de[i] = tempnode;
		tempnode = na[temp];
		na[temp] = na[i];
		na[i] = tempnode;
		tempnode = id[temp];
		id[temp] = id[i];
		id[i] = tempnode;
		tempnode1= gra[temp];
		gra[temp] = gra[i];
		gra[i] = tempnode1;
	}
	for (int i = 0; i < v; i++)
	{//전화번호순으로 오름차순정렬된 배열들을 차례대로 출력
		cout << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
		log << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
	}
	log << endl << endl;
	cout << endl << endl;
}
inline void Manager::FIND_NAME(char * str, DepartmentList & d, NameList & n)
{
	ofstream log("LOG.txt", ios::app);//쓰기형식으로 텍스트파일 열기
	DepartmentNode* pWalk = d.getde_head();

	char* de[300] = { 0, };//학과 배열
	char* na[300] = { 0, };//이름 배열
	int gra[300] = { 0, };//학년 배열
	char* id[300] = { 0, };//학번 배열
	char* co[300] = { 0, };//번호 배열

	int k = 0;
	for (int i = 0; i < d.getde_size(); i++)
	{
		NameNode* pWalkdown = (NameNode*)pWalk->getPdown();
		while (pWalkdown != NULL)
		{//배열에 링크드리스트 저장
			de[k] = pWalk->get_de();
			na[k] = pWalkdown->getname();
			gra[k] = pWalkdown->getPleft()->getgrade();
			id[k] = pWalkdown->getPfornt()->getid();
			co[k] = pWalkdown->getPright()->getcontact();
			pWalkdown = (NameNode*)pWalkdown->getPdown();
			k++;
		}
		pWalk = (DepartmentNode*)pWalk->getNext();
	}
	int v = 0;
	while (co[v] != NULL)
		++v;//배열길이 측정
	char* tempnode;
	int tempnode1;
	for (int i = 0; i < v; i++)
	{//버블 정렬
		for (int j = 0; j < v - (i + 1); j++)
		{//맨 앞에서 부터 계속 훑어 가면서 정렬
			if (strcmp(na[j], na[j + 1]) > 0)
			{
				tempnode = co[j];
				co[j] = co[j + 1];
				co[j + 1] = tempnode;
				tempnode = de[j];
				de[j] = de[j + 1];
				de[j + 1] = tempnode;
				tempnode = na[j];
				na[j] = na[j + 1];
				na[j + 1] = tempnode;
				tempnode = id[j];
				id[j] = id[j + 1];
				id[j + 1] = tempnode;
				tempnode1 = gra[j];
				gra[j] = gra[j + 1];
				gra[j + 1] = tempnode1;
			}
		}
	}
	bool check = 0;
	if (str[2] != NULL)
	{//이름을 다 입력받았을때
		for (int i = 0; i < v; i++)
		{
			if (strcmp(str, na[i]) == 0)
			{//해당 이름이 발견된다면
				check = 1;
				cout << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
				log << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
			}
		}
	}
	char temp[3] = { str[0], str[1] };
	if(str[2] == NULL)
	{//성만 입력받았을때
		for (int i = 0; i < v; i++)
		{
			char* tempname = na[i];
			char tempnamearr[3] = { tempname[0], tempname[1] };
			if (strcmp(str, tempnamearr) == 0)
			{//해당 성을 가진사람이 존재하면
				check = 1;
				cout << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
				log << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
			}
		}
	}
	if (check == 0)
	{//해당 이름 또는 성이 존재하지 않을 경우 에러코드 900출력
		log  << "Error code : 900" << endl;
		cout  << "Error code : 900" << endl;
		log << "No result" << endl << endl << endl;
		cout << "No result" << endl << endl << endl;
	}
	log << endl << endl;
	cout << endl << endl;
}
inline void Manager::SAVE(char * str, DepartmentList & d, NameList & n, GradeList & g, StudentIDList & s, ContactList & c)
{
	if (str != NULL)
	{//파일명 인자를 입력받았다면
		ofstream of(str);//입력받은 파일명으로 쓰기파일 생성후 오픈
		DepartmentNode* pWalk = (DepartmentNode*)d.getde_head();
		for (int i = 0; i < d.getde_size(); i++)
		{
			NameNode* ptempWalk = (NameNode*)pWalk->getPdown();
			while (ptempWalk != NULL)
			{//모든 링크드 리스트정보를 파일에 입력
				of  << pWalk->get_de() << "/"
					<< ptempWalk->getname() << "/"
					<< ptempWalk->getPleft()->getgrade() << "/"
					<< ptempWalk->getPfornt()->getid() << "/"
					<< ptempWalk->getPright()->getcontact() << endl;
				ptempWalk = (NameNode*)ptempWalk->getPdown();
			}
			pWalk = (DepartmentNode*)pWalk->getNext();
		}
		of << endl;
		ofstream log("LOG.txt", ios::app);
		log << "[SAVE]" << endl << str << " Success" << endl << endl << endl;
		cout << "[SAVE]" << endl << str << " Success" << endl << endl << endl;
	}
	else
	{//파일명 인자가 없는경우 에러코드 1000출력
		ofstream log("LOG.txt", ios::app);
		log << "[SAVE]" << endl << "Error code : 1000" << endl;
		cout << "[SAVE]" << endl << "Error code : 1000" << endl;
		log << "No result" << endl << endl << endl;
		cout << "No result" << endl << endl << endl;
	}
}
