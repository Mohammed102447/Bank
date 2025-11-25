#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsFindUserScreen :protected clsScreen
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
	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\t Find User Screen","");
		string sUserName = "";
		cout << "\nPlease Enter UserName for Delete";
		sUserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(sUserName))
		{
			cout << "\nnUser is not found, choose another one";
			sUserName = clsInputValidate::ReadString();
		}
		clsUser objUser = clsUser::objFind(sUserName);
		if (!objUser.IsEmpty())
		{
			cout << "\n User Found :-)";
		}
		else
		{
			cout << " \n User was not  Found :-(";
		}
		_PrintUser(objUser);
	}
	
};




