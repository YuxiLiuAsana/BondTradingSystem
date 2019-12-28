#ifndef BONDEXECUTION_SERVICE_HPP
#define BONDEXECUTION_SERVICE_HPP

#include <string>
#include "soa.hpp"
#include "Bond.hpp"
#include "BondMarketDataService.hpp"
#include "ExecutionOrder.hpp"
#include <iostream>


class BondExecutionService:public Service<string, ExecutionOrder<Bond>>
{
    
private:
    
    map<string, ExecutionOrder<Bond>> executionOrder;
    vector<ServiceListener<ExecutionOrder<Bond>>*> listeners;
    
public:
    
    //constructor and destructor    
    BondExecutionService();
    BondExecutionService(const BondExecutionService&);
    ~BondExecutionService();
    
    //virtual functions
    ExecutionOrder<Bond>& GetData(string  key);
    void OnMessage(ExecutionOrder<Bond> &data) ;
    void AddListener(ServiceListener<ExecutionOrder<Bond>> &listener) ;
    vector< ServiceListener<ExecutionOrder<Bond>> *> GetListeners();
    
    //operator overload
    BondExecutionService& operator=(BondExecutionService&);
    friend ostream& operator<<(ostream& os, BondExecutionService& source)
    {
        os<<"BondExecutionService: "<<endl<<source.executionOrder["912828M72"]<<source.executionOrder["912828N22"]<<source.executionOrder["912828M98"]<<source.executionOrder["912828M80"]<<source.executionOrder["912828M56"]<<source.executionOrder["912810RP5"];
        return os;
    }
        
    //other functions
    void ExecuteOrder(const AlgoExecution<Bond>& order);
    
};

BondExecutionService::BondExecutionService()
{
    Bond y2("912828M72","CUSIP","T",0,date(2017,Dec,1));
    Bond y3("912828N22","CUSIP","T",0,date(2018,Dec,1));
    Bond y5("912828M98","CUSIP","T",0,date(2019,Dec,1));
    Bond y7("912828M80","CUSIP","T",0,date(2022,Dec,1));
    Bond y10("912828M56","CUSIP","T",0,date(2025,Dec,1));
    Bond y30("912810RP5","CUSIP","T",0,date(2045,Dec,1));
    ExecutionOrder<Bond> e2(y2,"BUY","T1","LIMIT",0,10000000,10000000,"T1",0);
    ExecutionOrder<Bond> e3(y3,"SELL","T2","LIMIT",0,10000000,10000000,"T2",0);
    ExecutionOrder<Bond> e5(y5,"BUY","T3","LIMIT",0,10000000,10000000,"T3",0);
    ExecutionOrder<Bond> e7(y7,"SELL","T4","LIMIT",0,10000000,10000000,"T4",0);
    ExecutionOrder<Bond> e10(y10,"SELL","T5","LIMIT",0,10000000,10000000,"T5",0);
    ExecutionOrder<Bond> e30(y30,"BUY","T6","LIMIT",0,10000000,10000000,"T6",0);
    executionOrder.insert(pair<string, ExecutionOrder<Bond>>("912828M72",e2));
    executionOrder.insert(pair<string, ExecutionOrder<Bond>>("912828N22",e3));
    executionOrder.insert(pair<string, ExecutionOrder<Bond>>("912828M98",e5));
    executionOrder.insert(pair<string, ExecutionOrder<Bond>>("912828M80",e7));
    executionOrder.insert(pair<string, ExecutionOrder<Bond>>("912828M56",e10));
    executionOrder.insert(pair<string, ExecutionOrder<Bond>>("912810RP5",e30));
    
}

BondExecutionService::BondExecutionService(const BondExecutionService& source):executionOrder(source.executionOrder),listeners(source.listeners)
{

}

BondExecutionService::~BondExecutionService()
{

}

ExecutionOrder<Bond>& BondExecutionService::GetData(string  key)
{
    return executionOrder[key];
}

void BondExecutionService::OnMessage(ExecutionOrder<Bond> &data)
{
    string key = data.GetProduct().GetProductId();
    executionOrder[key] = data;
}

void BondExecutionService::AddListener(ServiceListener<ExecutionOrder<Bond>> &listener)
{
    listeners.push_back(&listener);
}

vector< ServiceListener<ExecutionOrder<Bond>> *> BondExecutionService::GetListeners()
{
    return listeners;
}

BondExecutionService& BondExecutionService::operator=(BondExecutionService& source)
{
    executionOrder["912828M72"] = source.executionOrder["912828M72"];
    executionOrder["912828N22"] = source.executionOrder["912828N22"];
    executionOrder["912828M98"] = source.executionOrder["912828M98"];
    executionOrder["912828M80"] = source.executionOrder["912828M80"];
    executionOrder["912828M56"] = source.executionOrder["912828M56"];
    executionOrder["912810RP5"] = source.executionOrder["912810RP5"];
    listeners = source.listeners;
    return * this;
    
}

void BondExecutionService::ExecuteOrder(const AlgoExecution<Bond>& order)
{
    cout<<"yeah";
}










#endif
