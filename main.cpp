#include "Bank.hpp"
#include <fstream>
using namespace std;

int main()
{
    fstream fio;
    system("cls");
    system("color 3");

    Branch b1("Rajakhera Dholpur", "Ramesh dayal", 1002311);
    b1.setHeadOfficeDetails("XYZ BANK", "Indraganj Delhi");
    //-------------------------------------------------
    bool flag = true;
    system("cls");
    while (flag)
    {
        cout << "!! *********************************************** !! \n";

        int choice;

        cout << "\t\tEnter 1 for Create Account \n";
        cout << "\t\tEnter 2 For Transaction \n";
        cout << "\t\tEnter 3 for balance enquiry \n";
        cout << "\t\tEnter 4 for get info \n";
        // cout << "Enter 5 for Get Bank Details  \n";
        cout << "\t\tEnter 5 for Know Transaction History \n";
        cout << " \n\n !! *********************************************** !! \n\n";
        cout << "Enter Your choice - ";
        cin >> choice;
        if (choice == 1)
        {
            system("cls");
            createAccount();
            char ok;
            cout << "\n\n\t\t Enter Any Key For Clear Details \n\n";
            cin >> ok;
            system("cls");
        }
        else if (choice == 2)
        {

            int ch;
        transactionchoice:
            system("cls");
            cout << " \n\n !! *********************************************** !! \n\n";
            cout << "Enter 1 for Withdraw Cash \n";
            cout << "Enter 2 For Deposit Cash \n";
            cout << " \n\n !! *********************************************** !! \n\n";
            cout << "Enter Your Choice - ";
            cin >> ch;
            if (ch == 1)
            {
                system("cls");
                withdrawcash();
                int c1;
                cout << " \n\n !! *********************************************** !! \n\n";
                cout << "\t\tEnter 1 for Making Transaction Again \n";
                cout << "\t\tEnter 2 for Back to main menu\n";
                cout << " \n\n !! *********************************************** !! \n\n";
                cout << "Enter Your Choice - ";
                cin >> c1;
                if (c1 == 1)
                {
                    goto transactionchoice;
                }
                else
                {
                    // char ok;
                    // cout << "\t\t\nEnter Any Key to Back \n\n";
                    // cin >> ok;
                    system("cls");
                }
            }
            else if (ch == 2)
            {
                system("cls");
                depositcash();
                int c1;
                cout << " \n\n !! *********************************************** !! \n\n";
                cout << "\t\tEnter 1 for Making Transaction Again \n";
                cout << "\t\tEnter 2 for Back to main menu\n";
                cout << " \n\n !! *********************************************** !! \n\n";
                cout << "Enter Your Choice - ";
                cin >> c1;
                if (c1 == 1)
                {
                    goto transactionchoice;
                }
                else
                {
                    // char ok;
                    // cout << "\t\t\nEnter Any Key to Back \n\n";
                    // cin >> ok;
                    system("cls");
                }
            }
            else
            {
                // cout << "Enter Valid Choice " ;
                // sleep(3) ;
                system("cls");
                goto transactionchoice;
            }
        }
        else if (choice == 3)
        {
            system("cls");
            cout << " \n\n !! *********************************************** !! \n\n";
            balancequery();
            cout << " \n\n !! *********************************************** !! \n\n";
            char ok;
            cout << "\t\t\nEnter Any Key to Back \n\n";
            cin >> ok;
            system("cls");
        }
        else if (choice == 4)
        {
            system("cls");
            int ch;
            cout << " \n\n !! *********************************************** !! \n\n";
            cout << "Enter 1 for get Account Info \n";
            cout << "Enter 2 for Get Bank Details \n";
            cout << " \n\n !! *********************************************** !! \n\n";
            cout << "Enter Your Choice - ";
            cin >> ch;
            if (ch == 1)
            {
                cout << " \n\n !! *********************************************** !! \n\n";
                getaccountinfo();
                cout << " \n\n !! *********************************************** !! \n\n";
            }
            else if (ch == 2)
            {
                cout << " \n\n !! *********************************************** !! \n\n";
                cout << "\n\n\t\t -------- BANK INFO -------- \n\n";
                cout << "\t\tBank name is - " << b1.getBankname() << endl;
                cout << "\t\tCode of branch - "<< "XYZ" << b1.getbranchCode() << endl;
                cout << "\t\tManager of Branch - " << b1.getbranchManager() << endl;
                cout << "\t\tAddress of Branch - " << b1.getbranchAddress() << endl;
                cout << "\t\tAddress of bank Head office - " << b1.getBankAddress() << endl;
                cout << " \n\n !! *********************************************** !! \n\n";
            }
            char ok;
            cout << "\t\t\nEnter Any Key to Back \n\n";
            cin >> ok;
            system("cls");
        }
        else if (choice == 5)
        {
            system("cls");
            cout << " \n\n !! *********************************************** !! \n\n";
            prevtransactionhistory();
            cout << " \n\n !! *********************************************** !! \n\n";
            char ok;
            cout << "\t\t\nEnter Any Key to Back \n\n";
            cin >> ok;
            system("cls");
        }
        //-------------------------------------------------
    }
}