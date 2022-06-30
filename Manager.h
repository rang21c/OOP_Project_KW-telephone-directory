#pragma once
#include <iostream>
#include "DepartmentList Class.h"
#include "NameList class.h"
#include "GradeList class.h"
#include "StudentIDList class.h"
#include "ContactList class.h"
#include <fstream>
#include <string>
using namespace std;

class Manager
{//�Ŵ��� Ŭ����
public:
	Manager() {}
	~Manager() {}
	void LOAD(char* str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c);
	void ADD(char* str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c);
	void UPDATE(char* str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c);
	void MODIFY_DEPARTMENT(char* str, char* str1, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c);
	void DELETE_DEPARTMENT(char* str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c);
	void PRINT(char* str, DepartmentList &d);
	void PRINT_STUDENT_ID(DepartmentList &d, NameList &n, StudentIDList &s);
	void PRINT_CONTACT(DepartmentList &d);
	void FIND_NAME(char* str, DepartmentList & d, NameList &n);
	void SAVE(char* str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c);
};
inline void Manager::LOAD(char* str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c)
{
	ifstream in("information.txt");//������ ��� �ؽ�Ʈ���� ����
	ofstream log("LOG.txt", ios::app);//LOG������ ������������ Ŀ���ǳ����� �̵��ѵ� ����
	if (in.is_open() == false)//������ ������ �ʾ�����
	{//�����ڵ� 100 ����� ����
		log << "[LOAD]"<<endl<<"Error code : 100" << endl << endl << endl;
		cout << "[LOAD]" << endl << "Error code : 100" << endl << endl << endl;
		exit(100);
	}
	char command[300];
	while (!in.eof())
	{//������ ������ �ݺ�
		in.getline(command, 300);//���� �о����
		char* token;//�а�
		char* token1;//�̸�
		char* token2;//�г�
		char* token3;//�й�
		char* token4;//��ȭ��ȣ
		token = strtok(command, "\t");
		token1 = strtok(NULL, "\t");
		token2 = strtok(NULL, "\t");
		token3 = strtok(NULL, "\t");
		token4 = strtok(NULL, "\t");
		if (token == NULL)
			break;
		d.insert(token, token1, atoi(token2), token3, token4);//�а�����Ʈ ����
	}
	n.insert(d.getde_head(), d.getde_size());//�̸�����Ʈ ����
	g.gradelist(n.getname_head(), n.getname_size());//�г⸮��Ʈ ����
	s.idlist(n.getname_head(), n.getname_size());//�й�����Ʈ ����
	c.contactlist(n.getname_head(), n.getname_size());//��ȭ��ȣ ����Ʈ ����
	log << "[LOAD]" << endl << "Success" << endl << endl << endl;
	cout << "[LOAD]" << endl << "Success" << endl << endl << endl;
}
inline void Manager::ADD(char* str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c)
{
	ifstream in("Add_information.txt");//������ ��� �ؽ�Ʈ���� ����
	ofstream log("LOG.txt", ios::app);//LOG������ ������������ Ŀ���ǳ����� �̵��ѵ� ����
	if (in.is_open() == false)//������ ������ �ʾ�����
	{//�����ڵ� 200 ���
		log << "[ADD]" << endl << "Error code : 200" << endl << endl << endl;
		cout << "[ADD]" << endl << "Error code : 200" << endl << endl << endl;
	}
	char command[300];
	while (!in.eof())
	{//������ ������ �ݺ�
		in.getline(command, 300);//���� �о����
		char* token;//�а�
		char* token1;//�̸�
		char* token2;//�г�
		char* token3;//�й�
		char* token4;//��ȭ��ȣ
		token = strtok(command, "\t");
		token1 = strtok(NULL, "\t");
		token2 = strtok(NULL, "\t");
		token3 = strtok(NULL, "\t");
		token4 = strtok(NULL, "\t");
		bool flag = 0;
		DepartmentNode* pWalk1 = d.getde_head();
		for (int i = 0; i < d.getde_size(); i++)
		{//�а�����Ʈ �������ݺ�
			NameNode* ptempWalk = (NameNode*)pWalk1->getPdown();
			while (ptempWalk != NULL)
			{//�ش��а� �̸� ������ �ݺ�
				if (strcmp(token3, ptempWalk->getPfornt()->getid()) == 0 || strcmp(token4, ptempWalk->getPright()->getcontact()) == 0)
				{//�й� �Ǵ� ��ȣ�� ������ ���� �ߺ��� ��� �����ڵ�200-1���
					log << "[ADD]" << endl << "Error code : 200-1" << endl << endl << endl;
					cout << "[ADD]" << endl << "Error code : 200-1" << endl << endl << endl;
					flag = 1;//�÷��׺��� 1�� ����
					break;
				}
				ptempWalk = (NameNode*)ptempWalk->getPdown();
			}
			if (flag)break;
			pWalk1 = (DepartmentNode*)pWalk1->getNext();
		}
		if (flag)continue;//�÷��װ� 1�̸� ����Ʈ�� �߰������ʰ� �ٽ� �ݺ�
		d.insert(token, token1, atoi(token2), token3, token4);//�а�����Ʈ
	}
	n.clear();//����Ʈ �ʱ�ȭ
	c.clear();//����Ʈ �ʱ�ȭ
	g.clear();//����Ʈ �ʱ�ȭ
	s.clear();//����Ʈ �ʱ�ȭ
	n.insert(d.getde_head(), d.getde_size());//�̸�����Ʈ
	g.gradelist(n.getname_head(), n.getname_size());//�г⸮��Ʈ
	s.idlist(n.getname_head(), n.getname_size());//�й�����Ʈ
	c.contactlist(n.getname_head(), n.getname_size());//��ȭ��ȣ����Ʈ
	log << "[ADD]" << endl << "Success" << endl << endl << endl;
	cout << "[ADD]" << endl << "Success" << endl << endl << endl;
}
inline void Manager::UPDATE(char * str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c)
{
	ifstream in("Update_information.txt");
	ofstream log("LOG.txt", ios::app);
	if (in.is_open() == false)
	{
		log << "[UPDATE]" << endl << "Error code : 300" << endl << endl << endl;
		cout << "[UPDATE]" << endl << "Error code : 300" << endl << endl << endl;
	}
	char command[300];
	while (!in.eof())
	{//������ ������ �ݺ�
		in.getline(command, 300);//���� �о����
		char* token;//�а�
		char* token1;//�̸�
		char* token2;//�г�
		char* token3;//�й�
		char* token4;//��ȭ��ȣ
		token = strtok(command, "\t");
		token1 = strtok(NULL, "\t");
		token2 = strtok(NULL, "\t");
		token3 = strtok(NULL, "\t");
		token4 = strtok(NULL, "\t");
		bool flag = 0;
		DepartmentNode* pWalk1 = d.getde_head();
		for (int i = 0; i < d.getde_size(); i++)
		{//�а�����Ʈ �������ݺ�
			NameNode* ptempWalk = (NameNode*)pWalk1->getPdown();
			while (ptempWalk != NULL)
			{//�ش��а� �̸� ������ �ݺ�
				if (strcmp(token1, ptempWalk->getname()) != 0 && (strcmp(token3, ptempWalk->getPfornt()->getid()) == 0 || strcmp(token4, ptempWalk->getPright()->getcontact()) == 0))
				{//�й� �Ǵ� ��ȣ�� ������ ���� �ߺ��� ��� �����ڵ�300-1���
					log << "[UPDATE]" << endl << "Error code : 300-1" << endl << endl << endl;
					cout << "[UPDATE]" << endl << "Error code : 300-1" << endl << endl << endl;
					flag = 1;//�÷��� 1�� ����
					break;
				}
				ptempWalk = (NameNode*)ptempWalk->getPdown();
			}
			if (flag)break;
			pWalk1 = (DepartmentNode*)pWalk1->getNext();
		}
		if (flag)continue;//�÷��װ� 1�̸� ����Ʈ�� �߰������ʰ� �ٽ� �ݺ�

		DepartmentNode* pWalk = d.getde_head();
		bool check = 0;
		for (int i = 0; i < d.getde_size(); i++)
		{
			check = 0;
			NameNode* pWalkdown = (NameNode*)pWalk->getPdown();
			while (pWalkdown != NULL)
			{
				if (strcmp(pWalkdown->getname(), token1) == 0)
				{//�Ȱ��� �̸��� ã���� UPDATE
					check = 1;
					if (pWalkdown->getPdown() == NULL)
					{//���� ��尡 ������
						pWalkdown->getPup()->setPdown(pWalkdown->getPdown());
					}
					else
					{//�� �̿��� ���
						pWalkdown->getPup()->setPdown(pWalkdown->getPdown());
						pWalkdown->getPdown()->setPup(pWalkdown->getPup());
					}
					delete pWalkdown->getPleft();
					delete pWalkdown->getPfornt();
					delete pWalkdown->getPright();
					delete pWalkdown;//�ش� �̸� ����
					n.setname_size(n.getname_size() - 1);
					if (pWalk->getPdown() == NULL)
					{//�ش� �а��� ���л��� �������
						pWalk->getPre()->setNext(pWalk->getNext());
						pWalk->getNext()->setPrev(pWalk->getPre());
						d.setde_size(d.getde_size() - 1);
						delete pWalk;//�ش� �а� ��� ����
					}
					d.insert(token, token1, atoi(token2), token3, token4);//������ �����͸� ������Ʈ�ؼ� ����Ʈ�� �ٽ� �߰�
					break;
				}
				pWalkdown = (NameNode*)pWalkdown->getPdown();//�Ʒ����� �̵�
			}
			if (check)break;//������Ʈ�� �ߴٸ� �ݺ��� Ż��
			pWalk = (DepartmentNode*)pWalk->getNext();//���� �а��� �̵�
		}
		if (check == 0)
		{//������ information�� �������� ���� ���
			log << "[UPDATE]" << endl << "Error code : 300-2" << endl << endl << endl;
			cout << "[UPDATE]" << endl << "Error code : 300-2" << endl << endl << endl;
		}
	}
	n.clear();//����Ʈ �ʱ�ȭ
	c.clear();//����Ʈ �ʱ�ȭ
	g.clear();//����Ʈ �ʱ�ȭ
	s.clear();//����Ʈ �ʱ�ȭ
	n.insert(d.getde_head(), d.getde_size());//���ο� �̸� ����Ʈ ����
	g.gradelist(n.getname_head(), n.getname_size());//���ο� �г� ����Ʈ ����
	s.idlist(n.getname_head(), n.getname_size());//���ο� �й� ����Ʈ ����
	c.contactlist(n.getname_head(), n.getname_size());//���ο� ����ó ����Ʈ ����
	log << "[UPDATE]" << endl << "Success" << endl << endl << endl;
	cout << "[UPDATE]" << endl << "Success" << endl << endl << endl;
}
inline void Manager::MODIFY_DEPARTMENT(char * str, char * str1, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c)
{
	ofstream log("LOG.txt", ios::app);//������������ ���� ����
	if (str == NULL)
	{//�Էµ� �а��� �������� ���� ��� �����ڵ� 400���
		log << "[MODIFY_DEPARTMENT]" << endl << "Error code : 400" << endl;
		cout << "[MODIFY_DEPARTMENT]" << endl << "Error code : 400" << endl;
		log << "No result" << endl << endl << endl;
		cout << "No result" << endl << endl << endl;
	}
	else
	{
		DepartmentNode* pWalk = (DepartmentNode*)d.getde_head();
		for (int i = 0; i < d.getde_size() - 1; i++)
		{
			if (strcmp(pWalk->get_de(), str) == 0)
			{//��ġ�ϴ� �а��� �����ϸ� �ش��а� ���� ����
				pWalk->getPre()->setNext(pWalk->getNext());
				pWalk->getNext()->setPrev(pWalk->getPre());
				d.setde_size(d.getde_size() - 1);
				break;
			}
			pWalk = (DepartmentNode*)pWalk->getNext();
		}
		NameNode* ptempWalk = (NameNode*)pWalk->getPdown();
		while (ptempWalk != NULL)
		{//�ش� �а��� ������� ���ϴ� �а��� �̵��Ͽ� ����Ʈ ����
			d.insert(str1, ptempWalk->getname(), ptempWalk->getPleft()->getgrade(), ptempWalk->getPfornt()->getid(), ptempWalk->getPright()->getcontact());
			ptempWalk = (NameNode*)ptempWalk->getPdown();
		}

		ptempWalk = (NameNode*)pWalk->getPdown();
		while (ptempWalk != NULL)
		{
			while (ptempWalk != NULL)
			{//��� ������ �̵�
				if (ptempWalk->getPdown() == NULL)
					break;
				ptempWalk = (NameNode*)ptempWalk->getPdown();
			}
			NameNode* tempnode = (NameNode*)ptempWalk->getPup();
			NameNode* deleteWalk = ptempWalk;
			//�л� ���� ����
			delete deleteWalk->getPleft();
			delete deleteWalk->getPfornt();
			delete deleteWalk->getPright();
			delete deleteWalk;//�� �Ʒ������� ����
			n.setname_size(n.getname_size() - 1);
			tempnode->setPdown(NULL);
			ptempWalk = (NameNode*)pWalk->getPdown();//�Ʒ����� �̵�
		}
		delete pWalk;//�ش� �а� ����
		n.clear();//����Ʈ �ʱ�ȭ
		c.clear();//����Ʈ �ʱ�ȭ
		g.clear();//����Ʈ �ʱ�ȭ
		s.clear();//����Ʈ �ʱ�ȭ
		n.insert(d.getde_head(), d.getde_size());//���ο� �̸� ����Ʈ ����
		g.gradelist(n.getname_head(), n.getname_size());//���ο� �г� ����Ʈ ����
		s.idlist(n.getname_head(), n.getname_size());//���ο� �й� ����Ʈ ����
		c.contactlist(n.getname_head(), n.getname_size());//���ο� ����ó ����Ʈ ����
		log << "[MODIFY_DEPARTMENT]" << endl << "Success" << endl << endl << endl;
		cout << "[MODIFY_DEPARTMENT]" << endl << "Success" << endl << endl << endl;
	}
}
inline void Manager::DELETE_DEPARTMENT(char * str, DepartmentList &d, NameList &n, GradeList &g, StudentIDList &s, ContactList &c)
{
	ofstream log("LOG.txt", ios::app);//������������ ���� ����
	if (str == NULL)
	{//�Էµ� �а��� �������� ���� ��� �����ڵ� 500���
		log << "[DELETE_DEPARTMENT]" << endl << "Error code : 500" << endl;
		cout << "[DELETE_DEPARTMENT]" << endl << "Error code : 500" << endl;
		log << "No result" << endl << endl << endl;
		cout << "No result" << endl << endl << endl;
	}
	else
	{
		DepartmentNode* pWalk = (DepartmentNode*)d.getde_head();
		for (int i = 0; i < d.getde_size() - 1; i++)
		{
			if (strcmp(pWalk->get_de(), str) == 0)
			{//�ش� �а���� ��ġ�ϸ�
				NameNode* ptempWalk = (NameNode*)pWalk->getPdown();
				while (ptempWalk != NULL)
				{//��� ������ �̵�
					while (ptempWalk != NULL)
					{
						if (ptempWalk->getPdown() == NULL)
							break;
						ptempWalk = (NameNode*)ptempWalk->getPdown();
					}
					NameNode* tempnode = (NameNode*)ptempWalk->getPup();
					NameNode* deleteWalk = ptempWalk;
					//�л� ���� ����
					delete deleteWalk->getPleft();
					delete deleteWalk->getPfornt();
					delete deleteWalk->getPright();
					delete deleteWalk;//�ش� �л� ��� ����
					n.setname_size(n.getname_size() - 1);
					tempnode->setPdown(NULL);
					ptempWalk = (NameNode*)pWalk->getPdown();//�Ʒ����� �̵�
				}
				pWalk->getPre()->setNext(pWalk->getNext());
				pWalk->getNext()->setPrev(pWalk->getPre());
				delete pWalk;//�ش� �а� ����
				d.setde_size(d.getde_size() - 1);
				break;
			}
			pWalk = (DepartmentNode*)pWalk->getNext();//���� �а����� �̵�
		}
		log << "[DELETE_DEPARTMENT]" << endl << "Success" << endl << endl << endl;
		cout << "[DELETE_DEPARTMENT]" << endl << "Success" << endl << endl << endl;
		n.clear();//����Ʈ �ʱ�ȭ
		c.clear();//����Ʈ �ʱ�ȭ
		g.clear();//����Ʈ �ʱ�ȭ
		s.clear();//����Ʈ �ʱ�ȭ
		n.insert(d.getde_head(), d.getde_size());//���ο� �̸� ����Ʈ ����
		g.gradelist(n.getname_head(), n.getname_size());//���ο� �г� ����Ʈ ����
		s.idlist(n.getname_head(), n.getname_size());//���ο� �й� ����Ʈ ����
		c.contactlist(n.getname_head(), n.getname_size());//���ο� ����ó ����Ʈ
	}
}
inline void Manager::PRINT(char* str, DepartmentList & d)
{
	ofstream log("LOG.txt", ios::app);//������������ �ؽ�Ʈ���� ����
	log << "[PRINT]" << endl;
	cout << "[PRINT]" << endl;
	if (d.getde_head() == NULL)
	{//��ũ�� ����Ʈ�� �������� ������� �����ڵ� 600-1���
		log  << "Error code : 600-1" << endl;
		cout << "Error code : 600-1" << endl;
		log << "No result" << endl << endl << endl;
		cout << "No result" << endl << endl << endl;
	}
	if (str == NULL)
	{//�а��� �Էµ��� �ʾ��� ���
		DepartmentNode* pWalk = (DepartmentNode*)d.getde_head()->getPre();
		for (int i = 0; i < d.getde_size(); i++)
		{
			NameNode* ptempWalk = (NameNode*)pWalk->getPdown();
			while (ptempWalk != NULL)
			{//���� ���
				cout<< pWalk->get_de() << "/"
					<< ptempWalk->getname() << "/"
					<< ptempWalk->getPleft()->getgrade() << "/"
					<< ptempWalk->getPfornt()->getid() << "/"
					<< ptempWalk->getPright()->getcontact() << endl;
				log << pWalk->get_de() << "/"
					<< ptempWalk->getname() << "/"
					<< ptempWalk->getPleft()->getgrade() << "/"
					<< ptempWalk->getPfornt()->getid() << "/"
					<< ptempWalk->getPright()->getcontact() << endl;
				ptempWalk = (NameNode*)ptempWalk->getPdown();//�Ʒ����� �̵�
			}
			pWalk = (DepartmentNode*)pWalk->getPre();
		}
		log << endl << endl << endl;
		cout << endl << endl << endl;
	}
	else
	{//�а��� �ԷµǾ������
		bool check = 0;
		DepartmentNode* pWalk = (DepartmentNode*)d.getde_head();
		for (int i = 0; i < d.getde_size() - 1; i++)
		{
			if (strcmp(pWalk->get_de(), str) == 0)
			{//�Է¹��� �а��� ��ġ�ϸ�
				check = 1;
				NameNode* ptempWalk = (NameNode*)pWalk->getPdown();
				while (ptempWalk != NULL)
				{//���� ���
					cout<< pWalk->get_de() << "/"
						<< ptempWalk->getname() << "/"
						<< ptempWalk->getPleft()->getgrade() << "/"
						<< ptempWalk->getPfornt()->getid() << "/"
						<< ptempWalk->getPright()->getcontact() << endl;
					log << pWalk->get_de() << "/"
						<< ptempWalk->getname() << "/"
						<< ptempWalk->getPleft()->getgrade() << "/"
						<< ptempWalk->getPfornt()->getid() << "/"
						<< ptempWalk->getPright()->getcontact() << endl;
					ptempWalk = (NameNode*)ptempWalk->getPdown();//�Ʒ����� �̵�
				}
			}
			pWalk = (DepartmentNode*)pWalk->getNext();
		}
		log << endl << endl << endl;
		cout << endl << endl << endl;
		if (check == 0)
		{//�ش� �а��� �������� ���� ��� �����ڵ� 600-2 ���
			log << "[PRINT]" << endl << "Error code : 600-2" << endl << endl << endl;
			cout << "[PRINT]" << endl << "Error code : 600-2" << endl << endl << endl;
		}
	}
}
inline void Manager::PRINT_STUDENT_ID(DepartmentList & d, NameList &n, StudentIDList &s)
{
	ofstream log("LOG.txt", ios::app);//������������ ���Ͽ���
	cout << "[PRINT_STUDENT_ID]" << endl;
	log << "[PRINT_STUDENT_ID]" << endl;
	DepartmentNode* pWalk = d.getde_head();
	if (pWalk == NULL)
	{//��ũ�� ����Ʈ�� �������� ������� �����ڵ� 700���
		log << "Error code : 700" << endl;
		cout << "Error code : 700" << endl;
		log << "No result" << endl << endl << endl;
		cout << "No result" << endl << endl << endl;
	}
	char* de[300] = { 0, };//�а� �迭
	char* na[300] = { 0, };//�̸� �迭
	int gra[300] = { 0, };//�г� �迭
	char* id[300] = { 0, };//�й� �迭
	char* co[300] = { 0, };//��ȣ �迭
	
	int k = 0;
	for (int i = 0; i < d.getde_size(); i++)
	{
		NameNode* pWalkdown = (NameNode*)pWalk->getPdown();
		while (pWalkdown != NULL)
		{//�� �迭�� ��ũ�帮��Ʈ ����
			de[k] = pWalk->get_de();
			na[k] = pWalkdown->getname();
			gra[k] = pWalkdown->getPleft()->getgrade();
			id[k] = pWalkdown->getPfornt()->getid();
			co[k] = pWalkdown->getPright()->getcontact();
			pWalkdown = (NameNode*)pWalkdown->getPdown();
			k++;
		}
		pWalk = (DepartmentNode*)pWalk->getNext();
	}
	int v = 0;
	while (id[v] != NULL)
		v++;//�迭 ���� ����
	
	char* tempnode;
	int tempnode1;
	int p;
	for (int i = 0; i < v-1; i++)
	{//��������
		for(int p = i + 1; p>0; p--)
		{
			if (strcmp(id[p - 1], id[p])>0)
			{
				tempnode = co[p];
				co[p] = co[p-1];
				co[p - 1] = tempnode;
				tempnode = de[p];
				de[p] = de[p - 1];
				de[p - 1] = tempnode;
				tempnode = na[p];
				na[p] = na[p - 1];
				na[p - 1] = tempnode;
				tempnode = id[p];
				id[p] = id[p - 1];
				id[p - 1] = tempnode;
				tempnode1 = gra[p];
				gra[p] = gra[p - 1];
				gra[p - 1] = tempnode1;
			}
			else
				continue;
		}
	}
	for (int i = 0; i < v; i++)
	{//�й������� �����������ĵ� �迭���� ���ʴ�� ���
		cout << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
		log << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
	}
	log << endl << endl;
	cout << endl << endl;
}
inline void Manager::PRINT_CONTACT(DepartmentList & d)
{
	ofstream log("LOG.txt", ios::app);//������������ �ؽ�Ʈ���� ����
	cout << "[PRINT_CONTACT]" << endl;
	log << "[PRINT_CONTACT]" << endl;
	DepartmentNode* pWalk = d.getde_head();
	if (pWalk == NULL)
	{//��ũ�� ����Ʈ�� ������������ ��� �����ڵ� 800���
		log << "Error code : 800" << endl;
		cout << "Error code : 800" << endl;
		log << "No result" << endl << endl << endl;
		cout << "No result" << endl << endl << endl;
	}
	char* de[300] = { 0, };//�а� �迭
	char* na[300] = { 0, };//�̸� �迭
	int gra[300] = { 0, };//�г� �迭
	char* id[300] = { 0, };//�й� �迭
	char* co[300] = { 0, };//��ȣ �迭

	int k = 0;
	for (int i = 0; i < d.getde_size(); i++)
	{
		NameNode* pWalkdown = (NameNode*)pWalk->getPdown();
		while (pWalkdown != NULL)
		{//�迭�� ��ũ�帮��Ʈ ����
			de[k] = pWalk->get_de();
			na[k] = pWalkdown->getname();
			gra[k] = pWalkdown->getPleft()->getgrade();
			id[k] = pWalkdown->getPfornt()->getid();
			co[k] = pWalkdown->getPright()->getcontact();
			pWalkdown = (NameNode*)pWalkdown->getPdown();
			k++;
		}
		pWalk = (DepartmentNode*)pWalk->getNext();
	}
	int v = 0;
	while (co[v] != NULL)
		++v;//�迭 ���� ����

	char* tempnode;
	int tempnode1;
	for (int i = 0; i < v - 1; i++)
	{//���� ����
		int temp = i;
		for (int j = i + 1; j < v; j++)
		{
			if (strcmp((char*)co[temp], (char*)co[j]) > 0)
				temp = j;//���ʿ��� �������� �߰ߵǸ� temp�� ����
		}
		tempnode = co[temp];
		co[temp] = co[i];
		co[i] = tempnode;
		tempnode = de[temp];
		de[temp] = de[i];
		de[i] = tempnode;
		tempnode = na[temp];
		na[temp] = na[i];
		na[i] = tempnode;
		tempnode = id[temp];
		id[temp] = id[i];
		id[i] = tempnode;
		tempnode1= gra[temp];
		gra[temp] = gra[i];
		gra[i] = tempnode1;
	}
	for (int i = 0; i < v; i++)
	{//��ȭ��ȣ������ �����������ĵ� �迭���� ���ʴ�� ���
		cout << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
		log << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
	}
	log << endl << endl;
	cout << endl << endl;
}
inline void Manager::FIND_NAME(char * str, DepartmentList & d, NameList & n)
{
	ofstream log("LOG.txt", ios::app);//������������ �ؽ�Ʈ���� ����
	DepartmentNode* pWalk = d.getde_head();

	char* de[300] = { 0, };//�а� �迭
	char* na[300] = { 0, };//�̸� �迭
	int gra[300] = { 0, };//�г� �迭
	char* id[300] = { 0, };//�й� �迭
	char* co[300] = { 0, };//��ȣ �迭

	int k = 0;
	for (int i = 0; i < d.getde_size(); i++)
	{
		NameNode* pWalkdown = (NameNode*)pWalk->getPdown();
		while (pWalkdown != NULL)
		{//�迭�� ��ũ�帮��Ʈ ����
			de[k] = pWalk->get_de();
			na[k] = pWalkdown->getname();
			gra[k] = pWalkdown->getPleft()->getgrade();
			id[k] = pWalkdown->getPfornt()->getid();
			co[k] = pWalkdown->getPright()->getcontact();
			pWalkdown = (NameNode*)pWalkdown->getPdown();
			k++;
		}
		pWalk = (DepartmentNode*)pWalk->getNext();
	}
	int v = 0;
	while (co[v] != NULL)
		++v;//�迭���� ����
	char* tempnode;
	int tempnode1;
	for (int i = 0; i < v; i++)
	{//���� ����
		for (int j = 0; j < v - (i + 1); j++)
		{//�� �տ��� ���� ��� �Ⱦ� ���鼭 ����
			if (strcmp(na[j], na[j + 1]) > 0)
			{
				tempnode = co[j];
				co[j] = co[j + 1];
				co[j + 1] = tempnode;
				tempnode = de[j];
				de[j] = de[j + 1];
				de[j + 1] = tempnode;
				tempnode = na[j];
				na[j] = na[j + 1];
				na[j + 1] = tempnode;
				tempnode = id[j];
				id[j] = id[j + 1];
				id[j + 1] = tempnode;
				tempnode1 = gra[j];
				gra[j] = gra[j + 1];
				gra[j + 1] = tempnode1;
			}
		}
	}
	bool check = 0;
	if (str[2] != NULL)
	{//�̸��� �� �Է¹޾�����
		for (int i = 0; i < v; i++)
		{
			if (strcmp(str, na[i]) == 0)
			{//�ش� �̸��� �߰ߵȴٸ�
				check = 1;
				cout << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
				log << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
			}
		}
	}
	char temp[3] = { str[0], str[1] };
	if(str[2] == NULL)
	{//���� �Է¹޾�����
		for (int i = 0; i < v; i++)
		{
			char* tempname = na[i];
			char tempnamearr[3] = { tempname[0], tempname[1] };
			if (strcmp(str, tempnamearr) == 0)
			{//�ش� ���� ��������� �����ϸ�
				check = 1;
				cout << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
				log << de[i] << "/" << na[i] << "/" << gra[i] << "/" << id[i] << "/" << co[i] << endl;
			}
		}
	}
	if (check == 0)
	{//�ش� �̸� �Ǵ� ���� �������� ���� ��� �����ڵ� 900���
		log  << "Error code : 900" << endl;
		cout  << "Error code : 900" << endl;
		log << "No result" << endl << endl << endl;
		cout << "No result" << endl << endl << endl;
	}
	log << endl << endl;
	cout << endl << endl;
}
inline void Manager::SAVE(char * str, DepartmentList & d, NameList & n, GradeList & g, StudentIDList & s, ContactList & c)
{
	if (str != NULL)
	{//���ϸ� ���ڸ� �Է¹޾Ҵٸ�
		ofstream of(str);//�Է¹��� ���ϸ����� �������� ������ ����
		DepartmentNode* pWalk = (DepartmentNode*)d.getde_head();
		for (int i = 0; i < d.getde_size(); i++)
		{
			NameNode* ptempWalk = (NameNode*)pWalk->getPdown();
			while (ptempWalk != NULL)
			{//��� ��ũ�� ����Ʈ������ ���Ͽ� �Է�
				of  << pWalk->get_de() << "/"
					<< ptempWalk->getname() << "/"
					<< ptempWalk->getPleft()->getgrade() << "/"
					<< ptempWalk->getPfornt()->getid() << "/"
					<< ptempWalk->getPright()->getcontact() << endl;
				ptempWalk = (NameNode*)ptempWalk->getPdown();
			}
			pWalk = (DepartmentNode*)pWalk->getNext();
		}
		of << endl;
		ofstream log("LOG.txt", ios::app);
		log << "[SAVE]" << endl << str << " Success" << endl << endl << endl;
		cout << "[SAVE]" << endl << str << " Success" << endl << endl << endl;
	}
	else
	{//���ϸ� ���ڰ� ���°�� �����ڵ� 1000���
		ofstream log("LOG.txt", ios::app);
		log << "[SAVE]" << endl << "Error code : 1000" << endl;
		cout << "[SAVE]" << endl << "Error code : 1000" << endl;
		log << "No result" << endl << endl << endl;
		cout << "No result" << endl << endl << endl;
	}
}
