/*
Třídy a objekty - 1. část
Implementujte příklad z přednášky a do třídy KeyValues přidejte metodu
KeyValue* RemoveObject(int k), která odebere objekt s daným klíčem a vrátí
ukazatel na něj.
*/
#include <iostream>


class KeyValue
{
    private:
        int key;
        double value;

    public:
        KeyValue(int k, double v);
        int GetKey();
        double GetValue();
};

class KeyValues
{
    private:
        KeyValue** keyValues;
        int count_;

    public:
        KeyValues(int n);
        ~KeyValues();
        KeyValue* CreateObject(int k, double v);
        KeyValue* SearchObject(int k);
        KeyValue* RemoveObject(int k);
        int count();
};


KeyValues::KeyValues(int n) {
    this->keyValues = new KeyValue*[n];
    this->count_ = 0;
}



KeyValues::~KeyValues() {
    for (int i = 0; i < this->count_; i++)
    {
        delete this->keyValues[i];
    }
    delete[] this->keyValues;
}

KeyValue* KeyValues::CreateObject(int k, double v)
{
    KeyValue* newObject = new KeyValue(k, v);

    this->keyValues[this->count_] = newObject;
    this->count_+=1;

    return newObject;
}

KeyValue* KeyValues::SearchObject(int k)
{
    for (int i = 0; i < this->count_; i++)
    {
        if (this->keyValues[i]->GetKey() == k)
        {
            return this->keyValues[i];
        }
    }
    return nullptr;
}

int KeyValues::count()
{
    return this->count_;
}


KeyValue* KeyValues::RemoveObject(int k)
{
    int index = -1;
    for (int i = 0; i < this->count_; i++)
    {
        if (this->keyValues[i]->GetKey() == k)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        return nullptr;
    }

    

    KeyValue* removedObject = this->keyValues[index];

    
    for (int i = index; i < this->count_ - 1; i++)
    {
        this->keyValues[i] = this->keyValues[i + 1];
    }
    this->count_ -= 1;
    this->keyValues[this->count_] = nullptr;

    return removedObject;
}