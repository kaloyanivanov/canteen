#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

Menu::Menu(vector<Product> products)
{
    this->products=products;
}


vector<Product> Menu::get_products()
{
    return products;
}

void Menu::set_products(vector<Product> products)
{
    this->products=products;
}

void Menu::writeProducts(string path)
{
    fileToWrite.open(path, ios::out);
    for(Product product:products)
    {
             fileToWrite << product;

    }
     fileToWrite.close();
}

void Menu::readProducts(string path)
{
    fileToRead.open(path, ios::in);
    while (!fileToRead.eof())
    {
             Product tempProduct;
             fileToRead>>tempProduct;
             if(fileToRead.eof()) break;
             products.push_back(tempProduct);
    }
    fileToRead.close();
}

void Menu::addProduct()
{
    Product p;
    cout << "Enter product id:" << endl;
    int productId;
    input_id(productId);
    p.set_id(productId);
    cout << "Enter product name:" << endl;
    string name;
    cin >> name;
    p.set_name(name);
    cout << "Enter product price:" << endl;
    double price;
    input_price(price);
    p.set_price(price);
    cout << "Enter product quantity:" << endl;
    int quantity;
    cin >> quantity;
    p.set_quantity(quantity);
    products.push_back(p);
}

void Menu::input_price(double& price)
{
    cin >> price;
    if(price <= 0)
    {
        cout << "Invalid price try again" << endl;
        input_price(price);
    }
}

void Menu::removeProduct()
{
    cout << "Enter id of product which you want to delete" << endl;
    int productId;
    cin >> productId;
    for(unsigned int i = 0; i < products.size(); i++)
    {
        if(productId==products[i].get_id()) products.erase(products.begin()+i);
    }
}

void Menu::viewMenu()
{
    for(Product product: products)
    {
        cout << product;
    }
}

Product Menu::findProduct(int id)
{
    for(Product product: products)
    {
        if(product.get_id()== id) return product;
    }
    Product p;
    return p;
}

void Menu::editProductQuantity(int id, int quantity)
{
       for(unsigned int i = 0; i < products.size(); i++)
    {
        if(id==products[i].get_id()) products[i].set_quantity(quantity);
    }
}
