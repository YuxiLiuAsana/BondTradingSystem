#ifndef BONDPRODUCTSERVICE_HPP
#define BONDPRODUCTSERVICE_HPP

#include <iostream>
#include <map>
#include "soa.hpp"
#include <string>
#include "Bond.hpp"

using namespace std;
using namespace boost::gregorian;


class BondProductService : public Service<string,Bond>
{
    
private:
    
    map<string,Bond> bonds;
    vector<ServiceListener<Bond>*> listeners;
    
public:
    
    //constructor and destructor
    BondProductService();
    BondProductService(const BondProductService&);
    ~BondProductService();
    
    //virtual functions
    Bond& GetData(string productId);
    void OnMessage(Bond & data) ;
    void AddListener(ServiceListener<Bond> & listener) ;
    vector<ServiceListener<Bond>*> GetListeners() ;
    
    
    //operator overload
    BondProductService& operator=(BondProductService&);
    friend ostream& operator<<(ostream &os, BondProductService& s)
    {
        os<<"BondProductService: "<<endl<<s.bonds["912828M72"]<<s.bonds["912828N22"]<<s.bonds["912828M98"]<<s.bonds["912828M80"]<<s.bonds["912828M56"]<<s.bonds["912810RP5"];
        return os;
    }
    
    
};
                      
BondProductService::BondProductService()
{
    Bond b2("912828M72","CUSIP","T",0.2,date(2017,Dec,1));
    Bond b3("912828N22","CUSIP","T",0.2,date(2018,Dec,1));
    Bond b5("912828M98","CUSIP","T",0.2,date(2020,Dec,1));
    Bond b7("912828M80","CUSIP","T",0.2,date(2022,Dec,1));
    Bond b10("912828M56","CUSIP","T",0.2,date(2025,Dec,1));
    Bond b30("912810RP5","CUSIP","T",0.2,date(2045,Dec,1));
    bonds.insert(pair<string,Bond>("912828M72" , b2));
    bonds.insert(pair<string,Bond>("912828N22" , b3));
    bonds.insert(pair<string,Bond>("912828M98" , b5));
    bonds.insert(pair<string,Bond>("912828M80" , b7));
    bonds.insert(pair<string,Bond>("912828M56" , b10));
    bonds.insert(pair<string,Bond>("912810RP5" , b30));
  
}
                      
BondProductService::BondProductService(const BondProductService& source):bonds(source.bonds),listeners(source.listeners)
{
    
}
                      
BondProductService::~BondProductService()
{
                      
}
                      
Bond& BondProductService::GetData(string productId)
{
  return bonds[productId];
}
                      
void BondProductService::OnMessage(Bond & data)
{
    string key = data.GetBondIdType();
    bonds[key] = data;
}

void BondProductService::AddListener(ServiceListener<Bond> & listener)
{
    listeners.push_back(&listener);
}

vector<ServiceListener<Bond>*> BondProductService::GetListeners()
{
    return listeners;
}


BondProductService& BondProductService::operator=(BondProductService& source)
{
    bonds["912828M72"] = source.bonds["912828M72"];
    bonds["912828N22"] = source.bonds["912828N22"];
    bonds["912828M98"] = source.bonds["912828M98"];
    bonds["912828M80"] = source.bonds["912828M80"];
    bonds["912828M56"] = source.bonds["912828M56"];
    bonds["912810RP5"] = source.bonds["912810RP5"];
    listeners = source.listeners;
    return *this;
}

#endif
