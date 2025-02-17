#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "clsPerson.h"
#include "Client.h"

using namespace std;

class clsRead {
	static enum _enMainChoice {
		ShowClientLIst = 1,
		adddNewClient = 2,
		deleteClient = 3,
		updateClient = 4,
		findClient = 5,
		resetClients = 6,
		TransActions = 7,
		MangeUsers = 8,
		LogOut = 9,
		Quit = 10
	};
	enum _enTrans { Deposit = 1, WithDrow = 2, ShowMoneyList = 3, MainMenu = 4 };

public:

    static string AccountNum() {
        string AccountName;
        cout << "\nEnter account number you want to : ";
        cin >> AccountName;
        return AccountName;
    }
	static _enMainChoice ReadMainChoiceFromUser() {
		short choice;
		cout << "\n\nWhich of these would you like to start with ? (1 : 10) : ";
		cin >> choice;

		while (cin.fail() || choice > 10 || choice < 1) {
			cin.clear();
			cin.ignore(std::numeric_limits< std::streamsize> ::max(), '\n');
			cout << "\npls enter a valid choice (1 : 10) only \n";
			cin >> choice;
		}
		return _enMainChoice(choice);
	}
	static _enTrans ReadTransChoice() {
		short choice;
		cout << "\n\n(1 : 4) : ";
		cin >> choice;
		while (cin.fail() || choice > 4 || choice < 1) {
			cin.clear();
			cin.ignore(std::numeric_limits< std::streamsize> ::max(), '\n');
			cout << "\npls enter a valid choice (1 : 4) only \n";
			cin >> choice;
		}
		return _enTrans(choice);
	}
	friend void MainProgram();
	friend void Trans();

};