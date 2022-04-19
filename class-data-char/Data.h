#pragma once
using namespace std;
class Data
{
private:
	char* day; char* month; char* year;
	int size;
public:
	Data();
	Data(const char* d,const char* m,const char* y);
	Data(const Data& d,const Data& m, const Data& y);
	void setDay(const char* a);//�����- ���� ����� �������� ���� �����;
	void setMonth(const char* a);//�����-  ���� ����� �������� �����
	void setYear(const char* a); //�����- ���� ����� �������� ���� �����;
	bool verifikation();//������� ��� �������� ���������� ���� � �������(true / false) ��������(��������� / �����������).� ���� ���� �� ��������� ���� �������� 01.01.1900;
	void check();//����� ���� �������� ����������� ����
	void OutDataddmmyy();//�����-  �������� ���� � ������ ��.��.��, ��������� 02.03.19;
	void OutDataddMonthyyyy();//�����-  �������� ���� � ������ �� ����� ����, ��������� 02 March 2019.
	void OutDataddmmyyyy();//�����-  �������� ���� � ������ ��.��.����, ��������� 02.03.2019;
	~Data();
};