#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H
#include <fstream>
#include <vector>
#include "Manager.h"
#include "Order.h"
using namespace std;


class OrderManager : public Manager
{
    public:
        OrderManager();
        ~OrderManager();
        OrderManager(vector<Order>);
        void writeOrders(string);
        vector<Order> readOrders(string);
        vector<Order> get_orders();
        void set_orders(vector<Order>);
        void viewOrders();
        void addOrder();
        void removeOrder();
        void set_percentage();

    private:
        vector<Order> orders;
        ofstream fileToWrite;
        ifstream fileToRead;
        double percentage[3];

};

#endif // ORDERMANAGER_H
