#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsCurrencyCalculatorScreen :protected clsScreen
{
	static float _fReadAmount()
	{
		cout << "\nEnter Amount to Exchange: ";
		float fAmount = 0;
		fAmount = clsInputValidate::ReadFloatNumber();
		return fAmount;
	}
	static clsCurrency _objGetCurrency(string Message)
	{
		string sCurrencyCode;
		cout << Message << endl;
		sCurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::bIsCurrencyExist(sCurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			sCurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency objCurrency = clsCurrency::objFindByCode(sCurrencyCode);
		return objCurrency;
	}
	static void _PrintCurrencyCard(clsCurrency objCurrency, string sTitle = "Currency Card:")
	{
		cout << "\n" << sTitle << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry : " << objCurrency.sGet_Country();
		cout << "\nCode : " << objCurrency.sGet_CurrencyCode();
		cout << "\nName : " << objCurrency.sGet_CurrencyName();
		cout << "\nRate(1$) = : " << objCurrency.fGet_Rate();
		cout << "\n_____________________________\n";

	}
	static void _PrintCalculationResults(float fAmount, clsCurrency objCurrency1, clsCurrency objCurrency2)
	{
		_PrintCurrencyCard(objCurrency1, "Convert From:");
		float fAmountInUSD = objCurrency1.fConvertToUSD(fAmount);
		cout << fAmount << " " << objCurrency1.sGet_CurrencyCode()
			<< " = " << fAmountInUSD << " USD\n";
		if (objCurrency2.sGet_CurrencyCode() == "USD")
		{
			return;
		}
		cout << "\nConverting from USD to:\n";
		_PrintCurrencyCard(objCurrency2,"To");
		float fAmountInCurrrency2 = objCurrency1.fConvertToOtherCurrency(fAmount, objCurrency2);
		cout << fAmount << " " << objCurrency1.sGet_CurrencyCode()
			<< " = " << fAmountInCurrrency2 << " " << objCurrency2.sGet_CurrencyCode();
	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		char cContinue = 'y';
		while (cContinue == 'y' || cContinue == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\tUpdate Currency Screen", "");
			clsCurrency objCurrencyFrom = _objGetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency objCurrencyTo = _objGetCurrency("\nPlease Enter Currency2 Code: ");
			float fAmount = _fReadAmount();
			_PrintCalculationResults(fAmount, objCurrencyFrom, objCurrencyTo);
			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> cContinue;
		}
	}
};



