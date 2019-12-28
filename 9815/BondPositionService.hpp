#ifndef BONDPOSITIONSERVICE_HPP
#define BONDPOSITIONSERVICE_HPP

#include <map>
#include <string>
#include "Bond.hpp"
#include "Position.hpp"
#include "Trade.hpp"


class BondPositionService : public Service<string, Position<Bond>>
{
    
private:
    map<string,Position<Bond>> positions;
    vector<ServiceListener<Position<Bond>>* > listeners;
    
public:
    
    //constructor and destructor
    BondPositionService();
    BondPositionService(const BondPositionService&);
    ~BondPositionService();
    
    //virtual function
    Position<Bond>& GetData(string key);
    void OnMessage(Position<Bond>& data);
    void AddListener(ServiceListener<Position<Bond>> &listener);
    vector< ServiceListener<Position<Bond>> *> GetListeners() ;

    
    //operator Overload
    BondPositionService& operator=(BondPositionService&);
    friend ostream& operator<<(ostream & os, BondPositionService& source)
    {
        os<<"BondPositionService: "<<endl<<source.positions["912828M72"]<<source.positions["912828N22"]<<source.positions["912828M98"]<<source.positions["912828M80"]<<source.positions["912828M56"]<<source.positions["912810RP5"];
        return os;
    }
    
    //other functions
    void AddTrade(const Trade<Bond> & trade);
    
    
};

BondPositionService::BondPositionService()
{
   
    positions = map<string, Position<Bond>>();
    Bond y2("912828M72","CUSIP","T",0,date(2017,Dec,1));
    Bond y3("912828N22","CUSIP","T",0,date(2018,Dec,1));
    Bond y5("912828M98","CUSIP","T",0,date(2020,Dec,1));
    Bond y7("912828M80","CUSIP","T",0,date(2022,Dec,1));
    Bond y10("912828M56","CUSIP","T",0,date(2025,Dec,1));
    Bond y30("912810RP5","CUSIP","T",0,date(2045,Dec,1));
    Position<Bond> p2(y2);
    Position<Bond> p3(y3);
    Position<Bond> p5(y5);
    Position<Bond> p7(y7);
    Position<Bond> p10(y10);
    Position<Bond> p30(y30);
    positions.insert(pair<string, Position<Bond>>("912828M72",p2));
    positions.insert(pair<string, Position<Bond>>("912828N22",p3));
    positions.insert(pair<string, Position<Bond>>("912828M98", y5));
    positions.insert(pair<string, Position<Bond>>("912828M80",y7));
    positions.insert(pair<string, Position<Bond>>("912828M56",y10));
    positions.insert(pair<string, Position<Bond>>("912810RP5",y30));
}

BondPositionService::BondPositionService(const BondPositionService& source):positions(source.positions),listeners(source.listeners)
{
    
}

BondPositionService::~BondPositionService()
{

}

Position<Bond>& BondPositionService::GetData(string key)
{
    return positions[key];
}

void BondPositionService::OnMessage(Position<Bond>& data)
{
    string k = data.GetProduct().GetProductId();
    positions[k] = data;
}
void BondPositionService::AddListener(ServiceListener<Position<Bond>> &listener)
{
    listeners.push_back(& listener);
}

vector< ServiceListener<Position<Bond>> *> BondPositionService::GetListeners()
{
    return listeners;
}

BondPositionService& BondPositionService::operator=(BondPositionService& source)
{
    positions["912828M72"] = source.positions["912828M72"];
    positions["912828N22"] = source.positions["912828N22"];
    positions["912828M98"] = source.positions["912828M98"];
    positions["912828M80"] = source.positions["912828M80"];
    positions["912828M56"] = source.positions["912828M56"];
    positions["912810RP5"] = source.positions["912810RP5"];
    listeners = source.listeners;
    return *this;
}

void BondPositionService :: AddTrade(const Trade<Bond> & trade)
{
    string key = trade.GetProduct().GetProductId();
    int q = trade.GetQuantity();
    if(trade.GetSide() == "SELL")
        q = -q;
    string b = trade.GetBook();
    positions[key].AddPosition(b,q);
    listeners[0]->ProcessAdd(positions[key]);
    //cout<<positions[key];
    
}


#endif 