#pragma once

class Grade 
{//학년 노드 클래스
private:
	int grade;//학년 변수 선언
	Grade* Pleft;//다음 노드 변수
public:
	Grade() {
		grade = 0;//변수 초기화
		Pleft = NULL;//변수 초기화
	}
	~Grade() {

	}
	Grade(int num) {
		grade = num;//학년 저장
	}
	int getgrade() { return grade; }//학년 가져오는 함수
	void setgrade(int num) { grade = num; }//학년 설정하는 함수
	Grade* getleft() { return Pleft; }//다음 노드를 가져오는 함수
	void setleft(Grade* tempnode) { Pleft = tempnode; }//다음 노드를 설정하는 함수
};