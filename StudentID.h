#pragma once
#include <iostream>

class StudentID
{
private:
	char studentid[32];//�й� �迭 ����
	StudentID* Pfront;//������� ����
public:
	StudentID() {
		for (int i = 0; i < 32; i++)
			studentid[i] = NULL;//���� �ʱ�ȭ
		Pfront = NULL;//���� �ʱ�ȭ
	}
	~StudentID() {

	}
	StudentID(char* str) {
		strcpy(studentid, str);//�й� ����
	}
	char* getid() { return studentid; }//�й� �޾ƿ��� �Լ�
	void setid(char* str) { strcpy(studentid, str); }//�й� �����ϴ� �Լ�
	StudentID* getfront() { return Pfront; }//������� �������� �Լ�
	void setfront(StudentID* tempnode) { Pfront = tempnode; }//������� �����ϴ� �Լ�
};