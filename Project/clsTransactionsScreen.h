#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<string>
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalanceScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
using namespace std;
class clsTransactionsScreen:protected clsScreen
{


	enum _enTransacionsMenueOptions {

		eDeposit = 1, eWithDarw = 2, 
		eShowTotalBalance = 3, eShowMainMenue = 6,
		eTransfer=4,eTransferLog=5
	};

	static void _ShowDepositScreen()
	{
		/*cout << " Deposit Here...";*/
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		/*cout << " Withdraw Here...";*/
		clsWithdrawScreen::ShowWithdrawScreen();

	}

	static void _ShowTotalBalancesScreen()
	{
	/*	cout << " Total Balance Here...";*/
		clsTotalBalanceScreen::ShowTotalBalances();
	}

	static void _ShowTransferLogScreen()
	{
		/*cout << "Is Here..";*/
		clsTransferLogScreen::ShowTransferLogScreen();

	}

	static void _GoBackToTransacionsMenue()
	{

		cout << "\n\n\tPress any key to go back to Transacion Menue...";
		system("pause>0");
		ShowTransactionsMenue();
	}

	static short _ReadTransacionsMenueOption(){

        short N = 0;
		cout << setw(37) << left << "" << "Choose What do you want to do ? [1 to 6]? ";
		N = clsInputValidate::ReadTypeNumberBetween<short>(1, 6, "Enter Number Between 1 to 6 ? ");

		return N;
	

	}
	static void _ShowTransferScreen()
	{
		//cout << "Is Here...";
		clsTransferScreen::ShowTransferScreen();

	}

	static void _PerformTransacionMenue(_enTransacionsMenueOptions TransacionsMenueOptions)
	{


		switch (TransacionsMenueOptions)
		{

		case _enTransacionsMenueOptions::eDeposit:
		{

			system("cls");
			_ShowDepositScreen();
			_GoBackToTransacionsMenue();
			break;
		}

		case _enTransacionsMenueOptions::eWithDarw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransacionsMenue();
			break;

		}

		case _enTransacionsMenueOptions::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransacionsMenue();

			break;

		}

		case _enTransacionsMenueOptions::eTransfer:
		{
			system("cls");

			_ShowTransferScreen();

			_GoBackToTransacionsMenue();
			break;

		}
		case _enTransacionsMenueOptions::eTransferLog:
		{
			system("cls");

			_ShowTransferLogScreen();
			_GoBackToTransacionsMenue();
			break;

		}
		
		case _enTransacionsMenueOptions::eShowMainMenue:
		{
			system("cls");
				break;
		}


		}

	}


public:

	static void ShowTransactionsMenue()
	{


		if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
		{

			return;

		}

		system("cls");
		_DrawscreanHeader("\t  Transaction Screen");
		cout << setw(37) << left << " " << "==========================================\n";
		cout << setw(37) << left << " " << "\t\t   Main Menue\n";
		cout << setw(37) << left << " " << "==========================================\n";
		cout << setw(37) << left << " " << "[1] Deposit.\n";
		cout << setw(37) << left << " " << "[2] Withdraw.\n";
		cout << setw(37) << left << " " << "[3] Total Balance.\n";
		cout << setw(37) << left << " " << "[4] Transfer.\n";
		cout << setw(37) << left << " " << "[5] Transfer Log.\n";
		cout << setw(37) << left << " " << "[6] Main Menue.\n";
		cout << setw(37) << left << " " << "==========================================\n";

		_PerformTransacionMenue((_enTransacionsMenueOptions)_ReadTransacionsMenueOption());

			
	}


};

