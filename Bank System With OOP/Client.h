#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "clsPerson.h"
#include "string.h"


using namespace std;
class clsClient : public clsPerson {
	string _AccountNumber;
	string _PinCode;
	string _Balance;
	int _ClientPos = 0;
	enum enMode{Empty = 0, update = 1};
	enMode _Mode;
	static vector <string> _SaveFileContentToVec(string FileName) {
		vector <string> clients;
		fstream file;
		file.open(FileName, ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {

				if (line != "") {
					clients.push_back(line);
				}
			}
			file.close();
		}
		else cout << "no clients have been added yet! \n";
		return clients;
	}
	static clsClient _ConvertLineToClientObject(string line) {
		vector <string> data = clsString::Split(line, " () ");
		clsClient client (enMode::update, data[0], data[1], data[2], data[3], data[4], data[5]);
		return client;
	}
	static clsClient _EmptyObject() {
		return clsClient(enMode::Empty, "", "", "", "", "", "");
	}
public:
	clsClient(enMode Mode, string Name, string Phone, string Email, string AccountNumber, string PinCode, string Balance):
		clsPerson(Name, Phone, Email)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_Balance = Balance;
	}
	static clsClient Find(string AccountNumber) {
		fstream file;
		int pos = 0;
		vector <clsClient> Clients;
		file.open("clients.txt", ios::in);
		if (file.is_open()) { 
			string line;
			while (getline(file, line)) {
				
				clsClient client = _ConvertLineToClientObject(line);
				Clients.push_back(client);
				if (client.AccountNumber() == AccountNumber) 
				{
					file.close();
					client.SetClientPos(pos);
					return client;
				}
				pos += 1;
			}
			file.close();
		}
		return _EmptyObject();
	}
	void Print() {
		cout << left << setw(15) << "\nAccount Number" << ": " << _AccountNumber;
		cout << left << setw(15) << "\nPin code" << ": " << _PinCode;
		cout << left << setw(15) << "\nName" << ": " << _Name;
		cout << left << setw(15) << "\nphone number" << ": " << _Phone;
		cout << left << setw(15) << "\nsalary" << ": " << _Balance << " $";
		cout << left << setw(15) << "\nEmail" << ": " << _Email << '\n';
	}
	bool IsEmbty() {
		return (_Mode == enMode::Empty);
	}
	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	void SetAccountNumber(string AccountNumber) {
		_PinCode = AccountNumber;
	}
	void SetBalance(string Balance) {
		_Balance = Balance;
	}
	string AccountNumber() {
		return _AccountNumber;
	}
	void SetClientPos(int ClientPos) {
		_ClientPos = ClientPos;
	}
	int ClientPos() {
		return _ClientPos;
	}
	string PinCode() {
		return _PinCode;
	}
	string Balance() {
		return _Balance;
	}
	bool IsCLientExist(string AccontNumber) {
		clsClient client = clsClient::Find(AccontNumber);
		return (!client.IsEmbty());
	}
	


































};