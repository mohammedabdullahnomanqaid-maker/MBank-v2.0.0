#pragma once
#include<iostream>
#include"clsScreen.h"
#include<string>
#include"clsInputValidate.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCurrencyCalculator.h"
class clsCurrencyMainMenue:protected clsScreen
{

	enum eCurrencyMainMenueOptions {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate= 3,
		eCurrencyCalculator = 4, eMainMenue = 5
	};


	static void _GoBackToCurrencyMainMenue()
	{
		cout << "\n\n\tPress any key to go back to Currency Menue...";
		system("Pause>0");
		ShowCurrencyMainMenue();
	}
	static short _ReadCurrencyMainMenueOption() {

		short N = 0;
		cout << setw(32) << left << "" << "Choose What do you want to do ? [1 to 5]? ";
		N = clsInputValidate::ReadTypeNumberBetween<short>(1, 5, "Enter Number Between 1 to 5 ? ");

		return N;
	}

	static void _ShowCurrenciesListScreen()
	{
		/*cout << "List Is Here...";*/
		clsCurrenciesListScreen::ShowCurrrenciesListScreen();
	}
	static void _ShowFindCurrencyScreen()
	{
		//cout << "Find Is Here...";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateRateScreen()
	{
		/*cout << "Update Is Here...";*/
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		/*cout << "Currency Calculator Is Here...";*/
		clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrrencyMainMenueOptions(eCurrencyMainMenueOptions CurrencyMainMenueOption)
	{


		switch (CurrencyMainMenueOption)
		{


		case eCurrencyMainMenueOptions::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyMainMenue();

		}


		case eCurrencyMainMenueOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMainMenue();

		}



		case eCurrencyMainMenueOptions::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyMainMenue();

		}


		case eCurrencyMainMenueOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyMainMenue();

		}


		case eCurrencyMainMenueOptions::eMainMenue:
		{
			system("cls");
		
		}

		}


	}

public:


	static void ShowCurrencyMainMenue()
	{

		system("cls");

		_DrawscreanHeader("Currency Exchange Main Screen");

		

		cout << setw(32) << left<<"" << "==================================================\n";
		cout << setw(32) << left << "" << "\t   Currency Exchange Menue\n";
		cout << setw(32) << left << "" << "==================================================\n";
		cout << setw(32) << left << "" << "[1] List Currencies.\n";
		cout << setw(32) << left << "" << "[2] Find Currency.\n";
		cout << setw(32) << left << "" << "[3] Update Rate.\n";
		cout << setw(32) << left << "" << "[4] Currency Calculator.\n";
		cout << setw(32) << left << "" << "[5] Main Menue.\n";
		cout << setw(32) << left << "" << "==================================================\n";
		_PerformCurrrencyMainMenueOptions((eCurrencyMainMenueOptions)_ReadCurrencyMainMenueOption());






	}





};

