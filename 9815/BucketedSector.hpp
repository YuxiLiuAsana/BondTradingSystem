#ifndef BUCKETEDSECTOR_HPP
#define BUCKETEDSECTOR_HPP

#include <stdio.h>
#include "soa.hpp"
#include <iostream>

template<typename T>
class BucketedSector
{
    
private:
    
    vector<T> products;
    string name;
    
public:
    
    //constructor and destructor
    BucketedSector();
    BucketedSector(const vector<T> &_products, string _name);
    BucketedSector(const BucketedSector&);
    ~BucketedSector();
    
    //Getters
    const vector<T>& GetProducts() const;
    const string& GetName() const;
    
    //Operator Overload
    BucketedSector& operator=(BucketedSector&);
    friend ostream& operator<<(ostream&os, BucketedSector& source)
    {
        os<<"BucketedSector: "<<source.name<<endl;
        for(int i = 0 ; i < source.products.size(); i++)
        {
            os<<source.products[i];
        }
        return os;
    }
};
template<typename T>
BucketedSector<T>::BucketedSector()
{
    
}

template<typename T>
BucketedSector<T>::BucketedSector(const vector<T>& _products, string _name) :
products(_products),name(_name)
{
    
}

template<typename T>
BucketedSector<T>::BucketedSector(const BucketedSector<T>& source):products(source.products),name(source.name)
{
    
}

template<typename T>
BucketedSector<T>::~BucketedSector()
{

}

template<typename T>
const vector<T>& BucketedSector<T>::GetProducts() const
{
    return products;
}

template<typename T>
const string& BucketedSector<T>::GetName() const
{
    return name;
}

template<typename T>
BucketedSector<T>& BucketedSector<T>::operator=(BucketedSector<T>& source)
{
    products = source.products;
    name = source.name;
}


#endif /* BucketedSector_hpp */
