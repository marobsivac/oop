#include <iostream>


class KeyValue 
{
    private:
        int key;
        double value;
        KeyValue* next;

    public:
        KeyValue(int k, double v);
        ~KeyValue();
        int GetKey();
        double GetValue();
        KeyValue* GetNext();
        KeyValue* CreateNext(int k, double v);
};

KeyValue::KeyValue(int k, double v) {
    this->key = k;
    this->value = v;
    this->next = nullptr;
}

KeyValue::~KeyValue() {
    if (this->next != nullptr)
    {
        delete this ->next;
        this ->next = nullptr;

    }
}


KeyValue* KeyValue::GetNext() 
{
    return this->next;
}

KeyValue* KeyValue::CreateNext(int k, double v)
{
    this->next = new KeyValue(k, v);
    return this->next;
}

int KeyValue::GetKey()
{
    return this->key;
}

double KeyValue::GetValue()
{
    return this->value;
}


int main()
{
    KeyValue* first = new KeyValue(1, 3);
    int i = 0;
    KeyValue* last = first;
    while(i < 1000)
    {
        last = last->CreateNext(i, i + 1);
        i++;
    }

    KeyValue* current = first;

    while (current != nullptr)
    {
        std::cout << "Key: " << current->GetKey()
                << ", Value: " << current->GetValue()
                << std::endl;

        current = current->GetNext();
    }




}