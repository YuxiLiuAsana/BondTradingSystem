
#ifndef MARKETDATASERVICE_HPP
#define MARKETDATASERVICE_HPP

#include <string>
#include <vector>
#include "soa.hpp"
#include "Bond.hpp"
#include "BidOffer.hpp"
#include<iostream>
#include "OrderBook.hpp"
#include "AlgoExecution.hpp"

using namespace std;

class BondMarketDataService : public Service<string,OrderBook <Bond> >
{
private:
    
    map<string, OrderBook<Bond>> orderBook;
    vector<ServiceListener<OrderBook<Bond>>*> listeners;
    
public:
    
    //constructor and destructor
    BondMarketDataService();
    BondMarketDataService(const BondMarketDataService&);
    ~BondMarketDataService();
    
    //virtual functions
    void OnMessage(OrderBook<Bond> & data);
    OrderBook<Bond>& GetData(string key);
    void AddListener(ServiceListener<OrderBook<Bond>>& listener);
    vector<ServiceListener<OrderBook<Bond>>*> GetListeners();
    
    //operator Overload
    BondMarketDataService& operator=(BondMarketDataService& );
    friend ostream& operator<<(ostream& os, BondMarketDataService& source)
    {
        os<<"BondMarketDataService: "<<source.orderBook["912828M72"]<<source.orderBook["912828N22"]<<source.orderBook["912828M98"]<<source.orderBook["912828M80"]<<source.orderBook["912828M56"]<<source.orderBook["912828M56"]<<source.orderBook["912810RP5"];
        return os;
    }
    
    //other functions
    OrderBook<Bond> AggregateDepth(string &productId);
    BidOffer GetBestBidOffer(string &productId);
    void ExecuteOrder(AlgoExecution<Bond>&);
    
};


BondMarketDataService::BondMarketDataService()
{
    Bond y2("912828M72","CUSIP","T",0,date(2017,Dec,1));
    Bond y3("912828N22","CUSIP","T",0,date(2018,Dec,1));
    Bond y5("912828M98","CUSIP","T",0,date(2019,Dec,1));
    Bond y7("912828M80","CUSIP","T",0,date(2022,Dec,1));
    Bond y10("912828M56","CUSIP","T",0,date(2025,Dec,1));
    Bond y30("912810RP5","CUSIP","T",0,date(2045,Dec,1));
    Order a(0,10000000,"BUY");
    Order b(0,10000000,"SELL");
    vector<Order> bid;
    vector<Order> offer;
    bid.push_back(a);
    bid.push_back(a);
    bid.push_back(a);
    bid.push_back(a);
    bid.push_back(a);
    offer.push_back(b);
    offer.push_back(b);
    offer.push_back(b);
    offer.push_back(b);
    offer.push_back(b);
    OrderBook<Bond> the2(y2,bid,offer);
    OrderBook<Bond> the3(y3,bid,offer);
    OrderBook<Bond> the5(y5,bid,offer);
    OrderBook<Bond> the7(y7,bid,offer);
    OrderBook<Bond> the10(y10,bid,offer);
    OrderBook<Bond> the30(y30,bid,offer);
    orderBook.insert(pair<string,OrderBook<Bond>>("912828M72",the2));
    orderBook.insert(pair<string,OrderBook<Bond>>("912828N22",the3));
    orderBook.insert(pair<string,OrderBook<Bond>>("912828M98",the5));
    orderBook.insert(pair<string,OrderBook<Bond>>("912828M80",the7));
    orderBook.insert(pair<string,OrderBook<Bond>>("912828M56",the10));
    orderBook.insert(pair<string,OrderBook<Bond>>("912810RP5",the30));
}

BondMarketDataService::BondMarketDataService(const BondMarketDataService& source):orderBook(source.orderBook),listeners(source.listeners)
{
    
}

BondMarketDataService::~BondMarketDataService()
{

}

void BondMarketDataService::OnMessage(OrderBook<Bond> & data)
{
    string key = data.GetProduct().GetProductId();
    orderBook[key] = data;
    //cout<<orderBook[key];    
}

OrderBook<Bond>& BondMarketDataService::GetData(string Key)
{
    return orderBook[Key];
}
void BondMarketDataService::AddListener(ServiceListener<OrderBook<Bond>>& listener)
{
    
    listeners.push_back(&listener);
}
vector<ServiceListener<OrderBook<Bond>>*> BondMarketDataService::GetListeners()
{
    return listeners;
}

BondMarketDataService& BondMarketDataService::operator=(BondMarketDataService& source)
{
    orderBook["912828M72"] = source.orderBook["912828M72"];
    orderBook["912828N22"] = source.orderBook["912828N22"];
    orderBook["912828M98"] = source.orderBook["912828M98"];
    orderBook["912828M80"] = source.orderBook["912828M80"];
    orderBook["912828M56"] = source.orderBook["912828M56"];
    orderBook["912810RP5"] = source.orderBook["912810RP5"];
    listeners = source.listeners;
    return *this;
}

BidOffer BondMarketDataService::GetBestBidOffer(string &productId)
{
    Order bid;
    Order offer;
    bid = orderBook[productId].GetBidStack()[0];
    offer = orderBook[productId].GetOfferStack()[0];
    BidOffer ret(bid,offer);
    return ret;
}

OrderBook<Bond> BondMarketDataService::AggregateDepth(string & productId)
{
    return orderBook[productId];
}

void BondMarketDataService::ExecuteOrder(AlgoExecution<Bond> & data)
{
    cout<<"yeah"<<endl;
}
#endif
