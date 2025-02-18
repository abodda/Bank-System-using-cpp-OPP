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
class clsUser : public clsPerson {
private:
	string _Permesion;
	string _Password;
	int _pos;
	static clsUser _ConvertLineToUserObject(string line) {
		vector <string> data = clsString::Split(line, " () ");
		clsUser User(data[0], data[1], data[2], data[3], data[4]);
		return User;
	}
	static clsUser _EmptyObject() {
		return clsUser("", "", "", "", "");
	}
public:
	clsUser(string Name, string Phone, string Email, string password, string permesion) : 
		clsPerson(Name, Phone, Email) {
		_Permesion = permesion;
		_Password = password;
	}
	static clsUser Find(string Name) {
		fstream file;
		int pos;
		pos = -1;
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				if (line != "") {
					pos += 1;
					clsUser User = _ConvertLineToUserObject(line);
					if (User.Name() == Name)
					{
						file.close();
						User.SetClientPos(pos);
						return User;
					}
				}
			}
			file.close();
		}
		return _EmptyObject();
	}
	void SetPass(string password) {
		_Password = password;
	}
	void Setper(string permesion) {
		_Permesion = permesion;
	}
	string password() {
		return _Password;
	}
	string permesion() {
		return _Permesion;
	}
	int SetClientPos(int pos) {
		_pos = pos;
	}
	int pos() {
		return _pos;
	}

};