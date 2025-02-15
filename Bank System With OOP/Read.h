#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "clsPerson.h"
#include "Client.h"

using namespace std;

class clsRead {
public:
    static string AccountNum() {
        string AccountName;
        cout << "\nEnter account number you want to : ";
        cin >> AccountName;
        return AccountName;
    }


};