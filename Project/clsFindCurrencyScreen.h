#pragma once
#include<iostream>
#include"clsString.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
using namespace std;
class clsFindCurrencyScreen:protected clsScreen
{

	

	static void _PrintCurrencyInfo(clsCurrency Currency)
	{

		cout << "\n\nCurrency Card:";
		cout << "\n\n_______________________________\n";
		cout << "Country        : " << Currency.Country() << endl;
		cout << "Code           : " << Currency.CurrencyCode() << endl;
		cout << "Name           : " << Currency.CurrencyName() << endl;
		cout << "Rate (1$) =    : " << Currency.Rate() << endl;
		cout << "\n_______________________________";
	}
	static void _ShowResualts(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\n\nCurrency Found :-)";
			_PrintCurrencyInfo(Currency);
		}
		else
		{
			cout << "\n\nCurrency Not Found :-(";
		}

	}

public:

	static void ShowFindCurrencyScreen()
	{
		short Answer;
		
		_DrawscreanHeader("\t Find Currency Screen");

		cout << "\n\nFind By: [1] Code  [2] Country? ";
		Answer = clsInputValidate::ReadTypeNumberBetween<short>(1, 2, "Invalid Number,Enter Number Between 1 to 2 ? ");
			
		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease Enter CurrencyCode? ";
			CurrencyCode = clsInputValidate::ReadString<string>();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResualts(Currency);

		}
		else
		{
			string Country;
			cout << "\nPlease Enter Country? ";
			Country = clsInputValidate::ReadString<string>();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResualts(Currency);


		}


	}










};

