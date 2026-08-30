#pragma once
#include<iostream>
#include<string>
#include"clsPerson.h"
#include"clsString.h"
#include<vector>
#include"Global.h" 
#include"clsUtil.h"
#include<fstream>
using namespace std;
class clsUser :public clsPerson
{

private:

	static string  _FileName;

	int  _Permission;
	string _Password;
	string _UserName;
	bool _MarkedForDelete = false;

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
	enMode _Mode;

	static clsUser _ConvertLineToUserObject(string Line, string seperator = "#//#")
	{
		vector<string>VClientData;

		VClientData = clsString::Split(Line, seperator);

		return clsUser(enMode::UpdateMode, VClientData[0], VClientData[1], VClientData[2],
			VClientData[3], VClientData[4], clsUtil::DecryptText(VClientData[5],2), stoi(VClientData[6]));

	}

	static clsUser _GetEmptyClientObject()
	{

		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);

	}

	static vector<clsUser>_LoadUserDataFromFile()
	{

		fstream File;
		vector<clsUser>vClients;

		File.open(_FileName, ios::in);
		if (File.is_open())
		{

			string Line;
			while (getline(File, Line))
			{

				clsUser Client = _ConvertLineToUserObject(Line);
				vClients.push_back(Client);
			}

			File.close();
		}
		return vClients;
	}
	static string _ConvertUserObjectToLine(clsUser Client, string seperator = "#//#")
	{
		
		string S1 = "";
		
		S1 += Client.FirstName + seperator;
		S1 += Client.LastName + seperator;
		S1 += Client.Email + seperator;
		S1 += Client.Phone + seperator;
		S1 += Client.GetUserName() + seperator;
		S1 += clsUtil::EncryptText(Client.Password,2) + seperator;
		S1 += to_string(Client.Permissions);

		return S1;
	}

	
	 string _PrepareLoginRecord(string Seperator="#//#")
	{

		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString();
		LoginRecord += Seperator + _UserName;
		LoginRecord += Seperator+ clsUtil::EncryptText(_Password, 2);
		LoginRecord += Seperator + to_string(Permissions);

		return LoginRecord;

	}

	static void _SaveUserDataToFile(vector<clsUser>VClients)
	{

		fstream _File;
		_File.open(_FileName, ios::out);
		string S1;
		if (_File.is_open())
		{
			for (clsUser& C : VClients)
			{
				if (C._MarkedForDelete == false)
				{

					S1 = _ConvertUserObjectToLine(C);
					_File << S1 << endl;

				}
			}

			_File.close();

		}
	}
	struct stLoginRegister;

	static stLoginRegister _ConvertLoginRegisterLineToRecord(string Line)
	{
		vector<string>Vs=clsString::Split(Line, "#//#");
		stLoginRegister LoginRegister;

		LoginRegister.Date_Time = Vs[0];
		LoginRegister.UserName = Vs[1];
		LoginRegister.Password = clsUtil::DecryptText(Vs[2], 2);
		LoginRegister.Permission = Vs[3];

		return LoginRegister;
		
	}
	
	void _AddDataLineToFile(string stDataLine)
	{

		fstream File;
		File.open(_FileName, ios::app);

		if (File.is_open())
		{

			File << stDataLine << endl;
			File.close();
		}

	}
	void _Update()
	{
		vector<clsUser>_VClients;
		_VClients = _LoadUserDataFromFile();

		for (clsUser& C : _VClients)
		{

			if (C.GetUserName() == GetUserName())
			{
				C = *this;
				break;
			}

		}
		_SaveUserDataToFile(_VClients);

	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

public:
	
	clsUser(enMode Mode, string FirstName, string LastName
		, string Email, string Phone, string UserName, string Password, int Permission)
		:clsPerson(FirstName, LastName, Email, Phone)
	{

		this->_Mode = Mode;
		this->Permissions = Permission;
		this->Password = Password;
		this->UserName = UserName;

	}
	struct stLoginRegister
	{


		string Date_Time;
		string UserName;
		string Password;
		string Permission;
	};

	string GetUserName()
	{
		return _UserName;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName))string UserName;

	void SetPermission(float Permission)
	{
		_Permission = Permission;
	}

	int GetPermission()
	{

		return _Permission;
	}

	__declspec(property(get = GetPermission, put = SetPermission))int Permissions;

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);

	}

	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	void SetPassword(string  Password)
	{
		_Password = Password;
	}


	string  GetPassword()
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword))string Password;


	static clsUser Find(string UserName)
	{
		fstream File;

		File.open(_FileName, ios::in);

		if (File.is_open())
		{

			string Line;

			while (getline(File, Line))
			{

				clsUser User = _ConvertLineToUserObject(Line);
				if (User.GetUserName() == UserName)
				{
					File.close();
					return User;
				}

			}

			File.close();

		}
		return _GetEmptyClientObject();
	}

	static clsUser Find(string UserName, string Password)
	{
		fstream File;

		File.open(_FileName, ios::in);

		if (File.is_open())
		{

			string Line;

			while (getline(File, Line))
			{

				clsUser Client = _ConvertLineToUserObject(Line);
				if (Client.GetUserName() == UserName && Client.Password == Password)
				{
					File.close();
					return Client;
				}
			}

			File.close();

		}
		return _GetEmptyClientObject();
	}


	static bool IsUserExist(string UserName)
	{
		clsUser Client = clsUser::Find(UserName);

		return (!Client.IsEmpty());

	}

	enum enPermissions 
	{
		eAll = -1, pListClients = 1, pAddNewClient = 2, pUpdateClient = 4, pDeleteClient = 8
		, pFindClient = 16, pTransactions = 32,pLoginRegister=64, pManageUsers = 128
	};
	enum enSaveResults { svSucceeded = 0, svFaildEmptyObject = 1, svFailAccountNumberExists = 2 };
	
	enSaveResults Save()
	{

		switch (_Mode)
		{

		case enMode::EmptyMode:
		{
			if (IsEmpty())
				return enSaveResults::svFaildEmptyObject;
		}

		case enMode::UpdateMode:
		{
		
			_Update();
			return enSaveResults::svSucceeded;
			break;

		}

		case enMode::AddNewMode:
		{
			if (IsUserExist(GetUserName()))
			{
				return enSaveResults::svFailAccountNumberExists;
			}
			else
			{
				_AddNew();
				/*	_Mode = enMode::UpdateMode;*/
				return enSaveResults::svSucceeded;
			}
		}
		}

	}

	static bool _IsAdmin(string UserName)
	{
		return (UserName == "Aiman.");
	}
	static clsUser AddNewUser(string AccountNumber)
	{
		return  clsUser(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	
	static vector<clsUser>GetUsersList()
	{
		return _LoadUserDataFromFile();
	}
	static vector<stLoginRegister>GetLoginRegisterList()
	{
		fstream File;
		vector<stLoginRegister>Vs;
		stLoginRegister LoginRegister;

		File.open("FileRegisters.txt", ios::in);

		if (File.is_open())
		{

			string Line;
			while (getline(File, Line))
			{


				LoginRegister = _ConvertLoginRegisterLineToRecord(Line);

				Vs.push_back(LoginRegister);
			}


			File.close();
		}


		return Vs;

	}
	
	 bool CheckAccessPermission(enPermissions Permission)
	{

		if (this->Permissions == enPermissions::eAll)
			return true;

		if ((Permission & this->Permissions ) == Permission)
			return true;

		else
		return false;

	}


  void RegisterLogIn()
	{

		 fstream File;
		 string stDateLine = _PrepareLoginRecord();

		 File.open("FileRegisters.txt", ios::app);

		 if (File.is_open())
		 {
			 
			 File << stDateLine << endl;

			 File.close();
		 }



	 }
  
	bool Delete()
	{
		
		vector<clsUser>_vClients = _LoadUserDataFromFile();


		for (clsUser& C : _vClients)
		{

			if (C.GetUserName() == _UserName)
			{
				C._MarkedForDelete = true;
				break;
			}
		}
		_SaveUserDataToFile(_vClients);

		*this = _GetEmptyClientObject();
		return true;

	}

};
string clsUser::_FileName = "UserData.txt";

