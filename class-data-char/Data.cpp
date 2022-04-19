#include "Data.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
Data::Data() {
	char arr[3]{ '0','1' }; char array[5]{ '1','9','0','0' };
	for (int i = 0; i < 3; i++)
	{
		this->day[i] = arr[i];
		this->month[i] = arr[i];
	}
	for (int i = 0; i < 5; i++)
	{
		this->year[i] = array[i];
	}
}


Data::Data(const char* d, const char* m, const char* y) {
	this->size = strlen(d);
	this->day = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		this->day[i] = d[i];
	}
	this->day[size] = '\0';

	this->size = strlen(m);
	this->month = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		this->month[i] = m[i];
	}
	this->month[size] = '\0';
	this->size = strlen(y);
	this->year = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		this->year[i] = y[i];
	}
	this->year[size] = '\0';
}


Data::Data(const Data& d, const Data& m, const Data& y) {
	this->size = d.size;
	this->day = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		this->day[i] = d.day[i];
	}
	this->day[size] = '\0';
	this->size = m.size;
	this->month = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		this->month[i] = m.month[i];
	}
	this->month[size] = '\0';
	this->size = y.size;
	this->year = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		this->year[i] = y.year[i];
	}
	this->year[size] = '\0';
}


void Data::setDay(const char* a) {// метод, €кий зм≥нюЇ значенн€ дати класу;
	delete[]this->day;
	this->day = new char[3];
	for (int i = 0; i < 2; i++)
	{
		this->day[i] = a[i];
	}
	this->day[2] = '\0';
}


void Data::setMonth(const char* a) {// метод, €кий зм≥нюЇ значенн€ м≥с€ц€;
	delete[]this->month;
	this->month = new char[3];
	for (int i = 0; i < 2; i++)
	{
		this->month[i] = a[i];
	}
	this->month[2] = '\0';
}


void Data::setYear(const char* a) {// метод, €кий зм≥нюЇ значенн€ року класу;
	delete[]this->year;
	this->year = new char[5];
	for (int i = 0; i < 4; i++)
	{
		this->year[i] = a[i];
	}
	this->year[4] = '\0';
}


bool Data::verifikation() {//  метод, €кий перев≥р€Ї коректн≥сть дати ≥ повертаЇ(true / false) в≥дпов≥дно(правильна / неправильна).≤ €кщо дата не правильна надаЇ значенн€ 01.01.1900;
string MonthNumb[] = { "01","02","03","04","05","06","07","08","09","10","11","12" };
string check; bool find=false, find1 = false, find2 = false;
	for (int i = 0; i < 13; i++) {

		if (MonthNumb[i] == this->month) check = this->month;
	}
	for (int i = 0; i < 3; i++) {
		if (check == this->month) find1=true;
		else  find1=false;
	}

	for (int i = 0; i < 3; i++)
	{
		if ((('0' > this->day[0]) or ('2' < this->day[0])) or (('3' == this->day[0]) and ('1' < this->day[1]))) find2= false;
		else  find2=true;
	}
	for (int i = 0; i < 5; i++)
	{
		if ((this->size>5) or (('0' > this->year[0]) or ('2' < this->year[0])) or (('2'== this->year[0]) and ('0' <this->year[1])) or(('2' == this->year[0]) and ('0' == this->year[1])and ('5' <= this->year[2]) and ('0' < this->year[3]))) find = false;
		else  find = true;
	}
	if (find == true and find1 == true and find2 == true)return true;
	else return false;
}
	

void Data::check() {
	if (!verifikation()) {
		std::cout << "Error date" << std::endl;
		char arr[3]{ '0','1' }; char array[5]{ '1','9','0','0' };
	for (int i = 0; i < 3; i++)
	{
		this->day[i] = arr[i];
		this->month[i] = arr[i];
	}
	for (int i = 0; i < 5; i++)
	{
		this->year[i] = array[i];
	}
	}
}


void Data::OutDataddmmyy() {// метод виводить дату у формат≥ дд.мм.рр, наприклад 02.03.19;
	check();
	string year;
	for (int i = 2; i <5; i++)
	{ 
		year+=this->year[i];
	}

	std::cout << this->day << "." << this->month << "." << year<< std::endl;
}


void Data::OutDataddmmyyyy() {// метод виводить дату у формат≥ дд.мм.рррр, наприклад 02.03.2019;
	check();
	std::cout << this->day << "." << this->month << "." << this->year << std::endl;
}


void Data::OutDataddMonthyyyy() {// метод виводить дату у формат≥ дд м≥с€ць рррр, наприклад 02 March 2019.
	check();
	int k = 0;
	std::cout << this->day << ' '; 
	string Month[] = { "January","February","March"," April","May","June","July","August","September","October","November","December" };
	string MonthNumb[] = {"01","02","03","04","05","06","07","08","09","10","11","12"};
	for (int i = 0; i <13; i++)
	{
		if (MonthNumb[i] == this->month) { k = i; }
	}
	std::cout << Month[k] << ' ';
	std::cout << this->year<<std::endl;
}


Data::~Data() {
	delete[]day;
	delete[]month;
	delete[]year;
}