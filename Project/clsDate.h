#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include"clsString.h"
using namespace std;

class clsDate {


	short _Year;
	short _Day;
	short _Month;

public:

	clsDate()
	{


		time_t t = time(0);
		tm* dt = localtime(&t);

		_Day = dt->tm_mday;
		_Month = dt->tm_mon + 1;
		_Year = dt->tm_year + 1900;
	}
	clsDate(string Date)
	{
		vector<string>VD;
		VD = clsString::Split(Date, "/");

		_Day = stoi(VD[0]);
		_Month = stoi(VD[1]);
		_Year = stoi(VD[2]);

	}

	clsDate(short Day, short Month, short Year)
	{

		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	static bool IsLeapYear(short Year) {

		return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));

	}

	bool IsLeapYear() {
		return IsLeapYear(_Year);

	}

	static short GetDayInMonth(short Month, short Year) {


		if (Month < 1 || Month>12) {
			return 0;
		}


		short Days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };


		return (Month == 2) ? IsLeapYear(Year) ? 29 : 28 : (Days[Month - 1]);


	}
	short GetDayInMonth()
	{

		return GetDayInMonth(_Month, _Year);

	}

	static bool IsLastDayInMonth(clsDate Date)
	{

		return (Date._Day == (GetDayInMonth(Date._Month, Date._Year)));

	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);

	}



	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		clsDate Date;

		Date._Year = Year;
		Date._Day = 1;
		Date._Month = 1;
		short DaysOfMonth;

		while (true)
		{

			DaysOfMonth = GetDayInMonth(Date._Month, Date._Year);

			if (DateOrderInYear > DaysOfMonth)
			{
				DateOrderInYear -= DaysOfMonth;

				Date._Month++;

				if (Date._Month > 12) {
					Date._Month = 1;
					Date._Year++;
				}

			}


			else {

				Date._Day = DateOrderInYear;
				break;
			}
		}

		return Date;
	}

	clsDate(int Days, int Year)
	{
		clsDate Date = GetDateFromDayOrderInYear(Days, Year);

		_Day = Date._Day;
		_Month = Date._Month;
		_Year = Date._Year;
	}

	void SetDay(short Day)
	{
		_Day = Day;

	}
	short GetDay()
	{
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay))short Day;

	void SetYear(short Year)
	{
		_Year = Year;

	}

	short GetYear()
	{
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear))short Year;


	void SetMonth(short Month)
	{
		_Month = Month;

	}

	short GetMonth()
	{
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth))short Month;




	static short DayOfWeekOrder(short Year, short Month, short Day) {

		short a, y, m;
		a = ((14 - Month) / 12);
		y = Year - a;
		m = Month + (12 * a) - 2;
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;

	}
	short DayOfWeekOrder(clsDate Date)
	{
		return  DayOfWeekOrder(Date._Year, Date._Month, Date._Day);
	}

	static clsDate IncreaseDateByOneDay(clsDate& Date)
	{


		if (IsLastDayInMonth(Date))
		{


			if (IsLastMonthInYear(Date._Month))
			{
				Date._Month = 1;
				Date._Year++;
				Date._Day = 1;
			}
			else
			{
				Date._Month++;
				Date._Day = 1;
			}

		}
		else
		{
			Date._Day++;
		}
		return Date;
	}
	static string DateToString(clsDate Date)
	{
		return (to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year));
	}
	string DateToString()
	{
		return DateToString(*this);
	}
	void Print() {

		cout << DateToString() << endl;
	}

	static string ShowNameOfMonth(short MonthOrder) {

		string Name[12] = { "Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec" };

		return Name[MonthOrder - 1];
	}
	string ShowNameOfMonth() {
		return ShowNameOfMonth(_Month);
	}

	static void PrintMonthCalender(short Month, short Year) {

		short DayOrder = DayOfWeekOrder(Year, Month, 1);
		short MonthNumber = GetDayInMonth(Month, Year);
		short Number = 0;

		printf("\t______________________%s_________________________\n", ShowNameOfMonth(Month).c_str());

		printf("\tSun     Mon     Tue     Wed     Thu     Fri     Sat\n");


		for (int i = 0; i <= DayOrder; i++)
		{
			printf("\t   ");
			Number++;

		}
		for (int i = 1; i <= MonthNumber; i++)
		{


			if (Number == 7) {
				cout << endl;
				Number = 0;
			}
			Number++;
			printf("\t%d", i);
		}

		printf("\n\t___________________________________________________\n");

	}
	void PrintMonthCalender()
	{
		PrintMonthCalender(_Month, _Year);
	}

	static clsDate GetSystemDate()
	{

		short Day, Month, Year;
		time_t t = time(0);
		tm* dt = localtime(&t);

		Day = dt->tm_mday + 1;
		Month = dt->tm_mon + 1;
		Year = dt->tm_year + 1900;
		return clsDate(Day, Month, Year);

	}

	static string GetSystemDateTimeString()
	{
		short Day, Month, Year,Hour,Minute,Sec;
		time_t t = time(0);
		tm* dt = localtime(&t);

		Day = dt->tm_mday + 1;
		Month = dt->tm_mon + 1;
		Year = dt->tm_year + 1900;
		Hour = dt->tm_hour;
		Minute = dt->tm_min;
		Sec = dt->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - " + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Sec));

		

	}
	static void PrintYearCalender(short Year)
	{
		printf("\n\n\t\t___________________________________\n\n");
		printf("\t\t        Calender - %d", Year);
		printf("\n\n\t\t__________________________________\n\n");


		for (short i = 1; i <= 12; i++)
		{

			PrintMonthCalender(i, Year);

			cout << endl;
		}


	}

	void PrintYearCalender()
	{
		PrintYearCalender(_Year);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);

	}

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}



	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true : (Date1._Year == Date2._Year) ? ((Date1._Month < Date2._Month) ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false;
	}
	bool IsDateBeforeDate2(clsDate Date2)
	{
		return  IsDate1BeforeDate2(*this, Date2);
	}

	static int CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		int Days = 0;
		clsDate CurrentDate;
		while (IsDate1BeforeDate2(DateOfBirth, CurrentDate))
		{

			Days++;

			DateOfBirth = IncreaseDateByOneDay(DateOfBirth);
		}
		return Days;

	}


	static bool IsValidDate(clsDate Date)
	{
		if (Date._Month < 1 || Date._Month>12)
			return false;

		if (Date._Day > GetDayInMonth(Date._Month, Date._Year))
			return false;
		else
			return true;
	}
	bool IsValid()
	{
		return IsValidDate(*this);
	}


	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month ? (Date1._Day == Date2._Day) : false)) : false;
	}
	bool IsDateEqualDate2(clsDate Date2)
	{
		return  IsDate1EqualDate2(*this, Date2);
	}


	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return ((!IsDate1BeforeDate2(Date1, Date2)) && (!IsDate1EqualDate2(Date1, Date2)));
	}
	bool IsDateAfterDate2(clsDate Date2)
	{
		return  IsDate1AfterDate2(*this, Date2);
	}


	void AddDays(short Days)
	{

		for (short i = 1; i <= Days; i++)
		{
			IncreaseDateByOneDay(*this);
		}

	}

	static string ShowNameOfDay(short DayOrder)
	{
		string NumberOfDays[] = { "Sut","San","Mon","Tues","Wed","Thur","Fri" };

		return NumberOfDays[DayOrder - 1];

	}
	string ShowNameOfDay()
	{
		return ShowNameOfDay(_Day);
	}


	static int NumberOfDaysFromTheBeginingOfTheYear(short Year, short Month, short Day)
	{

		int NumberOfDays = 0;


		for (short i = 1; i < Month; i++)
		{


			NumberOfDays += GetDayInMonth(i, Year);

		}
		return NumberOfDays + Day;
	}
	int NumberOfDaysFromTheBeginingOfTheYear()
	{
		return NumberOfDaysFromTheBeginingOfTheYear(_Year, _Month, _Day);
	}
	enum enDateCompare { Before = -1, After = 1, Equal = 0 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{


		if (IsDate1AfterDate2(Date1, Date2))
			return enDateCompare::After;

		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;



		else
			return enDateCompare::Equal;
	}
	static void Swap(clsDate& d1, clsDate& d2)
	{
		clsDate temp;
		temp.Year = d1.Year;
		temp.Day = d1.Day;
		temp.Month = d1.Month;

		d1.Year = d2.Year;
		d1.Day = d2.Day;
		d1.Month = d2.Month;

		d2.Year = temp.Year;
		d2.Day = temp.Day;
		d2.Month = temp.Month;

	}
	void Swap(clsDate& d2)
	{
		Swap(*this, d2);
	}
};



