#pragma once

class Contact
{//��ȭ��ȣ ��� Ŭ����
private:
	char contact[32];//��ȭ��ȣ �迭
	Contact* Pright;//������� ����
public:
	Contact() {
		for (int i = 0; i < 32; i++)
			contact[i] = NULL;//���� �ʱ�ȭ
		Pright = NULL;//���� �ʱ�ȭ
	}
	~Contact() {

	}
	Contact(char* str) {
		strcpy(contact, str);//��ȭ��ȣ ����
	}
	char* getcontact() { return contact; }//��ȭ��ȣ�� �޾ƿ����Լ�
	void setcontact(char* str) { strcpy(contact, str); }//��ȭ��ȣ�� �����ϴ� �Լ�
	Contact* getright() { return Pright; }//�������� �̵��ϴ� �Լ�
	void setright(Contact* tempnode) { Pright = tempnode; }//������带 �����ϴ� �Լ�
};