#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUser.h"
class clsClientListScreen :protected clsScreen
{
static void PrintClientRecordToLine(clsBankClient objClient)
	{
		cout << "|" << setw(20) << left << objClient.GetsAccountNumber();
		cout << "|" << setw(20) << left << objClient.sFullName();
		cout << "|" << setw(20) << left << objClient.sPhone;
		cout << "|" << setw(20) << left << objClient.sEmail;
		cout << "|" << setw(20) << left << objClient.sPinCode;
		cout << "|" << setw(20) << left << objClient.fAccountBalance;
	}
public:
	
	static void ShowClientsLists()
	{
		if (!bCheckAccessRights(clsUser::enuPermissions::eListClient))
		{
			return ;
		}

		vector <clsBankClient> vClients = clsBankClient::vobjGetClientsList();
		string sTitle = "\t\t Client List Screen";
		string sSubTitle = "\t\t    (" + to_string(vClients.size()) + ")Client(s).";
		_DrawScreenHeader(sTitle, sSubTitle);
		//cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n___________________________________________________";
		cout << "____________________________________________\n" << endl;

		cout << "|" << setw(20) << left << "Account Number";
		cout << "|" << setw(20) << left << "Client Name";
		cout << "|" << setw(20) << left << "Phone";
		cout << "|" << setw(20) << left << "Email";
		cout << "|" << setw(20) << left << "Pin Code";
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
				PrintClientRecordToLine(objClient);
				cout << endl;
			}
		}

		cout << "\n___________________________________________________";
		cout << "____________________________________________\n" << endl;
	}
};

