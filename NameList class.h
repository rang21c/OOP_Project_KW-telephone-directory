#pragma once
#include "Name.h"
#include "DepartmentList Class.h"
#include <iostream>
using namespace std;

class NameList
{//이름 리스트 클래스
private:
	Node* pHead;//헤드노드
	int name_size;//리스트 사이즈
public:
	NameList() {//변수 초기화
		pHead = NULL;
		name_size = 0;
	}
	~NameList() {
		Node* temp = pHead;
		Node* deletenode = pHead;
		while (deletenode != NULL)
		{
			if (deletenode->getNext() == NULL)
				break;
			deletenode = deletenode->getNext();
			delete temp;//이름리스트 메모리해제
			temp = deletenode;
		}
	}
	virtual void insert(DepartmentNode* de_head, int desize);//리스트 구성 함수
	NameNode* getname_head() { return (NameNode*)pHead; }//헤드노드 받아오는 함수
	int getname_size() { return name_size; }//리스트 사이즈 받아오는 함수
	void setname_size(int num) { name_size = num; }//리스트 사이즈 설정하는 함수
	void clear();//초기화 함수
};
inline void NameList::insert(DepartmentNode* de_head, int desize)
{
	if (pHead == NULL)
	{//헤드노드가 없을때
		pHead = de_head->getPdown();//헤드노드 설정
		pHead->setNext(NULL);//다음노드 설정
		name_size++;//리스트 사이즈 증가
	}

	DepartmentNode* pWalknext = de_head;
	for (int i = 0; i < desize; i++)
	{//학과리스트 사이즈만큼 반복
		NameNode* pWalkdown = (NameNode*)pWalknext->getPdown();//학과리스트에서 아래노드로 내려가는 변수
		if (name_size == 1)
			pWalkdown = (NameNode*)pWalknext->getPdown()->getPdown();
		while (pWalkdown != NULL)
		{//해당 학과의 이름 끝까지 반복
			NameNode* pWalk = (NameNode*)pHead;
			while(pWalk != NULL)
			{//이름리스트 끝까지 반복
				if (strcmp(pWalk->getname(), pWalkdown->getname()) < 0)
				{//새로들어온값이 더 클때
					if (pWalk->getNext() == NULL)
					{//맨 끝에 삽입할때
						pWalk->setNext(pWalkdown);//이름리스트 맨 끝에 노드 삽입
						pWalkdown->setPrev(pWalk);
						pWalkdown->setNext(NULL);
						name_size++;//리스트 사이즈 증가
						break;//반복문 탈출
					}
					if (pWalk->getNext() == NULL)
						break;//이름리스트 끝까지 도착했다면 반복문 탈출
					pWalk = (NameNode*)pWalk->getNext();//이름리스트 다음노드로 이동
				}
				else if (strcmp(pWalk->getname(), pWalkdown->getname()) > 0)
				{//새로 들어온 값이 더 작을때 -  중간에 삽입해야하는 경우
					if (pWalk == pHead)
					{//헤드노드 바로앞에 삽입할때
						pWalkdown->setNext(pHead);
						pHead->setPrev(pWalkdown);
						pHead = pWalkdown;//새로운 이름을 헤드노드로 설정
						name_size++;//리스트 사이즈 증가
						break;//반복문 탈출
					}
					else
					{//그 이외의 일반적인 경우
						pWalk->getPre()->setNext(pWalkdown);
						pWalkdown->setPrev(pWalk->getPre());
						pWalkdown->setNext(pWalk);
						pWalk->setPrev(pWalkdown);
						name_size++;//리스트 사이즈 증가
						break;//반복문 탈출
					}
				}
				else if (strcmp(pWalk->getname(), pWalkdown->getname()) == 0)
				{//중복된 이름이 있을경우
					if (pWalk == pHead)
					{//헤드노드 바로앞에 삽입할때
						pWalkdown->setNext(pHead);
						pHead->setPrev(pWalkdown);
						pHead = pWalkdown;//새로운 이름을 헤드노드로 설정
						name_size++;//리스트 사이즈 증가
						break;//반복문 탈출
					}
					else
					{//그 이외의 일반적인 경우
						pWalk->getPre()->setNext(pWalkdown);
						pWalkdown->setPrev(pWalk->getPre());
						pWalkdown->setNext(pWalk);
						pWalk->setPrev(pWalkdown);
						name_size++;//리스트 사이즈 증가
						break;//반복문 탈출
					}
				}
			}
			pWalkdown = (NameNode*)pWalkdown->getPdown();//아래노드로 이동
		}
		pWalknext = (DepartmentNode*)pWalknext->getNext();//다음 학과로 이동
	}
}
inline void NameList::clear()
{//리스트 초기화
	pHead = NULL;//헤드노드 초기화
	name_size = 0;//사이즈 초기화
}