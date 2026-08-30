#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<string>
using namespace std;

class clsWithdrawScreen :protected clsScreen
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

	static void ShowWithdrawScreen()
	{


		_DrawscreanHeader("\t  Withdraw Screen.");

		string AccountNumber;
		cout << "Please Enter Account Number ? ";
		AccountNumber = clsInputValidate::ReadString<string>();

		while (!clsBankClient::IsClientEixst(AccountNumber))
		{

			cout << "\nAccount Client With [" << AccountNumber << "] does not Exist.\n";
			cout << "Please Enter Account Number ?";
			AccountNumber = clsInputValidate::ReadString<string>();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);


		double Amount = 0;
		cout << "\nPlease Enter Withdraw Amount? ";
		Amount = clsInputValidate::ReadTypeOfNumber<double>();


		char Answer = 'N';
		cout << "\n\nAre you sure,you want to Perform this Transaction ? Y/N ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\nAmount Withdraw Sccessfully.\n";
				cout << "\nNew Balance Is: " << Client.AccountBalance << endl;
			}


			else
			{

				cout << "\nCannot withdrew , Insuffecient Balance! \n";
				cout << "Account to withdraw is: " << Amount;
				cout << "\nYour Balance Is : " << Client.AccountBalance;

			}
		}

		else
		{

			cout << "\nOperation was Cancelled.\n";
		}

	}







};



