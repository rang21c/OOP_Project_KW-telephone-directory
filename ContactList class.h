#pragma once
#include "DepartmentList Class.h"
#include "NameList class.h"
#include "Contact.h"
#include <iostream>
using namespace std;

class ContactList
{//��ȭ��ȣ ����Ʈ Ŭ����
private:
	Contact* pHead;//�����
	int contact_size;//��ȭ��ȣ����Ʈ ũ��
public:
	ContactList() {
		pHead = NULL;//���� �ʱ�ȭ
		contact_size = 0;//���� �ʱ�ȭ
	}
	~ContactList() {
		Contact* temp = pHead;
		Contact* deletenode = pHead;
		while (deletenode != NULL)
		{
			if (deletenode->getright() == NULL)
				break;
			deletenode = deletenode->getright();
			delete temp;//����ó����Ʈ �޸�����
			temp = deletenode;
		}
	}
	void contactlist(NameNode* name_head, int namesize);//��ȭ��ȣ ����Ʈ ����� �Լ�
	void clear();//��ȭ��ȣ ����Ʈ �ʱ�ȭ�Լ�
};
inline void ContactList::contactlist(NameNode* name_head, int namesize)
{
	if (pHead == NULL)
	{//�ƹ� ��嵵 ���ٸ�
		pHead = name_head->getPright();//����带 ����
		pHead->setright(NULL);//������� ����
		contact_size++;//����Ʈ ũ������
	}
	Contact* pCur = pHead;
	NameNode* pWalk = name_head;
	while(pWalk != NULL)
	{//name��� ����Ʈ�� ������ �ݺ�
		if (pWalk->getNext() == NULL)
			break;//name��� ����Ʈ ���� �����ϸ� �ݺ��� Ż��
		pWalk = (NameNode*)pWalk->getNext();//name����� ���� ���� ��� �̵�
		pCur->setright(pWalk->getPright());//���� ��� ����
		pCur->getright()->setright(NULL);
		pCur = pCur->getright();//��ȭ��ȣ����Ʈ �������� �̵�
		contact_size++;//����Ʈ ũ������
	}
}
inline void ContactList::clear()
{//�ʱ�ȭ�Լ�
	pHead = NULL;//����带 �ʱ�ȭ����
	contact_size = 0;//����Ʈ ����� �ʱ�ȭ
}
