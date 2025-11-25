#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>
class clsAddNewUserScreen :protected clsScreen
{
	static void _ReadUserInfo(clsUser &objUser)
	{
		cout << "\nEnter FirstName: ";
		objUser.sFristName = clsInputValidate::ReadString();
		cout << "\nEnter LastName: ";
		objUser.sLastName = clsInputValidate::ReadString();
		cout << "\nEnter Email: ";
		objUser.sEmail = clsInputValidate::ReadString();
		cout << "\nEnter Phone: ";
		objUser.sPhone = clsInputValidate::ReadString();
		cout << "\nEnter Password: ";
		objUser.sPassWord = clsInputValidate::ReadString();
		cout << "\nEnter Permission: ";
		objUser.iPermissions = _iReadPermissionsToSet();
	}
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
	static int _iReadPermissionsToSet()
	{
		int iPermissions = 0;
		char cAnswer = 'n';
		cout << "\nDo You Want to Give Full Access? Y/N?";
		cin >> cAnswer;
		if (cAnswer=='Y'||cAnswer=='y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List?y/n";
		cin >> cAnswer;
		if (cAnswer == 'Y' || cAnswer == 'y')
		{
			iPermissions = iPermissions + clsUser::enuPermissions::eListClient;
		}

		cout << "\nAdd New Client ? y/n";
		cin >> cAnswer;
		if (cAnswer == 'Y' || cAnswer == 'y')
		{
			iPermissions = iPermissions + clsUser::enuPermissions::eAddNewClient;
		}

		cout << "\nDelete  Client ? y/n";
		cin >> cAnswer;
		if (cAnswer == 'Y' || cAnswer == 'y')
		{
			iPermissions = iPermissions + clsUser::enuPermissions::eDeleteClient;
		}

		cout << "\nUpdate  Client ? y/n";
		cin >> cAnswer;
		if (cAnswer == 'Y' || cAnswer == 'y')
		{
			iPermissions = iPermissions + clsUser::enuPermissions::eUpdateClients;
		}

		cout << "\nFind  Client ? y/n";
		cin >> cAnswer;
		if (cAnswer == 'Y' || cAnswer == 'y')
		{
			iPermissions = iPermissions + clsUser::enuPermissions::eFindClient;
		}
		cout << "\nTransaction  Client ? y/n";
		cin >> cAnswer;
		if (cAnswer == 'Y' || cAnswer == 'y')
		{
			iPermissions = iPermissions + clsUser::enuPermissions::eTransaction;
		}

		cout << "\nManage  Users ? y/n";
		cin >> cAnswer;
		if (cAnswer == 'Y' || cAnswer == 'y')
		{
			iPermissions = iPermissions + clsUser::enuPermissions::eManageUsers;
		}
		cout << "\nnShow Login Register? y/n";
		cin >> cAnswer;
		if (cAnswer == 'Y' || cAnswer == 'y')
		{
			iPermissions = iPermissions + clsUser::enuPermissions::eLoginRegister;
		}
		return iPermissions;
		
	}


public:
	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t Add New User Screen", "");
		string sUserName = "";
		cout << "\nEnter UserName";
		sUserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(sUserName))
		{
			cout << "\nUserName Is Already Used, Choose another one: ";
			sUserName = clsInputValidate::ReadString();
		}
		clsUser objNewUser = clsUser::objGetAddNewUserObject(sUserName);
		
		_ReadUserInfo(objNewUser);
		
		clsUser::enuSaveResults enSaveResult;

		enSaveResult = objNewUser.enSave();

		switch (enSaveResult)
		{
		case clsUser::svFaildEmptyObject:
			
			cout << "\n USer Not saved because it's Empty";
			break;

		case clsUser::svSucceeded:
			cout << "\nUser was saved successfully :-)";
			_PrintUser(objNewUser);
			break;

		case clsUser::svFaildUserExists:
			cout << "\n Error User Was NOt Saved Because UserName Is Used!\n";
			break;
		
		}
	}
	
};



