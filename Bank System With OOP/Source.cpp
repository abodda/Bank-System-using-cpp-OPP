#include <iostream>
#include "client.h"
#include "Read.h"

using namespace std;

void FindClient() {
	clsClient client = clsClient::Find();
	client.Print();
}
void DeleteClient() {
	string AccountName = clsRead::AccountNum();
	clsClient client = clsClient::Find();
	client.Print();
	char ans;
	cout << "\nAre you sure you want to delete ??? (y,n) :";
	cin >> ans;
	if (ans == 'y' || ans == 'Y') 
	{
		client.Delete();
		cout << "\nClient Deleted successfully :')\n";
	}
}
void UpdateClient() {
	clsClient client = clsClient::Find();
	client.Print();
	cout << "\n--------- Update ---------";
	client.Update();
	cout << "\nClient Updated successfully :')\n";
	cout << "the new client Data is : \n\n";
	client.Print();
}
int main() {





}