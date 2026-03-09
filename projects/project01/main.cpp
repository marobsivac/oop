#include <iostream>


class Trida {
    private:
        std::string email;
        std::string osoba;
        std::string dokument;


    public:
        Trida(std::string email, std::string osoba, std::string dokument) {
            this->email = email;
            this->osoba = osoba;
            this->dokument = dokument;
        }

        void getter() {
            std::cout << "Email: " << email << std::endl;
            std::cout << "Osoba: " << osoba << std::endl;
            std::cout << "Dokument: " << dokument << std::endl;
        }
};


int main() {

    Trida* objekt = new Trida("example@email.com", "John Doe", "Document 1");
    objekt->getter();



    return 0;
    
}