#include "Order.h"

Order::Order()
{
    this->percentage=0;
}

Order::~Order()
{
    //dtor
}

Order::Order(int id,Customer customer,vector<OrderElement> elements,double percentage)
{
    this->id = id;
    this->customer = customer;
    this->elements = elements;
    this->percentage=percentage;
}


int Order::get_id()
{
    return id;
}


void Order::set_id(int id)
{
    this->id=id;
}

Customer Order::get_customer()
{
    return customer;
}


void Order::set_customer(Customer customer)
{
    this->customer=customer;
}

vector<OrderElement> Order::get_elements()
{
    return elements;
}


void Order::set_elements(vector<OrderElement>elements)
{
        this->elements = elements;
}


double Order::get_total()
{
    this->caluclateTotal();
    return total;
}


void Order::caluclateTotal()
{
    double total=0;

    for(OrderElement element:elements)
    {
       total=total+element.get_total();
    }
    total=total + percentage/100*total;
    this->total=total;
}

ostream& operator << (ostream& output, Order order)
{
         output << "Order_Id:" << endl;
         output << order.get_id();
         output << "\n";
         Customer tempCustomer=order.get_customer();
         output << tempCustomer;
         output << "Percentage:" << endl;
         output << order.get_percentage() << endl;
         output << "Order_elements:" << endl;
         output <<order.get_elements().size();
         output << "\n";
         vector<OrderElement> elements=order.get_elements();
         for(OrderElement element:elements)
         {
             output << element;

         }
         output << "Total:" << endl;
         output << order.get_total();
         output << "\n";
         return output;
}

istream& operator >> (istream &input,  Order &order)
{
    string temp;
    input >> temp;
    int id;
    input >> id;
    order.set_id(id);
    Customer tempCustomer;
    input >> tempCustomer;
    order.set_customer(tempCustomer);
    input >> temp;
    double percentage;
    input >> percentage;
    order.set_percentage(percentage);
    input >> temp;
    int numElements;
    input >> numElements;
    vector<OrderElement> elements;
    for(int i = 0; i < numElements; i++)
    {
        OrderElement tempElement;
        input >> tempElement;
        elements.push_back(tempElement);


    }
    order.set_elements(elements);
    input >> temp;
    double total;
    input >> total;
    return input;
}

 void Order::set_percentage(double percentage)
 {
     this->percentage=percentage;
 }

 double Order::get_percentage()
 {
     return percentage;
 }





