#pragma once
#include <iostream>
using namespace std;

class Node
{//���Ŭ����
private:
	Node* Pnext;//�������
	Node* Pprev;//�������
	Node* Pup;//���ʳ��
	Node* Pdown;//�Ʒ����
public:
	Node() {//�����ʱ�ȭ
		Pnext = NULL;
		Pprev = NULL;
		Pup = NULL;
		Pdown = NULL;
	}
	~Node() {

	}
	virtual Node* getNext() { return Pnext; }//������� �޾ƿ��� �Լ�
	virtual Node* getPre() { return Pprev; }//������� �޾ƿ��� �Լ�
	virtual Node* getPup() { return Pup; }//���ʳ�� �޾ƿ��� �Լ�
	virtual Node* getPdown() { return Pdown; }//�Ʒ���� �޾ƿ��� �Լ�
	virtual void setNext(Node* pNew1) { Pnext = pNew1; }//������� �����ϴ� �Լ�
	virtual void setPrev(Node* pPre1) { Pprev = pPre1; }//������� �����ϴ� �Լ�
	virtual void setPup(Node* pUp1) { Pup = pUp1; }//���ʳ�� �����ϴ� �Լ�
	virtual void setPdown(Node* pDown1) { Pdown = pDown1; }//�Ʒ���� �����ϴ� �Լ�
};