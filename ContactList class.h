#pragma once
#include "DepartmentList Class.h"
#include "NameList class.h"
#include "Contact.h"
#include <iostream>
using namespace std;

class ContactList
{//전화번호 리스트 클래스
private:
	Contact* pHead;//헤드노드
	int contact_size;//전화번호리스트 크기
public:
	ContactList() {
		pHead = NULL;//변수 초기화
		contact_size = 0;//변수 초기화
	}
	~ContactList() {
		Contact* temp = pHead;
		Contact* deletenode = pHead;
		while (deletenode != NULL)
		{
			if (deletenode->getright() == NULL)
				break;
			deletenode = deletenode->getright();
			delete temp;//연락처리스트 메모리해제
			temp = deletenode;
		}
	}
	void contactlist(NameNode* name_head, int namesize);//전화번호 리스트 만드는 함수
	void clear();//전화번호 리스트 초기화함수
};
inline void ContactList::contactlist(NameNode* name_head, int namesize)
{
	if (pHead == NULL)
	{//아무 노드도 없다면
		pHead = name_head->getPright();//헤드노드를 설정
		pHead->setright(NULL);//다음노드 설정
		contact_size++;//리스트 크기증가
	}
	Contact* pCur = pHead;
	NameNode* pWalk = name_head;
	while(pWalk != NULL)
	{//name노드 리스트의 끝까지 반복
		if (pWalk->getNext() == NULL)
			break;//name노드 리스트 끝에 도달하면 반복문 탈출
		pWalk = (NameNode*)pWalk->getNext();//name노드의 다음 노드로 계속 이동
		pCur->setright(pWalk->getPright());//다음 노드 설정
		pCur->getright()->setright(NULL);
		pCur = pCur->getright();//전화번호리스트 다음노드로 이동
		contact_size++;//리스트 크기증가
	}
}
inline void ContactList::clear()
{//초기화함수
	pHead = NULL;//헤드노드를 초기화해줌
	contact_size = 0;//리스트 사이즈도 초기화
}
