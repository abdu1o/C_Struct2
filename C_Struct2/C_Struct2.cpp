#include <iostream>
#include "windows.h"
using namespace std;

struct car
{
    string color;
    string model;
    char number[8];
};

void FillCars(car cars[], const int size);
void PrintCars(car cars[], const int size);
void ChooseOptions(car cars[], const int size);
void EditCar(car cars[], int count, int choise);
void SearchByNum(car cars[], const int size);

int main()
{
    const int size = 2;
    int choice = 1;

    car cars[size];

    FillCars(cars, size);
    system("cls");

    while (choice != 0)
    {
        cout << "Choose option:\n\n[1] Print cars \n[2] Edit car \n[3] Search car by number\
                     \n[0] Exit\n\n";
        cin >> choice;

        if (choice == 1)
        {
            PrintCars(cars, size);
        }
        else if (choice == 2)
        {
            ChooseOptions(cars, size);
        }
        else if (choice == 3)
        {
            SearchByNum(cars, size);
        }
    }
}

void FillCars(car cars[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\Car " << i + 1 << "\n\n";

        cout << "Enter color: ";
        cin >> cars[i].color;

        cout << "Enter model: ";
        cin >> cars[i].model;

        cout << "Enter number: ";
        cin >> cars[i].number;

    }
}

void PrintCars(car cars[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << " - Color: " << cars[i].color << "\nModel: "
            << cars[i].model << "\nNumber: " << cars[i].number << "\n\n";
    }
}

void ChooseOptions(car cars[], const int size)
{
    int number, choise;

    cout << "Choose number of car to edit: ";
    cin >> number;

    if (number >= 1 && number <= 10)
    {
        cout << "Choose what to change: \n[1] color \n[2] model \n[3] number \n";
        cin >> choise;
        EditCar(cars, number, choise);
    }
    else
    {
        system("cls");
        ChooseOptions(cars, size);
    }
}

void EditCar(car cars[], int count, int choise)
{
    switch (choise)
    {
        case 1:
        {
            cout << "Enter new color: ";
            cin >> cars[count - 1].color;
            break;
        }
        case 2:
        {
            cout << "Enter new model: ";
            cin >> cars[count - 1].model;
            break;
        }
        case 3:
        {
            cout << "Enter new number: ";
            cin >> cars[count - 1].number;
            break;
        }
        default:
        {
            break;
        }
    }
}

void SearchByNum(car cars[], const int size)
{
    char search_num[8];

    cout << "Enter number of car:\n";
    cin >> search_num;

    for (int i = 0; i < size; i++)
    {
        if (strcmp(search_num, cars[i].number) == 0)
        {
            cout << "Color: " << cars[i].color << "\nModel: " << cars[i].model << "\nNumber: " << cars[i].number;
            break;
        }
        else if (i == size - 1)
        {
            cout << "Not found!\n";
        }
    }
}