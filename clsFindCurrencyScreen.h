#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsFindCurrencyScreen :protected clsScreen
{
	static void _PrintCurrency(clsCurrency objCurrency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry : " << objCurrency.sGet_Country();
		cout << "\nCode : " << objCurrency.sGet_CurrencyCode();
		cout << "\nName : " << objCurrency.sGet_CurrencyName();
		cout << "\nRate(1$) = : " << objCurrency.fGet_Rate();
		cout << "\n_____________________________\n";

	}
	static void _ShowResults(clsCurrency objCurrency)
	{
		if (objCurrency.bIsEmpty())
		{
			cout << "\nCurrency Is Not Found!\n";
		}
		else
		{
			cout << "\nCurrency Is  Found!\n";
			_PrintCurrency(objCurrency);
		}
	}
public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen", "");
		cout << "\nFind By: [1] Code or [2] Country ? ";
		short iAnswer = 1;
		iAnswer = clsInputValidate::ReadIntNumberBetween(1, 2);
		if (iAnswer==1)
		{
			string sCurrencyCode;
			cout << "\nPlease Enter CurrencyCode: ";
			sCurrencyCode = clsInputValidate::ReadString();
			clsCurrency objCurrency = clsCurrency::objFindByCode(sCurrencyCode);
			_ShowResults(objCurrency);
		}
		else 
		
		{
			string sCountry;
			cout << "\nPlease Enter Country Name: ";
			sCountry = clsInputValidate::ReadString();
			clsCurrency objCurrency = clsCurrency::objFindByCountry(sCountry);
			_ShowResults(objCurrency);
		}
	}
};


