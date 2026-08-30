#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<string>
using namespace std;
class clsDepositScreen:protected clsScreen
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

	static void ShowDepositScreen()
	{


		_DrawscreanHeader("\t  Deposit Screen.");

		string AccountNumber;
		cout << "Please Enter Account Number ? ";
		AccountNumber = clsInputValidate::ReadString<string>();

		while (!clsBankClient::IsClientEixst(AccountNumber))
		{

			cout << "\nAccount Client With ["<<AccountNumber<<"] does not Exist.\n";
			cout << "Please Enter Account Number ?";
			AccountNumber = clsInputValidate::ReadString<string>();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);


		double Amount=0;
		cout << "\nPlease Enter Deposit Amount? ";
		Amount = clsInputValidate::ReadTypeOfNumber<double>();

		char Answer = 'N';
		cout << "\n\nAre you sure,you want to Perform this Transaction ? Y/N ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y') 
		{
			Client.Deposit(Amount);

			cout << "\nAmount Deposited Sccessfully.\n";
			cout << "\nNew Balance Is: " << Client.AccountBalance << endl;

		}

		else
		{

			cout << "\nOperation was Cancelled.\n";
		}

	}







};

