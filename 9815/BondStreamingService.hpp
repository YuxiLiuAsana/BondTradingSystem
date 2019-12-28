#ifndef BONDSTREAMINGSERVICE_HPP
#define BONDSTREAMINGSERVICE_HPP

#include "soa.hpp"
#include "BondMarketDataService.hpp"
#include "PriceStream.hpp"
#include <map>
#include <vector>

#include <string>
#include "soa.hpp"
#include "Bond.hpp"
#include "BondMarketDataService.hpp"
#include "PriceStream.hpp"
#include <iostream>


class BondStreamingService:public Service<string, PriceStream<Bond>>
{
    
private:
    
    map<string, PriceStream<Bond>> priceStream;
    vector<ServiceListener<PriceStream<Bond>>*> listeners;
    
public:
    
    //constructor and destructor
    BondStreamingService();
    BondStreamingService(const BondStreamingService&);
    ~BondStreamingService();
    
    //virtual functions
    PriceStream<Bond>& GetData(string  key);
    void OnMessage(PriceStream<Bond> &data) ;
    void AddListener(ServiceListener<PriceStream<Bond>> &listener) ;
    vector< ServiceListener<PriceStream<Bond>> *> GetListeners();
    
    //operator overload
    BondStreamingService& operator=(BondStreamingService&);
    friend ostream& operator<<(ostream& os, BondStreamingService& source)
    {
        os<<"BondStreamingService: "<<endl<<source.priceStream["912828M72"]<<source.priceStream["912828N22"]<<source.priceStream["912828M98"]<<source.priceStream["912828M80"]<<source.priceStream["912828M56"]<<source.priceStream["912810RP5"];
        return os;
    }
    
    //other functions
    void PublishPrice(const AlgoStream<Bond>& order);
    
};

BondStreamingService::BondStreamingService()
{
    Bond y2("912828M72","CUSIP","T",0,date(2017,Dec,1));
    Bond y3("912828N22","CUSIP","T",0,date(2018,Dec,1));
    Bond y5("912828M98","CUSIP","T",0,date(2019,Dec,1));
    Bond y7("912828M80","CUSIP","T",0,date(2022,Dec,1));
    Bond y10("912828M56","CUSIP","T",0,date(2025,Dec,1));
    Bond y30("912810RP5","CUSIP","T",0,date(2045,Dec,1));
    PriceStreamOrder c1;
    PriceStreamOrder c2;
    PriceStreamOrder c3;
    PriceStreamOrder c4;
    PriceStreamOrder c5;
    PriceStreamOrder c6;
    PriceStreamOrder b1;
    PriceStreamOrder b2;
    PriceStreamOrder b3;
    PriceStreamOrder b4;
    PriceStreamOrder b5;
    PriceStreamOrder b6;
    PriceStream<Bond> e2(y2,c1,b1);
    PriceStream<Bond> e3(y3,c2,b2);
    PriceStream<Bond> e5(y5,c3,b3);
    PriceStream<Bond> e7(y7,c4,b4);
    PriceStream<Bond> e10(y10,c5,b5);
    PriceStream<Bond> e30(y30,c6,b6);
    priceStream.insert(pair<string, PriceStream<Bond>>("912828M72",e2));
    priceStream.insert(pair<string, PriceStream<Bond>>("912828N22",e3));
    priceStream.insert(pair<string, PriceStream<Bond>>("912828M98",e5));
    priceStream.insert(pair<string, PriceStream<Bond>>("912828M80",e7));
    priceStream.insert(pair<string, PriceStream<Bond>>("912828M56",e10));
    priceStream.insert(pair<string, PriceStream<Bond>>("912810RP5",e30));
    
}

BondStreamingService::BondStreamingService(const BondStreamingService& source):priceStream(source.priceStream),listeners(source.listeners)
{
    
}

BondStreamingService::~BondStreamingService()
{
    
}

PriceStream<Bond>& BondStreamingService::GetData(string  key)
{
    return priceStream[key];
}

void BondStreamingService::OnMessage(PriceStream<Bond> &data)
{
    string key = data.GetProduct().GetProductId();
    priceStream[key] = data;
}

void BondStreamingService::AddListener(ServiceListener<PriceStream<Bond>> &listener)
{
    listeners.push_back(&listener);
}

vector< ServiceListener<PriceStream<Bond>> *> BondStreamingService::GetListeners()
{
    return listeners;
}

BondStreamingService& BondStreamingService::operator=(BondStreamingService& source)
{
    priceStream["912828M72"] = source.priceStream["912828M72"];
    priceStream["912828N22"] = source.priceStream["912828N22"];
    priceStream["912828M98"] = source.priceStream["912828M98"];
    priceStream["912828M80"] = source.priceStream["912828M80"];
    priceStream["912828M56"] = source.priceStream["912828M56"];
    priceStream["912810RP5"] = source.priceStream["912810RP5"];
    listeners = source.listeners;
    return * this;
    
}

void BondStreamingService::PublishPrice(const AlgoStream<Bond>& order)
{
    cout<<"yeah";
}



#endif
