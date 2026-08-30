#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include<string>
using namespace std;
class clsAddNewUserScreen:protected clsScreen
{

	static void _ReadUserInfo(clsUser& Client)
	{
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString<string>();
		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadString<string>();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString<string>();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString<string>();

		cout << "\nEnter Password: ";
		Client.Password = clsInputValidate::ReadString<string>();

		Client.Permissions= _ReadPermission();

	} 

	static short _ReadPermission()
	{
		short Per = 0;
		char Answer = 'h';
		cout << "\n\nDo you want to give full access? Y/N? ";
		cin >> Answer;
		if (toupper(Answer)=='Y')
		{
			return clsUser::enPermissions::eAll;
		}


		cout << "\n\nDo you want to give access to : ";

		cout << "\n\nShow Client List? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Per += clsUser::enPermissions::pListClients;
		}

		cout << "\n\nAdd New Client? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Per += clsUser::enPermissions::pAddNewClient;
		}
		cout << "\n\nUpdate Client? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Per += clsUser::enPermissions::pUpdateClient;
		}
		cout << "\n\Delete Client? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Per += clsUser::enPermissions::pUpdateClient;
		}
		cout << "\n\Find Client? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Per += clsUser::enPermissions::pFindClient;
		}
		
		cout << "\n\Transactions? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Per += clsUser::enPermissions::pTransactions;
		}
		cout << "\n\nManage Users? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Per += clsUser::enPermissions::pUpdateClient;
		}
		cout << "\n\nLogin Register? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Per += clsUser::enPermissions::pLoginRegister;
		}
		return Per;

	}
	static void _PrintClient(clsUser NewClient)
	{
		cout << "\n\nUser Card:\n";
		cout << "_______________________________\n";
		cout << "FirstName   : " << NewClient.FirstName << endl;
		cout << "LastName    : " << NewClient.LastName << endl;
		cout << "FullName    : " << NewClient.FullName() << endl;
		cout << "Email       : " << NewClient.Email << endl;
		cout << "Phone       : " << NewClient.Phone << endl;
		cout << "UserName    : " << NewClient.UserName << endl;
		cout << "PassWord    : " << NewClient.Password << endl;
		cout << "Permission  : " << NewClient.Permissions << endl;
		cout << "__________________________\n";
	}


public:

	static void ShowAddNewUser()
	{
		_DrawscreanHeader("\t  Add New User Screen");
		string UserN;
		cout << "Please Enter UserName? ";
		UserN = clsInputValidate::ReadString<string>();

		while (clsUser::IsUserExist(UserN))
		{
			cout << "This User Name Already Used,try another one? ";
			UserN = clsInputValidate::ReadString<string>();
		}

		clsUser NewUser = clsUser::AddNewUser(UserN);
		_ReadUserInfo(NewUser);


		clsUser::enSaveResults SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult)
		{

		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "\n\nUser Added Successfully :-).";
			_PrintClient(NewUser);
			break;

		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{

			cout << "\n\nError User was not saved ,becouse it is Empty.";

		}
		case clsUser::enSaveResults::svFailAccountNumberExists:
		{
			cout << "\n\nError User was not saved ,becoude  UserName is Used.";
			break;

		}
		}
	}


};
