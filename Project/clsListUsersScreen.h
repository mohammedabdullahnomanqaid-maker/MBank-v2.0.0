#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include<string>
using namespace std;
class clsListUsersScreen:protected clsScreen
{


private:

	static void _PrintUserRecordToLine(clsUser User)
	{ 
		cout << setw(8)<<left<<""<<"| "<<setw(12)<<left << User.UserName;
		cout << "\t| " << left << setw(25) << User.FullName();
		cout << "\t| " << left << setw(12) << User.Phone;
		cout << "\t| " << left << setw(20) << User.Email;
		cout << "\t| " << left << setw(12) << User.Password;
		cout << "\t| " << left << setw(12) << User.Permissions;

	}

public:




	static void ShowUsersList()
	{

		vector<clsUser>vClients = clsUser::GetUsersList();
		string Title = "\t  User List Screen";

		string SubTitle = "\t (" + to_string(vClients.size()) + ") User(s).";

		_DrawscreanHeader(Title, SubTitle);


		cout << "\t__________________________________________________________________________________________________________________\n\n";
		cout << setw(8) << left << "" << "| " << setw(12) << left << "UserName";
		cout << "\t| " << left << setw(25) << "Full Name";
		cout << "\t| " << left << setw(12) << "Phone";
		cout << "\t| " << left << setw(20) << "Email";
		cout << "\t| " << left << setw(12) << "Password";
		cout << "\t| " << left << setw(12) << "Permission";
		cout << "\n\t__________________________________________________________________________________________________________________\n";

		if (vClients.size() == 0)
		{

			cout << "\n\t\t\t\tNo Users Available In the system.";

		}

		for (clsUser& C : vClients)
		{

			_PrintUserRecordToLine(C);
			cout << endl;
		}

		cout << "\t__________________________________________________________________________________________________________________\n\n";

	}







};

