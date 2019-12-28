#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
#include <iostream>
#include "boost/date_time/gregorian/gregorian.hpp"
using namespace boost::gregorian;
using namespace std;

class Product
{

private:
    
    string productId;
    string productType;
    
public:
    
    //Constructor and Destructor
    Product();
    Product(string _productId, string _productType);
    Product(const Product&);
    ~Product();
    
    //Getters
    const string& GetProductId() const;
    const string& GetProductType() const;
    
    //operator Overload
    Product& operator=(Product& );
    friend ostream& operator<<(ostream& os, const Product& source)
    {
        os<<"Product: "<<source.productId<<", "<<source.productType<<endl;
        return os;
    }
    
};

Product::Product():productId("912828M72"),productType("BOND")
{

}

Product::Product(string _productId, string _productType):productId(_productId), productType(_productType)
{

}

Product::Product(const Product& source):productId(source.productId),productType(source.productType)
{

}

Product::~Product()
{

}

const string& Product::GetProductId() const
{
    return productId;
}

const string& Product::GetProductType() const
{
    return productType;
}


Product& Product::operator=(Product& source)
{
    productId = source.productId;
    productType = source.productType;
    return *this;
}

#endif
