#pragma once
#include<iostream>
#include"clsDate.h"
#include"clsPeriod.h"
#include"clsUtil.h"
#include<string>
using namespace std;

class clsInputValidate
{


public:

	 template<typename T>static T IsNumberBetween(T Number, T From, T To)
	{
		return (Number >= From && Number <= To) ? true : false;
	}

	template<typename T> static T IsDateBetween(T Date, T From, T To)
	{
		if (clsDate::IsDate1AfterDate2(From, To))
		{
			clsUtil::Swap(From, To);

		}
		
		if (
			clsDate::CompareDates(Date, To) == clsDate::enDateCompare::Before
			&&
			clsDate::CompareDates(Date, From) == clsDate::enDateCompare::After
			)
			return true;
		else
			return false;

	}

	template<typename T> static T ReadTypeOfNumber(string Message = "Invalide Number,Enter a Valide one: ")
	{
		T Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message;
		}

		return Number;
	}
	template<typename T> static T ReadTypeNumberBetween(T From, T To, string Message= "Number is Not within range, Enter again: ")
	{

		T Number;
		Number = ReadTypeOfNumber<T>();

		while (!IsNumberBetween(Number,From,To))
		{

			cout << Message << endl;
			Number = ReadTypeOfNumber<T>();

		}

		return Number;

	}

	
	template<typename T> static T IsValideDate(clsDate Date)
	{

		return clsDate::IsValidDate(Date);

	}
	

	template<typename T> static T  ReadString()
	{
		string Put="";

		getline(cin >> ws, Put);
		return Put;
	}

};

