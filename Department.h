#pragma once
#include "Node.h"
class DepartmentNode : public Node
{//�а� ��� Ŭ����
private:
	char de_name[32];//�а��̸� �迭����
public:
	DepartmentNode() {
		for (int i = 0; i < 32; i++)
			de_name[i] = NULL;//���� �ʱ�ȭ
	}
	~DepartmentNode() {

	}
	DepartmentNode(char* str) {
		strcpy(de_name, str);//�а��̸� ����
	}
	char* get_de() { return de_name; }//�а��̸� ��������
	void set_de(char* name) { strcpy(de_name, name); }//�а��̸� ����
};