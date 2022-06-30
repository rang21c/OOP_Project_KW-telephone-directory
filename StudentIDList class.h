#pragma once
#include "DepartmentList Class.h"
#include "NameList class.h"
#include "StudentID.h"
#include <iostream>
using namespace std;

class StudentIDList
{//�й� ����Ʈ Ŭ����
private:
	StudentID* pHead;//�����
	int id_size;//�й�����Ʈ ũ��
public:
	StudentIDList() {
		pHead = NULL;//���� �ʱ�ȭ
		id_size = 0;//���� �ʱ�ȭ
	}
	~StudentIDList() {
		StudentID* temp = pHead;
		StudentID* deletenode = pHead;
		while (deletenode != NULL)
		{
			if (deletenode->getfront() == NULL)
				break;
			deletenode = deletenode->getfront();
			delete temp;//�й� ����Ʈ �޸�����
			temp = deletenode;
		}
	}
	void idlist(NameNode* name_head, int namesize);//�й�����Ʈ ���
	StudentID* gethead() { return pHead; }//����带 �������� �Լ�
	void clear();//�й� ����Ʈ �ʱ�ȭ�Լ�
};
inline void StudentIDList::idlist(NameNode* name_head, int namesize)
{
	if (pHead == NULL)
	{//�ƹ� ��嵵 ���ٸ�
		pHead = name_head->getPfornt();//����带 ����
		pHead->setfront(NULL);//������� ����
		id_size++;//����Ʈ ũ������
	}
	StudentID* pCur = pHead;
	NameNode* pWalk = name_head;
	while(pWalk != NULL)
	{//name��� ����Ʈ�� ������ �ݺ�
		if (pWalk->getNext() == NULL)
			break;//name��� ����Ʈ ���� �����ϸ� �ݺ��� Ż��
		pWalk = (NameNode*)pWalk->getNext();//name����� ���� ���� ��� �̵�
		pCur->setfront(pWalk->getPfornt());//���� ��� ����
		pCur->getfront()->setfront(NULL);
		pCur = pCur->getfront();//��ȭ��ȣ����Ʈ �������� �̵�
		id_size++;//����Ʈ ũ������
	}
}
inline void StudentIDList::clear()
{//�ʱ�ȭ�Լ�
	pHead = NULL;//����带 �ʱ�ȭ����
	id_size = 0;//����Ʈ ����� �ʱ�ȭ
}
