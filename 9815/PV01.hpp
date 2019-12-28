#ifndef PV01_HPP
#define PV01_HPP

#include <stdio.h>
#include "soa.hpp"
#include "Bond.hpp"

template<typename T>
class PV01
{
private:
    
    T product;
    double pv01;
    int quantity;
    
public:
    
    //constructor & destructor
    PV01();
    PV01(const T &_product, double _pv01, long _quantity);
    PV01(const PV01<T>&);
    ~PV01();
    
    //Getters and setters
    const T& GetProduct() const;
    double GetPV01() const;
    int GetQuantity() const;
    void SetQuantity(int );
    
    //Operator overload
    PV01<T>& operator=(PV01<T>&);
    friend ostream& operator<<(ostream& os, PV01& source)
    {
        os<<"PV01: "<<source.GetProduct()<<source.GetPV01()<<","<<source.GetQuantity()<<endl;
        return os;
    }
};

template<typename T>
PV01<T>::PV01():product(Bond()),pv01(0),quantity(0)
{
    
}

template<typename T>
PV01<T>::PV01(const T &_product, double _pv01, long _quantity) :
product(_product),pv01(_pv01),quantity(_quantity)
{
   
}

template<typename T>
PV01<T>::PV01(const PV01& source):product(source.product),pv01(source.pv01),quantity(source.quantity)
{

}

template<typename T>
PV01<T> :: ~PV01()
{

}

template<typename T>
const T& PV01<T> :: GetProduct() const
{
    return product;
}

template<typename T>
double PV01<T>::GetPV01() const
{
    return pv01;
}

template<typename T>
int PV01<T> :: GetQuantity() const
{
    return quantity;
}

template<typename T>
void PV01<T>::SetQuantity(int q)
{
    quantity = q;
}

template<typename T>
PV01<T>& PV01<T>::operator=(PV01<T>& source)
{
    product = source.product;
    pv01 = source.pv01;
    quantity = source.quantity;
    return * this;
}

#endif /* PV01_hpp */
