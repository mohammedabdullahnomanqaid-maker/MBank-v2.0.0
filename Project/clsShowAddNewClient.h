#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;

class clsShowAddNewClient:protected clsScreen
{

private:
	static void ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString<string>();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadString<string>();
		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString<string>();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString<string>();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString<string>();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadTypeOfNumber<float>();
	}

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


	static void AddNewClient()
	{


		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{

			return;

		}

		_DrawscreanHeader("\t  Add New Client.");

		string AccountNumber;
		cout << "Please Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString<string>();

		while (clsBankClient::IsClientEixst(AccountNumber))
		{

			cout << "\nAccount Number Is Already Used,try another one: ";
			AccountNumber = clsInputValidate::ReadString<string>();
		}

		cout << "\n______________________\n";
		clsBankClient NewClient = clsBankClient::AddNewClient(AccountNumber);
		ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{

		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\n\nAccount Added Successfully :-).";
			_PrintClient(NewClient);
			break;

		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{

			cout << "\n\nError account was not saved ,becouse it is Empty.";

		}
		case clsBankClient::enSaveResults::svFailAccountNumberExists:
		{
			cout << "\n\nError account was not saved ,becoude  Acount Number is Used.";
			break;

		}
		}
	}



};

