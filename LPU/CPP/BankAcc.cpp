#include<iostream>
using namespace std;

class BankAccount {
    private:
    int AccNo;
    int Balance;

    public:
    void setdata (int a, int b) {
        AccNo = a;
        Balance = b;
    }

    void display () {
        cout << "Account no. is: " << AccNo << " and balance is: " << Balance << endl;
    }

    friend void BankManager(BankAccount &account, int b);
};

void BankManager(BankAccount &p, int b) {
    p.Balance = b;
}

int main() {

    BankAccount anil;
    anil.setdata(101, 5000);
    anil.display();
    BankManager(anil, 10000);
    anil.display();
}