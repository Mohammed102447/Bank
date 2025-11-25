#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDepositScreen :protected clsScreen

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
	static string _sReadAccountNumber()
	{
		string sAccountNumber = "";
		cout << "\nPlease enter AccountNumber ?";
		cin >> sAccountNumber;
		return sAccountNumber;
	}
public:
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t Deposit Screen","");
		string sAccountNumber = _sReadAccountNumber();

		while (!clsBankClient::IsClientExist(sAccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			sAccountNumber = _sReadAccountNumber();
		}
		clsBankClient objClient1 = clsBankClient::objFind(sAccountNumber);
		_PrintClient(objClient1);

		double dAmount;
		cout << "\nPlease Enter Deposit Amount?";
		dAmount = clsInputValidate::ReadDblNumber();

		cout<< "\nAre you sure you want to perform this transaction? y or n";
		char cAnswer = 'n';
		cin >> cAnswer;
		if (cAnswer=='Y'|| cAnswer=='y')
		{
			objClient1.Deposit(dAmount);
			cout << "\nAmount Deposited Successfully";
			cout << "\nNew Balance is "<<objClient1.fAccountBalance;
		}
		else
		{
			cout << "\n canceled Operation";
		}
	}


};

