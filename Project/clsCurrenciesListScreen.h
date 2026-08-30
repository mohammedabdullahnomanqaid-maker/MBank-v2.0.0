#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"clsCurrency.h"
#include<iomanip>
#include"clsScreen.h"
using namespace std;
class clsCurrenciesListScreen:protected clsScreen
{

	static void _PrintCurrenciesList(clsCurrency Currency)
	{

		cout << "\t| " << left << setw(40) << Currency.Country();
		cout << "| " << left << setw(10) << Currency.CurrencyCode();
		cout << "| " << left << setw(40) << Currency.CurrencyName();
		cout << "| " << left << setw(10) << Currency.Rate();

	}

public:

	static void ShowCurrrenciesListScreen()
	{


		vector<clsCurrency>VC = clsCurrency::GetCurrenciesInfo();

		string Title, SubTitle;

		Title = "Currencies List Screen";
		SubTitle = "\t(" + to_string(VC.size()) + ") Currency";

		_DrawscreanHeader(Title, SubTitle);

		cout << "\t_____________________________________________________________________________________________________________\n\n";
		cout << "\t| " << left << setw(40) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << "\n\t_____________________________________________________________________________________________________________\n\n";

		if (VC.size() == 0)
		{

			cout << "\n\t\t\t\tNo Currencies Available in system.";
		

		}
		else
		for (clsCurrency& C : VC)
		{

			_PrintCurrenciesList(C);
			cout << endl;

		}

		cout << "\n\t_____________________________________________________________________________________________________________\n\n";


	}









};

