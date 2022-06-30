#pragma once
#include "Name.h"
#include "DepartmentList Class.h"
#include <iostream>
using namespace std;

class NameList
{//�̸� ����Ʈ Ŭ����
private:
	Node* pHead;//�����
	int name_size;//����Ʈ ������
public:
	NameList() {//���� �ʱ�ȭ
		pHead = NULL;
		name_size = 0;
	}
	~NameList() {
		Node* temp = pHead;
		Node* deletenode = pHead;
		while (deletenode != NULL)
		{
			if (deletenode->getNext() == NULL)
				break;
			deletenode = deletenode->getNext();
			delete temp;//�̸�����Ʈ �޸�����
			temp = deletenode;
		}
	}
	virtual void insert(DepartmentNode* de_head, int desize);//����Ʈ ���� �Լ�
	NameNode* getname_head() { return (NameNode*)pHead; }//����� �޾ƿ��� �Լ�
	int getname_size() { return name_size; }//����Ʈ ������ �޾ƿ��� �Լ�
	void setname_size(int num) { name_size = num; }//����Ʈ ������ �����ϴ� �Լ�
	void clear();//�ʱ�ȭ �Լ�
};
inline void NameList::insert(DepartmentNode* de_head, int desize)
{
	if (pHead == NULL)
	{//����尡 ������
		pHead = de_head->getPdown();//����� ����
		pHead->setNext(NULL);//������� ����
		name_size++;//����Ʈ ������ ����
	}

	DepartmentNode* pWalknext = de_head;
	for (int i = 0; i < desize; i++)
	{//�а�����Ʈ �����ŭ �ݺ�
		NameNode* pWalkdown = (NameNode*)pWalknext->getPdown();//�а�����Ʈ���� �Ʒ����� �������� ����
		if (name_size == 1)
			pWalkdown = (NameNode*)pWalknext->getPdown()->getPdown();
		while (pWalkdown != NULL)
		{//�ش� �а��� �̸� ������ �ݺ�
			NameNode* pWalk = (NameNode*)pHead;
			while(pWalk != NULL)
			{//�̸�����Ʈ ������ �ݺ�
				if (strcmp(pWalk->getname(), pWalkdown->getname()) < 0)
				{//���ε��°��� �� Ŭ��
					if (pWalk->getNext() == NULL)
					{//�� ���� �����Ҷ�
						pWalk->setNext(pWalkdown);//�̸�����Ʈ �� ���� ��� ����
						pWalkdown->setPrev(pWalk);
						pWalkdown->setNext(NULL);
						name_size++;//����Ʈ ������ ����
						break;//�ݺ��� Ż��
					}
					if (pWalk->getNext() == NULL)
						break;//�̸�����Ʈ ������ �����ߴٸ� �ݺ��� Ż��
					pWalk = (NameNode*)pWalk->getNext();//�̸�����Ʈ �������� �̵�
				}
				else if (strcmp(pWalk->getname(), pWalkdown->getname()) > 0)
				{//���� ���� ���� �� ������ -  �߰��� �����ؾ��ϴ� ���
					if (pWalk == pHead)
					{//����� �ٷξտ� �����Ҷ�
						pWalkdown->setNext(pHead);
						pHead->setPrev(pWalkdown);
						pHead = pWalkdown;//���ο� �̸��� ������ ����
						name_size++;//����Ʈ ������ ����
						break;//�ݺ��� Ż��
					}
					else
					{//�� �̿��� �Ϲ����� ���
						pWalk->getPre()->setNext(pWalkdown);
						pWalkdown->setPrev(pWalk->getPre());
						pWalkdown->setNext(pWalk);
						pWalk->setPrev(pWalkdown);
						name_size++;//����Ʈ ������ ����
						break;//�ݺ��� Ż��
					}
				}
				else if (strcmp(pWalk->getname(), pWalkdown->getname()) == 0)
				{//�ߺ��� �̸��� �������
					if (pWalk == pHead)
					{//����� �ٷξտ� �����Ҷ�
						pWalkdown->setNext(pHead);
						pHead->setPrev(pWalkdown);
						pHead = pWalkdown;//���ο� �̸��� ������ ����
						name_size++;//����Ʈ ������ ����
						break;//�ݺ��� Ż��
					}
					else
					{//�� �̿��� �Ϲ����� ���
						pWalk->getPre()->setNext(pWalkdown);
						pWalkdown->setPrev(pWalk->getPre());
						pWalkdown->setNext(pWalk);
						pWalk->setPrev(pWalkdown);
						name_size++;//����Ʈ ������ ����
						break;//�ݺ��� Ż��
					}
				}
			}
			pWalkdown = (NameNode*)pWalkdown->getPdown();//�Ʒ����� �̵�
		}
		pWalknext = (DepartmentNode*)pWalknext->getNext();//���� �а��� �̵�
	}
}
inline void NameList::clear()
{//����Ʈ �ʱ�ȭ
	pHead = NULL;//����� �ʱ�ȭ
	name_size = 0;//������ �ʱ�ȭ
}