#pragma once
#include <iostream>
using namespace std;

class Node
{//노드클래스
private:
	Node* Pnext;//다음노드
	Node* Pprev;//이전노드
	Node* Pup;//위쪽노드
	Node* Pdown;//아래노드
public:
	Node() {//변수초기화
		Pnext = NULL;
		Pprev = NULL;
		Pup = NULL;
		Pdown = NULL;
	}
	~Node() {

	}
	virtual Node* getNext() { return Pnext; }//다음노드 받아오는 함수
	virtual Node* getPre() { return Pprev; }//이전노드 받아오는 함수
	virtual Node* getPup() { return Pup; }//위쪽노드 받아오는 함수
	virtual Node* getPdown() { return Pdown; }//아래노드 받아오는 함수
	virtual void setNext(Node* pNew1) { Pnext = pNew1; }//다음노드 설정하는 함수
	virtual void setPrev(Node* pPre1) { Pprev = pPre1; }//이전노드 설정하는 함수
	virtual void setPup(Node* pUp1) { Pup = pUp1; }//위쪽노드 설정하는 함수
	virtual void setPdown(Node* pDown1) { Pdown = pDown1; }//아래노드 설정하는 함수
};