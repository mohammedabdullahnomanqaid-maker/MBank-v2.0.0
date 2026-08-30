#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<string>
class clsTotalBalanceScreen:protected clsScreen
{


	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << "\t| " << left << setw(16) << Client.AccountNumber();
		cout << "\t| " << left << setw(40) << Client.FullName();
		cout << "\t| " << left << setw(12) << Client.AccountBalance;

	}
public:

  static void ShowTotalBalances()
	{
		vector<clsBankClient>vClients = clsBankClient::GetClientsList();


		string Tital = "\t  Balance List"; 

	  string SubTital = "\t  ("+to_string(vClients.size()) + ")  Client(s).";
	
	  _DrawscreanHeader(Tital,SubTital);

		cout << "\t__________________________________________________________________________________________________________\n\n";
		cout << "\t| " << left << setw(16) << "Account Number";
		cout << "\t| " << left << setw(40) << "Client Name";
		cout << "\t| " << left << setw(12) << "Balance";
		cout << "\n\t__________________________________________________________________________________________________________\n";


		if (vClients.size() == 0)
		{

			cout << "\n\t\t\tNo Clients Available in the system.";

		}

		for (clsBankClient& C : vClients)
		{

			_PrintClientRecordBalanceLine(C);
			cout << endl;

		}

		cout << "\t__________________________________________________________________________________________________________\n";
		cout << "\t\t\t\t\tTotal Balance= " << clsBankClient::GetTotalBalances() << endl;
		cout << "\t\t\t (" << clsBankClient::NumberToText(clsBankClient::GetTotalBalances()) << ")" << endl;


	}



};

