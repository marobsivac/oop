/*
Implementujte příklad z přednášky a navrhněte kód,
který bude používat všechny třídy. Vytvořte desítky
klientů a účtů v bance a nasimulujte některé běžné
úkony prováděné v bance.
*/


#include <iostream>
#include <string>


class Client
{
    private:
        int code;
        std::string name;
    public:
        Client(int c, std::string n);

        int GetCode();
        std::string GetName();
};


class Account
{
    private:
        int number;
        double balance;
        double interestRate;

        Client* owner;
        Client* partner;

    public:
        Account(int n, Client* c);
        Account(int n, Client* c, double ir);
        Account(int n, Client* c, Client* p);
        Account(int n, Client* c, Client* p, double ir);

        int GetNumber();
        double GetBalance();
        double GetInterestRate();
        Client* GetOwner();
        Client* GetPartner();
        bool CanWithdraw(double a);


        void Deposit(double a);
        bool Withdraw(double a);
        void AddInterest();

};



class Bank
{
    private:
        Client** clients;
        int clientsCount;

        Account** accounts;
        int accountsCount;

    public:
        Bank(int c, int a);
        ~Bank();

        Client* GetClient(int c);
        Account* GetAccount(int n);

        Client* CreateClient(int c, std::string n);
        Account* CreateAccount(int n, Client* c);
        Account* CreateAccount(int n, Client* c, double ir);
        Account* CreateAccount(int n, Client* c, Client* p);
        Account* CreateAccount(int n, Client* c, Client* p, double ir);

        void AddInterest();
};


//Implementace třídy Client

Client::Client(int c, std::string n)
{
    this->code = c;
    this->name = n;
}

int Client::GetCode()
{
    return this->code;
}

std::string Client::GetName()
{
    return this->name;
}

//Implementace třídy Account
    //Konstruktory
Account::Account(int n, Client* c)
{
    this->number = n;
    this->owner = c;
    this->balance = 0;
    this->partner = nullptr;
    this->interestRate = 0;
}
Account::Account(int n, Client* c, double ir)
{
    this->number = n;
    this->owner = c;
    this->interestRate = ir;
    this->partner = nullptr;
    this->balance = 0;
}

Account::Account(int n, Client* c, Client* p)
{
    this->number = n;
    this->owner = c;
    this->partner = p;
    this->interestRate = 0;
    this->balance = 0;
}

Account::Account(int n, Client* c, Client* p, double ir)
{
    this->number = n;
    this->owner = c;
    this->partner = p;
    this->interestRate = ir;
    this->balance = 0;
}
    
    //Gettery
int Account::GetNumber()
{
    return this->number;
}
double Account::GetBalance()
{
    return this->balance;
}
double Account::GetInterestRate()
{
    return this->interestRate;
}
Client* Account::GetOwner()
{
    return this->owner;
}
Client* Account::GetPartner()
{
    return this->partner;
}

    //jine metody
bool Account::CanWithdraw(double a)
{
    if(this->balance >= a && a > 0) return true;
    else return false;
}

void Account::Deposit(double a)
{
    if (a > 0){
        this->balance += a;
    }
}
bool Account::Withdraw(double a)
{
    if (this->CanWithdraw(a)){
        this->balance -= a;
        return true;
    }
    else return false;
}

void Account::AddInterest()
{
    double amount = this->balance * this->interestRate;
    this->balance += amount;
}


//Implementace třídy Bank
Bank::Bank(int c, int a)
{
    this->clientsCount = 0;
    this->accountsCount = 0;
    this->clients = new Client*[c];
    this->accounts = new Account*[a];
}

Bank::~Bank()
{
    for (int i = 0; i < this->accountsCount; i++){
        delete this->accounts[i];
    }
    for (int i = 0; i < this->clientsCount; i++){
        delete this->clients[i];
    }
    delete[] this->accounts;
    delete[] this->clients;

}

Client* Bank::GetClient(int c)
{
    for (int i = 0; i < this->clientsCount; i++){
        if (this->clients[i]->GetCode() == c){
            return this->clients[i];
        }
    }

    return nullptr;

}

