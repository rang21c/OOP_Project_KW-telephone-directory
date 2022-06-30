#pragma once
#include <iostream>

class StudentID
{
private:
	char studentid[32];//학번 배열 선언
	StudentID* Pfront;//다음노드 변수
public:
	StudentID() {
		for (int i = 0; i < 32; i++)
			studentid[i] = NULL;//변수 초기화
		Pfront = NULL;//변수 초기화
	}
	~StudentID() {

	}
	StudentID(char* str) {
		strcpy(studentid, str);//학번 저장
	}
	char* getid() { return studentid; }//학번 받아오는 함수
	void setid(char* str) { strcpy(studentid, str); }//학번 설정하는 함수
	StudentID* getfront() { return Pfront; }//다음노드 가져오는 함수
	void setfront(StudentID* tempnode) { Pfront = tempnode; }//다음노드 설정하는 함수
};