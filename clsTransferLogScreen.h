#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"
class clsTransferLogScreen :protected clsScreen
{
	static void PrintTransferLogRecordLine(clsBankClient::strcTransferLogRecord stTransferLogRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(23) << left << stTransferLogRecord.sDateTime;
		cout << "| " << setw(8) << left << stTransferLogRecord.sSourceAccountNumber;
		cout << "| " << setw(8) << left << stTransferLogRecord.sDestinationAccountNumber;
		cout << "| " << setw(8) << left << stTransferLogRecord.fAmount;
		cout << "| " << setw(10) << left << stTransferLogRecord.fsrcBalanceAfter;
		cout << "| " << setw(10) << left << stTransferLogRecord.fdestBalanceAfter;
		cout << "| " << setw(8) << left << stTransferLogRecord.sUserName;
	}
public:
	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::strcTransferLogRecord> vstTransferLogRecord = clsBankClient::vstGetTransfersLogList();
		string sTitle = "\tTransfer Log List Screen";
		string sSubTitle = "\t (" + to_string(vstTransferLogRecord.size()) + ") Record(s).";
		_DrawScreenHeader(sTitle, sSubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(8) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vstTransferLogRecord.size() == 0)
			cout << "\t\t\t\tNo Transfers Available In the System!";
		else
			for (clsBankClient::strcTransferLogRecord stRecord : vstTransferLogRecord)
			{
				PrintTransferLogRecordLine(stRecord);
				cout << endl;
			}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
	
};


