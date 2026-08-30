#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include<string>
using namespace std;
class clsUpdateUserScreen:protected clsScreen
{

	static void _ReadUserInfo(clsUser& Uuser)
	{
		cout << "\nEnter FirstName: ";
		Uuser.FirstName = clsInputValidate::ReadString<string>();

		cout << "\nEnter LastName: ";
		Uuser.LastName = clsInputValidate::ReadString<string>();

		cout << "\nEnter Email: ";
		Uuser.Email = clsInputValidate::ReadString<string>();

		cout << "\nEnter Phone: ";
		Uuser.Phone = clsInputValidate::ReadString<string>();

		cout << "\nEnter Password: ";
		Uuser.Password = clsInputValidate::ReadString<string>();

		Uuser.Permissions = _ReadPermission();

	}

	static short _ReadPermission()
	{
		short Per = 0;
		char Answer = 'h';
		cout << "\n\nDo you want to give full access? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
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

	static void ShowUpdateUserScreen()
	{
	
		_DrawscreanHeader("\t  Update User Screen");
		string UserN;
		cout << "Please Enter UserName? ";
		UserN = clsInputValidate::ReadString<string>();

		while (!clsUser::IsUserExist(UserN))
		{
			cout << "This User is Not found,try another one? ";
			UserN = clsInputValidate::ReadString<string>();
		}

		clsUser Uuser = clsUser::Find(UserN);
		_PrintClient(Uuser);

		char Answer = 'y';
		cout << "Are you sure ,you want to Update this User? Y/N? ";
		cin >> Answer;
		clsUser::enSaveResults SaveResult;


		if (toupper(Answer) == 'Y')
		{
			cout << "\n\nUpdate Info.";
			cout << "\n______________________\n";

			_ReadUserInfo(Uuser);
			SaveResult=Uuser.Save();

			switch (SaveResult)
			{

			case clsUser::enSaveResults::svSucceeded:
			{
				cout << "\n\nUser Updated Successflly :-)";
			_PrintClient(Uuser);
				break;
			}

			case clsUser::enSaveResults::svFaildEmptyObject:
			{
				cout << "\n\nUser was Not Updated ,becoude User Object is Empty.";
				break;
			}

			}
		}
		else
		{
			cout << "\n\nThe Operation was Cancelled.";
		
		}




	}



};

