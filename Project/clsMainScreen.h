#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsShowAddNewClient.h"
#include"clsDeleteClientScreen.h"
#include"clsShowUpdateClientScreen.h"
#include"clsShowFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyMainMenue.h"
#include"Global.h"
#include"clsUser.h"
class clsMainScreen:protected clsScreen
{

private:


	enum _enMainMenuOptions 
	{
		eListClients=1,eAddClient=2,eDeleteClient=3,eUpdateClient=4,
		eFindClient=5,eShowTransactionMenue=6,eMangeUser=7,eLoginRegister=8,
		eCurrencyExchange=9,Exit=10
	};

	static short _ReadMainMenueOption()
	{

		short N = 0;
		cout << setw(37) << left <<"" << "Choose What do you want to do ? [1 to 10]? ";
		N = clsInputValidate::ReadTypeNumberBetween<short>(1, 10, "Enter Number Between 1 to 10? ");

		return N;


}

	static void _GoBackToMainMenue()
	{

		cout << "\n\n\tPress any key to go back to Main Menue...";
		system("pause>0");
		MainMenuScreen();

	}

	static void _ShowAllClientsScreen()
	{
		/*cout << "\nClient Lists Will be Here...";*/
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen()
	{
		/*cout << "Add New Client will be here...";*/
		clsShowAddNewClient::AddNewClient();

	}


	static void _ShowUpdateClientsScreen()
	{

		clsShowUpdateClientScreen::UpdateClient();

	}
	static void _ShowCurrencyExchangeScreen()
	{
		/*cout << "is Here..";*/
		clsCurrencyMainMenue::ShowCurrencyMainMenue();
	}
	static void _ShowFindClientScreen()
	{
		/*cout << "Find Client will be here...";*/
		clsShowFindClientScreen::ShowFindClientScreen();
	}
	static void _ShowDeleteClientsScreen()
	{
		clsDeleteClientScreen::DeleteClient();
	}

	static void _ShowTransactionsMenue()
	{
		//cout << "Transaction Main Menue will be here...";

		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void _ShowLogInRegisterScreen()
	{

		clsLoginRegisterScreen::ShowLoginRegisterScreen();

	}
	static void _ShowManageUsersMenue()
	{
		/*cout << "Manage Users will be here...";*/
		clsManageUsersScreen::ShowManageUsersMenue();
	}



	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void _PerformMainMenueOption(_enMainMenuOptions MainMenuOptions)
	{


		switch (MainMenuOptions)
		{


		case _enMainMenuOptions::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case _enMainMenuOptions::eAddClient:
		{
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		}

		case _enMainMenuOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientsScreen();
			_GoBackToMainMenue();
			break;
		}


		case _enMainMenuOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		}

		case _enMainMenuOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientsScreen();
			_GoBackToMainMenue();
			break;
		}

		case _enMainMenuOptions::eShowTransactionMenue:
		{
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenue();
			break;
		}
		case _enMainMenuOptions::eMangeUser:
		{
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;
		}
		
		case _enMainMenuOptions::eLoginRegister:
		{
			system("cls");
			_ShowLogInRegisterScreen();
			_GoBackToMainMenue();
			break;
		}
		

		case _enMainMenuOptions::eCurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenue();
			break;
		}

		case _enMainMenuOptions::Exit:
		{
			system("cls");
			_Logout();

			break;
		}


		}



	}

public:


	static void MainMenuScreen()
	{

		system("cls");
		_DrawscreanHeader("\t  Main Screen");
		cout << setw(37) << left <<" " << "==========================================\n";
		cout << setw(37) << left << " " << "\t\t   Main Menue\n";
		cout << setw(37) << left << " " << "==========================================\n";
		cout << setw(37) << left << " " << "[1] Show Client List.\n";
		cout << setw(37) << left << " " << "[2] Add New Client.\n";
		cout << setw(37) << left << " " << "[3] Delete Client.\n";
		cout << setw(37) << left << " " << "[4] Update Client.\n";
		cout << setw(37) << left << " " << "[5] Find Client.\n";
		cout << setw(37) << left << " " << "[6] Transactions.\n";
		cout << setw(37) << left << " " << "[7] Mange Users.\n";
		cout << setw(37) << left << " " << "[8] Login Registre.\n";
		cout << setw(37) << left << " " << "[9] Currency Exchange.\n";
		cout << setw(37) << left << " " << "[10] Logout.\n";
		cout << setw(37) << left << " " << "==========================================\n";
		_PerformMainMenueOption(_enMainMenuOptions(_ReadMainMenueOption()));
		
	}


};

