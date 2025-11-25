#pragma once
#include <iostream>
#include <fstream>
#include<vector>
#include "clsString.h"
#include<string>
using namespace std;
class clsCurrency
{
	enum  enuMode
	{
		eEmptyMode=0,eUpdateMode=1
	};
	enuMode _enMode;
	string _sCountry;
	string _sCurrencyCode;
	string _sCurrencyName;
	float _fRate;
static clsCurrency _objConvertLineToCurrencyObject(string sLine, string sSeperator = "#//#")
	{
	vector <string> vsCurrencyData = clsString::Split(sLine, sSeperator);
	return clsCurrency(enuMode::eUpdateMode,vsCurrencyData[0], vsCurrencyData[1], vsCurrencyData[2], stof(vsCurrencyData[3]));
	}
static string _sConvertCurrencyObjectToLine(clsCurrency objCurrency,string sSeperator ="#//#")
{
	return objCurrency.sGet_Country() + sSeperator
		+ objCurrency.sGet_CurrencyCode() + sSeperator
		+ objCurrency.sGet_CurrencyName() + sSeperator
		+ to_string(objCurrency.fGet_Rate());
}
static vector<clsCurrency> _vobjLoadCurrencysDataFromFile() {
	vector<clsCurrency> vobjCurrencys;
	fstream MyFile;
	MyFile.open("Currencies.txt", ios::in);
	if (MyFile.is_open()) {
		string sLine;
		while (getline(MyFile, sLine)) {
			vobjCurrencys.push_back(_objConvertLineToCurrencyObject(sLine));
		}
		MyFile.close();
	}
	return vobjCurrencys;
}

static void _SaveCurrencyDataToFile(vector<clsCurrency> vobjCurrencys) {
	fstream MyFile;
	MyFile.open("Currencies.txt", ios::out);
	if (MyFile.is_open()) {
		for (clsCurrency objCurrency : vobjCurrencys) {
			MyFile << _sConvertCurrencyObjectToLine(objCurrency) << endl;
		}
		MyFile.close();
	}
}
void _Update()
{
	vector <clsCurrency> vobjCurrency = _vobjLoadCurrencysDataFromFile();
	for ( clsCurrency &objCurrency : vobjCurrency)
	{
		if (objCurrency.sGet_CurrencyCode()== this->_sCurrencyCode)
		{
			objCurrency = *this;

		}

	}
	_SaveCurrencyDataToFile(vobjCurrency);
}

static clsCurrency objGetEmptyCurrencyObject()
{
	return clsCurrency(enuMode::eEmptyMode, "", "", "", 0);

}
public:
	clsCurrency (enuMode enMode, string sCountry, string sCurrencyCode, string sCurrencyName,
		float fRate)
	{
		this->_enMode = enMode;
		this->_sCountry = sCountry;
		this->_sCurrencyCode = sCurrencyCode;
		this->_sCurrencyName = sCurrencyName;
		this->_fRate = fRate;
	}
	//setters
	void UpdateRate(float fRate) {
		this->_fRate = fRate;
		_Update();
	};
	//getters
	enuMode enGet_Mode() { return this->_enMode; }
	string sGet_Country() { return this->_sCountry; }
	string sGet_CurrencyCode() { return this->_sCurrencyCode; }
	string sGet_CurrencyName() { return this->_sCurrencyName; }
	float fGet_Rate() { return this->_fRate; }

	bool bIsEmpty()
	{
		return this->_enMode == enuMode::eEmptyMode;

	}

	static clsCurrency objFindByCode(string sCurrencyCode)
	{
		sCurrencyCode = clsString::UpperAllString(sCurrencyCode);
		fstream Myfile;
		Myfile.open("Currencies.txt", ios::in);
		if (Myfile.is_open())
		{
			string sLine;
			while (getline(Myfile, sLine)) 
			{
				clsCurrency objCurrency = _objConvertLineToCurrencyObject(sLine);
				if (objCurrency.sGet_CurrencyCode() == sCurrencyCode) 
				{
					Myfile.close();
					return objCurrency;
				}
			}
		}
		return objGetEmptyCurrencyObject();
	}

	static clsCurrency objFindByCountry(string sCountry)
	{
		 sCountry = clsString::UpperAllString(sCountry);
		fstream Myfile;
		Myfile.open("Currencies.txt", ios::in);
		if (Myfile.is_open()) 
		{
			string sLine;
			while (getline(Myfile, sLine)) 
			{
				clsCurrency objCurrency = _objConvertLineToCurrencyObject(sLine);
				if (clsString::UpperAllString( objCurrency.sGet_Country()) == sCountry) 
				{
					Myfile.close();
					return objCurrency;
				}
			}
		}
		return objGetEmptyCurrencyObject();
	}
	static bool bIsCurrencyExist(string sCurrencyCode)
	{
		clsCurrency objCurrency = objFindByCode(sCurrencyCode);
		return(!objCurrency.bIsEmpty());
	}
	static vector <clsCurrency> vobjGetCurrenciesList()
	{
		return _vobjLoadCurrencysDataFromFile();
	}
	float fConvertToUSD(float fAmount)
	{
		return (float)(fAmount / fGet_Rate());
	}
	float fConvertToOtherCurrency(float fAmount, clsCurrency objCurrency)
	{
		float fAmountInUSD = fConvertToUSD(fAmount);
		if (objCurrency.sGet_CurrencyCode()=="USD")
		{
			return fAmountInUSD;
		}
		return (float)fAmountInUSD*objCurrency.fGet_Rate();
		//return fAmount * (objCurrency.fGet_Rate() / this->fGet_Rate()); //another sol
	}
};



