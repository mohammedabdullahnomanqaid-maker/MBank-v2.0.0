#pragma once
#include<iostream>
#include<string>
#include"clsPerson.h"
#include"clsString.h"
#include<vector>
#include<fstream>
using namespace std;
class clsBankClient:public clsPerson
{

private:


static string  _FileName;

float  _AccountBalance;
string _PinCode;
string _AccountNumber;
bool _MarkedForDelete = false;
enum enMode{EmptyMode=0,UpdateMode=1, AddNewMode = 2};
enMode _Mode;

 

static clsBankClient _ConvertLineToClientObject(string Line,string seperator ="#//#")
{
	vector<string>VClientData;

	VClientData = clsString::Split(Line, seperator);

	return clsBankClient(enMode::UpdateMode, VClientData[0], VClientData[1], VClientData[2],
		VClientData[3], VClientData[4], VClientData[5], stoi(VClientData[6]));

	
}

static clsBankClient _GetEmptyClientObject()
{
	return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "",0);

}

static vector<clsBankClient>_LoadClientDataFromFile()
{

	fstream File;
	vector<clsBankClient>vClients;

	File.open(_FileName, ios::in);
	if (File.is_open())
	{

		string Line;
		while (getline(File, Line))
		{

			clsBankClient Client = _ConvertLineToClientObject(Line);
			vClients.push_back(Client);
		}

		File.close();
	}
	return vClients;
}
static string _ConvertClientObjectToLine(clsBankClient Client, string seperator = "#//#")
{

	string S1 = "";

	S1 += Client.FirstName + seperator;
	S1 += Client.LastName + seperator;
	S1 += Client.Email + seperator;
	S1 += Client.Phone + seperator;
	S1 += Client.AccountNumber() + seperator;
	S1 += Client.PinCode + seperator;
	S1 += to_string(Client.AccountBalance);

	return S1;
}

static void _SaveClientDataToFile(vector<clsBankClient>VClients)
{

	fstream _File;
	_File.open(_FileName, ios::out);
	string S1;
	if (_File.is_open())
	{
		for (clsBankClient& C : VClients)
		{
			if (C._MarkedForDelete == false)
			{

			S1 = _ConvertClientObjectToLine(C);
			_File << S1 << endl;
			
		    }
		}

		_File.close();

	}
}

struct stTransferLogIfo;

static stTransferLogIfo _CovertLineTransferLogToRecord(string Line)
{
	stTransferLogIfo TransferLogIfo;

	vector<string>Vs = clsString::Split(Line,"#//#");

	TransferLogIfo.Date_Time = Vs[0];
	TransferLogIfo.AccountNumberFrom = Vs[1];
	TransferLogIfo.AccountNumberTo = Vs[2];
	TransferLogIfo.Amount = stoi(Vs[3]);
	TransferLogIfo.AccountBalanceFrom = stoi(Vs[4]);
	TransferLogIfo.AccountBalanceTo= stoi(Vs[5]);
	TransferLogIfo.Username = Vs[6];
	
	return TransferLogIfo;
}

 static vector<stTransferLogIfo>_LoadTransferLogDataFromFile()
{

	fstream File;
	vector< stTransferLogIfo>TLV;
	stTransferLogIfo TransferLogIfo;

	File.open("TransferLog.txt", ios::in);

	if (File.is_open())
	{

		string Line;

		while (getline(File, Line))
		{


			TransferLogIfo =_CovertLineTransferLogToRecord(Line);
			TLV.push_back(TransferLogIfo);
		}

		return TLV;
	}


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
	vector<clsBankClient>_VClients;
	_VClients = _LoadClientDataFromFile();

	for (clsBankClient& C : _VClients)
	{

		if (C.AccountNumber() == AccountNumber())
		{
			C = *this;
			break;
		}

	}
	_SaveClientDataToFile(_VClients);

}
string _ConvertRecordTransferLogToLine(double Amount, clsBankClient Client,string UserName, string Seperator = "#//#") {


	string Info = "";
	Info += clsDate::GetSystemDateTimeString() + Seperator;
	Info += _AccountNumber + Seperator;
	Info += Client.AccountNumber() + Seperator;
	Info += to_string(Amount) + Seperator;
	Info += to_string(Client.AccountBalance) + Seperator;
	Info += to_string(AccountBalance) + Seperator +UserName;

	return Info;
}
void _TransferLog(double Amount, clsBankClient Client,string UserName)

