#pragma once
#include<iostream>
#include<string>
#include"clsDate.h";


using namespace std;

class clsUtil
{

public:
	enum enCharType {
		SmallLetter = 1, CapitalLetter = 2,
		Digit = 3, MixChars = 4, SpecialCharacter = 5
	};
	static void Srand() {

		srand((unsigned)time(NULL));

	}
	static int RandomNumber(short From, short To) {

		int random;
		random = rand() % (To - From + 1) + From;
		return random;

	}
	

	static char GetRandomCharacter(enCharType CharType)
	{

		if (enCharType::MixChars)
		{
			CharType = (enCharType)RandomNumber(1,3);

		}

		switch (CharType)
		{

		case enCharType::CapitalLetter:
		{
			return RandomNumber(65,90);
			break;
		}

		case enCharType::SmallLetter:
		{
			return RandomNumber(97,122);
			break;
		}
		case enCharType::Digit:
		{

			return RandomNumber(48,57);
		}
		case enCharType::SpecialCharacter:
		{
			return RandomNumber(32, 47);
			break;
		}
		default:
		{

			return RandomNumber(65, 90);
			break;
		}

		}
	}

	static string GenerateWord(enCharType CharType,short Length)
	{

		string word = "";
		for (short i = 0; i < Length; i++) {

			word += GetRandomCharacter(CharType);

		}

		return word;
	}
	static string GenerateKey(enCharType CharType)
	{
		string Word = "";
		
		Word =Word+ GenerateWord(CharType, 4) + "-";
		Word=Word+ GenerateWord(CharType, 4) + "-";
		Word = Word + GenerateWord(CharType, 4) + "-";
		Word = Word + GenerateWord(CharType, 4);

		return Word;
	}

	static void GenerateKeys(enCharType CharType, short Length)
	{ 
		for (short i = 0; i < Length; i++)
		{

			cout << "Key [" << i+1 << "] : " << GenerateKey(CharType) << endl;
		}

	}

	static void Swap(int& A,int& B)
	{
		int temp;
		temp = A;
		A = B;
		B = temp;
	}
	static void Swap(double& A, double& B)
	{
		double temp;
		temp = A;
		A = B;
		B = temp;
	}
	static void Swap(string& A, string& B)
	{
		string temp;
		temp = A;
		A = B;
		B = temp;
	}

	static void Swap(clsDate& d1,clsDate &d2)
	{
		clsDate::Swap(d1, d2);
	}

	static void ShuffleArray(int Arr[100], short Length)
	{

		for (short i = 0; i < Length; i++)
		{
			Swap(Arr[RandomNumber(1, Length)-1], Arr[RandomNumber(1, Length)-1]);

		}

	}
	static void ShuffleArray(string Arr[100], short Length)
	{

		for (short i = 0; i < Length; i++)
		{
			Swap(Arr[RandomNumber(1, Length) - 1], Arr[RandomNumber(1, Length) - 1]);

		}

	}

	static void FillArrayWithRandomWords(string Arr[100], short LengthArr, enCharType CharType, short LengthWord)
	{

		for (short i = 0; i < LengthArr; i++)
		{
			Arr[i] = GenerateWord(CharType, LengthWord);
		}


	}
	static void FillArrayWithRandomKeys(string Arr[100], short LengthArr, enCharType CharType)
	{

		for (short i = 0; i < LengthArr; i++)
		{
			Arr[i] = GenerateKey(CharType);
		}


	}

	static void FillArrayWithRandomNumbers(int Arr[100], short LengthArr,short From,short To)
	{

		for (short i = 0; i < LengthArr; i++)
		{
			Arr[i] = RandomNumber(From, To);
		}


	}

	static string Tabs(short space)
	{
		string t = "";

		for (short i = 0; i < space; i++)
		{
			t =t+ "\t";
			cout << t;
		}
		return t;
	}


	static string EncryptText(string Text, short EncryptionKey)
	{


		for (short i = 0; i < Text.length(); i++)
		{

			Text[i] = (char(Text[i] + EncryptionKey));


		}
		return Text;
	}
	static string DecryptText(string Text, short EncryptionKey)
	{


		for (short i = 0; i < Text.length(); i++)
		{

			Text[i] = (char(Text[i] - EncryptionKey));


		}




		return Text;
	}

};

