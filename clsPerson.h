#pragma once
#include <iostream>
#include <string>
#include "clsInterfaceCommunication.h"
using namespace std;
class clsPerson :public clsInterfaceCommunication
{
private:
	string _sFristName;
	string _sLastName;
	string _sEmail;
	string _sPhone;
public:
	clsPerson(string sFristName, string sLastName, string sEmail, string sPhone)
	{
		this->_sFristName = sFristName;
		this->_sLastName = sLastName;
		this->_sEmail = sEmail;
		this->_sPhone = sPhone;

	}
	void SetFristName(string sFristName)
	{
		this->_sFristName = sFristName;
	}
	string GetsFristName()
	{
		return this->_sFristName;
	}
	_declspec(property(get = GetsFristName, put = SetFristName))string sFristName;

	void SetLastName(string sLastName)
	{
		this->_sLastName = sLastName;
	}
	string GetsLastName()
	{
		return	this->_sLastName;
	}
	_declspec(property(get = GetsLastName, put = SetLastName))string sLastName;

	void SetEmail(string sEmail)
	{
		this->_sEmail = sEmail;
	}
	string GetsEmail()
	{
		return this->_sEmail;
	}
	_declspec(property(get = GetsEmail, put = SetEmail))string sEmail;

	void SetPhone(string sPhone)
	{
		this->_sPhone = sPhone;
	}
	string GetsPhone()
	{
		return this->_sPhone;
	}
	_declspec(property(get = GetsPhone, put = SetPhone))string sPhone;
	string sFullName()
	{
		return sFristName + " " + sLastName;
	}
	void print()
	{
		cout << "\nInfo:";
		cout << "\n-------------------------";
		cout << "\nFristName:" << sFristName;
		cout << "\n LastName: " << sLastName;
		cout << "\nFullName" << sFullName();
		cout << "\nEmail:" << sEmail;
		cout << "\nPhone:" << sPhone;
		cout << "\n-------------------------";
	}
	void SendEmail(string Title, string Body)
	{

	}

	void SendFax(string Title, string Body)
	{

	}

	void SendSMS(string Title, string Body)
	{


	}
};

