/*
Implementuje třídu Faktura, která bude obsahovat číslo, objekt třídy Osoba
(se jménem a adresou) a pole objektů PolozkaFaktury (s názvem, počtem a
cenou). Navrhněte konstruktor a destruktor a další potřebné metody.
Faktura bude mít metodu (funkci), která spočítá a vrátí celkovou cenu.
*/

#include <iostream>
#include <string>

//Deklarace tříd
class Osoba
{
    private:
        std::string jmeno;
        std::string adresa;
    public:
        Osoba(std::string j, std::string a);
        ~Osoba();
        std::string GetJmeno();
        std::string GetAdresa();
};

class PolozkaFaktury
{
    private:
        std::string nazev;
        int pocet;
        double cena;
    public:
        PolozkaFaktury(std::string n, int p, double c);
        ~PolozkaFaktury();
        std::string GetNazev();
        int GetPocet();
        double GetCena();
};

class Faktura
{
    private:
        PolozkaFaktury** polozky;
        Osoba osoba;
        int cislo_faktury;
        int pocetPolozek;
        int kapacita;

    public:
        Faktura(int n, Osoba o, int cislo);
        void PridejPolozku(PolozkaFaktury* polozka);
        double SpocitejCelkovaCenu();
        ~Faktura();
};

//Implementace konstrukrotu, destruktoru a metod třídy Osoba, PolozkaFaktury a Faktura

PolozkaFaktury::PolozkaFaktury(std::string n, int p, double c) {
    this->nazev = n;
    this->pocet = p;
    this->cena = c;
}

PolozkaFaktury::~PolozkaFaktury() {
}

std::string PolozkaFaktury::GetNazev() {
    return this->nazev;
}

int PolozkaFaktury::GetPocet() {
    return this->pocet;
}

double PolozkaFaktury::GetCena() {
    return this->cena;
}

Faktura::Faktura(int n, Osoba o, int cislo) : osoba(o), cislo_faktury(cislo) {
    this->polozky = new PolozkaFaktury*[n];
    this->pocetPolozek = 0;
    this->kapacita = n;
}

double Faktura::SpocitejCelkovaCenu() 
{
    double suma = 0.0;
    for (int i = 0; i < this->pocetPolozek; i++)
    {
        suma += this->polozky[i]->GetPocet() * this->polozky[i]->GetCena();
    }
    return suma;
}

void Faktura::PridejPolozku(PolozkaFaktury* polozka) {
    if (this->pocetPolozek >= this->kapacita) {
        std::cerr << "Nelze přidat další položku, kapacita faktury je plná." << std::endl;
        return;
    }
    this->polozky[this->pocetPolozek] = polozka;
    this->pocetPolozek += 1;
}

Faktura::~Faktura() {
    for (int i = 0; i < this->pocetPolozek; i++)
    {
        delete this->polozky[i];
    }
    delete[] this->polozky;
}

Osoba::Osoba(std::string j, std::string a) {
    this->jmeno = j;
    this->adresa = a;
}

Osoba::~Osoba() {
}

std::string Osoba::GetJmeno() {
    return this->jmeno;
}

std::string Osoba::GetAdresa() {
    return this->adresa;
}

int main()
{
    Osoba osoba("Jan Novak", "Praha 1");
    Faktura faktura(10, osoba, 12345);

    PolozkaFaktury* polozka1 = new PolozkaFaktury("Polozka 1", 2, 100.0);
    PolozkaFaktury* polozka2 = new PolozkaFaktury("Polozka 2", 3, 150.0);

    faktura.PridejPolozku(polozka1);
    faktura.PridejPolozku(polozka2);

    faktura.SpocitejCelkovaCenu();

    std::cout << "Celkova cena: " << faktura.SpocitejCelkovaCenu() << std::endl;

    return 0;
}