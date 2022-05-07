#include "Customer.h"

Customer::Customer()
{
    //ctor
}

Customer::~Customer()
{
    //dtor
}

Customer::Customer(int id, CustomerType type)
{
    this->id= id;
    this->type=type;
}

int Customer::get_id()
{
    return id;
}


void Customer::set_id(int id)
{
    this->id=id;
}


CustomerType Customer::get_CustomerType()
{
    return type;
}

void Customer::set_CustomerType(CustomerType type)
{
    this->type=type;
}

ostream& operator << (ostream& output, Customer customer)
{
         output << "Customer_Id:" << endl;
         output << customer.get_id();
         output << "\n";
         output << "Type:" << endl;
         output << customer.get_CustomerType();
         output << "\n";
         return output;
}

istream& operator >> (istream &input,  Customer &customer)
{
    string temp;
    input >> temp;
    int custId;
    input >> custId;
    customer.set_id(custId);
    input >> temp;
    int type;
    input >> type;
    customer.set_CustomerType((CustomerType) type);
    return input;
}

