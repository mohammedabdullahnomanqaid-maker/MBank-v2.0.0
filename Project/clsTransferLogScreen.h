#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<string>
using namespace std;
class clsTransferLogScreen :protected clsScreen
{



	static void _PrintTransferLogRecordToLine(clsBankClient::stTransferLogIfo TLInfo)
	{

		cout << "\t| " << left << setw(15) << TLInfo.Date_Time;
		cout << "\t| " << left << setw(10) << TLInfo.AccountNumberFrom;
		cout << "\t| " << left << setw(10) << TLInfo.AccountNumberTo;
		cout << "\t| " << left << setw(10) << TLInfo.Amount;
		cout << "\t| " << left << setw(12) << TLInfo.AccountBalanceFrom;
		cout << "\t| " << left << setw(12) << TLInfo.AccountBalanceTo;
		cout << "\t| " << left << setw(10) << TLInfo.Username;

	}

	static void _HeaderTransferLogScreen()
	{


		cout << "\t______________________________________________________________________________________________________________\n\n";
		cout << "\t| " << left << setw(15) << "Date/Time";
		cout << "\t| " << left << setw(10) << "s.Acct";
		cout << "\t| " << left << setw(10) << "d.Acct";
		cout << "\t| " << left << setw(10) << "Amount";
		cout << "\t| " << left << setw(12) << "s.Balance";
		cout << "\t| " << left << setw(12) << "d.Balance";
		cout << "\t| " << left << setw(10) << "User";
		cout << "\n\t______________________________________________________________________________________________________________\n";

	}

public:
	static void ShowTransferLogScreen()
	{

		vector<clsBankClient::stTransferLogIfo>TLV = clsBankClient::GetTransferLogInfo();

		string Title, SubTitle;
		Title = "Transfer Log List Screen";
		SubTitle = "\t(" + to_string(TLV.size()) + ") Record(s).";

		_DrawscreanHeader(Title,SubTitle);

		_HeaderTransferLogScreen();


		if (TLV.size() == 0)
		{

			cout << "\n\t\t\t\tNo Transfer Log Available In the system.";

		}
		else {
			for (clsBankClient::stTransferLogIfo& C : TLV)
			{

				_PrintTransferLogRecordToLine(C);
				cout << endl;
			}
		}
		cout << "\t________________________________________________________________________________________________________________\n\n";


	}

};

