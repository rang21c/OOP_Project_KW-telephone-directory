#pragma once
#include "DepartmentList Class.h"
#include "NameList class.h"
#include "Grade.h"
#include <iostream>
using namespace std;

class GradeList
{//학년 리스트 클래스
private:
	Grade* pHead;//헤드 노드
	int grade_size;//학년 리스트 사이즈
public:
	GradeList() {
		pHead = NULL;//변수 초기화
		grade_size = 0;//변수 초기화
	}
	~GradeList() {
		Grade* temp = pHead;
		Grade* deletenode = pHead;
		while (deletenode != NULL)
		{
			if (deletenode->getleft() == NULL)
				break;
			deletenode = deletenode->getleft();
			delete temp;//학년리스트 메모리해제
			temp = deletenode;
		}
	}
	void gradelist(NameNode* name_head, int namesize);//학년리스트 함수
	void clear();//리스트 초기화 함수
};
inline void GradeList::gradelist(NameNode* name_head, int namesize)
{
	if (pHead == NULL)
	{//아무 노드도 없다면
		pHead = name_head->getPleft();//헤드노드를 설정
		pHead->setleft(NULL);//다음노드 설정
		grade_size++;//리스트 크기증가
	}
	Grade* pCur = pHead;
	NameNode* pWalk = name_head;
	while(pWalk != NULL)
	{//name노드 리스트의 끝까지 반복
		if (pWalk->getNext() == NULL)
			break;//name노드 리스트 끝에 도달하면 반복문 탈출
		pWalk = (NameNode*)pWalk->getNext();//name노드의 다음 노드로 계속 이동
		pCur->setleft(pWalk->getPleft());//다음 노드 설정
		pCur->getleft()->setleft(NULL);
		pCur = pCur->getleft();//학년리스트 다음노드로 이동
		grade_size++;//리스트 크기증가
	}
}
inline void GradeList::clear()
{//초기화함수
	pHead = NULL;//헤드노드를 초기화해줌
	grade_size = 0;//리스트 사이즈도 초기화
}
