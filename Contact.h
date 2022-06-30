#pragma once

class Contact
{//전화번호 노드 클래스
private:
	char contact[32];//전화번호 배열
	Contact* Pright;//다음노드 변수
public:
	Contact() {
		for (int i = 0; i < 32; i++)
			contact[i] = NULL;//변수 초기화
		Pright = NULL;//변수 초기화
	}
	~Contact() {

	}
	Contact(char* str) {
		strcpy(contact, str);//전화번호 저장
	}
	char* getcontact() { return contact; }//전화번호를 받아오는함수
	void setcontact(char* str) { strcpy(contact, str); }//전화번호를 설정하는 함수
	Contact* getright() { return Pright; }//다음노드로 이동하는 함수
	void setright(Contact* tempnode) { Pright = tempnode; }//다음노드를 설정하는 함수
};