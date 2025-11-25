#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"


class clsDeletUserScreen :protected clsScreen
{
	static void _PrintUser(clsUser objUser)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName : " << objUser.sFristName;
		cout << "\nLastName : " << objUser.sLastName;
		cout << "\nFull Name : " << objUser.sFullName();
		cout << "\nEmail : " << objUser.sEmail;
		cout << "\nPhone : " << objUser.sPhone;
		cout << "\nUser Name : " << objUser.sUserName;
		cout << "\nPassword : " << objUser.sPassWord;
		cout << "\nPermissions : " << objUser.iPermissions;
		cout << "\n___________________\n";
	}

public:
	static void _ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\t Delete User Screen", "");
		string sUserName = "";
		cout << "\nPlease Enter UserName for Delete";
		sUserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(sUserName))
		{
			cout << "\nnUser is not found, choose another one";
			sUserName = clsInputValidate::ReadString();
		}
		clsUser objUser = clsUser::objFind(sUserName);
		_PrintUser(objUser);
		cout << "\n Are You sure delete  above user ? Y/N";
		char cAnswer = 'n';
		cin >> cAnswer;

		if (cAnswer=='y'|| cAnswer == 'Y')
		{
			if (objUser.bDelete())
			{
				cout<< "\nUser Deleted Successfully : -)\n";
				_PrintUser(objUser);
			}
			else
			{
				cout << "\nError User Was not Deleted\n";
			}
		}

	}
};



