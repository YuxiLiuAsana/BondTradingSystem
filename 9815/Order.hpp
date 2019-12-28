#ifndef ORDER_HPP
#define ORDER_HPP
#include<iostream>

using namespace std;
class Order
{
    
private:
    
    double price;
    long quantity;
    string side;
    
public:
    //constructor and destructor
    Order();
    Order(double _price, long _quantity, string _side);
    Order(const Order&);
    ~Order();
    
    //getters
    double GetPrice() ;
    long GetQuantity() ;
    const string& GetSide() const;
    
    //operator overload
    Order& operator=(const Order&);
    Order& operator=(Order&);
    friend ostream& operator<<(ostream& os, const Order& source )
    {
        os<<"Order: "<<source.price<<","<<source.quantity<<","<<source.side<<endl;
        return os;
        
    }
};

Order::Order():price(0),quantity(0),side("BUY")
{

}

Order::Order(double _price, long _quantity, string _side):price(_price),quantity(_quantity),side(_side)
{
   
}

Order::Order(const Order& source):price(source.price),quantity(source.quantity),side(source.side)
{

}

Order::~Order()
{

}

double Order::GetPrice()
{
    return price;
}

long Order::GetQuantity()
{
    return quantity;
}

const string& Order::GetSide() const
{
    return side;
}

Order& Order::operator=(const Order& source)
{
    price = source.price;
    quantity = source.quantity;
    side = source.side;
    return *this;
}

Order& Order::operator=(Order& source)
{
    price = source.price;
    quantity = source.quantity;
    side = source.side;
    return *this;
}

#endif /* Order_h */
