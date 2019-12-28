#ifndef INQUIRY_HPP
#define INQUIRY_HPP
#include "soa.hpp"

template<typename T>
class Inquiry
{
private:
    
    string inquiryId;
    T product;
    string side;
    long quantity;
    double price;
    string state;
    
public:
    
    //constructor and destructor
    Inquiry();
    Inquiry(string _inquiryId, const T &_product, string _side, long _quantity, double _price, string  _state);
    Inquiry(const Inquiry<T>&);
    ~Inquiry();
    
    //getters
    const string& GetInquiryId() const;
    const T& GetProduct() const;
    const string& GetSide() const;
    long GetQuantity() const;
    double GetPrice() const;
    const string& GetState() const;
    
    //operator overloading
    Inquiry& operator=(Inquiry<T>& );
    friend ostream& operator<<(ostream& os, Inquiry& source)
    {
        os<<"Inqury: "<<endl<<source.inquiryId<<","<<source.product<<","<<source.side<<","<<source.quantity<<","<<source.price<<","<<source.state<<endl;
        return os;
    }
};

template<typename T>
Inquiry<T>::Inquiry():inquiryId("T1"),product(Bond()),side("BUY"),quantity(0),price(100),state("RECEIVED")
{

}

template<typename T>
Inquiry<T>::Inquiry(string _inquiryId, const T &_product, string _side, long _quantity, double _price, string _state) : inquiryId(_inquiryId),side(_side),quantity(_quantity),price(_price),state(_state),product(_product)
{
   
}

template<typename T>
Inquiry<T>::Inquiry(const Inquiry<T>& source):inquiryId(source.inquiryId),product(source.product),side(source.side),quantity(source.quantity),price(source.price),state(source.state)
{
    
}

template<typename T>
Inquiry<T>::~Inquiry()
{

}

template<typename T>
const string& Inquiry<T>::GetInquiryId() const
{
    return inquiryId;
}
template<typename T>
const T& Inquiry<T>::GetProduct() const
{
    return product;
}
template<typename T>
const string& Inquiry<T>::GetSide() const
{
    return side;
}

template<typename T>
long Inquiry<T>::GetQuantity() const
{
    return quantity;
}

template<typename T>
double Inquiry<T>::GetPrice() const
{
    return price;
}

template<typename T>
const string& Inquiry<T>::GetState() const
{
    return state;
}

template<typename T>
Inquiry<T>& Inquiry<T>::operator=(Inquiry<T>& source)
{
    inquiryId = source.inquiryId;
    product = source.product;
    side = source.side;
    quantity = source.quantity;
    price = source.price;
    state = source.state;
    return * this;
}

#endif /* Inquiry_h */
