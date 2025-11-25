#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
class clsListCurrenciesScreen :protected clsScreen
{
	static void PrintCurrencyRecordLine(clsCurrency objCurrency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << objCurrency.sGet_Country();
		cout << "| " << setw(8) << left << objCurrency.sGet_CurrencyCode();
		cout << "| " << setw(45) << left << objCurrency.sGet_CurrencyName();
		cout << "| " << setw(10) << left << objCurrency.fGet_Rate();
	}

public:
	
	static void ShowCureenciesList()
	{
		vector<clsCurrency> vobjCurrencies = clsCurrency::vobjGetCurrenciesList();
		string sTitle = "\t Currencies List Screen";
		string sSubTitle = "\t (" + to_string(vobjCurrencies.size()) + ") Currency.";
		_DrawScreenHeader(sTitle, sSubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
		if (vobjCurrencies.size()==0)
		{
			cout << "\t\t\t\tNo Currencies Available In the System!";
		}
		else
		{
			for (clsCurrency &objCurrency : vobjCurrencies )
			{
				PrintCurrencyRecordLine(objCurrency);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
	}
};


