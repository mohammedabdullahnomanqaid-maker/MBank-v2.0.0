#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<string>
using namespace std;

class clsShowFindClientScreen:protected clsScreen
{

	static void _PrintClient(clsBankClient NewClient)
	{
		cout << "\n\nClient Card:\n";
		cout << "_______________________________\n";
		cout << "FirstName   : " << NewClient.FirstName << endl;
		cout << "LastName    : " << NewClient.LastName << endl;
		cout << "FullName    : " << NewClient.FullName() << endl;
		cout << "Email       : " << NewClient.Email << endl;
		cout << "Phone       : " << NewClient.Phone << endl;
		cout << "Acc. Number : " << NewClient.AccountNumber() << endl;
		cout << "PassWord    : " << NewClient.PinCode << endl;
		cout << "Balance     : " << NewClient.AccountBalance << endl;
		cout << "__________________________\n";
	}


public:

	static void ShowFindClientScreen()
	{


		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{

			return;

		}


		_DrawscreanHeader("\t  Find Client.");

		string AccountNumber;
		cout << "Please Enter Client Account Number : ";
		AccountNumber = clsInputValidate::ReadString<string>();

		while (!clsBankClient::IsClientEixst(AccountNumber))
		{

			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString<string>();
		}


		clsBankClient Client = clsBankClient::Find(AccountNumber);


		if (!Client.IsEmpty())
		{

			cout << "\nClient Found :-)\n";
		}
		else
		{

			cout << "\nClient was Not Found\n";

		}

		_PrintClient(Client);
	}


};

