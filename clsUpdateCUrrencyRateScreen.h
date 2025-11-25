#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;
class clsUpdateCUrrencyRateScreen :protected clsScreen
{
	 static float _fReadRate()
	{
		cout << "\nEnter New Rate: ";
		float fNewRate = 0;
		fNewRate = clsInputValidate::ReadFloatNumber();
		return fNewRate;
	}




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

public:
	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen", "");
		string sCurrencyCode = "";
		cout << "\nPlease Enter Currency Code: ";
		sCurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::bIsCurrencyExist(sCurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			sCurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency objCurrency = clsCurrency::objFindByCode(sCurrencyCode);
		_PrintCurrency(objCurrency);
	
	cout << "\nAre you sure you want to update the rate of this Currency y/n? ";
	char cAnswer = 'n';
	cin >> cAnswer;
	if (cAnswer == 'y' || cAnswer == 'Y')
	{
		cout << "\n\nUpdate Currency Rate:";
		cout << "\n____________________\n";
		objCurrency.UpdateRate(_fReadRate());
		cout << "\nCurrency Rate Updated Successfully :-)\n";
		_PrintCurrency(objCurrency);
	}
}
};



