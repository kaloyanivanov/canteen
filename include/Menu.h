#ifndef MENU_H
#define MENU_H
using namespace std;
#include <fstream>
#include <vector>
#include <string>
#include "Manager.h"
#include "Product.h"

class Menu : public Manager
{
    public:
        Menu();
        Menu(vector<Product>);
        ~Menu();
        void writeProducts(string);
        void readProducts(string);
        vector<Product> get_products();
        void set_products(vector<Product>);
        void addProduct();
        void removeProduct();
        void viewMenu();
        Product findProduct(int);
        void editProductQuantity(int id, int quantity);

    private:
        vector<Product> products;
        ofstream fileToWrite;
        ifstream fileToRead;
        void input_price(double&);

};

#endif // MENU_H
