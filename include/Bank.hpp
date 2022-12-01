#ifndef BANK
#define BANK

#include <iostream>
#include <map>
#include <string.h>
#include <unordered_map>
#include <vector>

using namespace std;

extern long long accountnumber;
extern int transacid;
extern int index1;
extern map<int, long long> tranaccount;

class bankAccount
{
    long long accountNo;
    float balance;
    // friend bool calLength(bankAccount);
    friend void setbalance(float);

public:
    void setAccountNo(long long accNo, float balance);
    long long getAccountNo();
    void getAcountinfo();
    void setbalance(float val);
    float getbalance();
};

//*************************************************************

class savingsAccount : public bankAccount
{
public:
    string accountTitle;
    void view_account();
};

//*************************************************************

class currentAccount : public bankAccount
{
public:
    string accountTitle;
    void view_account();
};

//*************************************************************

class HeadOffice
{
    string bankname, address;

public:
    void setHeadOfficeDetails(string bankname, string address);
    string getBankname();
    string getBankAddress();
};

//*************************************************************

class Branch : public HeadOffice
{
    string address;
    string manager;
    int code;

public:
    Branch(string address, string manager, int code);
    string getbranchAddress();
    string getbranchManager();
    int getbranchCode();
};

//*************************************************************

class Customer
{

    string customer_username, customer_password;

public:
    string customer_name, customer_address, customer_email, customer_phoneNo;

    void setCustomerDetails(string username, string password, string name,
                            string address, string email, string phoneNo);
    string getCustomer_name();
    string getCustomer_address();
    string getCustomer_email();
    string getCustomer_phoneNo();
    string getCustomer_username();
    string getCustomer_password();
};

//*************************************************************

class Transaction
{
public:
    int transactionId;
    double depositAmount, withdrawAmount, totalPrevAmount, remainingAmount;

    void setTransactiondetails(int id, double amount, double wamount,
                               double tamount, double ramount);
    int getTransactionId();
    double getDepositAmount();
    double getWithdrawAmount();
    double getPrevAmount();
    double printRemaingAmount();
};

//*************************************************************

extern bool checkemail(string email);
extern bool checkname(string name);
extern bool checkphone(string phone);
extern vector<string> usernameArray;
extern bool check(string username);

// mapping between account number and customer class object
extern unordered_map<long long, string> customerAccountmapcurr;
extern unordered_map<long long, string> customerAccountmapsav;

extern currentAccount currentaccountarray[1000];
extern savingsAccount savingaccountarray[1000];
extern Transaction transactionArray[1000];
extern Customer customerarray[1000];

extern bool check(long long accno, string username, string password);
extern void createAccount();

extern void depositcash();

extern void withdrawcash();
extern void getaccountinfo();
extern void balancequery();
extern void getbankdetails();
extern void prevtransactionhistory();
#endif