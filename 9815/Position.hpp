#ifndef POSITION_HPP
#define POSITION_HPP

#include <iostream>

template<typename T>//where T is the bond
class Position
{
    
private:
    
    T product;
    map<string,int> positions;//positions for product in different books
    
public:
    
    //constructor & destructor
    Position();
    Position(const T &_product);
    Position(const Position<T>& );
    ~Position();
    
    //getters
    const T& GetProduct() const;
    int GetPosition(string& book) ;
    
    //operator Overload
    Position<T>& operator=(Position<T>&);
    friend ostream& operator<<(ostream& os, Position& source)
    {
        string s1 = "TRSY1";
        string s2 = "TRSY2";
        string s3 = "TRSY3";
        os<<"Position: "<<endl<<source.GetProduct()<<"TRSY1:"<<source.GetPosition(s1)<<" TRSY2:"<<source.GetPosition(s2)<<" TRSY3:"<<source.GetPosition(s3)<<endl;
        return os;
    }
    
    
    //other Functions
    int GetAggregatePosition() ;
    void AddPosition(string &book,int quantitiy);
    
};

template<typename T>
Position<T>::Position()
{

}

template<typename T>
Position<T>::Position(const T &_product) :product(_product)
{
    positions.insert(pair<string, int>("TRSY1",0));
    positions.insert(pair<string, int>("TRSY2",0));
    positions.insert(pair<string, int>("TRSY3",0));
}

template<typename T>
Position<T>::Position(const Position<T>& source):product(source.product),positions(source.positions)
{
    
}

template<typename T>
Position<T> ::~Position()
{
    
}

template<typename T>
const T& Position<T>::GetProduct() const
{
    return product;
}

template<typename T>
int Position<T>::GetPosition(string& book)
{
    return positions[book];
}

template<typename T>
Position<T>& Position<T>::operator=(Position& source)
{
    product = source.product;
    positions["TRY1"] = source.positions["TRY1"];
    positions["TRY2"] = source.positions["TRY2"];
    positions["TRY3"] = source.positions["TRY3"];
    return *this;
}

template<typename T>
int Position<T>::GetAggregatePosition()
{
    int sum = positions["TRSY1"] + positions["TRSY2"] + positions["TRSY3"];
    
    return sum;
}

template<typename T>
void Position<T>::AddPosition(string &book,int quantitiy)
{
    positions[book] += quantitiy;
}
#endif 
