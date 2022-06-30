#pragma once
#include "Node.h"
#include "Grade.h"
#include "Contact.h"
#include "StudentID.h"

class NameNode : public Node
{//�̸���� Ŭ����
private:
	Grade* Pleft;//���ʳ��
	StudentID* Pfornt;//���ʳ��
	Contact* Pright;//�����ʳ��
	char name[32];//�̸� �迭 ����
public:
	NameNode() {//���� �ʱ�ȭ
		Pleft = NULL;
		Pfornt = NULL;
		Pright = NULL;
		for (int i = 0; i < 32; i++)
			name[i] = NULL;
	}
	~NameNode() {

	}
	NameNode(char* str) {
		strcpy(name, str);//�̸� ����
	}
	char* getname() { return name; }//�̸� �޾ƿ��� �Լ�
	void setname(char* str) { strcpy(name, str); }//�̸� �����ϴ� �Լ�
	virtual Grade* getPleft() { return Pleft; }//���ʳ�� �޾ƿ��� �Լ�
	virtual StudentID* getPfornt() { return Pfornt; }//���ʳ�� �޾ƿ��� �Լ�
	virtual Contact* getPright() { return Pright; }//�����ʳ�� �޾ƿ��� �Լ�
	virtual void setPleft(Grade* grade) { Pleft = grade; }//���ʳ�� �����ϴ� �Լ�
	virtual void setPfornt(StudentID* id) { Pfornt = id; }//���ʳ�� �����ϴ� �Լ�
	virtual void setPright(Contact* contact) { Pright = contact; }//�����ʳ�� �����ϴ� �Լ�
};