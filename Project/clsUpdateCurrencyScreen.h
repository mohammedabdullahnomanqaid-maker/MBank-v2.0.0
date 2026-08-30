#pragma once
#include<iostream>
#include"clsString.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include<string>
using namespace std;
class clsUpdateCurrencyScreen:protected clsScreen
{


	static void _PrintCurrencyInfo(clsCurrency Currency)
	{

		cout << "\n\nCurrency Card:";
		cout << "\n\n_______________________________\n";
		cout << "Country        : " << Currency.Country() << endl;
		cout << "Code           : " << Currency.CurrencyCode() << endl;
		cout << "Name           : " << Currency.CurrencyName() << endl;
		cout << "Rate (1$) =    : " << Currency.Rate()<< endl;
		cout << "\n_______________________________";
	}

	static float _ReadRate()
	{
		float NewRate = 0;
		cout << "Enter New Rate? ";
		NewRate = clsInputValidate::ReadTypeOfNumber<float>();
		return NewRate;
	}

public:
	static void ShowUpdateCurrencyScreen()
	{

		_DrawscreanHeader("\t Update Currency Screen");

		string CurrencyCode;
		cout << "\nPlease Enter CurrencyCode? ";
		CurrencyCode = clsInputValidate::ReadString<string>();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{

			cout << "\nCurrecy is Not Found,Choose another one ? ";
			CurrencyCode = clsInputValidate::ReadString<string>();


		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrencyInfo(Currency);

		char Answer = 'h';
		cout << "\nAre you sure ,you want to Update the Rate of this Currency Y/N ? ";
		cin >> Answer;

		

		if (toupper(Answer) == 'Y')
		{

			cout << "\n\nUpdate Currency Rate : " << endl;
			cout << "____________________________" << endl;

			Currency.UpdateRate(_ReadRate());
			cout << "\n\nCurrency Rate Update Successfully :-)";
			_PrintCurrencyInfo(Currency);
		}

		else
		{
			cout << "\t\t\nThe Operation was Cancelled.";
		}

	}






};

