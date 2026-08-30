#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"

#include"clsInputValidate.h"
#include<string>
using namespace std;
class clsTransferScreen:protected clsScreen
{




	static void _PrintClient(clsBankClient Client)
	{

		cout << "\n\nClient Card:\n";
		cout << "_______________________________\n";
        cout << "FullName     : " << Client.FullName() << endl;
		cout << "Acc. Number  : " << Client.AccountNumber() << endl;
		cout << "Balance      : " << Client.AccountBalance << endl;
		cout << "__________________________\n";


	}



	static string _ReadAccountNumber(string Message)
	{


		cout << "Please Enter Account Number to Transfer " << Message;

		string Account;
		Account= clsInputValidate::ReadString<string>();
		while (!clsBankClient::IsClientEixst(Account))
		{

			cout << "\n\nThis Account Not found,try another One: ";
			Account= clsInputValidate::ReadString<string>();

		}

		return Account;
	}


	static double _ReadAmount(clsBankClient TransferFromClient)

	{


		double amount;
		cout << "\n\nEnter Transfer Amount? ";
		amount = clsInputValidate::ReadTypeOfNumber<double>();




		while (amount > TransferFromClient.AccountBalance)
		{

			cout << "\n\nAmount Exceeds the available Balance,Enter another Amount? ";
			amount = clsInputValidate::ReadTypeOfNumber < double> ();

		}
		
		 
		return amount;
	}


public:

	static void ShowTransferScreen()
	{

		_DrawscreanHeader("\t Transfer Screen");
	
		clsBankClient TransferFromClient = clsBankClient::Find(_ReadAccountNumber("From : "));
		_PrintClient(TransferFromClient);

		clsBankClient TransferToClient = clsBankClient::Find(_ReadAccountNumber("To : "));
		_PrintClient(TransferToClient);

		double amount = _ReadAmount(TransferFromClient);

		char Answer = 'h';
		cout << "Are you sure ,you want to perform this Operation? Y/N? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{

			if (TransferFromClient.Transfer(amount, TransferToClient,CurrentUser.UserName))
			{

			cout << "\n\nTransfer done Successfully.\n";

			_PrintClient(TransferFromClient);
			 
			_PrintClient(TransferToClient);

			}

			else
			{
				cout << "\n\nThe Transfer faild.";
			}


		}
		else
		{
			cout << "\n\n The Operation was Cancelled.";
		}




	}












};

