#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include<string>
using namespace std;

class clsFindUserScreen:protected clsScreen
{




	static void _PrintUser(clsUser NewClient)
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


	static void ShowFindUserScreen()
	{

		_DrawscreanHeader("\t  Find User Screen");
		string UserN;
		cout << "Please Enter UserName? ";
		UserN = clsInputValidate::ReadString<string>();

		while (!clsUser::IsUserExist(UserN))
		{
			cout << "This User is Not found,try another one? ";
			UserN = clsInputValidate::ReadString<string>();
		}

		clsUser Uuser = clsUser::Find(UserN);

		if (!Uuser.IsEmpty()) {

			cout << "\n User Found :-).\n";
		_PrintUser(Uuser);

		}
		else
		{
			cout << "\n\nUser was Not Found:-(";
		}


	}



};

