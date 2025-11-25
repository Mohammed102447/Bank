#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include <vector>
#include<fstream>

class clsBankClient :public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode };
	enMode _eMode;
	string _sAccountNumber;
	string _sPinCode;
	float _fAccountBalance;
	bool _IsMarkForDelet = false;


	static clsBankClient _objConvertLinetoClientObject(string sLine, string sSeperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(sLine, sSeperator);
		//return clsBankClient(enMode::UpdateMode,vClientData[0],vClientData[1],vClientData[2]
		//,vClientData[3],vClientData[4],vClientData[5],stod( vClientData[6]));
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1]
			, vClientData[2], vClientData[3], vClientData[4], vClientData[5],
			stod(vClientData[6]));
	}

	static clsBankClient _objGetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

static	vector <clsBankClient> _vobjLoadClintesDataFromFile()
	{
		vector <clsBankClient>vobjBankClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{

			string sLine;
			while (getline(MyFile, sLine))
			{
				clsBankClient objBankClient = _objConvertLinetoClientObject(sLine);
				vobjBankClients.push_back(objBankClient);
			}

		}
		MyFile.close();
		return vobjBankClients;
	}

	
	static void _SaveClientsDataToFile(vector<clsBankClient> &_vobjClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		if (MyFile.is_open())
		{

			for (clsBankClient& C : _vobjClients)
			{
				if (!C.IsMarkedForDelete() == true)
				{
					MyFile << _sConvertClientsObjectToLine(C) << endl;

				}

			}



		}
		MyFile.close();
	}

	void _Update()
	{
		vector <clsBankClient> _vobjClients;
		_vobjClients = _vobjLoadClintesDataFromFile();
		for (clsBankClient& C : _vobjClients)
		{
			if (C.GetsAccountNumber() == this->GetsAccountNumber())
			{
				C = *this;
				break;

			}
		}
		_SaveClientsDataToFile(_vobjClients);
	}
	static string _sConvertClientsObjectToLine(clsBankClient objBankClient, string sSeperator = "#//#")
	{
		return objBankClient.GetsFristName() + sSeperator +
			objBankClient.GetsLastName() + sSeperator +
			objBankClient.GetsEmail() + sSeperator +
			objBankClient.GetsPhone() + sSeperator +
			objBankClient.GetsAccountNumber() + sSeperator +
			objBankClient.GetsPinCode() + sSeperator +
			to_string(objBankClient.GetfAccountBalance());
	}
	void _AddDataLineToFile(string sDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << sDataLine << endl;
			MyFile.close();
		}


	}
	void _AddNew()
	{
		_AddDataLineToFile(_sConvertClientsObjectToLine(*this));
	}
	public:
		struct strcTransferLogRecord
		{
			string sDateTime;
			string sSourceAccountNumber;
			string sDestinationAccountNumber;
			float fAmount;
			float fsrcBalanceAfter;
			float fdestBalanceAfter;
			string sUserName;
		};
		private:
	static  strcTransferLogRecord _ConvertTransferLogLineToRecord(string sLine,string sSeperator="#//#")
	{
		strcTransferLogRecord stTransferLogRecord;
		vector <string> vsTransferLogRecordLine = clsString::Split(sLine, sSeperator);
		stTransferLogRecord.sDateTime = vsTransferLogRecordLine[0];
		stTransferLogRecord.sSourceAccountNumber = vsTransferLogRecordLine[1];
		stTransferLogRecord.sDestinationAccountNumber = vsTransferLogRecordLine[2];
		stTransferLogRecord.fAmount = stod(vsTransferLogRecordLine[3]);
		stTransferLogRecord.fsrcBalanceAfter = stod(vsTransferLogRecordLine[4]);
		stTransferLogRecord.fdestBalanceAfter = stod(vsTransferLogRecordLine[5]);
		stTransferLogRecord.sUserName = vsTransferLogRecordLine[6];
		return stTransferLogRecord;
	}
