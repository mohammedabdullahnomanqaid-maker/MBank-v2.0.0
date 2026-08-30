#pragma once
#include<iostream>
#include"clsMainScreen.h"
#include"clsUser.h"
#include"Global.h"
class clsLoginScreern:protected clsScreen
{








	static bool _Login()

	{

		bool FailLogin = false;
		short Trials = 0;
		string UserName, Password;

		
		do {
			

			if (FailLogin)
			{
				Trials++;
				cout << "\nInvalid UserName/Password";
				cout << "\nYou have " <<3-Trials << " Trial(s) to login.\n\n";
				
			}
		
			if (Trials == 3)
			{
				cout << "You are Locked after 3 faild trails\n\n";
				return false;
			}

			cout << "\nEnter UserName? ";
			cin >> UserName;
			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);
			
			FailLogin = CurrentUser.IsEmpty();


		} while (FailLogin);

		CurrentUser.RegisterLogIn();
		clsMainScreen::MainMenuScreen();
		return true;
		
	}

public:
	 
	static bool ShowLoginScreen()
	{

		system("cls");
		_DrawscreanHeader("\t Login Screen");
		return _Login();

	}



};

