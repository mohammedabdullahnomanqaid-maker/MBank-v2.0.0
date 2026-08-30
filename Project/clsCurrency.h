#pragma once
#include<iostream>
#include<string>
#include"clsString.h"
#include<fstream>
#include<vector>
#include"clsUtil.h"
using namespace std;
class clsCurrency
{

enum eMode {eUpdate=1,eEmpty=2};

eMode _Mode;
static string _FileName;

string _Country;
string _Name;
string _Code;
float _Rate;


static clsCurrency _CovertCurrencyLineToRecord(string Line)
{

	vector<string> vS = clsString::Split(Line,"#//#");

	return clsCurrency(eMode::eUpdate, vS[0], vS[1], vS[2], stof(vS[3]));

}
static clsCurrency _GetEmptyCurrencyRecod()
{

	return clsCurrency(eMode::eEmpty,"", "", "", 0.0);

}
static vector<clsCurrency>_LoadDataCurrenciesFromFile()
{
	fstream File;

	vector<clsCurrency>VC;
	File.open(_FileName, ios::in);

	if (File.is_open())
	{

		string Line;
		while (getline(File, Line))
		{

			clsCurrency C = _CovertCurrencyLineToRecord(Line);
			VC.push_back(C);

		}

		File.close();
	}


	return VC;
}
string _ConvertCurrencyRecordToLine(clsCurrency Currency, string Seperator = "#//#")
{
	string Line = "";

	Line += Currency.Country() + Seperator;
	Line += Currency.CurrencyCode() + Seperator;
	Line += Currency.CurrencyName() + Seperator;
	Line += to_string(Currency.Rate());

	return Line;
}
void _SaveCurrencyDataToFile(vector<clsCurrency>Vc)
{
	fstream File;


	File.open(_FileName, ios::out);
	if (File.is_open())
	{
		string Line;

		for (clsCurrency C : Vc)
		{

			string Line = _ConvertCurrencyRecordToLine(C);
			File << Line << endl;
		}
		File.close();
	}

}
void _Update()
{
	vector<clsCurrency>VC = _LoadDataCurrenciesFromFile();

	for (clsCurrency& C : VC)
	{
		if (C.CurrencyCode() == _Code)
		{
			C = *this;
			break;
		}
	}
	_SaveCurrencyDataToFile(VC);

}

public:

	clsCurrency(eMode Mode, string Country, string Code, string Name, float Rate)
	{

		_Mode = Mode;
		_Country = Country;
		_Code = Code;
		_Name = Name;
		_Rate = Rate;

	}


	string  Country()
	{
		return _Country;
	}


	string  CurrencyName()
	{
		return _Name;
	}


	string  CurrencyCode()
	{
		return _Code;
	}

	float  Rate()
	{
		return _Rate;
	}

	bool IsEmpty()
	{
		return _Mode == eMode::eEmpty;
     }

	enum eSaveResualt 
	{
		eSaveSucceed = 1, eSaveFaild = 2
	};

	static clsCurrency FindByCode(string Code)
	{
		fstream File;

		File.open(_FileName, ios::in);

		if (File.is_open())
		{

			string Line;
			while (getline(File, Line))
			{

				clsCurrency C = _CovertCurrencyLineToRecord(Line);
				if (clsString::UpperAllString(C.CurrencyCode()) == clsString::UpperAllString(Code))
				{
					File.close();
					return C;
				}

			}

			File.close();
		}
		
			return _GetEmptyCurrencyRecod();
	}
	static clsCurrency FindByCountry(string Country)
	{
		fstream File;

		File.open(_FileName, ios::in);

		if (File.is_open())
		{

			string Line;
			while (getline(File, Line))
			{

				clsCurrency C = _CovertCurrencyLineToRecord(Line);
				if (clsString::UpperAllString(C.Country()) == clsString::UpperAllString(Country))
				{
					File.close();
					return C;
				}

			}

			File.close();
		}

		return _GetEmptyCurrencyRecod();
	}
	static vector<clsCurrency>GetCurrenciesInfo()
	{

		return   _LoadDataCurrenciesFromFile();

	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();

	}

	

	static bool IsCurrencyExist(string Code)
	{

		clsCurrency Currency = FindByCode(Code);
		return (!Currency.IsEmpty());

	}



	 float CovertToUSD(float amount)
	{

	return (float)(amount / _Rate);

	}

	 float CovertAnotherCurrencyToUSD(float amount, clsCurrency Currency2)
	{
		 float AmountUSD = CovertToUSD(amount);
		 if (Currency2.CurrencyCode() == "USD")
		 {
			 return AmountUSD;
		 }
		return(float)(AmountUSD *Currency2.Rate());

	}

};
string clsCurrency::_FileName = "Currencies.txt";
