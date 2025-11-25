#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string sTitle, string sSubTitle)
	{
		cout << "\t\t\t\t_________________________________________________";
		cout << "\n\n\t\t\t\t" << sTitle;
		if (sSubTitle !="")
		{
			cout << "\n\n\t\t\t\t" << sSubTitle;
		}
		cout << "\n\t\t\t\t_________________________________________________\n\n";
		cout << "\n\t\t\t\t User :"<<objCurrentUser.sUserName;
		cout << "\n\t\t\t\t Date :"<< clsDate::DateToString(clsDate::GetSystemDate());
		
		cout << endl;
	}
	static bool bCheckAccessRights(clsUser::enuPermissions enPermission)
	{
		if (!objCurrentUser.bCheckAccessPermission(enPermission))
		{
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			return false;
		}
		else
		{
			return true;
		}
		
	}
};

