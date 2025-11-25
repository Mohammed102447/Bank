#pragma once
#include<iostream>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"
#include <string>
#include"clsDate.h"
using namespace std;

class clsUser :public clsPerson
{
	private:

		enum enuMode{eEmptyMode=0,eUpdatMod=1,eAddMode=3};
		enuMode _enMode;
		string _sUserName="";
		string _sPassWord="";
		int _iPermission=0;
		bool _bMarkedForDelete = false;
public:
		struct  stLoginRegisterRecord
		{
			string sDateTime;
			string sUserName;
			string sPassword;
			int iPermission;

		};
private:
	static stLoginRegisterRecord _stConvertLoginRegisterLineRecord(string sLine,string sSeprator="#//#")
	{
		stLoginRegisterRecord stLoginregisterRecord;
		vector <string> vsLoginRegisterDataLine = clsString::Split(sLine, sSeprator);
		stLoginregisterRecord.sDateTime = vsLoginRegisterDataLine[0];
		stLoginregisterRecord.sUserName = vsLoginRegisterDataLine[1];
		stLoginregisterRecord.sPassword = clsUtil::DecryptText( vsLoginRegisterDataLine[2]);
		stLoginregisterRecord.iPermission =stoi ( vsLoginRegisterDataLine[3]);
		return stLoginregisterRecord;

	}
public:

	static vector <stLoginRegisterRecord> vstGetLoginRegisterList() {
		vector <stLoginRegisterRecord> vLoginRegisterRecord;
		fstream MyFile; MyFile.open("LoginRegister.txt", ios::in);//read Mode
		if (MyFile.is_open()) {
			string Line;
			stLoginRegisterRecord LoginRegisterRecord;
			while (getline(MyFile, Line)) {
				LoginRegisterRecord = _stConvertLoginRegisterLineRecord(Line);
				vLoginRegisterRecord.push_back(LoginRegisterRecord);
			}
			MyFile.close();
		}
		return vLoginRegisterRecord;
	}
public:
		enum enuPermissions
		{
			eAll=-1,eListClient=1,eAddNewClient=2,eDeleteClient=4,
			eUpdateClients=8,eFindClient=16,eTransaction=32,eManageUsers=64,
			eLoginRegister=128
		};

		//setters
		void set_UserName(string sUserName) {
			this->_sUserName = sUserName;
		}
		void set_PassWord(string sPassWord) {
			this->_sPassWord = sPassWord;
		}
		void set_Permissions(int iPermissions) {
			this->_iPermission = iPermissions;
		}
		//Getters
		string get_UserName() { return _sUserName; }
		string get_PassWord() { return _sPassWord; }
		int get_Permissions() { return _iPermission; }
		//declspec
		_declspec(property(get = get_UserName, put = set_UserName))string sUserName;
		_declspec(property(get = get_PassWord, put = set_PassWord))string sPassWord;
		_declspec(property(get = get_Permissions, put = set_Permissions))int iPermissions;
		static clsUser _objConvertLineToUserObject(string sLine,string sSeperator="#//#")
		{
			vector <string> vUserData = clsString::Split(sLine, sSeperator);
			clsUser objUser(enuMode::eUpdatMod, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4],clsUtil::DecryptText( vUserData[5]), stoi(vUserData[6]));
			return objUser;

		}
