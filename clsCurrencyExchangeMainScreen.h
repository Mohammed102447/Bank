#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCUrrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;
class clsCurrencyExchangeMainScreen :protected clsScreen
{
	enum enuCurrenciesMainMenueOption {
		eListCurrencies=1,eFindCurrency=2,eUpdateCurrencyRate=3,
		eCurrencyCalculator=4,eMainMenue=5
	};
	static short iReadCurrenciesMainMenueOptions()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short iChoice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return iChoice;
	}
	static void _GoBackToCurrenciesMenue()
	{
		cout << "\n\nPress any key to go back to Currencies Menue...";
		system("pause>0");
		ShowCurrenciesMenue();
	}
	static void _ShowCurrenciesListScreen()
	{
		clsListCurrenciesScreen::ShowCureenciesList();
	}
	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Screen Will Be Here.\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateCurrencyRateScreen()
	{
		//cout << "\nUpdate Currency Rate Screen Will Be Here.\n";
		clsUpdateCUrrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}
	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nCurrency Calculator Screen Will Be Here.\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	static void _PerformCurrenciesMainMenueOPtion(enuCurrenciesMainMenueOption enCurrenciesMainMenueOption)
	{
		switch (enCurrenciesMainMenueOption)
		{
		case clsCurrencyExchangeMainScreen::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case clsCurrencyExchangeMainScreen::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrenciesMenue();
			break; 
		}
		case clsCurrencyExchangeMainScreen::eUpdateCurrencyRate:
		{
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case clsCurrencyExchangeMainScreen::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case clsCurrencyExchangeMainScreen::eMainMenue:
		{
			//do nothing here the main screen will handle it :-) ;
		}
		default:
			break;
		}
	}
public:
	static void ShowCurrenciesMenue()
	{
		system("cls");
		_DrawScreenHeader(" Currancy Exhange Main Screen", "");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t Currency Exhange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformCurrenciesMainMenueOPtion((enuCurrenciesMainMenueOption)iReadCurrenciesMainMenueOptions());
	}
	
};



