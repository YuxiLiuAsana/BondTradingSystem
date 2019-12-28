#ifndef BONDPRICINGSERVICE_HPP
#define BONDPRICINGSERVICE_HPP

#include <string>
#include "soa.hpp"
#include "Bond.hpp"
#include "Price.hpp"
#include "ALgoStream.hpp"

class BondPricingService : public Service<string,Price <Bond> >
{
private:
    
    map<string, Price<Bond>> currentPrice;
    vector<ServiceListener<Price<Bond>>*> listeners;
    
public:
    
    //constructor and destructor
    BondPricingService();
    BondPricingService(const BondPricingService&);
    ~BondPricingService();
    
    //virtural functions
    Price<Bond>& GetData(string Key);
    void OnMessage(Price<Bond>& source);
    void AddListener(ServiceListener<Price<Bond>>& listener);
    vector<ServiceListener<Price<Bond>>*> GetListeners();
    
    //operator Overload
    BondPricingService& operator=(BondPricingService&);
    friend ostream& operator<<(ostream& os, BondPricingService& source)
    {
        os<<"BondPricingService: "<<endl<<source.currentPrice["912828M72"]<<source.currentPrice["912828N22"]<<source.currentPrice["912828M98"]<<source.currentPrice["912828M80"]<<source.currentPrice["912828M56"]<<source.currentPrice["912810RP5"];
        return os;
    }
    
    //others
    void PublishPrice(AlgoStream<Bond>&);
    
};
BondPricingService::BondPricingService()
{
    Bond y2("912828M72","CUSIP","T",0,date(2017,Dec, 1));
    Bond y3("912828N22","CUSIP","T",0,date(2018,Dec,1));
    Bond y5("912828M98","CUSIP","T",0,date(2020,Dec,1));
    Bond y7("912828M80","CUSIP","T",0,date(2022,Dec,1));
    Bond y10("912828M56","CUSIP","T",0,date(2025,Dec,1));
    Bond y30("912810RP5","CUSIP","T",0,date(2045,Dec,1));
    Price<Bond> p2(y2,0,0);
    Price<Bond> p3(y2,0,0);
    Price<Bond> p5(y2,0,0);
    Price<Bond> p7(y2,0,0);
    Price<Bond> p10(y2,0,0);
    Price<Bond> p30(y2,0,0);
    currentPrice.insert(pair<string,Price<Bond>>("912828M72",p2));
    currentPrice.insert(pair<string,Price<Bond>>("912828N22",p3));
    currentPrice.insert(pair<string,Price<Bond>>("912828M98",p5));
    currentPrice.insert(pair<string,Price<Bond>>("912828M80",p7));
    currentPrice.insert(pair<string,Price<Bond>>("912828M56",p10));
    currentPrice.insert(pair<string,Price<Bond>>("912810RP5",p30));
}

BondPricingService::BondPricingService(const BondPricingService& source):currentPrice(source.currentPrice),listeners(source.listeners)
{

}

BondPricingService::~BondPricingService()
{

}

Price<Bond>& BondPricingService::GetData(string Key)
{
    return currentPrice[Key];
}

void BondPricingService::OnMessage(Price<Bond>& source)
{
    string s = source.GetProduct().GetProductId();
    currentPrice[s] = source;
    //cout<<currentPrice[s];
}

void BondPricingService::AddListener(ServiceListener<Price<Bond>>& listener)
{
    listeners.push_back(&listener);
}

vector<ServiceListener<Price<Bond>>*> BondPricingService::GetListeners()
{
    return listeners;
}
BondPricingService& BondPricingService::operator=(BondPricingService& source)
{
    currentPrice["912828M72"] = source.currentPrice["912828M72"];
    currentPrice["912828N22"] = source.currentPrice["912828N22"];
    currentPrice["912828M98"] = source.currentPrice["912828M98"];
    currentPrice["912828M80"] = source.currentPrice["912828M80"];
    currentPrice["912828M56"] = source.currentPrice["912828M56"];
    currentPrice["912810RP5"] = source.currentPrice["912810RP5"];
    listeners = source.listeners;
    return *this;
}

void BondPricingService::PublishPrice(AlgoStream<Bond> & data)
{
    cout<<"yeah";
}


#endif
