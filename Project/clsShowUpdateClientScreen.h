#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsShowUpdateClientScreen :protected clsScreen
{


	static void _ReadClientInfo(clsBankClient& Client)
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


	static void UpdateClient()
	{


		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
		{

			return;

		}

		_DrawscreanHeader("\t  Update Client.");

		string AccountNumber;
		cout << "Please Enter Client Account Number : ";
		AccountNumber = clsInputValidate::ReadString<string>();

		while (!clsBankClient::IsClientEixst(AccountNumber))
		{

			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString<string>();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		char Answer = 'N';
		cout << "\n\nAre you sure,you want to Update this Client? Y/N ? ";
		cin >> Answer;

		if(toupper(Answer)=='Y'){

		cout << "\n\nUpdate Client Info .";
		cout << "\n______________________\n";
		_ReadClientInfo(Client);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = Client.Save();

		switch (SaveResult)
		{

		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\n\nAccount Update Successfully :-).";
			_PrintClient(Client);
			break;

		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{

			cout << "\n\nError account was not saved ,becouse it is Empty.";
			break;
		}
		}

		}
	}







};

