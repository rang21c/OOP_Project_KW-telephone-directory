#pragma once
#include "Node.h"
#include "Grade.h"
#include "Contact.h"
#include "StudentID.h"

class NameNode : public Node
{//이름노드 클래스
private:
	Grade* Pleft;//왼쪽노드
	StudentID* Pfornt;//앞쪽노드
	Contact* Pright;//오른쪽노드
	char name[32];//이름 배열 선언
public:
	NameNode() {//변수 초기화
		Pleft = NULL;
		Pfornt = NULL;
		Pright = NULL;
		for (int i = 0; i < 32; i++)
			name[i] = NULL;
	}
	~NameNode() {

	}
	NameNode(char* str) {
		strcpy(name, str);//이름 저장
	}
	char* getname() { return name; }//이름 받아오는 함수
	void setname(char* str) { strcpy(name, str); }//이름 설정하는 함수
	virtual Grade* getPleft() { return Pleft; }//왼쪽노드 받아오는 함수
	virtual StudentID* getPfornt() { return Pfornt; }//앞쪽노드 받아오는 함수
	virtual Contact* getPright() { return Pright; }//오른쪽노드 받아오는 함수
	virtual void setPleft(Grade* grade) { Pleft = grade; }//왼쪽노드 설정하는 함수
	virtual void setPfornt(StudentID* id) { Pfornt = id; }//앞쪽노드 설정하는 함수
	virtual void setPright(Contact* contact) { Pright = contact; }//오른쪽노드 설정하는 함수
};