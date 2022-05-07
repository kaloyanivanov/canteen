#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
using namespace std;

enum CustomerType { STUDENT, TEACHER, EXTERNAL };

class Customer
{
    public:
        Customer();
        Customer(int, CustomerType);
        int get_id();
        void set_id(int);
        CustomerType get_CustomerType();
        void set_CustomerType(CustomerType);
        friend ostream& operator << (ostream& output, Customer customer);
        friend istream& operator >> (istream &input,  Customer &customer);
        ~Customer();
    private:
        int id;
        CustomerType type;
};

#endif // CUSTOMER_H
