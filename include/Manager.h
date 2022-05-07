#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
using namespace std;

class Manager
{
    public:
        Manager();
        virtual ~Manager();

    protected:
        void input_id(int&);
        void input_quantity(int&);
};

#endif // MANAGER_H
