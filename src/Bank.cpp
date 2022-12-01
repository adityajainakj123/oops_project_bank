#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
#include <unordered_map>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include "Bank.hpp"
#include "cipher.hpp"

using namespace std;
static long long t = 0;
void bankAccount::setAccountNo(long long accNo, float balance)
{

    this->accountNo = accNo;
    this->balance = balance;
}
long long bankAccount::getAccountNo() { return accountNo; }
void bankAccount::getAcountinfo()
{
    // if (calLength(*this)) {
    cout << "Account no : " << accountNo << endl;
    // } else {
    //   cout << "invalid account number" << endl;
    //   return;
    // }
    cout << "balance is : " << balance << endl;
}
void bankAccount::setbalance(float val) { balance = val; }
float bankAccount::getbalance() { return balance; }

//*************************************************************

void savingsAccount::view_account()
{
    {
        cout << "Account type is :" << accountTitle << endl;
    }
}

//*************************************************************

void currentAccount::view_account()
{
    cout << "Account type is :" << accountTitle << endl;
}

//*************************************************************

void HeadOffice::setHeadOfficeDetails(string bankname, string address)
{
    this->bankname = bankname;
    this->address = address;
}
string HeadOffice::getBankname() { return bankname; }
string HeadOffice::getBankAddress() { return address; }

//*************************************************************

Branch::Branch(string address, string manager, int code)
{
    this->address = address;
    this->manager = manager;
    this->code = code;
}
string Branch::getbranchAddress() { return address; }
string Branch::getbranchManager() { return manager; }
int Branch::getbranchCode() { return code; }

//*************************************************************

void Customer::setCustomerDetails(string username, string password, string name,
                                  string address, string email, string phoneNo)
{
    customer_name = name;
    customer_address = address;
    customer_username = username;
    customer_email = email;
    customer_phoneNo = phoneNo;
    customer_password = password;
}
string Customer::getCustomer_name() { return customer_name; }
string Customer::getCustomer_address() { return customer_address; }
string Customer::getCustomer_email() { return customer_email; }
string Customer::getCustomer_phoneNo() { return customer_phoneNo; }
string Customer::getCustomer_username() { return customer_username; }
string Customer::getCustomer_password() { return customer_password; }

//*************************************************************

void Transaction::setTransactiondetails(int id, double amount, double wamount,
                                        double tamount, double ramount)
{
    transactionId = id;
    depositAmount = amount;
    withdrawAmount = wamount;
    totalPrevAmount = tamount;
    remainingAmount = ramount;
}
int Transaction::getTransactionId() { return transactionId; }
double Transaction::getDepositAmount() { return depositAmount; }
double Transaction::getWithdrawAmount() { return withdrawAmount; }
double Transaction::getPrevAmount() { return totalPrevAmount; }
double Transaction::printRemaingAmount()
{
    remainingAmount = totalPrevAmount - withdrawAmount + depositAmount;
    return remainingAmount;
}

//*************************************************************

bool checkemail(string email)
{
    if (email.length() <= 10)
    {
        return false;
    }
    string newemail = email.substr(email.length() - 10, email.length());
    if (newemail != "@gmail.com")
    {
        return false;
    }
    return true;
}

//*************************************************************

bool checkname(string name)
{
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] >= '0' && name[i] <= '9')
        {
            return false;
        }
    }
    return true;
}

//*************************************************************

bool checkphone(string phone)
{
    if (phone.length() < 10 || phone.length() > 10)
    {
        return false;
    }
    return true;
}

//*************************************************************

bool check(string username)
{
    for (int i = 0; i < usernameArray.size(); i++)
    {
        if (usernameArray[i] == username)
        {
            return false;
        }
    }
    usernameArray.push_back(username);
    return true;
}

//*************************************************************

