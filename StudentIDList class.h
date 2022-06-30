#pragma once
#include "DepartmentList Class.h"
#include "NameList class.h"
#include "StudentID.h"
#include <iostream>
using namespace std;

class StudentIDList
{//학번 리스트 클래스
private:
	StudentID* pHead;//헤드노드
	int id_size;//학번리스트 크기
public:
	StudentIDList() {
		pHead = NULL;//변수 초기화
		id_size = 0;//변수 초기화
	}
	~StudentIDList() {
		StudentID* temp = pHead;
		StudentID* deletenode = pHead;
		while (deletenode != NULL)
		{
			if (deletenode->getfront() == NULL)
				break;
			deletenode = deletenode->getfront();
			delete temp;//학번 리스트 메모리해제
			temp = deletenode;
		}
	}
	void idlist(NameNode* name_head, int namesize);//학번리스트 노드
	StudentID* gethead() { return pHead; }//헤드노드를 가져오는 함수
	void clear();//학번 리스트 초기화함수
};
inline void StudentIDList::idlist(NameNode* name_head, int namesize)
{
	if (pHead == NULL)
	{//아무 노드도 없다면
		pHead = name_head->getPfornt();//헤드노드를 설정
		pHead->setfront(NULL);//다음노드 설정
		id_size++;//리스트 크기증가
	}
	StudentID* pCur = pHead;
	NameNode* pWalk = name_head;
	while(pWalk != NULL)
	{//name노드 리스트의 끝까지 반복
		if (pWalk->getNext() == NULL)
			break;//name노드 리스트 끝에 도달하면 반복문 탈출
		pWalk = (NameNode*)pWalk->getNext();//name노드의 다음 노드로 계속 이동
		pCur->setfront(pWalk->getPfornt());//다음 노드 설정
		pCur->getfront()->setfront(NULL);
		pCur = pCur->getfront();//전화번호리스트 다음노드로 이동
		id_size++;//리스트 크기증가
	}
}
inline void StudentIDList::clear()
{//초기화함수
	pHead = NULL;//헤드노드를 초기화해줌
	id_size = 0;//리스트 사이즈도 초기화
}
