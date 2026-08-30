#pragma once
#include<iostream>
#include"clsString.h"
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include<string>
using namespace std;
class clsCurrencyCalculator:protected clsScreen
{
	static void _PrintCurrencyInfo(string Title,clsCurrency Currency)
	{

		cout << Title;
		cout << "\n_______________________________\n";
		cout << "Country        : " << Currency.Country() << endl;
		cout << "Code           : " << Currency.CurrencyCode() << endl;
		cout << "Name           : " << Currency.CurrencyName() << endl;
		cout << "Rate (1$) =    : " << Currency.Rate() << endl;
		cout << "\n_______________________________\n\n";
	}

	static clsCurrency GetCurrency(string Message)
	{
	
		string CurrencyCode;
		cout << Message;

		CurrencyCode = clsInputValidate::ReadString<string>();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{ 
			cout << "\nCurrecy is Not Found,Choose another one ? ";
			CurrencyCode = clsInputValidate::ReadString<string>();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static void _PrintCalculationsResualts(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{

		_PrintCurrencyInfo("\nConvert From:", Currency1);
		float AmountUSD = Currency1.CovertToUSD(Amount);
		cout <<Amount << " " << Currency1.CurrencyCode() << " = " << AmountUSD << " USD" << endl;

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}


		cout << "\nConverting From USD To: \n";
		_PrintCurrencyInfo("To: ", Currency2);
		cout << Amount <<" " << Currency1.CurrencyCode() << " = " << Currency1.CovertAnotherCurrencyToUSD(Amount, Currency2)
			<<" " << Currency2.CurrencyCode() << endl;


	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Answer='n';
		float amount;
		

		do {
			system("cls");
			_DrawscreanHeader("\tCurrency Calculator Screen");

			
			clsCurrency Currency1 = GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency Currency2 = GetCurrency("\nPlease Enter Currency2 Code: ");

			cout << "\n\nEnter Amount to Exchange? ";
			amount = clsInputValidate::ReadTypeOfNumber<float>();

			_PrintCalculationsResualts(amount, Currency1, Currency2);

			cout << "\n\nDo You want to perform another calculation? Y/N? ";
			cin >> Answer;
		} while (toupper(Answer) == 'Y');




	}


};

