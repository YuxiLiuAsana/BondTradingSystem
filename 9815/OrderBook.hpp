#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include<iostream>
#include "Order.hpp"
#include "Bond.hpp"
#include <vector>
using namespace std;


template<typename T>
class OrderBook
{
    
private:
    
    T product;
    vector<Order> bidStack;
    vector<Order> offerStack;
    
public:
    
    //constructor and destructor
    OrderBook();
    OrderBook(const T &_product, const vector<Order> &_bidStack, const vector<Order> &_offerStack);
    OrderBook(const OrderBook& );
    ~OrderBook();
    
    //getters
    const T& GetProduct() const;
    const vector<Order>& GetBidStack() ;
    const vector<Order>& GetOfferStack() ;
    
    //operator Overload
    OrderBook<T>& operator=( OrderBook<T> & source);
    friend ostream& operator<<(ostream& os, const OrderBook& source)
    {
        os<<"OrderBook: "<<endl<<source.product;
        for(int i = 0; i < source.bidStack.size();i++)
        {
            os<<"bid: "<<source.bidStack[i];
        }
        for(int i = 0; i < source.offerStack.size();i++)
        {
            os<<"offer: "<<source.offerStack[i];
        }
        return os;
    }
};

template<typename T>
OrderBook<T>::OrderBook():product(Bond())
{
    for(int i = 0; i < 5; i++)
    {
        Order a;
        bidStack.push_back(a);
        offerStack.push_back(a);
        
    }
}

template<typename T>
OrderBook<T>::OrderBook(const T &_product, const vector<Order> &_bidStack, const vector<Order> &_offerStack) :
product(_product), bidStack(_bidStack), offerStack(_offerStack)
{
    
}

template<typename T>
OrderBook<T>::OrderBook(const OrderBook<T>& source):product(source.product),bidStack(source.bidStack),offerStack(source.offerStack)
{

}

template<typename T>
OrderBook<T>::~OrderBook()
{

}

template<typename T>
const T& OrderBook<T>::GetProduct() const
{
    return product;
}

template<typename T>
const vector<Order>& OrderBook<T>::GetBidStack()
{
    return bidStack;
}

template<typename T>
const vector<Order>& OrderBook<T>::GetOfferStack()
{
    return offerStack;
}

template<typename T>
OrderBook<T>& OrderBook<T> :: operator=( OrderBook & source)
{
    product = source.product;
    bidStack = source.bidStack;
    offerStack = source.offerStack;
    return *this;
}



#endif /* OrderBook_h */