public:
	

	static vector <strcTransferLogRecord> vstGetTransfersLogList()
	{
		vector <strcTransferLogRecord> vstTransferLogRecord;
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string sLine;
			strcTransferLogRecord stTransferRecord;
			while (getline(MyFile, sLine))
			{
				stTransferRecord = _ConvertTransferLogLineToRecord(sLine);
				vstTransferLogRecord.push_back(stTransferRecord);
			}
			MyFile.close();
		}
		return vstTransferLogRecord;
	}

	enum enSaveResult
	{
		svFailedEmptyObject = 0, svSucceeded = 1, svFailedAccountNumberExist = 2
	};
	static clsBankClient objGetAddNewClientObject(string sAccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", sAccountNumber, "", 0);
	}
	enSaveResult eSave()
	{
		switch (_eMode)
		{
		case clsBankClient::EmptyMode:
		{
			return enSaveResult::svFailedEmptyObject;
		}
		case clsBankClient::UpdateMode:
		{
			_Update();
			return enSaveResult::svSucceeded;
			break;
		}

		case  clsBankClient::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_sAccountNumber))
			{
				return enSaveResult::svFailedAccountNumberExist;

			}
			else
			{
				_AddNew();
				_eMode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
			break;

		}
		}
	}


	clsBankClient(enMode Mode, string sFristName, string sLastName
		, string sEmail, string sPhone, string sAccountNumber,
		string sPinCode, float fAccountBalance) :clsPerson(sFristName, sLastName, sEmail, sPhone)
	{
		this->_eMode = Mode;
		this->_sAccountNumber = sAccountNumber;
		this->_sPinCode = sPinCode;
		this->_fAccountBalance = fAccountBalance;
	}
	bool IsEmpty()
	{
		return (_eMode == enMode::EmptyMode);
	}
	string GetsAccountNumber()
	{
		return _sAccountNumber;
	}
	void SetsPinCode(string sPinCode)
	{
		_sPinCode = sPinCode;
	}
	string GetsPinCode()
	{
		return _sPinCode;
	}
	__declspec(property(get = GetsPinCode, put = SetsPinCode)) string sPinCode;
	void SetfAccountBalance(float fAccountBalance)
	{
		_fAccountBalance = fAccountBalance;
	}
	float GetfAccountBalance()
	{
		return _fAccountBalance;
	}
	__declspec(property(get = GetfAccountBalance, put = SetfAccountBalance)) float fAccountBalance;
	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << sFristName;
		cout << "\nLastName    : " << sLastName;
		cout << "\nFull Name   : " << sFullName();
		cout << "\nEmail       : " << sEmail;
		cout << "\nPhone       : " << sPhone;
		cout << "\nAcc. Number : " << GetsAccountNumber();
		cout << "\nPassword    : " << sPinCode;
		cout << "\nBalance     : " << fAccountBalance;
		cout << "\n___________________\n";

	}
	static vector <clsBankClient> vobjGetClientsList()
	{
		return _vobjLoadClintesDataFromFile();
	}
	static double dGetTotalBalances()
	{
		vector <clsBankClient> vClients = vobjGetClientsList();
		double dTotalBalance=0;
		for (clsBankClient objClient:vClients)
		{
			dTotalBalance = dTotalBalance + objClient.fAccountBalance;
		}
		return dTotalBalance;
	}
	static clsBankClient objFind(string sAccontNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string sLine;
			while (getline(MyFile, sLine))
			{
				clsBankClient objClient = _objConvertLinetoClientObject(sLine);
				if (objClient.GetsAccountNumber() == sAccontNumber)
				{
					MyFile.close();
					return objClient;
				}


			}
			MyFile.close();


		}
		return _objGetEmptyClientObject();
	}
	static clsBankClient objFind(string sAccontNumber, string sPincode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string sLine;
			while (getline(MyFile, sLine))
			{
				clsBankClient objClient = _objConvertLinetoClientObject(sLine);
				if (objClient.GetsAccountNumber() == sAccontNumber &&
					objClient.sPinCode == sPincode)
				{
					MyFile.close();
					return objClient;
				}


			}
			MyFile.close();

		}
		return _objGetEmptyClientObject();
	}
	static bool IsClientExist(string sAccountNumber)
	{
		clsBankClient objClient = objFind(sAccountNumber);
		return (!objClient.IsEmpty());
	}
	bool IsMarkedForDelete()
	{
		return this->_IsMarkForDelet;
	}
	bool bDelet()
	{
		vector <clsBankClient> vobjDataBankClients;
		vobjDataBankClients = _vobjLoadClintesDataFromFile();
		for (clsBankClient &C : vobjDataBankClients)
		{
			if (C.GetsAccountNumber() == _sAccountNumber)
			{
				C._IsMarkForDelet = true;
				break;
			}

		}
		_SaveClientsDataToFile(vobjDataBankClients);
		*this = _objGetEmptyClientObject();
		return true;


	}
	void Deposit(double dAmount)
	{
		this->_fAccountBalance += dAmount;
		eSave();
	}

	bool bWithDraw(double dAmount)
	{
		if (dAmount>this->fAccountBalance)
		{
			return false;
		}
		else
		{
			this->_fAccountBalance -= dAmount;
			eSave();
			return true;
		}
		
	}
	bool bTransfer(float fAmount,clsBankClient &objDestinationClient,string sUserName)
	{
		if (fAmount>this->fAccountBalance)
		{
			return false;
		}
		this->bWithDraw(fAmount);
		objDestinationClient.Deposit(fAmount);
		_RegisterTransferLog( fAmount,  objDestinationClient,  sUserName);
		return true;
	}
	private:
		string _sPrepareTransferLogRecord(float fAmount,clsBankClient objDestination,string sUserName,string sSeperator="#//#")
		{
			string sTransferLogRecord = "";
			sTransferLogRecord += clsDate::sGetSystemDateTimeString()+sSeperator;
			sTransferLogRecord += this->GetsAccountNumber() + sSeperator;
			sTransferLogRecord += objDestination.GetsAccountNumber() + sSeperator;
			sTransferLogRecord += to_string( fAmount) + sSeperator;
			sTransferLogRecord += to_string(fAmount) + sSeperator;
			sTransferLogRecord += to_string(this->fAccountBalance) + sSeperator;
			sTransferLogRecord += to_string(objDestination.fAccountBalance) + sSeperator;
			sTransferLogRecord += sUserName;
			return sTransferLogRecord;
		}
		void _RegisterTransferLog(float fAmount ,clsBankClient objDestination,string sUserName)
		{
			string sDataLine = _sPrepareTransferLogRecord(fAmount, objDestination, sUserName);
			fstream MyFile;
			MyFile.open("TransferLog.txt", ios::out | ios::app);
				if (MyFile.is_open())
				{
					MyFile << sDataLine << endl;
					MyFile.close();
				}
		}

};

