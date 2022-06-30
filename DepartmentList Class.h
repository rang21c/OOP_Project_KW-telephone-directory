#pragma once
#include "Department.h"
#include "NameList class.h"
#include "Name.h"
#include "Contact.h"
#include "Grade.h"
#include "StudentID.h"
#include <iostream>
using namespace std;

class DepartmentList
{//�а� ����Ʈ Ŭ����
private:
	Node* pHead;//����� ���� ����
	int de_size;//�а�����Ʈ ũ�� ����
public:
	DepartmentList() {
		pHead = NULL;//���� �ʱ�ȭ
		de_size = 0;//���� �ʱ�ȭ
	}
	~DepartmentList()
	{//�Ҹ���
		DepartmentNode* pCur = (DepartmentNode*)pHead;
		DepartmentNode* pNext = NULL;
		NameNode* temp = NULL;
		pCur->getPre()->setNext(NULL);//��������Ʈ ������ ������
		while (pCur != NULL)
		{
			pNext = (DepartmentNode*)pCur->getNext();
			NameNode* pWalkdown = (NameNode*)pCur->getPdown();
			while (temp)
			{
				NameNode* temp = (NameNode*)pWalkdown->getPdown();
				delete(pWalkdown->getPfornt());
				delete(pWalkdown->getPleft());
				delete(pWalkdown->getPright());
				delete(pWalkdown);//�л����� �޸�����
				pWalkdown = temp;
			}
			delete(pCur);//�а���� �޸�����
			pCur = pNext;
		}
	}
	virtual void insert(char* department, char* name, int grade, char* stuID, char* contact);//��ü ����Ʈ(�а�����) �����Լ�
	DepartmentNode* getde_head() { return (DepartmentNode*)pHead; }//����带 �������� �Լ�
	int getde_size() { return de_size; }//�а�����Ʈ ������ �������� �Լ�
	void setde_size(int num) { de_size = num; }//�а�����Ʈ ������ ���� �Լ�
	void clear();//�а� ����Ʈ �ʱ�ȭ �Լ�
};
inline void DepartmentList::insert(char* department, char* name, int grade, char* stuID, char* contact)
{//�а� ��������
	//���ε��� �а������� �����Ҵ�
	DepartmentNode* pNewdepartment = new DepartmentNode(department);
	NameNode* pNewname = new NameNode(name);
	Grade* pNewgrade = new Grade(grade);
	StudentID* pNewid = new StudentID(stuID);
	Contact* pNewcontact = new Contact(contact);
	pNewname->setPleft(pNewgrade);
	pNewname->setPfornt(pNewid);
	pNewname->setPright(pNewcontact);
	bool check = 0;

	if (pHead == NULL)
	{//����尡 ������
		pHead = pNewdepartment;//���ο��带 ������ ����
		pHead->setNext(pHead);//������带 ������ �����Ͽ� ��������Ʈ ����
		pNewdepartment->setPdown(pNewname);//�̸��� ����
		pNewname->setPup(pHead);
		pNewname->setPdown(NULL);
		de_size++;//�а� ����Ʈ ������ ����
	}
	else
	{
		DepartmentNode* pWalk = (DepartmentNode*)pHead;
		DepartmentNode* plast = (DepartmentNode*)pHead;
		for (int i = 0; i < de_size; i++)
		{
			if (check == 1)
				break;
			if (strcmp(pWalk->get_de(), pNewdepartment->get_de()) < 0)
			{//���ε��� ���� �� Ŭ��
				plast = (DepartmentNode*)pHead;
				for (int j = 0; j < de_size - 1; j++)
					plast = (DepartmentNode*)plast->getNext();//����Ʈ ������ �ݺ�
				if (pWalk == plast)
				{//����Ʈ �ǳ��� �а� ����
					pWalk->setNext(pNewdepartment);
					pNewdepartment->setPrev(pWalk);
					pNewdepartment->setNext(pHead);
					pHead->setPrev(pNewdepartment);
					check = 1;
					de_size++;//�а� ����Ʈ ������ ����

					pNewdepartment->setPdown(pNewname);//���ο� �̸� �߰�
					pNewname->setPup(pNewdepartment);
					pNewname->setPdown(NULL);
					break;//�ݺ��� Ż��
				}
				pWalk = (DepartmentNode*)pWalk->getNext();//�������� �̵�
			}
			else if (strcmp(pWalk->get_de(), pNewdepartment->get_de()) > 0)
			{//���ε��� ���� �� ������ - �߰��� �����ؾ��Ҷ�
				if (pWalk == pHead)
				{//����庸�� �������� ��������
					plast = (DepartmentNode*)pHead;
					for (int j = 0; j < de_size-1; j++)
						plast = (DepartmentNode*)plast->getNext();//����Ʈ ������ �ݺ�
					pNewdepartment->setNext(pHead);
					pHead->setPrev(pNewdepartment);
					plast->setNext(pNewdepartment);
					pNewdepartment->setPrev(plast);
					pHead = pNewdepartment;//���ε��³�带 ������ ����
					check = 1;
					de_size++;//����Ʈ ������ ����

					pNewdepartment->setPdown(pNewname);//���ο� �̸� �߰�
					pNewname->setPup(pNewdepartment);
					pNewname->setPdown(NULL);
					break;
				}
				else
				{//������ ���
					pWalk->getPre()->setNext(pNewdepartment);
					pNewdepartment->setPrev(pWalk->getPre());
					pNewdepartment->setNext(pWalk);
					pWalk->setPrev(pNewdepartment);
					check = 1;
					de_size++;//����Ʈ ������ ����

					pNewdepartment->setPdown(pNewname);//���ο� �̸� �߰�
					pNewname->setPup(pNewdepartment);
					pNewname->setPdown(NULL);
					break;
				}
			}
			else if (strcmp(pWalk->get_de(), pNewdepartment->get_de()) == 0)
			{//���� �а� ��忡 ����־�� �Ҷ�
				NameNode* ptempWalk = (NameNode*)pWalk->getPdown();
				do
				{
					if (strcmp(ptempWalk->getname(), pNewname->getname()) < 0)
					{//���ε��� �̸��� �� ū ��� ��, �������� �����ϴ� ���
						if (ptempWalk->getPdown() == NULL)
						{//�̸� �ǳ��� �߰��ؾ��ϴ� ���
							ptempWalk->setPdown(pNewname);//�ǳ���带 ���ο��̸����� ����
							pNewname->setPup(ptempWalk);
							pNewname->setPdown(NULL);
							check = 1;
							break;
						}
						ptempWalk = (NameNode*)ptempWalk->getPdown();//���� ���� ��� �̵�
						continue;
					}
					else if (strcmp(ptempWalk->getname(), pNewname->getname()) > 0)
					{//�̸�����Ʈ �߰��� �����ؾ��ϴ°��
						if (ptempWalk == pWalk->getPdown())
						{//�� ���� �����ؾ��� ���
							pWalk->setPdown(pNewname);//�� ���� ���ο� �̸���� ����
							pNewname->setPup(pWalk);
							pNewname->setPdown(ptempWalk);
							ptempWalk->setPup(pNewname);
							check = 1;
						}
						else
						{//���״�� �߰��� ������ ���
							ptempWalk->getPup()->setPdown(pNewname);
							pNewname->setPup(ptempWalk->getPup());
							pNewname->setPdown(ptempWalk);
							ptempWalk->setPup(pNewname);
							check = 1;
						}
						break;
					}
					else if (strcmp(ptempWalk->getname(), pNewname->getname()) == 0)
					{//�ߺ��� �̸��� �������
						if (ptempWalk == pWalk->getPdown())
						{//�� ���� �����ؾ��� ���
							pWalk->setPdown(pNewname);//�� ���� ���ο� �̸���� ����
							pNewname->setPup(pWalk);
							pNewname->setPdown(ptempWalk);
							ptempWalk->setPup(pNewname);
							check = 1;
						}
						else
						{//���״�� �߰��� ������ ���
							ptempWalk->getPup()->setPdown(pNewname);
							pNewname->setPup(ptempWalk->getPup());
							pNewname->setPdown(ptempWalk);
							ptempWalk->setPup(pNewname);
							check = 1;
						}
						break;
					}
					break;//�ݺ��� Ż��
				} while (ptempWalk != NULL);
			}
		}
	}
	DepartmentNode* plast = (DepartmentNode*)pHead;
	for (int j = 0; j < de_size - 1; j++)
		plast = (DepartmentNode*)plast->getNext();
	plast->setNext(pHead);//��������Ʈ ����
	pHead->setPrev(plast);//��������Ʈ ����
}
inline void DepartmentList::clear()
{//�ʱ�ȭ �Լ�
	pHead = NULL;//����� �ʱ�ȭ
	de_size = 0;//�а�����Ʈ ������ �ʱ�ȭ
}
