#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include<string>
using namespace std;

class clsDeleteUserScreen:protected clsScreen
{



	static void _PrintClient(clsUser NewClient)
	{
		cout << "\n\nUser Card:\n";
		cout << "_______________________________\n";
		cout << "FirstName   : " << NewClient.FirstName << endl;
		cout << "LastName    : " << NewClient.LastName << endl;
		cout << "FullName    : " << NewClient.FullName() << endl;
		cout << "Email       : " << NewClient.Email << endl;
		cout << "Phone       : " << NewClient.Phone << endl;
		cout << "UserName    : " << NewClient.UserName << endl;
		cout << "PassWord    : " << NewClient.Password << endl;
		cout << "Permission  : " << NewClient.Permissions << endl;
		cout << "__________________________\n";
	}
public:
	static void ShowDeleteUser()
	{

		_DrawscreanHeader("\t  Delete User Screen");
		string UserN;
		cout << "Please Enter UserName? ";
		UserN = clsInputValidate::ReadString<string>();

		while (!clsUser::IsUserExist(UserN))
		{
			cout << "This User is Not found,try another one? ";
			UserN = clsInputValidate::ReadString<string>();
		}

		if (clsUser::_IsAdmin(UserN))
		{
			system("color 4F");
			cout << "\n\n\t\t\t\t=================================================================\n";
			cout << "\t\t\t\tError!!!,You Can Not Delete this User ,becouse it's the Admin !";
			cout << "\n\t\t\t\t=================================================================\n";
			return;
		}
		clsUser DUser = clsUser::Find(UserN);
		
		_PrintClient(DUser);
		char Answer = 'j';
		cout << "\n\nAre you sure,you want to Delete this User Y/N? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{

			if (DUser.Delete())
			{
				cout << "\nUser Deleted Successfully :-).";
				_PrintClient(DUser);
			}
			else
			{

				cout << "\n\nError User was Not Deleted.";
			}
		}
		else
		cout << "\n\nThe Operantion was Cancelled.";


	}


};

