#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsFindClientScreen :protected clsScreen
{
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
	static void ShowFindClientScreen()
	{

		if (!bCheckAccessRights(clsUser::enuPermissions::eFindClient))
		{
			return;
		}
		_DrawScreenHeader("\tFind Client Screen", "");
		

		string sAccountNumber;
		cout << "\nPlease Enter Account Number: ";
		sAccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(sAccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			sAccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient objClient1 = clsBankClient::objFind(sAccountNumber);

		if (!objClient1.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient Was not Found :-(\n";
		}

		_PrintClient(objClient1);




		
	}
};

