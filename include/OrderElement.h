#ifndef ORDERELEMENT_H
#define ORDERELEMENT_H
#include "Product.h"

class OrderElement
{
    public:
        OrderElement();
        OrderElement(Product,int);
        virtual ~OrderElement();
        Product get_product();
        void set_product(Product);
        int get_productQuantity();
        void set_productQuantity(int);
        double get_total();
        friend ostream& operator << (ostream& output, OrderElement element);
        friend istream& operator >> (istream &input,  OrderElement &element);

    private:
        Product product;
        int productQuantity;
};

#endif // ORDERELEMENT_H
