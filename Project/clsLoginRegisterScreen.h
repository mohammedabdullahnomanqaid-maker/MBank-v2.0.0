#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;
class clsLoginRegisterScreen:protected clsScreen
{




	static void _PrintRecordLoginRegister(clsUser::stLoginRegister User)
	{
		cout << "\t| " << left << setw(40) << User.Date_Time;
		cout << "\t| " << left << setw(20) << User.UserName;
		cout << "\t| " << left << setw(12) << User.Password;
		cout << "\t| " << left << setw(12) << User.Permission;

	}

public:

	

	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{

			return;

		}
		vector<clsUser::stLoginRegister>vLoginUser=clsUser::GetLoginRegisterList();


		string Tital = "  Login Register  List Screen";

		string SubTital = "\t  (" + to_string(vLoginUser.size()) + ")  Record(s).";

		_DrawscreanHeader(Tital, SubTital);

		cout << "\t__________________________________________________________________________________________________________\n\n";
		cout << "\t| " << left << setw(40) << "Date/Time";
		cout << "\t| " << left << setw(20) << "User Name";
		cout << "\t| " << left << setw(12) << "Password";
		cout << "\t| " << left << setw(12) << "Permissions";
		cout << "\n\t__________________________________________________________________________________________________________\n";


		if (vLoginUser.size() == 0)
		{

			cout << "\n\t\t\tNo Users Available in the system.";

		}

		for (clsUser::stLoginRegister& C : vLoginUser)
		{

			_PrintRecordLoginRegister(C);
			cout << endl;

		}

		cout << "\t__________________________________________________________________________________________________________\n";
		

	}







};

