#pragma once

class Grade 
{//�г� ��� Ŭ����
private:
	int grade;//�г� ���� ����
	Grade* Pleft;//���� ��� ����
public:
	Grade() {
		grade = 0;//���� �ʱ�ȭ
		Pleft = NULL;//���� �ʱ�ȭ
	}
	~Grade() {

	}
	Grade(int num) {
		grade = num;//�г� ����
	}
	int getgrade() { return grade; }//�г� �������� �Լ�
	void setgrade(int num) { grade = num; }//�г� �����ϴ� �Լ�
	Grade* getleft() { return Pleft; }//���� ��带 �������� �Լ�
	void setleft(Grade* tempnode) { Pleft = tempnode; }//���� ��带 �����ϴ� �Լ�
};