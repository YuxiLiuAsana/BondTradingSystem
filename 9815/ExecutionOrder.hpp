#ifndef EXECUTIONORDER_HPP
#define EXECUTIONORDER_HPP

#include <iostream>
#include <string>
#include "Bond.hpp"
using namespace std;

template<typename T>
class ExecutionOrder
{
    
private:
    
    T product;
    string side;
    string orderId;
    string orderType;
    double price;
    long visibleQuantity;
    long hiddenQuantity;
    string parentOrderId;
    bool isChildOrder;
    
public:
    
    //constructor and destructor
    ExecutionOrder();
    ExecutionOrder(const T &_product, string _side, string _orderId, string _orderType, double _price, long _visibleQuantity, long _hiddenQuantity, string _parentOrderId, bool _isChildOrder);
    ExecutionOrder(const ExecutionOrder<T>&);
    ~ExecutionOrder();
    
    //Getters
    const T& GetProduct() const;
    const string& GetSide() const;
    const string& GetOrderId() const;
    const string& GetOrderType() const;
    double GetPrice() const;
    long GetVisibleQuantity() const;
    long GetHiddenQuantity() const;
    const string& GetParentOrderId() const;
    bool IsChildOrder();
    
    //operator overload
    ExecutionOrder<T>& operator=(ExecutionOrder<T>&);
    friend ostream& operator<<(ostream& os, ExecutionOrder<T>& source)
    {
        
        os<<"ExecutionOrder: "<<source.product<<source.side<<","<<source.orderId<<","<<source.orderType<<","<<source.price<<","<<source.visibleQuantity<<","<<source.hiddenQuantity<<","<<source.parentOrderId<<","<<source.isChildOrder<<endl;
        return os;
    }

    
};

template<typename T>
ExecutionOrder<T>::ExecutionOrder():product(Bond()),side("BUY"),orderId("T1"),orderType("LIMIT"),price(0),visibleQuantity(10000000),hiddenQuantity(10000000),parentOrderId("T1"),isChildOrder(false)
{

}

template<typename T>
ExecutionOrder<T>::ExecutionOrder(const T &_product, string _side, string _orderId, string _orderType, double _price, long _visibleQuantity,long _hiddenQuantity, string _parentOrderId, bool _isChildOrder):
product(_product),side(_side),orderId(_orderId),orderType(_orderType),price(_price),visibleQuantity(_visibleQuantity),hiddenQuantity(_hiddenQuantity),parentOrderId(_parentOrderId),isChildOrder(_isChildOrder)
{
   
}

template<typename T>
ExecutionOrder<T> :: ExecutionOrder(const ExecutionOrder<T>& source):product(source.product),side(source.side),orderId(source.orderId),orderType(source.orderType),price(source.price),visibleQuantity(source.visibleQuantity),hiddenQuantity(source.hiddenQuantity),parentOrderId(source.parentOrderId),isChildOrder(source.isChildOrder)
{

}

template<typename T>
ExecutionOrder<T>::~ExecutionOrder()
{

}

template<typename T>
const T& ExecutionOrder<T>::GetProduct() const
{
    return product;
}

template<typename T>
const string& ExecutionOrder<T>::GetSide() const
{
    return side;
}

template<typename T>
const string& ExecutionOrder<T>::GetOrderId() const
{
    return orderId;
}

template<typename T>
const string& ExecutionOrder<T>::GetOrderType() const
{
    return orderType;
}

template<typename T>
double ExecutionOrder<T>::GetPrice() const
{
    return price;
}

template<typename T>
long ExecutionOrder<T>::GetVisibleQuantity() const
{
    return visibleQuantity;
}

template<typename T>
long ExecutionOrder<T>::GetHiddenQuantity() const
{
    return hiddenQuantity;
}

template<typename T>
const string& ExecutionOrder<T>::GetParentOrderId() const
{
    return parentOrderId;
}

template<typename T>
bool ExecutionOrder<T>::IsChildOrder()
{
    return isChildOrder;
}

template<typename T>
ExecutionOrder<T>& ExecutionOrder<T>:: operator=(ExecutionOrder<T>& source)
{
    side = source.side;
    orderId = source.orderId;
    orderType = source.orderType;
    price = source.price;
    visibleQuantity = source.visibleQuantity;
    hiddenQuantity = source.hiddenQuantity;
    parentOrderId = source.parentOrderId;
    isChildOrder = source.isChildOrder;
    return *this;
}

#endif
