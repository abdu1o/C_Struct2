#include <iostream>
#include <string>
#include "windows.h"
using namespace std;


//Struct cars=================================================
//struct car
//{
//    string color;
//    string model;
//    char number[8];
//};
//
//void FillCars(car cars[], const int size);
//void PrintCars(car cars[], const int size);
//void ChooseOptions(car cars[], const int size);
//void EditCar(car cars[], int count, int choise);
//void SearchByNum(car cars[], const int size);
//
//int main()
//{
//    const int size = 2;
//    int choice = 1;
//
//    car cars[size];
//
//    FillCars(cars, size);
//    system("cls");
//
//    while (choice != 0)
//    {
//        cout << "Choose option:\n\n[1] Print cars \n[2] Edit car \n[3] Search car by number\
//                     \n[0] Exit\n\n";
//        cin >> choice;
//
//        if (choice == 1)
//        {
//            PrintCars(cars, size);
//        }
//        else if (choice == 2)
//        {
//            ChooseOptions(cars, size);
//        }
//        else if (choice == 3)
//        {
//            SearchByNum(cars, size);
//        }
//    }
//}
//
//void FillCars(car cars[], const int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << "\Car " << i + 1 << "\n\n";
//
//        cout << "Enter color: ";
//        cin >> cars[i].color;
//
//        cout << "Enter model: ";
//        cin >> cars[i].model;
//
//        cout << "Enter number: ";
//        cin >> cars[i].number;
//
//    }
//}
//
//void PrintCars(car cars[], const int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << i + 1 << " - Color: " << cars[i].color << "\nModel: "
//            << cars[i].model << "\nNumber: " << cars[i].number << "\n\n";
//    }
//}
//
//void ChooseOptions(car cars[], const int size)
//{
//    int number, choise;
//
//    cout << "Choose number of car to edit: ";
//    cin >> number;
//
//    if (number >= 1 && number <= 10)
//    {
//        cout << "Choose what to change: \n[1] color \n[2] model \n[3] number \n";
//        cin >> choise;
//        EditCar(cars, number, choise);
//    }
//    else
//    {
//        system("cls");
//        ChooseOptions(cars, size);
//    }
//}
//
//void EditCar(car cars[], int count, int choise)
//{
//    switch (choise)
//    {
//        case 1:
//        {
//            cout << "Enter new color: ";
//            cin >> cars[count - 1].color;
//            break;
//        }
//        case 2:
//        {
//            cout << "Enter new model: ";
//            cin >> cars[count - 1].model;
//            break;
//        }
//        case 3:
//        {
//            cout << "Enter new number: ";
//            cin >> cars[count - 1].number;
//            break;
//        }
//        default:
//        {
//            break;
//        }
//    }
//}
//
//void SearchByNum(car cars[], const int size)
//{
//    char search_num[8];
//
//    cout << "Enter number of car:\n";
//    cin >> search_num;
//
//    for (int i = 0; i < size; i++)
//    {
//        if (strcmp(search_num, cars[i].number) == 0)
//        {
//            cout << "Color: " << cars[i].color << "\nModel: " << cars[i].model << "\nNumber: " << cars[i].number;
//            break;
//        }
//        else if (i == size - 1)
//        {
//            cout << "Not found!\n";
//        }
//    }
//}
//============================================================



struct Entity
{
    string color;
    string type;
    int ms;

    bool isHuman;
    bool isBird;
    bool isAnimal;

    double ms_flight;
    bool hooves;
    int iq;

    void SetSpeed()
    {
        cout << "Enter move speed: ";
        cin >> ms;
    }

    void SetType()
    {
        cout << "Enter type: ";
        cin >> type;
    }

    void SetColor()
    {
        cout << "Enter color: ";
        cin >> color;
    }
    
    void SetFlightSpeed()
    {
        cout << "Enter flight speed: ";
        cin >> ms_flight;
    }

    void isHooves()
    {
        cout << "Artiodactyl creature? \n[1/0]\n ";
        cin >> hooves;
    }

    void SetIq()
    {
        cout << "Enter iq: ";
        cin >> iq;
    }

    void PrintHuman()
    {
        cout << "Type: " << type << endl;
        cout << "Color: " << color << endl;
        cout << "Speed: " << ms << endl;
        cout << "Iq: " << iq << endl;
    }

    void PrintBird()
    {
        cout << "Type: " << type << endl;
        cout << "Color: " << color << endl;
        cout << "Speed: " << ms << endl;
        cout << "Flight speed: " << ms_flight << endl;
    }

    void PrintAnimal()
    {
        cout << "Type: " << type << endl;
        cout << "Color: " << color << endl;
        cout << "Speed: " << ms << endl;
        cout << "Is artiodactyl: " << hooves << endl;
    }

};

void WhatType(Entity structure);
void EditEntity(Entity creatures[3]);
void SearchEntity(Entity structure);

int main()
{
    Entity human{};
    Entity animal{};
    Entity bird{};
    Entity creatures[3] = { human, animal, bird };

    for (int i = 0; i < 3; i++)
    {
        creatures[i].SetSpeed();
        creatures[i].SetType();
        creatures[i].SetColor();
        WhatType(creatures[i]);
        system("cls");
    }
}

void SearchEntity(Entity structure)
{
    if (structure.isHuman)
    {
        structure.PrintHuman();
    }

    else if (structure.isAnimal)
    {
        structure.PrintAnimal();
    }

    else if (structure.isBird)
    {
        structure.PrintBird();
    }
}

void EditEntity(Entity creatures[3])
{
    int CreatureNum;
    cout << "Enter creature to edit it [1 - 3]: ";
    cin >> CreatureNum;

    CreatureNum -= 1;

    creatures[CreatureNum].SetSpeed();
    creatures[CreatureNum].SetType();
    creatures[CreatureNum].SetColor();

    WhatType(creatures[CreatureNum]);
}

void WhatType(Entity str)
{
    if (str.type == "human")
    {
        str.SetIq();
        str.PrintHuman();
        str.isHuman = true;
    }

    else if (str.type == "animal")
    {
        str.isHooves();
        str.PrintAnimal();
        str.isAnimal = true;
    }

    else if (str.type == "bird")
    {
        str.SetFlightSpeed();
        str.PrintBird();
        str.isBird = true;
    }
}