{
	fstream File;

	File.open("TransferLog.txt", ios::out | ios::app);

	if (File.is_open())
	{
		File << _ConvertRecordTransferLogToLine(Amount, Client,UserName) << endl;

		File.close();

	}

}
void _AddNew()
{
	_AddDataLineToFile(_ConvertClientObjectToLine(*this));
}
public:
	clsBankClient(enMode Mode,string FirstName, string LastName
		, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{

		_Mode = Mode;
		_AccountBalance = AccountBalance;
		_PinCode = PinCode;
		_AccountNumber = AccountNumber;

	}
	string AccountNumber()
	{
		return _AccountNumber;
	}


	struct stTransferLogIfo
	{

		string Username;
		string AccountNumberFrom, AccountNumberTo;
		float AccountBalanceFrom, AccountBalanceTo;
		string Date_Time;
		float Amount;

	};

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
	
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;

	bool IsEmpty()
	{
		return (_Mode ==enMode::EmptyMode);

	}
	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	void SetPinCode(string  PinCode)
	{
		_PinCode = PinCode;
	}

	string  GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	
	static clsBankClient Find(string AccountNumber)
	{
		fstream File;
		
		File.open(_FileName, ios::in);

		if (File.is_open())
		{
			
			string Line;

			while (getline(File, Line))
			{

				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					File.close();
					return Client;
				}
				
			}

			File.close();

		}
		return _GetEmptyClientObject();
	}

	

	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		fstream File;

		File.open(_FileName, ios::in);

		if (File.is_open())
		{

			string Line;

			while (getline(File, Line))
			{

				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber&&Client.PinCode==PinCode)
				{
					File.close();
					return Client;
				}
			}

			File.close();

		}
		return _GetEmptyClientObject();
	}

	


	static bool IsClientEixst(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		return (!Client.IsEmpty());

	}

	enum enSaveResults{svSucceeded=0,svFaildEmptyObject=1,svFailAccountNumberExists=2};

  enSaveResults Save()
	{

		switch (_Mode)
		{

		case enMode::EmptyMode:
		{
			if(IsEmpty())
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
			if (IsClientEixst(AccountNumber()))
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

  static clsBankClient AddNewClient(string AccountNumber)
  {
	  return  clsBankClient(enMode::AddNewMode, "", "", "","", AccountNumber, "", 0);
  }
  void Deposit(double Amount)
  {

	  _AccountBalance += Amount;
	  Save();
  }

  bool Withdraw(double Amount)
  {
	  if (Amount > _AccountBalance)
	  {
		  return false;
	  }

	  else {
		  _AccountBalance -= Amount;
		  Save();
		  return true;
	  }
  }

  
  

  bool Transfer(double Amount,clsBankClient& TransferFrom,string UserName)
  {



	  if (Amount>AccountBalance)
	  {
		  return false;
       }
	  Withdraw(Amount);
	  TransferFrom.Deposit(Amount);
	  _TransferLog(Amount, TransferFrom,UserName);
	  return true;
  }


  static vector<stTransferLogIfo>GetTransferLogInfo()
  {
	  return _LoadTransferLogDataFromFile();
 }

  static vector<clsBankClient>GetClientsList()
  {
	  return _LoadClientDataFromFile();
  }

  static double GetTotalBalances()
  {
	  vector<clsBankClient>vClients = clsBankClient::GetClientsList();
	  double TotalB=0;

	  for (clsBankClient& C : vClients)
	  {

		  TotalB += C.AccountBalance;

	  }
	  return TotalB;
  }
 static string NumberToText(int Number) {


	  if (Number == 0) {

		  return " ";

	  }

	  if (Number >= 1 && Number <= 19) {

		  string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen",
		  "sixteen","Seventeen","Eighteen","Nineteen" };

		  return arr[Number] + " ";

	  }
	  if (Number >= 20 && Number <= 99) {


		  string arr[] = { "","","Tweny","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };


		  return arr[Number / 10] + " " + NumberToText(Number % 10);
	  }


	  if (Number >= 100 && Number <= 199) {

		  return " One Hundred " + NumberToText(Number % 100);

	  }
	  if (Number >= 200 && Number <= 999) {


		  return NumberToText(Number / 100) + " Hundred " + NumberToText(Number % 100);


	  }

	  if (Number >= 1000 && Number <= 1999) {

		  return " One Thousand " + NumberToText(Number % 1000);


	  }


	  if (Number >= 2000 && Number <= 999999) {


		  return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);


	  }

	  if (Number >= 1000000 && Number <= 1999999) {


		  return " One Million " + NumberToText(Number % 1000000);
	  }

	  if (Number >= 2000000 && Number <= 999999999) {

		  return NumberToText(Number / 1000000) + " Million " + NumberToText(Number % 1000000);
	  }

	  if (Number >= 1000000000 && Number <= 1999999999) {

		  return " One Billion " + NumberToText(Number % 1000000000);


	  }
	  else
	  {

		  return NumberToText(Number / 1000000000) + " " + NumberToText(Number % 1000000000);
	  }



  }


 bool Delete()
 {

	 vector<clsBankClient>_vClients= _LoadClientDataFromFile();


	 for (clsBankClient& C : _vClients)
	 {

		 if (C.AccountNumber() == _AccountNumber)
		 {
			 C._MarkedForDelete = true;
			 break;
		 }
	 }
		 _SaveClientDataToFile(_vClients);
		 
		 *this = _GetEmptyClientObject();
		 return true;

 }

};
string clsBankClient::_FileName = "ClientData.txt";

