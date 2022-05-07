#include "common.h"
#include "OrderManager.h"
#include <iostream>

OrderManager::OrderManager()
{
    //ctor
}

OrderManager::~OrderManager()
{
    //dtor
}


OrderManager::OrderManager(vector<Order> orders)
{
    this->orders=orders;
}


vector<Order> OrderManager::get_orders()
{
    return orders;
}


void OrderManager::set_orders(vector<Order> orders)
{
    this->orders=orders;
}


void OrderManager::writeOrders(string path)
{
    fileToWrite.open(path, ios::out);
    for(Order order:orders)
    {
         fileToWrite << order;
    }
    fileToWrite.close();
}



vector<Order> OrderManager::readOrders(string path)
{
    fileToRead.open(path, ios::in);

    while (!fileToRead.eof())
    {
        Order order;
        fileToRead >> order;
        if(fileToRead.eof()) break;
        orders.push_back(order);
    }
    fileToRead.close();
    return orders;
}


void OrderManager::viewOrders()
{
    for(Order order: orders)
    {
        cout << order;
    }
}

void OrderManager::addOrder()
{
    Order order;
    cout << "Enter order id:" << endl;
    int id;
    input_id(id);
    order.set_id(id);
    Customer customer;
    int custId;
    cout << "Enter customer id:" << endl;
    input_id(custId);
    customer.set_id(custId);
    cout << "Enter customer type:" << endl;
    int type;
    cin >> type;
    customer.set_CustomerType((CustomerType) type);
    order.set_percentage(percentage[type]);
    order.set_customer(customer);
    vector<OrderElement> elements;
    char choise= 'y';
    while(choise=='y'||choise=='Y')
    {
        OrderElement tempElement;
        cout << "Enter product id:" << endl;
        int productId;
        input_id(productId);
        Product temp=menu.findProduct(productId);
        tempElement.set_product(temp);
        cout << "Enter product quantity:" << endl;
        int quantity;
        input_quantity(quantity);
        tempElement.set_productQuantity(quantity);
        int productQuantity=temp.get_quantity()-quantity;
        menu.editProductQuantity(productId,productQuantity);
        elements.push_back(tempElement);
        cout << "If you want to add more products to the order enter y:" << endl;
        cin >> choise;

    }
    order.set_elements(elements);
    orders.push_back(order);
}


void OrderManager::removeOrder()
{
    cout << "Enter id of order which you want to delete" << endl;
    int orderId;
    cin >> orderId;
    for(unsigned int i = 0; i < orders.size(); i++)
    {
        if(orderId==orders[i].get_id()) orders.erase(orders.begin()+i);
    }
}

void OrderManager::set_percentage()
{
    cout << "If you want to set different discount or increase for different customer groups enter y." << endl;
    char choise;
    cin >> choise;
    if(choise == 'Y' || choise == 'y')
    {
        cout << "Enter discount or increase percentage for student" << endl;
        cin >> percentage[0];
        cout << "Enter discount or increase percentage for teacher" << endl;
        cin >> percentage[1];
        cout << "Enter discount or increase percentage for external client" << endl;
        cin >> percentage[2];
        return;
    }
    percentage[0]=0;
    percentage[1]=0;
    percentage[2]=0;
}
