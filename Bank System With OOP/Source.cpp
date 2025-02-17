#include <iostream>
#include "client.h"
#include "Read.h"

using namespace std;

void FindClient() {
	clsClient FoundClient = clsClient::CheckIfItExist();
	FoundClient.Print();
}
void DeleteClient() {

	clsClient FoundClient = clsClient::CheckIfItExist();
	FoundClient.Print();
	char ans;
	cout << "\nAre you sure you want to delete ??? (y,n) : ";
	cin >> ans;
	if (ans == 'y' || ans == 'Y') 
	{
		FoundClient.Delete();
		cout << "\nClient Deleted successfully :')\n";
	}
}
void UpdateClient() {
	clsClient client = clsClient::CheckIfItExist();
	client.Print();
	cout << "\n--------- Update ---------\n";
	client.Update();
	cout << "\nClient Updated successfully :')\n";
	cout << "the new client Data is : \n\n";
	client.Print();
}
void AddClient() {
	clsClient client = clsClient::Add();
	cout << "\nClient Added Successfully :')\n";
}












int main() {







}