bool check(long long accno, string username, string password)
{
    for (auto i : customerAccountmapcurr)
    {
        long long ac = i.first;
        string name = i.second;
        if (ac == accno && name == username)
        {
            for (int j = 0; j < index1; j++)
            {
                Customer local = customerarray[j];
                string pass = local.getCustomer_password();
                string name1 = local.getCustomer_username();
                // cout << name1 << " " << pass << endl;
                if (name1 == username && pass == encrypt(password))
                {
                    return true;
                }
            }
        }
    }

    for (auto i : customerAccountmapsav)
    {
        long long ac = i.first;
        string name = i.second;
        if (ac == accno && name == username)
        {
            for (int j = 0; j < index1; j++)
            {
                Customer local = customerarray[j];
                string pass = local.getCustomer_password();
                string name1 = local.getCustomer_username();
                // cout << (password);
                if (name1 == username && pass == encrypt(password))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

//*************************************************************

void createAccount()
{

    Customer cus1;
    string name, address, email, phoneNo;
    long long cardNo;
    string username, password;

    cout << "Enter Name - ";
label1:

    cin >> name;
    if (!checkname(name))
    {
        cout << "Enter Valid Name - ";
        goto label1;
    }
    cout << "Enter Password - ";
    cin >> password;

    cout << "Enter username - ";
label4:
    cin >> username;
    if (!check(username))
    {
        cout << "\t\tuser with this username already exists \n";
        cout << "Enter Another username - ";
        goto label4;
    }
    cout << "Enter Address - ";
    cin >> address;
    cout << "Enter Email - ";
label2:
    cin >> email;
    if (!checkemail(email))
    {
        cout << "Enter Valid Email - ";
        goto label2;
    }
    cout << "Enter Phone Number - ";
label3:
    cin >> phoneNo;

    if (!checkphone(phoneNo))
    {
        cout << " \n\n !! ***************** !! \n\n";
        cout << "\t\tPhone number must be 10 digits ";
        cout << "\t\tEnter phone number again - ";
        goto label3;
    }
    cus1.setCustomerDetails(username, encrypt(password), name, address, email, phoneNo);

    int ch;
label5:
    system("cls");
    cout << " \n !! *********************************************** !! \n\n";
    cout << "\t\tEnter 1 for creating Saving Account \n";
    cout << "\t\tEnter 2 for Creating Current Account \n ";
    cout << " \n !! *********************************************** !! \n\n";
    cout << "Enter your choice - ";
    cin >> ch;
    cout << endl;
    if (ch == 1)
    {
        savingsAccount s;

        s.accountTitle = "saving";

        cout << "Enter the balance" << endl;
        float sbal;
        cin >> sbal;

        s.setAccountNo(accountnumber, sbal);
        customerAccountmapsav[accountnumber] = username;
        accountnumber++;
        system("cls");
        cout << " \n !! *********************************************** !! \n";
        s.view_account();
        s.getAcountinfo();
        cout << " \n !! *********************************************** !! \n";
        savingaccountarray[index1] = s;
    }
    else if (ch == 2)
    {
        currentAccount c;
        c.accountTitle = "current";

        cout << "Enter the balance" << endl;
        float cbal;
        cin >> cbal;
        if (cbal < 50000)
        {
            cout << "\n\t\tCurrent Account Minimum Balance must be 50,000\n";
            sleep(3);
            system("cls");
            goto label5;
        }

        c.setAccountNo(accountnumber, cbal);
        customerAccountmapcurr[accountnumber] = username;
        accountnumber++;
        system("cls");
        cout << " \n !! *********************************************** !! \n";
        c.view_account();
        c.getAcountinfo();
        cout << " \n !! *********************************************** !! \n";
        currentaccountarray[index1] = c;
    }
    else
    {
        cout << " \n\n !! ***************** !! \n\n";
        cout << "Enter valid choice - ";
        goto label5;
    }
    t++;
    customerarray[index1] = cus1;
    index1++;
    std::ofstream outfile;

    outfile.open("data.txt", std::ios_base::app); // append instead of overwrite
    outfile << "customer " << to_string(t) << endl
            << name << endl
            << to_string(accountnumber) << endl
            << username << endl
            << encrypt(password) << endl
            << email << endl
            << phoneNo << endl
            << endl;
}

//*************************************************************

void depositcash()
{
    long long accno;
    string username, password;
    cout << "Enter account number - ";
    cin >> accno;
    cout << "Enter username - ";
    cin >> username;
    cout << "Enter password - ";
    cin >> password;

    if (check(accno, username, password))
    {
        for (int i = 0; i < index1; i++)
        {
            currentAccount local = currentaccountarray[i];
            int a = local.getAccountNo();
            if (a == accno)
            {
                int deposit;
                cout << "which amount you want to Deposit - ";
                cin >> deposit;
                float val = local.getbalance();
                float remaining = val + deposit;
                currentaccountarray[i].setbalance(remaining);
                cout << " \n !! *********************************************** !! \n";
                cout << " Transaction Successfull \n";

                cout << "Amount in your Account - " << remaining << endl;
                cout << " \n !! *********************************************** !! \n";
                Transaction t;
                t.setTransactiondetails(transacid, deposit, 0, val, remaining);
                tranaccount[transacid] = accno;
                transactionArray[transacid] = t;
                transacid++;

                return;
            }
        }

        for (int i = 0; i < index1; i++)
        {
            savingsAccount local = savingaccountarray[i];
            int a = local.getAccountNo();
            if (a == accno)
            {
                int deposit;
                cout << "which amount you want to Deposit - ";
                cin >> deposit;
                float val = local.getbalance();
                float remaining = val + deposit;
                savingaccountarray[i].setbalance(remaining);
                cout << " \n !! *********************************************** !! \n";
                cout << "Transaction Successfull \n";
                cout << "Amount in your Account - " << remaining << endl;
                cout << " \n !! *********************************************** !! \n";
                Transaction t;
                t.setTransactiondetails(transacid, deposit, 0, val, remaining);
                tranaccount[transacid] = accno;
                transactionArray[transacid] = t;
                transacid++;
                return;
            }
        }
        sleep(3);
        system("cls");
    }
    else
    {
        cout << " \n !! *********************************************** !! \n";
        cout << "\t\tEnter Right credential \n";
        cout << " \n !! *********************************************** !! \n";
        sleep(3);
        system("cls");
    }
}

//*************************************************************

void withdrawcash()
{
    long long accno;
    string username, password;
    cout << "Enter account number - ";
    cin >> accno;
    cout << "Enter username - ";
    cin >> username;
    cout << "Enter password - ";
    cin >> password;

    if (check(accno, username, password))
    {
        for (int i = 0; i < index1; i++)
        {
            currentAccount local = currentaccountarray[i];
            int a = local.getAccountNo();
            if (a == accno)
            {
                int deposit;
                cout << "which amount you want to withdraw - ";
                cin >> deposit;
                float val = local.getbalance();
                if (val < deposit)
                {
                    cout << " \n !! *********************************************** !! \n";
                    cout << "\t\tInsufficent balance \n";
                    cout << " \n !! *********************************************** !! \n";
                    return;
                }
                float remaining = val - deposit;
                currentaccountarray[i].setbalance(remaining);
                cout << " \n !! *********************************************** !! \n";
                cout << " \t\tTransaction Successfull \n";
                cout << "Remaining amount in your Account - " << remaining << endl;
                cout << " \n !! *********************************************** !! \n";
                Transaction t;
                t.setTransactiondetails(transacid, 0, deposit, val, remaining);
                tranaccount[transacid] = accno;
                transactionArray[transacid] = t;
                transacid++;
                return;
            }
        }

        for (int i = 0; i < index1; i++)
        {
            savingsAccount local = savingaccountarray[i];
            int a = local.getAccountNo();
            if (a == accno)
            {
                int deposit;
                cout << "which amount you want to withdraw - ";
                cin >> deposit;
                float val = local.getbalance();
                if (val < deposit)
                {
                    cout << " \n !! *********************************************** !! \n";
                    cout << "\t\tInsufficent balance \n";
                    cout << " \n !! *********************************************** !! \n";
                    return;
                }
                float remaining = val - deposit;
                savingaccountarray[i].setbalance(remaining);
                cout << " \n !! *********************************************** !! \n";
                cout << "\t\tTransaction Successfull \n";
                cout << "Remaining amount in your Account - " << remaining << endl;
                cout << " \n !! *********************************************** !! \n";
                Transaction t;
                t.setTransactiondetails(transacid, 0, deposit, val, remaining);
                tranaccount[transacid] = accno;
                transactionArray[transacid - 1] = t;
                transacid++;

                return;
            }
        }
        sleep(3);
        system("cls");
    }
    else
    {
        cout << " \n !! *********************************************** !! \n";
        cout << "\t\t credentials are Wrong \n";
        cout << " \n !! *********************************************** !! \n";
        sleep(3);
        system("cls");
    }
}

//*************************************************************

void getaccountinfo()
{
    long long accno;
    string username, password;
    cout << "Enter account number - ";
    cin >> accno;
    cout << "Enter username - ";
    cin >> username;
    cout << "Enter password - ";
    cin >> password;
    if (check(accno, username, password))
    {
        for (int i = 0; i < index1; i++)
        {
            currentAccount local = currentaccountarray[i];
            if (local.getAccountNo() == accno)
            {
                system("cls");
                cout << " \n\n !! *********************************************** !! \n\n";
                cout << "Account Number is - " << local.getAccountNo() << endl;
                cout << "Account Type is Current Account \n";
                cout << "Username is - " << username << endl;
                cout << "Account Balance is - " << local.getbalance() << endl;
            }
        }
        for (int i = 0; i < index1; i++)
        {
            savingsAccount local = savingaccountarray[i];
            if (local.getAccountNo() == accno)
            {
                system("cls");
                cout << " \n\n !! *********************************************** !! \n\n";
                cout << "Account Number is - " << local.getAccountNo() << endl;
                cout << "Account Type is Saving Account \n";
                cout << "Username is - " << username << endl;
                cout << "Account Balance is - " << local.getbalance() << endl;
            }
        }
        for (int i = 0; i < index1; i++)
        {
            Customer local = customerarray[i];
            if (local.getCustomer_username() == username)
            {
                cout << "Account Holder name is - " << local.getCustomer_name() << endl;
                cout << "Account Holder username is - " << local.getCustomer_username()
                     << endl;
                cout << "Account Holder Email is - " << local.getCustomer_email()
                     << endl;
                cout << "Account Holder Phone number is - "
                     << local.getCustomer_phoneNo() << endl;
                cout << "Account Holder Address is - " << local.getCustomer_address()
                     << endl;
            }
        }
    }
    else
    {
        cout << " \n !! *********************************************** !! \n\n";
        cout << "\t\tNo Account Exists With these Entered details  \n";
        cout << " \n !! *********************************************** !! \n\n";
    }
}

//*************************************************************

void balancequery()
{
    long long accno;
    string username, password;
    cout << "Enter account number - ";
    cin >> accno;
    cout << "Enter username - ";
    cin >> username;
    cout << "Enter password - ";
    cin >> password;
    if (check(accno, username, password))
    {
        for (int i = 0; i < index1; i++)
        {
            currentAccount local = currentaccountarray[i];
            if (local.getAccountNo() == accno)
            {
                system("cls");
                cout << " \n\n !! *********************************************** !! \n\n";
                cout << "Account Number is - " << local.getAccountNo() << endl;
                cout << "Username is - " << username << endl;
                cout << "Account Balance is - " << local.getbalance() << endl;
            }
        }
        for (int i = 0; i < index1; i++)
        {
            savingsAccount local = savingaccountarray[i];
            if (local.getAccountNo() == accno)
            {
                system("cls");
                cout << " \n\n !! *********************************************** !! \n\n";
                cout << "Account Number is - " << local.getAccountNo() << endl;
                cout << "Username is - " << username << endl;
                cout << "Account Balance is - " << local.getbalance() << endl;
            }
        }
    }
    else
    {
        cout << " \n !! *********************************************** !! \n\n";
        cout << "\t\tNo Account Exists With these Entered details  \n";
        cout << " \n !! *********************************************** !! \n\n";
    }
}

//*************************************************************

void prevtransactionhistory()
{
    long long accno;
    string username, password;
    cout << "Enter account number - ";
    cin >> accno;
    cout << "Enter username - ";
    cin >> username;
    cout << "Enter password - ";
    cin >> password;
    bool flag = false;
    system("cls");
    if (check(accno, username, password))
    {
        for (int i = 0; i < transacid; i++)
        {
            Transaction t1 = transactionArray[i];
            int tid = t1.getTransactionId();
            if (tranaccount[tid] == accno)
            {
                flag = true;
                cout << " \n !! *********************************************** !! \n";
                cout << "Deposit Ammount is - " << t1.getDepositAmount() << endl;
                cout << "Withdraw Ammount is - " << t1.getWithdrawAmount() << endl;
                cout << "previous Amount is - " << t1.getPrevAmount() << endl;
                cout << "Remaining amount is - " << t1.printRemaingAmount() << endl;
            }
        }
    }
    if (!flag)
    {
        cout << " \n !! *********************************************** !! \n";
        cout << "\t\tNo transaction Happend till now \n";
    }
}

//*************************************************************

vector<string> usernameArray;

// mapping between account number and customer class object
unordered_map<long long, string> customerAccountmapcurr;
unordered_map<long long, string> customerAccountmapsav;

currentAccount currentaccountarray[1000];
savingsAccount savingaccountarray[1000];
Transaction transactionArray[1000];
Customer customerarray[1000];

long long accountnumber = 1;
int transacid = 1;
int index1 = 0;
map<int, long long> tranaccount;