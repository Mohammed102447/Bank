#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsUser.h"
class clsLoginRegisterScreen :protected clsScreen
{
	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord stLoginregisterRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << stLoginregisterRecord.sDateTime;
		cout << "| " << setw(20) << left << stLoginregisterRecord.sUserName;
		cout << "| " << setw(20) << left << stLoginregisterRecord.sPassword;
		cout << "| " << setw(10) << left << stLoginregisterRecord.iPermission;
	}
public:
	 static void ShowLoginRegisterScreen()
	{
		 if (!bCheckAccessRights(clsUser::enuPermissions::eLoginRegister))
		 {
			 return;
		 }
		vector <clsUser::stLoginRegisterRecord>vsLoginReisterRecord = 
			clsUser::vstGetLoginRegisterList();
		_DrawScreenHeader("Login Register ",
			"\t\t(" + to_string(vsLoginReisterRecord.size()) + ") Record(s).");

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vsLoginReisterRecord.size() == 0)
			cout << "\t\t\t\tNo Logins Available In the System!";
		else
			for (clsUser::stLoginRegisterRecord stRecord : vsLoginReisterRecord)
			{
				_PrintLoginRegisterRecordLine(stRecord);
				cout << endl;
			}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};




