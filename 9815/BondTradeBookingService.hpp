#ifndef BONDTRADEBOOKINGSERVICE_HPP
#define BONDTRADEBOOKINGSERVICE_HPP
#include "Trade.hpp"

class BondTradeBookingService : public Service<string,Trade <Bond> >
{
    
private:
    
    map<string,Trade<Bond>> tradingBook;
    vector<ServiceListener<Trade<Bond>>*>  listeners;
    
public:
    
    //constructor and destructor
    BondTradeBookingService();
    BondTradeBookingService(const BondTradeBookingService& );
    ~BondTradeBookingService();
    
    //virtual functions
    Trade<Bond>& GetData(string K);
    void OnMessage(Trade<Bond> & data);
    void AddListener(ServiceListener<Trade<Bond>> & listener);
    vector<ServiceListener<Trade<Bond>>*> GetListeners();
    
    //operator overload
    BondTradeBookingService& operator=(BondTradeBookingService&);
    friend ostream& operator<<(ostream& os, BondTradeBookingService& source)
    {
        os<<"BondTradeBookingService: "<<endl<<source.tradingBook["912828M72"]<<source.tradingBook["912828N22"]<<source.tradingBook["912828M98"]<<source.tradingBook["912828M80"]<<source.tradingBook["912828M56"]<<source.tradingBook["912810RP5"];
        return os;
    }
    
};

BondTradeBookingService:: BondTradeBookingService()
{
    Bond b2("912828M72","CUSIP","T",0.2,date(2017,Dec,1));
    Bond b3("912828N22","CUSIP","T",0.2,date(2018,Dec,1));
    Bond b5("912828M98","CUSIP","T",0.2,date(2020,Dec,1));
    Bond b7("912828M80","CUSIP","T",0.2,date(2022,Dec,1));
    Bond b10("912828M56","CUSIP","T",0.2,date(2025,Dec,1));
    Bond b30("912810RP5","CUSIP","T",0.2,date(2045,Dec,1));
    Trade<Bond> t2(b2,"T2","TRSY1",0,100.0,"BUY");
    Trade<Bond> t3(b3,"T3","TRSY1",0,100.0,"BUY");
    Trade<Bond> t5(b5,"T5","TRSY1",0,100.0,"BUY");
    Trade<Bond> t7(b7,"T7","TRSY1",0,100.0,"BUY");
    Trade<Bond> t10(b10,"T10","TRSY1",0,100.0,"BUY");
    Trade<Bond> t30(b30,"T30","TRSY1",0,100.0,"BUY");
    tradingBook.insert(pair<string, Trade<Bond>>("912828M72",t2));
    tradingBook.insert(pair<string, Trade<Bond>>("912828N22",t3));
    tradingBook.insert(pair<string, Trade<Bond>>("912828M98",t5));
    tradingBook.insert(pair<string, Trade<Bond>>("912828M80",t7));
    tradingBook.insert(pair<string, Trade<Bond>>("912828M56",t10));
    tradingBook.insert(pair<string, Trade<Bond>>("912810RP5",t30));
    
}

BondTradeBookingService::BondTradeBookingService(const BondTradeBookingService& source):tradingBook(source.tradingBook),listeners(source.listeners)
{
    
}

BondTradeBookingService :: ~BondTradeBookingService()
{

}

Trade<Bond>& BondTradeBookingService::GetData(string K)
{
    return tradingBook[K];
}


void BondTradeBookingService :: OnMessage(Trade<Bond> & data)
{
    string key = data.GetProduct().GetProductId();
    tradingBook[key] = data;
    listeners[0]->ProcessAdd(data);
    //cout<<tradingBook[key];
}


void BondTradeBookingService::AddListener(ServiceListener<Trade<Bond>> & listener)
{
    listeners.push_back(&listener);
}

vector<ServiceListener<Trade<Bond>>*> BondTradeBookingService::GetListeners()
{
    return listeners;
}

BondTradeBookingService& BondTradeBookingService::operator=(BondTradeBookingService& source)
{
    tradingBook["912828M72"] = source.tradingBook["912828M72"];
    tradingBook["912828N22"] = source.tradingBook["912828N22"];
    tradingBook["912828M98"] = source.tradingBook["912828M98"];
    tradingBook["912828M80"] = source.tradingBook["912828M80"];
    tradingBook["912828M56"] = source.tradingBook["912828M56"];
    tradingBook["912810RP5"] = source.tradingBook["912810RP5"];
    listeners = source.listeners;
    return *this;
}

#endif