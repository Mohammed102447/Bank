#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"

#include "Global.h"
using namespace std;
class clsLoginScreen :protected clsScreen
{
	static bool _bLogin()
	{
		bool bLoginFailed = false;
		string sUserName, sPassword;
		short iTimeOfalseInput = 0;
		do
		{
			
			if (bLoginFailed)
			{
				cout<< "\nInvlaid Username/Password!\n\n";
				cout << "\nYou Have "<<3-iTimeOfalseInput<<" for  Traying\n";
				
			}
			if (iTimeOfalseInput>=3)
			{
				
				cout << "\ you Are Blocking\n\n";
				system("pause>0");
				return false;
			}

			cout << "Enter UserName?";
			cin >> sUserName;
			cout << "Enter Password?";
			cin >> sPassword;
			objCurrentUser = clsUser::objFind(sUserName,sPassword);

			bLoginFailed = objCurrentUser.IsEmpty();
			iTimeOfalseInput++;
		} while (bLoginFailed);

		objCurrentUser.RegisterLog();
		clsMainScreen::ShowMainMenue();
		return true;
	}
public:
	static bool bShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\tLogin Screen","");
	 	return _bLogin();

	}
	
};



