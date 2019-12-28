#ifndef TRADE_HPP
#define TRADE_HPP

#include <string>
#include <iostream>

using namespace std;

template<typename T>
class Trade
{
    
private:
    
    T product;
    string tradeId;
    string book;
    int quantity;
    double price;
    string side;

public:
    
    //constructor and destructor
    Trade();
    Trade(T &_product, string _tradeId, string _book, int _quantity ,  double _price, string _side);
    Trade(const Trade&);
    ~Trade();
    
    //Getters
    const T& GetProduct() const;
    const string& GetTradeId() const;
    const string& GetBook() const;
    int GetQuantity() const;
    double GetPrice() const;
    const string& GetSide() const;
    
    //operator overload
    Trade<T>& operator=(Trade<T>& );
    friend ostream& operator<<(ostream& os, const Trade<T>& source)
    {
        os<<"Trade: "<<endl<<source.product<<source.tradeId<<","<<source.book<<","<<source.quantity<<","<<source.price<<","<<source.side<<endl;
        return os;
    }
    
};

template< typename T >
Trade<T> :: Trade()
{
    
}

template<typename T>
Trade<T> :: Trade(T &_product, string _tradeId, string _book, int _quantity,double _price, string _side) : product(_product),tradeId(_tradeId),book(_book),quantity(_quantity),price(_price),side(_side)
{
    
}

template<typename T>
Trade<T> ::Trade(const Trade& source):product(source.product),tradeId(source.tradeId),book(source.book),quantity(source.quantity),price(source.price),side(source.side)
{
    
}

template<typename T>
Trade<T> :: ~Trade()
{

}

template<typename T>
const T& Trade<T>::GetProduct() const
{
    return product;
}

template<typename T>
const string& Trade<T>::GetTradeId() const
{
    return tradeId;
}

template<typename T>
const string& Trade<T>::GetBook() const
{
    return book;
}

template<typename T>
int Trade<T>::GetQuantity() const
{
    return quantity;
}

template<typename T>
double Trade<T>::GetPrice() const
{
    return price;
}

template<typename T>
const string& Trade<T>::GetSide() const
{
    return side;
}

template<typename T>
Trade<T>& Trade<T>::operator=(Trade<T>& source)
{
    product = source.product;
    tradeId = source.tradeId;
    book = source.book;
    quantity = source.quantity;
    price = source.price;
    side =source.side;
    return *this;
}

#endif /* Trade_hpp */
