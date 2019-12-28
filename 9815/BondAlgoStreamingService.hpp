#ifndef BONDALGOSTREAMINGSERVICE_HPP
#define BONDALGOSTREAMINGSERVICE_HPP

#include "soa.hpp"
#include <string>
#include "Bond.hpp"
#include <vector>
#include <map>
#include "BondExecutionService.hpp"
#include "AlgoStream.hpp"
#include "PriceStreamOrder.hpp"

using namespace std;

class BondAlgoStreamingService : public Service<string,AlgoStream<Bond>>
{
    
private:
    
    map<string,AlgoStream<Bond>> algoStream;
    vector<ServiceListener<AlgoStream<Bond>>*> listeners;
    
public:
    
    //constructor and destructor
    BondAlgoStreamingService();
    BondAlgoStreamingService(const BondAlgoStreamingService&);
    ~BondAlgoStreamingService();
    
    //virtual functions
    AlgoStream<Bond>& GetData(string productId);
    void OnMessage(AlgoStream<Bond> & data) ;
    void AddListener(ServiceListener<AlgoStream<Bond>> & listener) ;
    vector<ServiceListener<AlgoStream<Bond>>*> GetListeners() ;
    
    //operator overload
    BondAlgoStreamingService& operator=(BondAlgoStreamingService&);
    friend ostream& operator<<(ostream& os, BondAlgoStreamingService& source)
    {
        os<<"BondAlgoStreamingService: "<<endl<<source.algoStream["912828M72"]<<source.algoStream["912828N22"]<<source.algoStream["912828M98"]<<source.algoStream["912828M80"]<<source.algoStream["912828M56"]<<source.algoStream["912810RP5"];
        return os;
    }
    
  
   
};

BondAlgoStreamingService::BondAlgoStreamingService()
{
    cout<<date(2010,Dec,1)<<endl;
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
    AlgoStream<Bond> a2(e2);
    AlgoStream<Bond> a3(e3);
    AlgoStream<Bond> a5(e5);
    AlgoStream<Bond> a7(e7);
    AlgoStream<Bond> a10(e10);
    AlgoStream<Bond> a30(e30);
    algoStream.insert(pair<string,AlgoStream<Bond>>("912828M72",a2));
    algoStream.insert(pair<string,AlgoStream<Bond>>("912828N22",a3));
    algoStream.insert(pair<string,AlgoStream<Bond>>("912828M98",a5));
    algoStream.insert(pair<string,AlgoStream<Bond>>("912828M80",a7));
    algoStream.insert(pair<string,AlgoStream<Bond>>("912828M56",a10));
    algoStream.insert(pair<string,AlgoStream<Bond>>("912810RP5",a30));
    
}

BondAlgoStreamingService::BondAlgoStreamingService(const BondAlgoStreamingService& source):algoStream(source.algoStream),listeners(source.listeners)
{
    
}

BondAlgoStreamingService::~BondAlgoStreamingService()
{
    
}

AlgoStream<Bond>& BondAlgoStreamingService::GetData(string productId)
{
    return algoStream[productId];
}

void BondAlgoStreamingService::OnMessage(AlgoStream<Bond> & data)
{
    string k =data.GetPriceStream()->GetProduct().GetProductId();
    algoStream[k] = data;
    listeners[0]->ProcessAdd(data);
    listeners[1]->ProcessAdd(data);
}

void BondAlgoStreamingService::AddListener(ServiceListener<AlgoStream<Bond>> & listener)
{
    listeners.push_back(&listener);
}

vector<ServiceListener<AlgoStream<Bond>>*> BondAlgoStreamingService::GetListeners()
{
    
    return listeners;
}

BondAlgoStreamingService& BondAlgoStreamingService::operator=(BondAlgoStreamingService& source)
{
    algoStream["912828M72"] = source.algoStream["912828M72"];
    algoStream["912828N22"] = source.algoStream["912828N22"];
    algoStream["912828M98"] = source.algoStream["912828M98"];
    algoStream["912828M80"] = source.algoStream["912828M80"];
    algoStream["912828M56"] = source.algoStream["912828M56"];
    algoStream["912810RP5"] = source.algoStream["912810RP5"];
    listeners = source.listeners;
    return *this;
}


#endif
