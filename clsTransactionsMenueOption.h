#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include "clsWithdraw.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;
class clsTransactionsMenueOption :protected clsScreen
{
	enum  enTransactionMenueOption
	{
		eDposit = 1, eWithdraw = 2, eShowTotalBalance = 3,eTransfer=4,eTransferLog=5,
		eShowMainMenue = 6
	};
	static short iReadTransactionMenueOption()
	{
		cout << setw(37) << left << "" << "Choose What Do You Want To Do?[1 to 6]";
		short iChoice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number Between 1 to 5 ? ");
		return iChoice;

	}

	static void _ShowDepositScreen()
	{
		//cout << "\n Deposit Screen will be here.\n";
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen()
	{
		//cout << "\n Withdraw Screen will be here.\n";
		clsWithdraw::ShowWithdrawScreen();
	}
	static void _ShowTotalBalancesScreen()
	{
		//cout << "\n Balances Screen will be here.\n";
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	static void _ShowTransferScreen()
	{
		//cout << "\n Transfer Screen will be here.\n";
		clsTransferScreen::ShowTransferScreen();
	}
	static void _ShowTranSferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}
	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\npress any key to back trnasactions Menue ...";
		system("pause>0");
		ShowTransactionsMenue();
	}

static void _PerformTransactionsMenueOption(enTransactionMenueOption eTransactionMenueOption)
	{
	switch (eTransactionMenueOption)
		{
	case clsTransactionsMenueOption::eDposit:
			{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
				break;
			}
		

	case clsTransactionsMenueOption::eWithdraw:

			{
				system("cls");
				_ShowWithdrawScreen();
				_GoBackToTransactionsMenue();
					break;
			}

	case clsTransactionsMenueOption::eShowTotalBalance:

			{
				system("cls");
				
				_ShowTotalBalancesScreen();
				_GoBackToTransactionsMenue();
					break;
			}
	
	case clsTransactionsMenueOption::eTransfer:

	{
		system("cls");

		_ShowTransferScreen();
		_GoBackToTransactionsMenue();
		break;
	}
	case clsTransactionsMenueOption::eTransferLog:

	{
		system("cls");

		_ShowTranSferLogScreen();
		_GoBackToTransactionsMenue();
		break;
	}
	case clsTransactionsMenueOption::eShowMainMenue:

			{
				
				//do nothing here the main screen will handle it :-) ;
					
			}
	
		}
	}
public:
	static void ShowTransactionsMenue()
	{
		if (!bCheckAccessRights(clsUser::enuPermissions::eTransaction))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\tTransactions Screen","");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5]  Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformTransactionsMenueOption((enTransactionMenueOption)iReadTransactionMenueOption());

	}




};

