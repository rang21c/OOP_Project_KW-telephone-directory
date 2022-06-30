#pragma once
#include "DepartmentList Class.h"
#include "NameList class.h"
#include "Grade.h"
#include <iostream>
using namespace std;

class GradeList
{//�г� ����Ʈ Ŭ����
private:
	Grade* pHead;//��� ���
	int grade_size;//�г� ����Ʈ ������
public:
	GradeList() {
		pHead = NULL;//���� �ʱ�ȭ
		grade_size = 0;//���� �ʱ�ȭ
	}
	~GradeList() {
		Grade* temp = pHead;
		Grade* deletenode = pHead;
		while (deletenode != NULL)
		{
			if (deletenode->getleft() == NULL)
				break;
			deletenode = deletenode->getleft();
			delete temp;//�г⸮��Ʈ �޸�����
			temp = deletenode;
		}
	}
	void gradelist(NameNode* name_head, int namesize);//�г⸮��Ʈ �Լ�
	void clear();//����Ʈ �ʱ�ȭ �Լ�
};
inline void GradeList::gradelist(NameNode* name_head, int namesize)
{
	if (pHead == NULL)
	{//�ƹ� ��嵵 ���ٸ�
		pHead = name_head->getPleft();//����带 ����
		pHead->setleft(NULL);//������� ����
		grade_size++;//����Ʈ ũ������
	}
	Grade* pCur = pHead;
	NameNode* pWalk = name_head;
	while(pWalk != NULL)
	{//name��� ����Ʈ�� ������ �ݺ�
		if (pWalk->getNext() == NULL)
			break;//name��� ����Ʈ ���� �����ϸ� �ݺ��� Ż��
		pWalk = (NameNode*)pWalk->getNext();//name����� ���� ���� ��� �̵�
		pCur->setleft(pWalk->getPleft());//���� ��� ����
		pCur->getleft()->setleft(NULL);
		pCur = pCur->getleft();//�г⸮��Ʈ �������� �̵�
		grade_size++;//����Ʈ ũ������
	}
}
inline void GradeList::clear()
{//�ʱ�ȭ�Լ�
	pHead = NULL;//����带 �ʱ�ȭ����
	grade_size = 0;//����Ʈ ����� �ʱ�ȭ
}
