
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsLoginScreen.h"
#include "clsCurrency.h"



int main()

{
	while (true)
	{
		if (!clsLoginScreen::bShowLoginScreen())
		{
			break;
		}
		
	}
	
	

	system("pause>0");
	return 0;
}

