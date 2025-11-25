#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
class clsListUsersScreen :protected clsScreen
{
	static void _PrintUserRecordLine(clsUser objUser)
	{
		cout << setw(8) << left << "" << "| " << setw(12) << left << objUser.sUserName;
		cout << "| " << setw(25) << left << objUser.sFullName();
		cout << "| " << setw(12) << left << objUser.sPhone;
		cout << "| " << setw(20) << left << objUser.sEmail;
		cout << "| " << setw(10) << left << objUser.sPassWord;
		cout << "| " << setw(12) << left << objUser.iPermissions;
	}

public:
	static void ShowUsersList()
	{
		vector <clsUser> vobjUsers = clsUser::vobjGetUsersList();
		string sTitle = "\t User List Screen";
		string sSubTitle = "\t (" + to_string(vobjUsers.size()) + ") User(s).";
		_DrawScreenHeader(sTitle, sSubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
		if (vobjUsers.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else
			for (clsUser objUser : vobjUsers)
			{
				_PrintUserRecordLine(objUser);
				cout << endl;
			}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
	}

};


