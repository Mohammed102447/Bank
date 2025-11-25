#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeletUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;
class clsManageUsersScreen :protected clsScreen
{
	enum enManageUsersScreenOption
	{
		eListUsers = 1, eAddNewUser = 2, eDeletUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};


	static short iReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do ?[1 to 6]";
		short iChoice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number Between 1 to 6");
		return iChoice;

	}
	static void _GoBackToManageUsersMainMenue()
	{
		cout << "\n\npress any Key to go back to Manage Users Menue ...";
		system("pause>0");
		ShowManageUsersScreen();
	}
	static void _ShowLisUsersScreen()
	{
		//cout << "\nList Users Screen Will Be Here.\n";
		clsListUsersScreen::ShowUsersList();
	}
	static void _ShowAddNewUsersScreen()
	{
		//cout << "\nList Users Screen Will Be Here";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUserScreen()
	{
		//cout << "\nDelete User Screen Will Be Here.\n";
		clsDeletUserScreen::_ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen()
	{
		//cout << "\nUpdate User Screen Will Be Here.\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen()
	{
		//cout << "\nFind User Screen Will Be Here.\n";
		clsFindUserScreen::ShowFindUserScreen();

	}

	static void _PerformManageUserMenueOption(enManageUsersScreenOption eManageUsersScreenOption)
	{
		switch (eManageUsersScreenOption)
		{
		case clsManageUsersScreen::eListUsers:
		{
			system("cls");
			_ShowLisUsersScreen();
			_GoBackToManageUsersMainMenue();
			break;
		}
		case clsManageUsersScreen::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUsersScreen();
			_GoBackToManageUsersMainMenue();
			break;
		}
		case clsManageUsersScreen::eDeletUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMainMenue();
			break;
		}
		case clsManageUsersScreen::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMainMenue();
			break;
		}
		case clsManageUsersScreen::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMainMenue();
			break;
		}
		case clsManageUsersScreen::eMainMenue:
		{
			//do nothing here the main screen will handle it :-) ;
		}
		
		}
	}

public:
	static void ShowManageUsersScreen()
	{
		if (!bCheckAccessRights(clsUser::enuPermissions::eManageUsers))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t Manage Users Screen","");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformManageUserMenueOption((enManageUsersScreenOption)iReadManageUsersMenueOption());
	}

};
	





