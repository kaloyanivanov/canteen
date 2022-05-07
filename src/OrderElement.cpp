#include "OrderElement.h"

OrderElement::OrderElement()
{
    //ctor
}

OrderElement::~OrderElement()
{
    //dtor
}

OrderElement::OrderElement(Product product,int productQuantity)
{
    this->product = product;
    this->productQuantity = productQuantity;
}

Product OrderElement::get_product()
{
    return product;
}


void OrderElement::set_product(Product product)
{
    this->product = product;
}


int OrderElement::get_productQuantity()
{
    return productQuantity;
}


void OrderElement::set_productQuantity(int productQuantity)
{
    this->productQuantity = productQuantity;
}

double OrderElement::get_total()
{
    return product.get_price()*productQuantity;
}

ostream& operator << (ostream& output, OrderElement element)
{
    output << "Quantity:" << endl;
    output << element.get_productQuantity();
    output << "\n";
    Product tempProduct=element.get_product();
    output << tempProduct;
    return output;
}

istream& operator >> (istream &input,  OrderElement &element)
{
    string temp;
    input >> temp;
    int quantity;
    input >> quantity;
    element.set_productQuantity(quantity);
    Product tempProduct;
    input >> tempProduct;
    element.set_product(tempProduct);
    return input;
}




