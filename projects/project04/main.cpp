/*
Implementuje strukturu (rozhodovací strom) na identifikaci zvířat nebo
rostlin. Klíčem uzlu stromu je rozhodovací kritérium, hodnotou uzlu je
název zvířete nebo rostliny, resp. druhu apod. Naplňte klíč alespoň deseti
objekty a vypište celou strukturu na obrazovku.
*/

#include <iostream>
#include <string>


class Tree
{
    private:
        std::string key;
        std::string value;
        Tree* next1;
        Tree* next2;
    public:
        Tree(std::string k, std::string v);
        ~Tree();
        std::string GetKey();
        std::string GetValue();

        Tree* CreateNext1(std::string k, std::string v);
        Tree* CreateNext2(std::string k, std::string v);
        Tree* GetNext1();
        Tree* GetNext2();
        void PrintTree(int depth = 0);
};

Tree::Tree(std::string k, std::string v) {
    this->key = k;
    this->value = v;
    this->next1 = nullptr;
    this->next2 = nullptr;
}

Tree::~Tree() {
    if (this->next1 != nullptr)
    {
        delete this ->next1;
        this ->next1 = nullptr;

    }
    if (this->next2 != nullptr)
    {
        delete this ->next2;
        this ->next2 = nullptr;

    }
}

std::string Tree::GetKey()
{
    return this->key;
}

std::string Tree::GetValue()
{
    return this->value;
}

Tree* Tree::CreateNext1(std::string k, std::string v)
{
    this->next1 = new Tree(k, v);
    return this->next1;
}
Tree* Tree::CreateNext2(std::string k, std::string v)
{
    this->next2 = new Tree(k, v);
    return this->next2;
}
Tree* Tree::GetNext1()
{
    return this->next1;
}
Tree* Tree::GetNext2()
{
    return this->next2;
}

void Tree::PrintTree(int depth)
{
    for (int i = 0; i < depth; i++)
    {
        std::cout << "  ";
    }

    std::cout << "Key: " << GetKey()
              << ", Value: " << GetValue() << std::endl;

    if (GetNext1() != nullptr)
    {
        GetNext1()->PrintTree(depth + 1);
    }

    if (GetNext2() != nullptr)
    {
        GetNext2()->PrintTree(depth + 1);
    }
}

int main()
{
    Tree* root = new Tree("Je to žijící organismus?", "Organismus");

    Tree* animals = root->CreateNext1("Je to savec?", "Zvíře");
    Tree* plants  = root->CreateNext2("Roste v zemi?", "Rostlina");

    Tree* dog = animals->CreateNext1("Štěká?", "Pes");
    Tree* cat = animals->CreateNext2("Mňouká?", "Kočka");

    Tree* shepherd  = dog->CreateNext1("Je to bojové plemeno?", "Německý ovčák");
    Tree* bernardyn = dog->CreateNext2("Je to velké plemeno?", "Bernardýn");

    Tree* sphynx = cat->CreateNext1("Má holou srst?", "Sphynx");
    Tree* perska = cat->CreateNext2("Má huňatou srst?", "Perská kočka");

    Tree* poisonous = plants->CreateNext1("Je to jedovatá rostlina?", "Jedovatá rostlina");
    Tree* medicinal = plants->CreateNext2("Je to léčivá rostlina?", "Léčivá rostlina");

    Tree* rulik      = poisonous->CreateNext1("Má červené plody?", "Rulík zlomocný");
    Tree* bily_kvet  = poisonous->CreateNext2("Má bílé květy?", "Durman");

    Tree* hermanek  = medicinal->CreateNext1("Má žlutý střed květu?", "Heřmánek");
    Tree* levandule = medicinal->CreateNext2("Má fialové květy?", "Levandule");

    root->PrintTree();
    delete root;

}