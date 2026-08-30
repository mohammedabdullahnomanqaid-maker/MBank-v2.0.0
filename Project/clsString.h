
#pragma once
#include<iostream>
#include<cctype>
#include<vector>

using namespace std;

class clsString {

	string _Value;




public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}


	void SetValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue))string Value;


	static short CountCapitalLetters(string S1) {

		short AccountNumber = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
			{
				AccountNumber++;
			}
		}

		return AccountNumber;
	}
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		short AccountNumber = 0;

		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length ();
		}


		else
			for (int i = 0; i < S1.length(); i++)
			{

				if (islower(S1[i]) && WhatToCount == enWhatToCount::SmallLetters)
				{
					AccountNumber++;
				}

				else if (isupper(S1[i]) && WhatToCount == enWhatToCount::CapitalLetters)
				{
					AccountNumber++;
				}
			}


		return AccountNumber;

	}
	short CountLetters(enWhatToCount WhatToCount = enWhatToCount::All)
	{
		return CountLetters(_Value, WhatToCount);
	}

	static short CountSmallLetters(string S1) {

		short AccountNumber = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
			{
				AccountNumber++;
			}
		}

		return AccountNumber;

	}
	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short CountSpecificLetters(string S1, char SpecificLetter, bool MatchCase = true)
	{
		short AccountNumber = 0;

		if (MatchCase)
		{

			for (int i = 0; i < S1.length(); i++)
			{
				if (toupper(S1[i]) == toupper(SpecificLetter) && MatchCase)
				{
					AccountNumber++;
				}

				else {

					if (S1[i] == SpecificLetter)
						AccountNumber++;
				}
			}

		}


		return AccountNumber;
	}
	short CountSpecificLetters(char SpecificLetter, bool MatchCase = true)
	{
		return CountSpecificLetters(_Value, SpecificLetter, MatchCase);
	}

	static bool IsVowel(char Letter) {

		if (toupper(Letter) == 'A' || toupper(Letter) == 'E' || toupper(Letter) == 'I' || toupper(Letter) == 'O' || toupper(Letter) == 'U')
		{
			return true;
		}

		return false;
	}

	static short CountVowels(string S1) {

		short AccountVowels = 0;
		for (int i = 0; i < S1.length(); i++)
		{

			if (IsVowel(S1[i]))
			{
				AccountVowels++;
			}

		}
		return AccountVowels;
	}
	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static short CountWords(string S1)
	{
		short NumberOfWords = 0;
		int pos;
		string Word;
		string Delim = " ";
		while ((pos = S1.find(Delim)) != S1.npos)
		{
			Word = S1.substr(0, pos);

			if (Word != "")
			{
				NumberOfWords++;
			}
			S1.erase(0, pos + Delim.length());
		}

		if (S1 != "")
		{
			NumberOfWords++;
		}
		return NumberOfWords;
	}
	short CountWords()
	{
		return CountWords(_Value);
	}

	static string InvertAllLettersCase(string S1)
	{

		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);

		}

		return S1;
	}
	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	static char InvertLetterCase(char Letter)
	{

		return (isupper(Letter) ? tolower(Letter) : toupper(Letter));
	}




	static string JoinString(string S1[], short Length, string Delim)
	{

		string Line = "";

		for (short i = 0; i < Length; i++)
		{

			Line += S1[i] + Delim;

		}

		return Line.substr(0, Line.length() - 1);
	}
	static string JoinString(vector<string>VS, short Length, string Delim)
	{

		string Line = "";

		for (short i = 0; i < Length; i++)
		{

			Line += VS[i] + Delim;

		}

		return Line.substr(0, Line.length() - 1);
	}


	static short Length(string S1)
	{
		return S1.length();
	}
	short Length()
	{
		return Length(_Value);

	}
	static string LowerAllString(string S1) {

		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}

		return S1;
	}
	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool FirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && FirstLetter)
			{
				S1[i] = tolower(S1[i]);
			}


			FirstLetter = (S1[i] == ' ') ? true : false;
		}
		return S1;
	}
	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string RemovePunctuations(string S1)
	{
		string S2 = "";
		for (short i = 0; i < S1.length(); i++)
		{

			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}

		return S2;
	}
	string RemovePunctuations()
	{
		return RemovePunctuations(_Value);
	}

	static string ReplaceWord(string S1, string ToReplace, string ReplaceTo)
	{
		short Pos;

		while ((Pos = S1.find(ToReplace)) != S1.npos)
		{

			S1.replace(Pos, ToReplace.length(), ReplaceTo);

		}

		return S1;
	}

	static string ReverseWordInString(string S1)
	{

		vector<string>VS1 = Split(S1, " ");

		vector<string>::iterator It;

		It = VS1.end();
		string Reverse = "";

		for (It; It != VS1.begin(); "")
		{

			It--;

			Reverse += *It + " ";
		}
		return Reverse;
	}
	void ReverseWordInString() {

		_Value = ReverseWordInString(_Value);
	}

	static vector<string>Split(string S1, string Delim = " ")
	{
		vector<string>VS1;
		short pos;
		string Word;
		while ((pos = S1.find(Delim)) != S1.npos) {


			Word = S1.substr(0, pos);
			if (Word != "")
			{
				VS1.push_back(Word);

			}

			S1.erase(0, pos + Delim.length());
		}

		if (S1 != " ") {
			VS1.push_back(S1);
		}

		return VS1;
	}
	vector<string>Split(string Delim)
	{
		return Split(_Value, Delim);
	}

	static string TrimLeft(string S1) {


		for (short i = 0; i <= S1.length() - 1; i++)
		{

			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() + 1);

			}
		}
	}
	void TrimLeft() {
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S1) {


		for (short i = S1.length() - 1; i >= 0; i--)
		{

			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);

			}
		}
	}
	void TrimRight() {
		_Value = TrimRight(_Value);
	}


	static string Trim(string S1) {

		return (TrimLeft(TrimRight(S1)));
	}
	void Trim() {
		_Value = Trim(_Value);
	}


	static string UpperAllString(string S1) {

		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}

		return S1;
	}
	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}




	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool FirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && FirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}


			FirstLetter = (S1[i] == ' ') ? true : false;
		}
		return S1;
	}
	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}


};