Account* Bank::GetAccount(int n)
{
    for (int i = 0; i < this->accountsCount; i++){
        if (this->accounts[i]->GetNumber() == n) {
            return this->accounts[i];
        }
    }
    return nullptr;
}

Client* Bank::CreateClient(int c, std::string n)
{
    Client* cl = new Client(c, n);
    this->clients[this->clientsCount] = cl;
    this->clientsCount+=1;

    return cl;
}

Account* Bank::CreateAccount(int n, Client* c)
{
    Account* acc = new Account(n, c);
    this->accounts[this->accountsCount] = acc;
    this->accountsCount+=1;

    return acc;
}

Account* Bank::CreateAccount(int n, Client* c, double ir) 
{
    Account* acc = new Account(n, c, ir);
    this->accounts[this->accountsCount] = acc;
    this->accountsCount+=1;

    return acc;
}

Account* Bank::CreateAccount(int n, Client* c, Client* p)
{
    Account* acc = new Account(n, c, p);
    this->accounts[this->accountsCount] = acc;
    this->accountsCount+=1;

    return acc;

}


Account* Bank::CreateAccount(int n, Client* c, Client* p, double ir)
{
    Account* acc = new Account(n, c, p, ir);
    this->accounts[this->accountsCount] = acc;
    this->accountsCount+=1;

    return acc;
}

void Bank::AddInterest()
{
    for (int i = 0; i < this->accountsCount; i++) {
        this->accounts[i]->AddInterest();
    }
}



int main()
{
    Bank* bank = new Bank(10, 10);

    Client* c1 = bank->CreateClient(1, "Pavel Kohut");
    Client* c2 = bank->CreateClient(2, "Maria Fofova");
    Client* c3 = bank->CreateClient(3, "Jan Novak");
    Client* c4 = bank->CreateClient(4, "Eva Svobodova");
    Client* c5 = bank->CreateClient(5, "Petr Dvorak");
    Client* c6 = bank->CreateClient(6, "Anna Horakova");
    Client* c7 = bank->CreateClient(7, "Lucie Kralova");
    Client* c8 = bank->CreateClient(8, "Tomas Vesely");
    Client* c9 = bank->CreateClient(9, "Martin Cerny");
    Client* c10 = bank->CreateClient(10, "Tereza Pokorna");

    Account* acc1 = bank->CreateAccount(1001, c1);
    Account* acc2 = bank->CreateAccount(1002, c1, c2, 0.05);
    Account* acc3 = bank->CreateAccount(1003, c3, 0.03);
    Account* acc4 = bank->CreateAccount(1004, c4);
    Account* acc5 = bank->CreateAccount(1005, c5, c6, 0.02);
    Account* acc6 = bank->CreateAccount(1006, c7, 0.04);
    Account* acc7 = bank->CreateAccount(1007, c8);
    Account* acc8 = bank->CreateAccount(1008, c9, c10, 0.01);
    Account* acc9 = bank->CreateAccount(1009, c2, 0.06);
    Account* acc10 = bank->CreateAccount(1010, c6, c7);

    acc1->Deposit(5000);
    acc2->Deposit(12000);
    acc3->Deposit(8000);
    acc4->Deposit(3500);
    acc5->Deposit(10000);
    acc6->Deposit(7200);
    acc7->Deposit(4100);
    acc8->Deposit(15000);
    acc9->Deposit(6300);
    acc10->Deposit(2000);

    acc1->Withdraw(1000);
    acc2->Withdraw(2500);
    acc4->Withdraw(500);
    acc7->Deposit(900);
    acc10->Withdraw(300);

    bank->AddInterest();

    std::cout << "Klient 1: " << bank->GetClient(1)->GetName() << std::endl;
    std::cout << "Klient 6: " << bank->GetClient(6)->GetName() << std::endl;
    std::cout << "Ucet 1001, zustatek: " << bank->GetAccount(1001)->GetBalance() << std::endl;
    std::cout << "Ucet 1002, zustatek: " << bank->GetAccount(1002)->GetBalance() << std::endl;
    std::cout << "Ucet 1008, zustatek: " << bank->GetAccount(1008)->GetBalance() << std::endl;
    std::cout << "Ucet 1009, zustatek: " << bank->GetAccount(1009)->GetBalance() << std::endl;

    delete bank;
    return 0;
}





