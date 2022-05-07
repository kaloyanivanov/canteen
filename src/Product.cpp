#include "Product.h"

Product::Product()
{
    //ctor
}

Product::~Product()
{
    //dtor
}


Product::Product(int id,string name,double price,int quantity)
{
    this->id = id;
    this->name = name;
    this->price = price;
    this->quantity = quantity;

}
int Product::get_id()
{
    return id;
}

void Product::set_id(int id)
{
    this->id = id;
}

string Product::get_name()
{
    return name;
}

void Product::set_name(string name)
{
    this->name = name;
}

double Product::get_price()
{
    return price;
}


void Product::set_price(double price)
{
    this->price = price;
}


int Product::get_quantity()
{
    return quantity;
}



void Product::set_quantity(int quantity)
{
    this->quantity = quantity;
}

istream& operator >> (istream &input,  Product &product)
{
    string temp;
    input >> temp;
    int id;
    input >> id;
    product.set_id(id);
    input >> temp;
    string name;
    input >> name;
    product.set_name(name);
    input >> temp;
    double price;
    input >> price;
    product.set_price(price);
    input >> temp;
    int quantity;
    input >> quantity;
    product.set_quantity(quantity);
    return input;
}

ostream& operator << (ostream& output, Product product)
{
    output << "Product_Id:" << endl;
    output << product.get_id();
    output << endl;
    output << "Name:" << endl;
    output << product.get_name();
    output << endl;
    output << "Price:" << endl;
    output << product.get_price();
    output << endl;
    output << "Quantity:" << endl;
    output << product.get_quantity();
    output << endl;

    return output;
}
