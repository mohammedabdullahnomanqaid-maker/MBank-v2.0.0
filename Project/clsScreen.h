#pragma once
#include<iostream>
#include"Global.h"
#include<iomanip>
#include"clsUser.h"
#include"clsDate.h"
using namespace std;

class clsScreen
{



protected:

	static void _DrawscreanHeader(string Title, string SubTitle = "")
	{

		cout << setw(37) << left << " " << "  ______________________________________\n\n";
		cout << setw(37) << left << " \t" << Title << endl;

		if (SubTitle != "")
		{

			cout << setw(37) << left << " \t" << SubTitle << endl;

		}

		cout << setw(37) << left << " " << "  ______________________________________\n\n";

		
		cout << "\t\t\t\t\tUser: " << CurrentUser.UserName << endl;
		cout << "\t\t\t\t\t\Date: " << clsDate::DateToString(clsDate()) << "\n\n";
	}

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{

		if (!CurrentUser.CheckAccessPermission(Permission))
		{

			cout << setw(37) << left << " " << "  ______________________________________\n\n";
			cout << setw(37) << left << " \t" << "Access Denied! Contact You Admin" << endl;
			cout << setw(37) << left << " " << "  ______________________________________\n\n";

			return false;
		}


		else
			return true;
	}

};

