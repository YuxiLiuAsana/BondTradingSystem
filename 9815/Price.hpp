#ifndef PRICE_HPP
#define PRICE_HPP

#include <string>
#include "soa.hpp"
#include "Bond.hpp"

template<typename T>
class Price
{
    
private:
    
    T product;
    double mid;
    double bidOfferSpread;
    
public:
    
    //constructor and destructor
    Price();
    Price(const T &_product, double _mid, double _bidOfferSpread);
    Price(const Price<T>&);
    ~Price();
    
    //Getters
    const T& GetProduct() const;
    double GetMid() const;
    double GetBidOfferSpread() const;
    
    //Operator Overload
    Price<T>& operator=(Price<T>& source);
    friend ostream& operator<<(ostream& os, Price& source)
    {
        os<<"Price: "<<source.product<<source.mid<<","<<source.bidOfferSpread<<endl;
        return os;
    }
};

template<typename T>
Price<T>::Price():product(Bond()),mid(100),bidOfferSpread(0)
{
    
}

template<typename T>
Price<T>::Price(const T &_product, double _mid, double _bidOfferSpread) :
product(_product),mid(_mid),bidOfferSpread(_bidOfferSpread)
{
    
}

template<typename T>
Price<T>::Price(const Price<T>& source):product(source.product),mid(source.mid),bidOfferSpread(source.bidOfferSpread)
{

}

template<typename T>
Price<T>::~Price()
{

}

template<typename T>
const T& Price<T>::GetProduct() const
{
    return product;
}

template<typename T>
double Price<T>::GetMid() const
{
    return mid;
}

template<typename T>
double Price<T>::GetBidOfferSpread() const
{
    return bidOfferSpread;
}

template<typename T>
Price<T>& Price<T>::operator=(Price<T>& source)
{
    product = source.product;
    mid = source.mid;
    bidOfferSpread = source.bidOfferSpread;
    return * this;
}




#endif /* Price_h */
