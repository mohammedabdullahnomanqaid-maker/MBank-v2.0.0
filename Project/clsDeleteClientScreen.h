#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsDeleteClientScreen :protected clsScreen
{


	static void PrintClient(clsBankClient DeleteClient)
	{
		cout << "\n\nClient Card:\n";
		cout << "_______________________________\n";
		cout << "FirstName   : " << DeleteClient.FirstName << endl;
		cout << "LastName    : " << DeleteClient.LastName << endl;
		cout << "FullName    : " << DeleteClient.FullName() << endl;
		cout << "Email       : " << DeleteClient.Email << endl;
		cout << "Phone       : " << DeleteClient.Phone << endl;
		cout << "Acc. Number : " << DeleteClient.AccountNumber() << endl;
		cout << "PassWord    : " << DeleteClient.PinCode << endl;
		cout << "Balance     : " << DeleteClient.AccountBalance << endl;
		cout << "__________________________\n";
	}


public:
	static void DeleteClient()
	{


		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{

			return;

		}

		_DrawscreanHeader("\t  Delete Client.");

		string AccountNumber = "";
		cout << "Please Enter Account Number: ";

		AccountNumber = clsInputValidate::ReadString<string>();


		while (!clsBankClient::IsClientEixst(AccountNumber))
		{

			cout << "\nAccount Number Is Not found,try another one: ";
			AccountNumber = clsInputValidate::ReadString<string>();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		PrintClient(Client);

		char Answer = 'N';
		cout << "\n\nAre you sure,you want to delete this Client? Y/N ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{

			if (Client.Delete())
			{
				cout << "\n\nCleint Deleted Successfully :-) ";
				PrintClient(Client);
			}

			else
			{
				cout << "\n\nError Client was Not Deleted :-( ";
			}

		}


	}


};

