#pragma once
#include "Node.h"
class DepartmentNode : public Node
{//학과 노드 클래스
private:
	char de_name[32];//학과이름 배열선언
public:
	DepartmentNode() {
		for (int i = 0; i < 32; i++)
			de_name[i] = NULL;//변수 초기화
	}
	~DepartmentNode() {

	}
	DepartmentNode(char* str) {
		strcpy(de_name, str);//학과이름 저장
	}
	char* get_de() { return de_name; }//학과이름 가져오기
	void set_de(char* name) { strcpy(de_name, name); }//학과이름 설정
};