#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"
class clsTotalBalancesScreen :protected clsScreen
{
	static void PrintClientRecordBalanceLine(clsBankClient objClient)
	{
		cout << "|" << setw(20) << left << objClient.GetsAccountNumber();
		cout << "|" << setw(20) << left << objClient.sFullName();

		cout << "|" << setw(20) << left << objClient.fAccountBalance;
	}

public:
	static void ShowTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::vobjGetClientsList();

		string sTitle = "\t Balances List Screen";
		string sSubTitle = "\t (" + to_string(vClients.size()) + ") Client(s).";
		_DrawScreenHeader(sTitle, sSubTitle);

		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n___________________________________________________";
		cout << "____________________________________________\n" << endl;

		cout << "|" << setw(20) << left << "Account Number";
		cout << "|" << setw(20) << left << "Client Name";
		cout << "|" << setw(20) << left << "Balance";

		cout << "\n___________________________________________________";
		cout << "____________________________________________\n" << endl;

		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available In the System!";

		}
		else
		{
			for (clsBankClient objClient : vClients)
			{
				PrintClientRecordBalanceLine(objClient);
				cout << endl;
			}
		}

		cout << "\n___________________________________________________";
		cout << "____________________________________________\n" << endl;

		double dTotalBalance = clsBankClient::dGetTotalBalances();
		cout << "\t\t\t\t\tTotal Balance " << dTotalBalance << endl;

		cout << "\t\t\t\t\t" << clsUtil::NumberToText(dTotalBalance);
	}


	


};