#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsUpdateClientScreen :protected clsScreen
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
public:
	static void ShowUpdateClientScreen()
	{
		if (!bCheckAccessRights(clsUser::enuPermissions::eUpdateClients))
		{
			return;
		}
		_DrawScreenHeader("\tUpdate Client Screen", "");
		string sAccountNumber = "";
		cout << "\nPlease Enter Client Account Number:";
		sAccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(sAccountNumber))
		{
			cout << "\nAccount number is not found, choose another one : ";
			sAccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient objBankClient1 = clsBankClient::objFind(sAccountNumber);
		objBankClient1.print();
		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";
		ReadClientInfo(objBankClient1);
		clsBankClient::enSaveResult eSaveResult;
		eSaveResult = objBankClient1.eSave();
		switch (eSaveResult)
		{
		case clsBankClient::svFailedEmptyObject:
		{
			cout << "\nError Account was Not Saved Because it's Empty\n";
			break;
		}

		case clsBankClient::svSucceeded:
		{
			cout << "\nAccount Updated Successfully :-)\n";
			objBankClient1.Print();

			break;

		}


		}
	}

};

