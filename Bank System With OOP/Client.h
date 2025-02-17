#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "clsPerson.h"
#include "string.h"
#include "Read.h"


using namespace std;
class clsClient : public clsPerson {
private:
	string _AccountNumber;
	string _PinCode;
	string _Balance;
	bool _Mode = 1;
	int _ClientPos = -1;
	static clsClient _ConvertLineToClientObject(string line) {
		vector <string> data = clsString::Split(line, " () ");
		clsClient client (1, data[0], data[1], data[2], data[3], data[4], data[5]);
		return client;
	}
	static string _ConvertClientObjectToLine(clsClient client) {
		vector <string> vclient;
		vclient.push_back(client.Name());
		vclient.push_back(client.Phone());
		vclient.push_back(client.Email());
		vclient.push_back(client.AccountNumber());
		vclient.push_back(client.PinCode());
		vclient.push_back(client.Balance());
		return clsString::JoinString(vclient, " () ");
	}
	static clsClient _EmptyObject() {
		return clsClient(0, "", "", "", "", "", "");
	}
	static void _SaveVecToFile(vector <string> clients, string name) {
		fstream file;
		file.open(name, ios::out);
		if (file.is_open()) {
			for (string s : clients) {
				file << s << "\n";
			}
			file.close();
		}
	}
	static vector <string> _SaveFileContentToVector(string FileName) {
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
	static void _SaveStringToFile(string Line, string name) {
		fstream file;
		file.open(name, ios::out | ios::app);
		if (file.is_open()) {
			if (Line != "") file << "\n" << Line;
			file.close();
		}
	}
public:
	static clsClient ReadClient() {
		string Name;
		string Phone;
		string Email;
		string PinCode;
		string Balance;
		cout << "Enter Name : ";
		getline(cin >> ws, Name);
		cout << "Enter Phone : ";
		getline(cin >> ws, Phone);
		cout << "Enter Email : ";
		getline(cin >> ws, Email);
		cout << "Enter PinCode : ";
		getline(cin >> ws, PinCode);
		cout << "Enter Balance : ";
		getline(cin >> ws, Balance);
		clsClient client(true, Name, Phone, Email, "", PinCode, Balance);
		return client;
	}
	clsClient(bool Mode, string Name, string Phone, string Email, string AccountNumber, string PinCode, string Balance):
		clsPerson(Name, Phone, Email)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_Balance = Balance;
	}
	static clsClient Find(string AccountNumber) {
		fstream file;
		int pos;
		vector <clsClient> Clients;
		file.open("clients.txt", ios::in);
		pos = -1;
		if (file.is_open()) { 
			string line;
			while (getline(file, line)) {
				if(line != "") {
					pos += 1;
					clsClient client = _ConvertLineToClientObject(line);
					if (client.AccountNumber() == AccountNumber)
					{
						file.close();
						client.SetClientPos(pos);
						return client;
					}
				}
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
		return (_Mode == 0);
	}
	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	void SetAccountNumber(string AccountNumber) {
		_AccountNumber = AccountNumber;
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
	static bool IsCLientExist(string AccountNumber) {
		clsClient client = clsClient::Find(AccountNumber);
		return (!client.IsEmbty());
	}
	void Delete() {
		vector <string> Clients = _SaveFileContentToVector("clients.txt");
		Clients.at(ClientPos()).clear();
		_SaveVecToFile(Clients, "clients.txt");
		*this = _EmptyObject();
	}
	void Update() {
		clsClient client = ReadClient();
		client.SetAccountNumber(_AccountNumber);
		string NewClientLine = _ConvertClientObjectToLine(client);
		vector <string> Clients = _SaveFileContentToVector("clients.txt");
		Clients.at(ClientPos()) = NewClientLine;
		_SaveVecToFile(Clients, "clients.txt");
		*this = client;
	}
	static clsClient Add() {
		string AccountNumber;
		while (true) {
			AccountNumber = clsRead::AccountNum();
			if (!clsClient::IsCLientExist(AccountNumber)) break;
			cout << "\nthe account number exist try again... \n\n";
		}
		clsClient Client = clsClient::ReadClient();
		Client.SetAccountNumber(AccountNumber);
		_SaveStringToFile(_ConvertClientObjectToLine(Client), "clients.txt");
		return Client;
	}
	static clsClient CheckIfItExist() {
		string AccountNumber;
		while (true) {
			AccountNumber = clsRead::AccountNum();
			if (clsClient::IsCLientExist(AccountNumber)) break;
			cout << "\nthe account number does not exist try again... \n\n";
		}
		return clsClient::Find(AccountNumber);
	}
	static void DisplayList() {
			system("cls");
			vector <string> clients = _SaveFileContentToVector("clients.txt");
			int clientsize = clients.size();
			printf("\n\nClient List (%d) Client (s).\n", clientsize);
			cout << "--------------------------------------------------------------------------------------------------\n";
			cout << "| " << left << setw(20) << "Account Number" << "| " << setw(10) << "Pin Code" << "| " << setw(25) << "client Name" << "| " << setw(25) << "Phone" << "| " << setw(10) << "Balance" << "\n";
			cout << "--------------------------------------------------------------------------------------------------\n\n";
			for (int i = 0; i < clients.size(); i++) {
				clsClient client = _ConvertLineToClientObject(clients[i]);
				cout << "| " << left << setw(20) << client.AccountNumber() << "| " << setw(10) << client.PinCode() << "| " << setw(25) << client.Name() << "| " << setw(25) << client.Phone() << "| " << client.Balance() << " $ \n";
			}
			cout << "\n--------------------------------------------------------------------------------------------------\n\n";
	}
	static void Reset() {
		fstream file;
		char ans;
		cout << "Are you Sure ?? (y,n) ";
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			file.open("clients.txt", ios::out);
			cout << "\nAll clients data has been deleted :')\n";
		}
	}
	static void ShowMoneyList() {
		vector <string> clients = _SaveFileContentToVector("clients.txt");
		int clientsize = clients.size();
		printf("\n\nClient List (%d) Client (s).\n", clientsize);
		cout << "----------------------------------------------------------------\n";
		cout << "| " << left << setw(20) << "Account Number" << "| " << setw(25) << "client Name" << "| " << "Balance" << "\n";
		cout << "----------------------------------------------------------------\n\n";
		for (int i = 0; i < clients.size(); i++) {
			clsClient client = _ConvertLineToClientObject(clients[i]);
			cout << "| " << left << setw(20) << client.AccountNumber() << "| " << setw(25) << client.Name() << "| " << client.Balance() << " $ \n";
		}
	}
	friend class clsTrans;
	friend void ShowMoneyList();
};