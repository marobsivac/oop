#include <iostream>
#include <string>

class Look
{
    private:
        std::string color;
        std::string height;
        std::string material;
    
    public:
        Look(std::string c, std::string h, std::string m);
        std::string get_color();
        std::string get_height();
        std::string get_material();

    };

class Guns
{
    
    private:
        std::string name;
        std::string type;
        

    public:
        Guns(std::string n, std::string t);
        std::string get_name();
        std::string get_type();
        

};

class Equipment
{
    private:
        Guns** guns;
        bool has_shield;

    public:
        Equipment(Guns**g, bool s);
        ~Equipment();

        Equipment(const Equipment&) = delete;
        Equipment& operator=(const Equipment&) = delete;

        Guns** get_guns();
        bool is_shield();
        int get_guns_count();

};

class Army_Robot
{
    private:
        Look* vzhled;
        Equipment* vybaveni;
        int HP;

    public:
        Army_Robot(Look* v, Equipment* vyb, int hp);
        void decrease_hp(int n);
        void increase_hp(int n);
        Look* get_look();
        Equipment* get_equipment();

        Look* change_look(std::string c, std::string h, std::string m);
        Equipment* change_equipment(Guns** g, bool s);
        ~Army_Robot();

        Army_Robot(const Army_Robot&) = delete;
        Army_Robot& operator=(const Army_Robot&) = delete;


};

//Implementace třídy LOOK
Look::Look(std::string c, std::string h, std::string m)
{
    this->color = c;
    this->height = h;
    this->material = m;
}

std::string Look::get_color()
{
    return this->color;
}

std::string Look::get_height()
{
    return this->height;
}

std::string Look::get_material()
{
    return this->material;
}

//Implementace třídy GUNS

Guns::Guns(std::string n, std::string t)
{
    this->name = n;
    this->type = t;
}

std::string Guns::get_name()
{
    return this->name;
}

std::string Guns::get_type()
{
    return this->type;
}



//Implementace třídy Equimpment

Equipment::Equipment(Guns**g, bool s)
{
    this->guns = g;
    this->has_shield = s;
}

int Equipment::get_guns_count()
{
    int count = 0;
    for (int i = 0; this->guns[i] != nullptr; i++)
    {
        count++;
    }
    return count;
}


Equipment::~Equipment()
{
    int n = get_guns_count();
    for (int i = 0; i < n; i++)
    {
        delete this->guns[i];
    }
    delete[] this->guns;
}

Guns** Equipment::get_guns()
{
    return this->guns;
}

bool Equipment::is_shield()
{
    return this->has_shield;
}

//Implementace třídy Army_Robot

Army_Robot::Army_Robot(Look* v, Equipment* vyb, int hp)
{
    this->vzhled = v;
    this->vybaveni = vyb;
    this->HP = hp;
}

void Army_Robot::decrease_hp(int n)
{
    this->HP -= n;
}

void Army_Robot::increase_hp(int n)
{
    this->HP += n;
}

Look* Army_Robot::get_look()
{
    return this->vzhled;
}
Equipment* Army_Robot::get_equipment()
{
    return this->vybaveni;
}

Look* Army_Robot::change_look(std::string c, std::string h, std::string m)
{
    delete this->vzhled;
    this->vzhled = new Look(c, h, m);
    return this->vzhled;
}

Equipment* Army_Robot::change_equipment(Guns** g, bool s)
{
    delete this->vybaveni;
    this->vybaveni = new Equipment(g, s);
    return this->vybaveni;
}

Army_Robot::~Army_Robot()
{
    delete this->vzhled;
    delete this->vybaveni;
}


int main()
{
    Look* look = new Look("red", "tall", "metal");
    Guns* gun1 = new Guns("AK-47", "rifle");
    Guns* gun2 = new Guns("M16", "rifle");
    Guns** guns = new Guns*[3];
    guns[0] = gun1;
    guns[1] = gun2;
    guns[2] = nullptr;
    Equipment* equipment = new Equipment(guns, true);
    Army_Robot* robot = new Army_Robot(look, equipment, 100);

    std::cout << "Robot's look: " << robot->get_look()->get_color() << ", " << robot->get_look()->get_height() << ", " << robot->get_look()->get_material() << std::endl;
    std::cout << "Robot's equipment: " << (robot->get_equipment()->is_shield() ? "has shield" : "no shield") << ", guns count: " << robot->get_equipment()->get_guns_count() << std::endl;

    delete robot;
    return 0;
}