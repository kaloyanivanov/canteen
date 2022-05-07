#ifndef ORDER_H
#define ORDER_H
using namespace std;
#include <vector>
#include <string>
#include "OrderElement.h"
#include "Customer.h"

class Order
{
    public:
        Order();
        Order(int,Customer,vector<OrderElement>,double);
        ~Order();
        int get_id();
        void set_id(int);
        Customer get_customer();
        void set_customer(Customer);
        vector<OrderElement> get_elements();
        void set_elements(vector<OrderElement>);
        double get_total();
        friend ostream& operator << (ostream& output, Order order);
        friend istream& operator >> (istream &input,  Order &product);
        void set_percentage(double);
        double get_percentage();

    private:
        int id;
        Customer customer;
        vector<OrderElement> elements;
        double total;
        double percentage;
        void caluclateTotal();
};

#endif // ORDER_H
