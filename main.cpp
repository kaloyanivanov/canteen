#include <iostream>
#include "common.h"
#include "OrderManager.h"

using namespace std;

void loadOrders();
void loadMenu();
void main_menu();
void set_menu();
void order_menu();

Menu menu;
OrderManager manager;
string ordersPath;
string menuPath;

int main()
{
    loadOrders();
    loadMenu();
    manager.set_percentage();
    main_menu();
    return 0;
}


void loadOrders()
{
    cout << "Enter file name of existing orders or create new." << endl;
    cin >> ordersPath;
    manager.readOrders(ordersPath);
}

void loadMenu()
{

    cout << "Enter file name of existing menu or create new." << endl;
    cin >> menuPath;
    menu.readProducts(menuPath);
}

void main_menu()
{
    cout << "You can enter the canteen menu or order menu." << endl;
    cout << "To choose the canteen menu enter 1." << endl;
    cout << "To choose the order menu enter 2." << endl;
    cout << "To exit the program enter random number." << endl;
    cout << "Enter your choice:" << endl;
    int choise;
    cin >> choise;
    switch(choise)
    {
        case 1:
            set_menu();
        break;
        case 2:
            order_menu();
        break;
        default:
            return;
    }


}

void set_menu()
{
    cout << "This is the canteen menu, enter the number on the right of an option to choose it." << endl;
    cout << "View menu                 1" << endl;
    cout << "Add product to menu       2" << endl;
    cout << "Remove product from menu  3" << endl;
    cout << "Save products to file     4" << endl;
    cout << "Return to main menu       5" << endl;

    int choise;
    cin >> choise;
    switch(choise)
    {
        case 1:
            menu.viewMenu();
            set_menu();
            break;
        case 2:
            menu.addProduct();
            set_menu();
        break;
        case 3:
            menu.removeProduct();
            set_menu();
        break;
        case 4:
            menu.writeProducts(menuPath);
            set_menu();
        break;
        case 5:
            main_menu();
        break;
        default:
            cout << "Invalid input try again." << endl;
            set_menu();

    }
}

void order_menu()
{
    cout << "View orders          1" << endl;
    cout << "View menu            2" << endl;
    cout << "Add order            3" << endl;
    cout << "Remove order         4" << endl;
    cout << "Save orders to file  5" << endl;
    cout << "Return to main menu  6" << endl;

    int choise;
    cin >> choise;
    switch(choise)
    {
        case 1:
            manager.viewOrders();
            order_menu();
        break;
        case 2:
            menu.viewMenu();
            order_menu();
        break;
        case 3:
            manager.addOrder();
            order_menu();
        break;
        case 4:
            manager.removeOrder();
            order_menu();
        break;
        case 5:
            manager.writeOrders(ordersPath);
            order_menu();
        break;
        case 6:
            main_menu();
        break;
        default:
            cout << "Invalid input try again." << endl;
            order_menu();
    }
}
