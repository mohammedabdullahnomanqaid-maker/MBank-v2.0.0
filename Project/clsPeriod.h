#pragma once
#include<iostream>
#include"clsDate.h"
#include<string>
class clsPeriod
{


public:

	clsDate startDate;
	clsDate EndDate;
	
	clsPeriod(clsDate StartDate, clsDate EndDate)
	{

		this->startDate = StartDate;
		this->EndDate = EndDate;
	}


	static bool IsOverLapPeriods(clsPeriod Period1,clsPeriod Period2) {


		if(
			clsDate::CompareDates(Period2.EndDate, Period1.startDate) == clsDate::enDateCompare::Before
			||
			clsDate::CompareDates(Period2.startDate, Period1.EndDate) == clsDate::enDateCompare::After
			)
			return false;
		else
		return true;
	
	}

	bool IsOverLapWith(clsPeriod Peroid2)
	{

		return IsOverLapPeriods(*this, Peroid2);

	}


	void Print()
	{
	
		cout << "Period Start: ";
		startDate.Print();

		cout << "Period End: ";
		EndDate.Print();

	}
};

