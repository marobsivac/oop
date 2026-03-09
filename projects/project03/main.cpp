#include <iostream>
/*Modularita - druhý ukol: Vytvořte podobnou třídu jako KeyValue, ale s hodnotou i klíčem typu
(třídy) string a se dvěma sousedícími (next) objekty. Výsledkem bude tzv.
strom.
*/


class LikeKeyValue
{
    private:
        std::string key;
        std::string value;
        LikeKeyValue* next1;
        LikeKeyValue* next2;
    
    public:
        LikeKeyValue(std::string k, std::string v);
        ~LikeKeyValue();
        std::string GetKey();
        std::string GetValue();

        LikeKeyValue* CreateNext1(std::string k, std::string v);
        LikeKeyValue* CreateNext2(std::string k, std::string v);
        LikeKeyValue* GetNext1();
        LikeKeyValue* GetNext2();

    
};


LikeKeyValue::LikeKeyValue(std::string k, std::string v) {
    this->key = k;
    this->value = v;
    this->next1 = nullptr;
    this->next2 = nullptr;
}

LikeKeyValue::~LikeKeyValue() {
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

std::string LikeKeyValue::GetKey()
{
    return this->key;
}

std::string LikeKeyValue::GetValue()
{
    return this->value;
}

LikeKeyValue* LikeKeyValue::CreateNext1(std::string k, std::string v)
{
    this->next1 = new LikeKeyValue(k, v);
    return this->next1;
}

LikeKeyValue* LikeKeyValue::CreateNext2(std::string k, std::string v)
{
    this->next2 = new LikeKeyValue(k, v);
    return this->next2;
}

LikeKeyValue* LikeKeyValue::GetNext1()
{
    return this->next1;
}

LikeKeyValue* LikeKeyValue::GetNext2()
{
    return this->next2;
}

int main()
{
    LikeKeyValue* root = new LikeKeyValue("A", "Value A");
    LikeKeyValue* child1 = root->CreateNext1("B", "Value B");
    LikeKeyValue* child2 = root->CreateNext2("C", "Value C");

    std::cout << "Root Key: " << root->GetKey() << ", Value: " << root->GetValue() << std::endl;
    std::cout << "Child 1 Key: " << child1->GetKey() << ", Value: " << child1->GetValue() << std::endl;
    std::cout << "Child 2 Key: " << child2->GetKey() << ", Value: " << child2->GetValue() << std::endl;


}

