#include <iostream>
using namespace std;
class BankAccount
{
private:
    double balance; 
public:

BankAccount(double openingBalance) 
{
balance = openingBalance;
}


void deposit(double amount) 
{
balance = balance + amount;
}

void withdraw(double amount) 
{
balance = balance - amount;
}

void display() 
{
cout << " Balance= "<< balance << endl;
}

};

int main()
{
BankAccount ba1(1000.00); 
cout << "Before transactions, ";    
ba1.display();

ba1.deposit(245.35); 
ba1.withdraw(100.00);

cout << "After transactions, ";
ba1.display(); 
return 0;
}