#pragma once
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsTransferScreen :protected clsScreen
{

	static void _PrintClient(clsBankClient objClient)
	{
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name : " << objClient.sFullName();
		cout << "\nAcc. Number : " << objClient.GetsAccountNumber();
		cout << "\nBalance : " << objClient.fAccountBalance;
		cout << "\n___________________\n";
	}


	static string _sReadAccountNumber()
	{
		string sAccountNumber;
		cout << "\nplease Enter Account Number to Transfer from :";
		sAccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(sAccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			sAccountNumber = clsInputValidate::ReadString();
		}
		return sAccountNumber;
	}
	static float _fReadAmount(clsBankClient objSourceClient)
	{
		float fAmount;
		cout << "\nEnter Transfer Amount";
		fAmount = clsInputValidate::ReadFloatNumber();
		while (fAmount>objSourceClient.fAccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			fAmount = clsInputValidate::ReadFloatNumber();
		}
		return fAmount;
	}
public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t Transfer Screen", "");
		clsBankClient objSourceClient = clsBankClient::objFind(_sReadAccountNumber());
		_PrintClient(objSourceClient);
		clsBankClient objDestinationClient = clsBankClient::objFind(_sReadAccountNumber());
		_PrintClient(objDestinationClient);
		float fAmount = _fReadAmount(objSourceClient);
		cout << "\nAre You Sure you Want to Perform This Operation ? y/n";
		char cAnswer = 'n';
		cin >> cAnswer;

		if (objSourceClient.bTransfer(fAmount, objDestinationClient,objCurrentUser.sUserName))
		{
			cout<< "\nTransfer done successfully\n";
		}

		else
		{
			cout << "\nTransfer Faild \n";
		}

		_PrintClient(objSourceClient);
		_PrintClient(objDestinationClient);
	}
};



