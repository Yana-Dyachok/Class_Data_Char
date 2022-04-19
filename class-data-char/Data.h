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
	void setDay(const char* a);//метод- €кий зм≥нюЇ значенн€ дати класу;
	void setMonth(const char* a);//метод-  €кий зм≥нюЇ значенн€ м≥с€ц€
	void setYear(const char* a); //метод- €кий зм≥нюЇ значенн€ року класу;
	bool verifikation();//функц≥€ €ка перев≥р€Ї коректн≥сть дати ≥ повертаЇ(true / false) в≥дпов≥дно(правильна / неправильна).≤ €кщо дата не правильна надаЇ значенн€ 01.01.1900;
	void check();//метод €кий перев≥р€Ї правильн≥сть дати
	void OutDataddmmyy();//метод-  виводить дату у формат≥ дд.мм.рр, наприклад 02.03.19;
	void OutDataddMonthyyyy();//метод-  виводить дату у формат≥ дд м≥с€ць рррр, наприклад 02 March 2019.
	void OutDataddmmyyyy();//метод-  виводить дату у формат≥ дд.мм.рррр, наприклад 02.03.2019;
	~Data();
};