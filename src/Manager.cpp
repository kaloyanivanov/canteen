#include "Manager.h"

Manager::Manager()
{
    //ctor
}

Manager::~Manager()
{
    //dtor
}

void Manager::input_id(int& id)
{
    cin >> id;
    if(id <= 0)
    {
        cout << "Invalid id try again" << endl;
        input_id(id);

    }
}

void Manager::input_quantity(int& quantity)
{
    cin >> quantity;
    if(quantity <= 0)
    {
        cout << "Invalid quantity try again" << endl;
        input_quantity(quantity);
    }
}
