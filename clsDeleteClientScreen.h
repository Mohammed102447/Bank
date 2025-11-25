#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsDeleteClientScreen :protected clsScreen
{
private:
	static void _PrintClient(clsBankClient objClient)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName : " << objClient.sFristName;
		cout << "\nLastName : " << objClient.sLastName;
		cout << "\nFull Name : " << objClient.sFullName();
		cout << "\nEmail : " << objClient.sEmail;
		cout << "\nPhone : " << objClient.sPhone;
		cout << "\nAcc. Number : " << objClient.GetsAccountNumber();
		cout << "\nPassword : " << objClient.sPinCode;
		cout << "\nBalance : " << objClient.fAccountBalance;
		cout << "\n___________________\n";
	}

public:
	static void ShowDeleteClient()
	{
		if (!bCheckAccessRights(clsUser::enuPermissions::eDeleteClient))
		{
			return;
		}
		_DrawScreenHeader("\tDelete Client Screen", "");
		string sAccountNumber = "";
		cout << "\nPlz enter Account Number for delet it ";
		sAccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(sAccountNumber))
		{
			cout << "\nAccount number is not found, please choose another one: ";
			sAccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient objBankCLient = clsBankClient::objFind(sAccountNumber);
		objBankCLient.print();
		cout << "\nAre you sure you want to delete this client y/n? ";
		char cAnswer = 'n';
		cin >> cAnswer;
		if (cAnswer == 'y' || cAnswer == 'Y')
		{
			if (objBankCLient.bDelet())
			{
				cout << "\nClient Deleted Susseccfully :-)\n";
				objBankCLient.print();

			}
			else {
				cout << "\nError Client Was not Deleted\n";
			}

		}
	}
};

