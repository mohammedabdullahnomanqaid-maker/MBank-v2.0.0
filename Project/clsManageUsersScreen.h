#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
#include<string>

class clsManageUsersScreen:protected clsScreen
{

	enum _enManageUsersMenueOptions {


		eListUsers = 1, eAddUser = 2, eUpdateUser = 3,
		eDeleteUser = 4, eMainMenue = 6,eFindUser=5
	};

	static short _ReadManageUsersMenueOption() {

		short N = 0;
		cout << setw(37) << left << "" << "Choose What do you want to do ? [1 to 6]? ";
		N = clsInputValidate::ReadTypeNumberBetween<short>(1, 6, "Enter Number Between 1 to 6 ? ");

		return N;
     }

	static void _ShowListUsersScreen() 
	{
	/*	cout << "List User here...";*/
		clsListUsersScreen::ShowUsersList();
	}
	static void _ShowAddNewUserScreen() 
	{
		/*cout << "Add New User here...";*/
		clsAddNewUserScreen::ShowAddNewUser();
	}
	static void _ShowUpdateUserScreen() 
	{
		/*cout << "Update User here...";*/
		clsUpdateUserScreen::ShowUpdateUserScreen();

	}
	static void _ShowDeleteUserScreen() {
		/*cout << "Delete User here...";*/
		clsDeleteUserScreen::ShowDeleteUser();

	}
	static void _ShowFindUserScreen() {
		/*cout << "Find User here...";*/
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackToManageUsersMenue()
	{

		cout << "\n\n\tPress any key to go back to Manage Users Menue...";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _PerformManageUsersMenueOption(_enManageUsersMenueOptions ManageUsersMenueOptions)
	{


		switch (ManageUsersMenueOptions)
		{

		case _enManageUsersMenueOptions::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case _enManageUsersMenueOptions::eAddUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case _enManageUsersMenueOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case _enManageUsersMenueOptions::eUpdateUser:
		{
			system("cls");

			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case _enManageUsersMenueOptions::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case _enManageUsersMenueOptions::eMainMenue:
		{
			system("cls");
	
		}


		}

	}


public:

	static void ShowManageUsersMenue()
	{
		system("color 0F");

		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{

			return;

		}

		system("cls");
		_DrawscreanHeader("\t  Manage Users Screen");
		cout << setw(37) << left << " " << "==========================================\n";
		cout << setw(37) << left << " " << "\t\t   Main Menue\n";
		cout << setw(37) << left << " " << "==========================================\n";
		cout << setw(37) << left << " " << "[1] List Users.\n";
		cout << setw(37) << left << " " << "[2] Add New User.\n";
		cout << setw(37) << left << " " << "[3] Update User.\n";
		cout << setw(37) << left << " " << "[4] Delete User.\n";
		cout << setw(37) << left << " " << "[5] Find User.\n";
		cout << setw(37) << left << " " << "[6] Main Menue.\n";
		cout << setw(37) << left << " " << "==========================================\n";

		_PerformManageUsersMenueOption((_enManageUsersMenueOptions)_ReadManageUsersMenueOption());


	}

};

