#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddClientScreen.h"
#include "clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsMenueOption.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"
//#include "clsC"
class clsMainScreen : protected clsScreen
{
private:
	enum  enMainMenueOption
	{
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7,eLoginRegiter=8,eCurrencyExchange=9 ,eExit = 10
	};
	static short _iReadMainMenueOption()
	{
		cout << setw(37)<<left<<""<< "Choose what do you want to do? [1 to 10]? ";
		short iChoice = clsInputValidate::ReadShortNumberBetween(1,10, 
			"Enter Number between 1 to 10 ? ");
		return iChoice;
	}

	static void _GoBackToManMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowAllClientsScreen()
	{

		//cout << "\nClients ListScreen Will be Here";
		clsClientListScreen::ShowClientsLists();
	}

	static void _ShowAddNewClientsScreen()
	{
		//cout << "\nAdd New Clients Screen Will be Here";
		clsAddClientScreen::ShowAddNewClient();
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << "\nDelete Client Screen Will be here...\n";
		clsDeleteClientScreen::ShowDeleteClient();
	}
	static void _ShowUpdateClientScreen()
	{
		//cout << "\nUpdate Client Screen Will be here...\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	static void _ShowFindClientScreen()
	{
		//cout << "\nFind Client Screen Will be here...\n";
		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _ShowTransactionsMenue()
	{
		//cout << "\nTransactions Menue Will be here...\n";
		clsTransactionsMenueOption::ShowTransactionsMenue();
	}
	static void _ShowManageUsersMenue()
	{
		//cout << "\nUsers Menue Will be here...\n";
		clsManageUsersScreen::ShowManageUsersScreen();
	}
	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}
	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
	}

	static void _Logout()
	{
		objCurrentUser = clsUser::objFind("", "");
		
	}

	static void _PerformMainMenueOption(enMainMenueOption eMainMenueOption)
	{
		switch (eMainMenueOption)
		{
		case clsMainScreen::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToManMenue();

		break;
		}
			
		case clsMainScreen::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToManMenue();

			break;
		}
		case clsMainScreen::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToManMenue();

			break;
		}
		case clsMainScreen::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToManMenue();

			break;
		}
		case clsMainScreen::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToManMenue();

			break;
		}
		case clsMainScreen::eShowTransactionsMenue:
		{
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToManMenue();

			break;
		}
		case clsMainScreen::eManageUsers:
		{
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToManMenue();

			break;
		}
		case clsMainScreen::eLoginRegiter:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToManMenue();
			break;

		}

		case clsMainScreen::eCurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToManMenue();
			break;
		}
		case clsMainScreen::eExit:
		{
			system("cls");
			
			_Logout();
			

			break;
		}
		
		}

	}

	public:
		static void ShowMainMenue()
		{
			system("cls");
			_DrawScreenHeader("\t\tMain Screen", "");
			cout << setw(37) << left << "" << "====================================\n";
			cout << setw(37) << left << "" << "\t\t Main Menue\n";
			cout << setw(37) << left << "" << "====================================\n";
			cout << setw(37) << left << "" << "\t[1]Show Client List.\n";
			cout << setw(37) << left << "" << "\t[2]Add New Client.\n";
			cout << setw(37) << left << "" << "\t[3]Delet Client \n";
			cout << setw(37) << left << "" << "\t[4] Update Client Info\n";
			cout << setw(37) << left << "" << "\t[5]Find Client\n";
			cout << setw(37) << left << "" << "\t[6] Transactions.\n";
			cout << setw(37) << left << "" << "\t[7]Manage Users\n";
			cout << setw(37) << left << "" << "\t[8]Login Register\n";
			cout << setw(37) << left << "" << "\t[9]Currency Exchange\n";
			cout << setw(37) << left << "" << "\t[10]Logout\n";
			cout << setw(37) << left << "" << "====================================\n";
			_PerformMainMenueOption((enMainMenueOption) _iReadMainMenueOption());
		}
};

