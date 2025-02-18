#include <iostream>
#include "client.h"
#include "Read.h"
#include "TransActions.h"
using namespace std; 
void Trans();
void Deposit() {
	system("cls");
	cout << "------------------------------\n";
	cout << "	Deposit Screen \n";
	cout << "------------------------------\n\n";
	int Deposit;
	clsClient client = clsClient::CheckIfItExist();
	clsTrans trans{ client };
	cout << "\nhow many you want to deposit : ";
	cin >> Deposit;
	trans.SetAdded(Deposit);
	trans.Deposit();
	if(Deposit > 0) printf("\n%d has been Added successfully to ", Deposit);
	else if (Deposit < 0) printf("\n%d has been WithDrown successfully from ", -Deposit);
	else printf("\nNothing has been Added to ");
	cout << client.AccountNumber() << " :')\n";
}
void WithDrow() {
	system("cls");
	cout << "------------------------------\n";
	cout << "	WithDrow Screen \n";
	cout << "------------------------------\n\n";
	int withdrow;
	clsClient client = clsClient::CheckIfItExist();
	while (true) {
		cout << "\nhow many you want to Withdrow : ";
		cin >> withdrow;
		if (withdrow < stoi(client.Balance())) break;
		if (client.Balance() != "0") cout << "you can withdrow up to " << client.Balance() << " only ..\n";
		else
		{
			cout << "account has no money :(\n\n";
			return;
		}
	}
	clsTrans trans{ client };
	trans.SetWithdrawen(withdrow);
	trans.Withdrow();
	printf("\n%d has been WithDrowen successfully from ", withdrow);
	cout << client.AccountNumber() << " :')\n";

}
void MainProgram();
void GoBackToMainMenue() {
	cout << "\n\npress any key to go to main menu...";
	system("pause>0");
	MainProgram();
}
void GoBackToTrans() {
	cout << "\n\npress any key to go to Trans menu...";
	system("pause>0");
	Trans();
}
void DisplayMainScreen()
{
	system("cls");
	cout << "\n ******************************************************************************* \n";
	cout << "				Main Menue Screen		\n";
	cout << " ******************************************************************************* \n";

	cout << "\n			   (1)  ==> Display Client List.\n";
	cout << "			   (2)  ==> Add New Client.\n";
	cout << "			   (3)  ==> Delete Client.\n";
	cout << "			   (4)  ==> Update Client.\n";
	cout << "			   (5)  ==> Find Client.\n";
	cout << "			   (6)  ==> reset Clients.\n";
	cout << "			   (7)  ==> TransActions.\n";
	cout << "			   (8)  ==> Manage Users.\n";
	cout << "			   (9)  ==> Log out .\n";
	cout << "			   (10) ==> Quit .\n";
}
void FindClient() {
	system("cls");
	cout << "------------------------------\n";
	cout << "	Find User screen\n";
	cout << "------------------------------\n\n";
	clsClient FoundClient = clsClient::CheckIfItExist();
	FoundClient.Print();
}
void DeleteClient() {
	system("cls");
	cout << "------------------------------\n";
	cout << "	Delete User screen\n";
	cout << "------------------------------\n";
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
	system("cls");
	cout << "------------------------------\n";
	cout << "	Update User screen\n";
	cout << "------------------------------\n\n";
	clsClient client = clsClient::CheckIfItExist();
	client.Print();
	cout << "\n--------- Update ---------\n";
	client.Update();
	cout << "\nClient Updated successfully :')\n";
	cout << "the new client Data is : \n\n";
	client.Print();
}
void AddClient() {
	system("cls");
	cout << "------------------------------\n";
	cout << "	Add User screen\n";
	cout << "------------------------------\n";
	clsClient client = clsClient::Add();
	cout << "\nClient Added Successfully :')\n";
}
void DisplayClientList() {
	clsClient::DisplayList();
}
void ResetClients() {
	system("cls");
	cout << "----------------------------------------\n";
	cout << "	  Reset Client Screen \n";
	cout << "----------------------------------------\n";
	clsClient::Reset();
}
void ShowMoneyList() {
	system("cls");
	clsClient::ShowMoneyList();
}
void Trans() {
	system("cls");
	cout << "\n ******************************************************************************* \n";
	cout << "			   Transactions Menue Screen		\n";
	cout << " ******************************************************************************* \n";

	cout << "\n			   (1) ==> Deposit.\n";
	cout << "			   (2) ==> WithDrow.\n";
	cout << "			   (3) ==> Show Money Lists.\n";
	cout << "			   (4) ==> Main Menue.\n";
	switch (clsRead::ReadTransChoice()) {
		case clsRead::_enTrans::Deposit:
			Deposit();
			GoBackToTrans();
			break;
		case clsRead::_enTrans::WithDrow:
			WithDrow();

			GoBackToTrans();
			break;
		case clsRead::_enTrans::MainMenu:
			MainProgram();
			GoBackToTrans();
			break;
		case clsRead::_enTrans::ShowMoneyList:
			ShowMoneyList();
			GoBackToTrans();
			break;
	}
}
void MainProgram(){
	DisplayMainScreen();
	switch (clsRead::ReadMainChoiceFromUser()) {
	case clsRead::_enMainChoice::ShowClientLIst:
			DisplayClientList();
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::adddNewClient:
			AddClient();
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::resetClients:
			ResetClients();
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::deleteClient:
				DeleteClient();
				GoBackToMainMenue();

			break;
		case clsRead::_enMainChoice::updateClient:
				UpdateClient();
				GoBackToMainMenue();
				break;
		case clsRead::_enMainChoice::findClient:
				FindClient();
				GoBackToMainMenue();
				break;
		case clsRead::_enMainChoice::LogOut:
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::TransActions:
			Trans();
			break;
		case clsRead::_enMainChoice::MangeUsers:
		
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::Quit:
			exit(0);
	}
}
void ManageUser() {
	system("cls");
	cout << "********************************************\n";
	cout << "	Manage Users screen\n";
	cout << "********************************************\n\n";
	cout << "(1) ==> Users List\n";
	cout << "(2) ==> Add new User\n";
	cout << "(3) ==> delete User\n";
	cout << "(4) ==> update User\n";
	cout << "(5) ==> find User\n";
	cout << "(6) ==> Main Menue\n";
	cout << "------------------------------";
}
int main() {
	MainProgram();
}