private:
		static string _sConvertFromUserObjectToLine(clsUser objUser, string sSeperator = "#//#")
		{
			return objUser.sFristName + sSeperator
				+ objUser.sLastName + sSeperator
				+ objUser.sEmail + sSeperator
				+ objUser.sPhone + sSeperator
				+ objUser.sUserName + sSeperator
				+ clsUtil::EncryptText( objUser.sPassWord) + sSeperator
				+ to_string(objUser.iPermissions);
		}

		static vector<clsUser> _vobjLoadUsersDataFromFile() {
			vector<clsUser>vobjUsers;
			fstream MyFile;
			MyFile.open("Users.txt", ios::in);
			if (MyFile.is_open()) {
				string sLine = "";
				while (getline(MyFile, sLine)) {
					vobjUsers.push_back(_objConvertLineToUserObject(sLine));
				}
				MyFile.close();
			}
			return vobjUsers;
		}
		static void _SaveUsersDataToFile(vector<clsUser>vobjUsers) {
			fstream MyFile;
			MyFile.open("Users.txt", ios::out);
			if (MyFile.is_open()) {
				for (clsUser &objUser : vobjUsers) 
				{
					if (objUser._bMarkedForDelete == false) {
						MyFile << _sConvertFromUserObjectToLine(objUser) << endl;
					}
				}
				MyFile.close();
			}
		}
		static void _AddDataLineToFile(string stDataLine) {
			fstream MyFile;
			MyFile.open("Users.txt", ios::out | ios::app);
			if (MyFile.is_open()) {
				MyFile << stDataLine << endl;
				MyFile.close();
			}
		}
		void _Update()
		{
			vector <clsUser> vobjUser = _vobjLoadUsersDataFromFile();
			for (clsUser &objUser : vobjUser)
			{
				if (objUser.sUserName==sUserName)
				{
					objUser = *this;
					break;
				}
			}
			_SaveUsersDataToFile(vobjUser);

		}
		void _AddNew()
		{
			_AddDataLineToFile(_sConvertFromUserObjectToLine(*this));
		}
		static clsUser _objGetEmptyUserObject()
		{
			return clsUser(enuMode::eEmptyMode, "", "", "", "", "", "", 0);
		}
		string _sPrepareLogInLine(string sSeperator="#//#")
		{
			string sLoginRecord = "";
			sLoginRecord += clsDate::sGetSystemDateTimeString() + sSeperator;
			sLoginRecord += sUserName + sSeperator;
			sLoginRecord +=clsUtil::EncryptText( sPassWord )+ sSeperator;
			sLoginRecord += to_string(iPermissions);
			return sLoginRecord;

		}
public:
	void RegisterLog()
	{
		string sDataLine = _sPrepareLogInLine();
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << sDataLine << endl;
			MyFile.close();
		}
	}

public:
	clsUser(enuMode enMode, string sFirstName, string sLastName, string sEmail, string sPhone, string sUserName
		, string sPassword, int iPermissions) :clsPerson(sFirstName, sLastName, sEmail, sPhone)
	{
		this->_enMode = enMode;
		this->_sUserName = sUserName;
		this->_sPassWord = sPassword;
		this->_iPermission = iPermissions;
	}
	bool IsEmpty()
	{
		return (_enMode == enuMode::eEmptyMode);
	}
	static bool IsUserExist(string sUserName)
	{
		clsUser objUser = clsUser::objFind(sUserName);
		return (!objUser.IsEmpty());
	}
	bool bCheckAccessPermission(enuPermissions enPermission)
	{
		if (this->iPermissions==enuPermissions::eAll)
		{
			return true;
		}
		if ((enPermission& this->iPermissions)== enPermission)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	static clsUser objFind(string sUserName) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string sLine = "";
			while (getline(MyFile, sLine)) {
				clsUser objUser = _objConvertLineToUserObject(sLine);
				if (objUser.sUserName == sUserName) {
					MyFile.close();
					return objUser;
				}
			}
			MyFile.close();
		}
		return _objGetEmptyUserObject();
	}
	static clsUser objFind(string sUserName,string sPassWord) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string sLine = "";
			while (getline(MyFile, sLine)) {
				clsUser objUser = _objConvertLineToUserObject(sLine);
				if (objUser.sUserName == sUserName&& objUser.sPassWord== sPassWord)
				{
					MyFile.close();
					return objUser;
				}
			}
			MyFile.close();
		}
		return _objGetEmptyUserObject();
	}
	enum enuSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };
	enuSaveResults enSave() {
		switch (this->_enMode )
		{
		case clsUser::eEmptyMode:
			if (IsEmpty()) 
			{
				return svFaildEmptyObject;
			}
			break;
		case clsUser::eUpdatMod:

			_Update();
			return svSucceeded;
			break;
		case clsUser::eAddMode:
			if (clsUser::IsUserExist(this->sUserName)) {
				return enuSaveResults::svFaildUserExists;
			}
			else {
				_AddNew();
				this->_enMode = eUpdatMod;
				return svSucceeded;
			}
			break;
		default:
			break;
		}
	}
	bool bDelete() {
		vector<clsUser>vobjUsers = _vobjLoadUsersDataFromFile();
		for (clsUser& U : vobjUsers)
		{
			if (U.sUserName == _sUserName)
			{
				U._bMarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(vobjUsers);
		
		*this = _objGetEmptyUserObject();
		return true;
	}
	static clsUser objGetAddNewUserObject(string sUserName)
	{
		return clsUser(enuMode::eAddMode, "", "", "", "", sUserName, "", 0);
	}
	static vector <clsUser> vobjGetUsersList()
	{
		return _vobjLoadUsersDataFromFile();
		
	}

};




