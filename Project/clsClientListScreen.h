#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include<string>
using namespace std;

class clsClientListScreen:protected clsScreen
{

private:

	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout << "\t| " << left << setw(16) << Client.AccountNumber();
		cout << "\t| " << left << setw(20) << Client.FullName();
		cout << "\t| " << left << setw(12) << Client.Phone;
		cout << "\t| " << left << setw(20) << Client.Email;
		cout << "\t| " << left << setw(12) << Client.PinCode;
		cout << "\t| " << left << setw(12) << Client.AccountBalance;

	}

public:


	static void ShowClientsList()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{

			return;

		}

		vector<clsBankClient>vClients = clsBankClient::GetClientsList();
		string Title = "\t  Client List";

		string SubTitle  = "\t (" + to_string (vClients.size() )+ ") Client(s).";

		_DrawscreanHeader(Title, SubTitle);


		cout << "\t__________________________________________________________________________________________________________________\n\n";
		cout << "\t| " << left << setw(16) << "Account Number";
		cout << "\t| " << left << setw(20) << "Client Name";
		cout << "\t| " << left << setw(12) << "Phone";
		cout << "\t| " << left << setw(20) << "Email";
		cout << "\t| " << left << setw(12) << "Pin Code";
		cout << "\t| " << left << setw(12) << "Balance";
		cout << "\n\t__________________________________________________________________________________________________________________\n";

		if (vClients.size() == 0)
		{

			cout << "\n\t\t\t\tNo Clients Available in system.";

		}

		for (clsBankClient& C : vClients)
		{

			_PrintClientRecordLine(C);
			cout << endl;
		}

		cout << "\t__________________________________________________________________________________________________________________\n\n";

	}





};

