#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
class clsAddClientScreen :protected clsScreen
{
	static void ReadClientInfo(clsBankClient& objBankClient)
	{
		
cout << "\nEnter FristName:";
		objBankClient.sFristName = clsInputValidate::ReadString();
		cout << "\nEnter LastName: ";
		objBankClient.sLastName = clsInputValidate::ReadString();
		cout << "\nEnter Email: ";
		objBankClient.sEmail = clsInputValidate::ReadString();
		cout << "\nEnter Phone: ";
		objBankClient.sPhone = clsInputValidate::ReadString();
		cout << "\nEnter PinCode: ";
		objBankClient.sPinCode = clsInputValidate::ReadString();
		cout << "\nEnter AccountBalance: ";
		objBankClient.fAccountBalance = clsInputValidate::ReadFloatNumber();

	}
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
	static void ShowAddNewClient()
	{
		if (!bCheckAccessRights(clsUser::enuPermissions::eAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("\t Add New Client Screen", "");
		string sAccountNumber = "";
		cout << "\nplz Enter Account Number :";
		sAccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(sAccountNumber))
		{
			cout << "\n the Account Number is Exsit ,plz enter New AccountNumber :";
			sAccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient objNewBankClient = clsBankClient::objGetAddNewClientObject(sAccountNumber);
		ReadClientInfo(objNewBankClient);
		clsBankClient::enSaveResult eSaveResult;
		eSaveResult = objNewBankClient.eSave();
		switch (eSaveResult)
		{
		case clsBankClient::svSucceeded:
		{
			cout << "\nAccount Added Successfully :-)\n";
			objNewBankClient.Print();
			break;

		}

		case clsBankClient::svFailedEmptyObject:

		{
			cout << "\nAccount was  not Added Successfully :-)\n";
			break;

		}
		case clsBankClient::svFailedAccountNumberExist:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;

		}
		


		}

	}
};

