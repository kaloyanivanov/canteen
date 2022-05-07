#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
using namespace std;



class Product
{
    public:
        Product();
        Product(int,string,double,int);
        ~Product();
        int get_id();
        void set_id(int);
        string get_name();
        void set_name(string);
        double get_price();
        void set_price(double);
         int get_quantity();
        void set_quantity(int);
        friend ostream& operator << (ostream& output, Product product);
        friend istream& operator >> (istream &input,  Product &product);

    private:
        int id;
        string name;
        double price;
        int quantity;
};

#endif // PRODUCT_H
