#pragma once
#include "Department.h"
#include "NameList class.h"
#include "Name.h"
#include "Contact.h"
#include "Grade.h"
#include "StudentID.h"
#include <iostream>
using namespace std;

class DepartmentList
{//학과 리스트 클래스
private:
	Node* pHead;//헤드노드 변수 선언
	int de_size;//학과리스트 크기 변수
public:
	DepartmentList() {
		pHead = NULL;//변수 초기화
		de_size = 0;//변수 초기화
	}
	~DepartmentList()
	{//소멸자
		DepartmentNode* pCur = (DepartmentNode*)pHead;
		DepartmentNode* pNext = NULL;
		NameNode* temp = NULL;
		pCur->getPre()->setNext(NULL);//원형리스트 연결을 끊어줌
		while (pCur != NULL)
		{
			pNext = (DepartmentNode*)pCur->getNext();
			NameNode* pWalkdown = (NameNode*)pCur->getPdown();
			while (temp)
			{
				NameNode* temp = (NameNode*)pWalkdown->getPdown();
				delete(pWalkdown->getPfornt());
				delete(pWalkdown->getPleft());
				delete(pWalkdown->getPright());
				delete(pWalkdown);//학생정보 메모리해제
				pWalkdown = temp;
			}
			delete(pCur);//학과노드 메모리해제
			pCur = pNext;
		}
	}
	virtual void insert(char* department, char* name, int grade, char* stuID, char* contact);//전체 리스트(학과기준) 구성함수
	DepartmentNode* getde_head() { return (DepartmentNode*)pHead; }//헤드노드를 가져오는 함수
	int getde_size() { return de_size; }//학과리스트 사이즈 가져오는 함수
	void setde_size(int num) { de_size = num; }//학과리스트 사이즈 설정 함수
	void clear();//학과 리스트 초기화 함수
};
inline void DepartmentList::insert(char* department, char* name, int grade, char* stuID, char* contact)
{//학과 정보삽입
	//새로들어온 학과정보들 동적할당
	DepartmentNode* pNewdepartment = new DepartmentNode(department);
	NameNode* pNewname = new NameNode(name);
	Grade* pNewgrade = new Grade(grade);
	StudentID* pNewid = new StudentID(stuID);
	Contact* pNewcontact = new Contact(contact);
	pNewname->setPleft(pNewgrade);
	pNewname->setPfornt(pNewid);
	pNewname->setPright(pNewcontact);
	bool check = 0;

	if (pHead == NULL)
	{//헤드노드가 없을때
		pHead = pNewdepartment;//새로운노드를 헤드노드로 설정
		pHead->setNext(pHead);//다음노드를 헤드노드로 설정하여 원형리스트 구성
		pNewdepartment->setPdown(pNewname);//이름과 연결
		pNewname->setPup(pHead);
		pNewname->setPdown(NULL);
		de_size++;//학과 리스트 사이즈 증가
	}
	else
	{
		DepartmentNode* pWalk = (DepartmentNode*)pHead;
		DepartmentNode* plast = (DepartmentNode*)pHead;
		for (int i = 0; i < de_size; i++)
		{
			if (check == 1)
				break;
			if (strcmp(pWalk->get_de(), pNewdepartment->get_de()) < 0)
			{//새로들어온 값이 더 클때
				plast = (DepartmentNode*)pHead;
				for (int j = 0; j < de_size - 1; j++)
					plast = (DepartmentNode*)plast->getNext();//리스트 끝까지 반복
				if (pWalk == plast)
				{//리스트 맨끝에 학과 삽입
					pWalk->setNext(pNewdepartment);
					pNewdepartment->setPrev(pWalk);
					pNewdepartment->setNext(pHead);
					pHead->setPrev(pNewdepartment);
					check = 1;
					de_size++;//학과 리스트 사이즈 증가

					pNewdepartment->setPdown(pNewname);//새로운 이름 추가
					pNewname->setPup(pNewdepartment);
					pNewname->setPdown(NULL);
					break;//반복문 탈출
				}
				pWalk = (DepartmentNode*)pWalk->getNext();//다음노드로 이동
			}
			else if (strcmp(pWalk->get_de(), pNewdepartment->get_de()) > 0)
			{//새로들어온 값이 더 작을때 - 중간에 삽입해야할때
				if (pWalk == pHead)
				{//헤드노드보다 작은값이 들어왔을때
					plast = (DepartmentNode*)pHead;
					for (int j = 0; j < de_size-1; j++)
						plast = (DepartmentNode*)plast->getNext();//리스트 끝까지 반복
					pNewdepartment->setNext(pHead);
					pHead->setPrev(pNewdepartment);
					plast->setNext(pNewdepartment);
					pNewdepartment->setPrev(plast);
					pHead = pNewdepartment;//새로들어온노드를 헤드노드로 설정
					check = 1;
					de_size++;//리스트 사이즈 증가

					pNewdepartment->setPdown(pNewname);//새로운 이름 추가
					pNewname->setPup(pNewdepartment);
					pNewname->setPdown(NULL);
					break;
				}
				else
				{//나머지 경우
					pWalk->getPre()->setNext(pNewdepartment);
					pNewdepartment->setPrev(pWalk->getPre());
					pNewdepartment->setNext(pWalk);
					pWalk->setPrev(pNewdepartment);
					check = 1;
					de_size++;//리스트 사이즈 증가

					pNewdepartment->setPdown(pNewname);//새로운 이름 추가
					pNewname->setPup(pNewdepartment);
					pNewname->setPdown(NULL);
					break;
				}
			}
			else if (strcmp(pWalk->get_de(), pNewdepartment->get_de()) == 0)
			{//같은 학과 노드에 집어넣어야 할때
				NameNode* ptempWalk = (NameNode*)pWalk->getPdown();
				do
				{
					if (strcmp(ptempWalk->getname(), pNewname->getname()) < 0)
					{//새로들어온 이름이 더 큰 경우 즉, 다음노드로 가야하는 경우
						if (ptempWalk->getPdown() == NULL)
						{//이름 맨끝에 추가해야하는 경우
							ptempWalk->setPdown(pNewname);//맨끝노드를 새로운이름으로 설정
							pNewname->setPup(ptempWalk);
							pNewname->setPdown(NULL);
							check = 1;
							break;
						}
						ptempWalk = (NameNode*)ptempWalk->getPdown();//다음 노드로 계속 이동
						continue;
					}
					else if (strcmp(ptempWalk->getname(), pNewname->getname()) > 0)
					{//이름리스트 중간에 삽입해야하는경우
						if (ptempWalk == pWalk->getPdown())
						{//맨 위에 삽입해야할 경우
							pWalk->setPdown(pNewname);//맨 위에 새로운 이름노드 설정
							pNewname->setPup(pWalk);
							pNewname->setPdown(ptempWalk);
							ptempWalk->setPup(pNewname);
							check = 1;
						}
						else
						{//말그대로 중간에 삽입할 경우
							ptempWalk->getPup()->setPdown(pNewname);
							pNewname->setPup(ptempWalk->getPup());
							pNewname->setPdown(ptempWalk);
							ptempWalk->setPup(pNewname);
							check = 1;
						}
						break;
					}
					else if (strcmp(ptempWalk->getname(), pNewname->getname()) == 0)
					{//중복된 이름이 있을경우
						if (ptempWalk == pWalk->getPdown())
						{//맨 위에 삽입해야할 경우
							pWalk->setPdown(pNewname);//맨 위에 새로운 이름노드 설정
							pNewname->setPup(pWalk);
							pNewname->setPdown(ptempWalk);
							ptempWalk->setPup(pNewname);
							check = 1;
						}
						else
						{//말그대로 중간에 삽입할 경우
							ptempWalk->getPup()->setPdown(pNewname);
							pNewname->setPup(ptempWalk->getPup());
							pNewname->setPdown(ptempWalk);
							ptempWalk->setPup(pNewname);
							check = 1;
						}
						break;
					}
					break;//반복문 탈출
				} while (ptempWalk != NULL);
			}
		}
	}
	DepartmentNode* plast = (DepartmentNode*)pHead;
	for (int j = 0; j < de_size - 1; j++)
		plast = (DepartmentNode*)plast->getNext();
	plast->setNext(pHead);//원형리스트 구성
	pHead->setPrev(plast);//원형리스트 구성
}
inline void DepartmentList::clear()
{//초기화 함수
	pHead = NULL;//헤드노드 초기화
	de_size = 0;//학과리스트 사이즈 초기화
}
