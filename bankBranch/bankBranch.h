/*
  Justin Bombay
  CS 202 - 1003
  Dr. Vasko
  Assignment 3
  bankBranch.h
*/

class bankBranch {
public:
    bankBranch ();
    void addAccount(std::string, std::string, double, long, short);
    int searchAccounts(long) const;
    bool verifyAccount(int, short);
    bool updateAccount(int, double);
    void outputUserInfo(int) const;
private:
    int amountOfAccounts;
    std::string first[20];
    std::string last[20];
    double amount[20];
    long acctNo[20];
    short pin[20];
    short attempts[20];
};
