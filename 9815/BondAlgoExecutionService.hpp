#ifndef BONDALGOEXECUTIONSERVICE_HPP
#define BONDALGOEXECUTIONSERVICE_HPP

#include "soa.hpp"
#include <string>
#include "Bond.hpp"
#include <vector>
#include <map>
#include "BondExecutionService.hpp"
#include "AlgoExecution.hpp"

using namespace std;

class BondAlgoExecutionService : public Service<string,AlgoExecution<Bond>>
{
    
private:
    
    map<string,AlgoExecution<Bond>> algoExecution;
    vector<ServiceListener<AlgoExecution<Bond>>*> listeners;
    
public:
    
    //constructor and destructor
    BondAlgoExecutionService();
    BondAlgoExecutionService(const BondAlgoExecutionService&);
    ~BondAlgoExecutionService();
    
    //virtual functions
    AlgoExecution<Bond>& GetData(string productId);
    void OnMessage(AlgoExecution<Bond> & data) ;
    void AddListener(ServiceListener<AlgoExecution<Bond>> & listener) ;
    vector<ServiceListener<AlgoExecution<Bond>>*> GetListeners() ;
    
    //operator overload
    BondAlgoExecutionService& operator=(BondAlgoExecutionService&);
    friend ostream& operator<<(ostream& os, BondAlgoExecutionService& source)
    {
        os<<"BondAlgoExecutionService: "<<endl<<source.algoExecution["912828M72"]<<source.algoExecution["912828N22"]<<source.algoExecution["912828M98"]<<source.algoExecution["912828M80"]<<source.algoExecution["912828M56"]<<source.algoExecution["912810RP5"];
        return os;
    }
};

BondAlgoExecutionService::BondAlgoExecutionService()
{
    cout<<date(2010,Dec,1)<<endl;
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
    AlgoExecution<Bond> a2(e2);
    AlgoExecution<Bond> a3(e3);
    AlgoExecution<Bond> a5(e5);
    AlgoExecution<Bond> a7(e7);
    AlgoExecution<Bond> a10(e10);
    AlgoExecution<Bond> a30(e30);
    algoExecution.insert(pair<string,AlgoExecution<Bond>>("912828M72",a2));
    algoExecution.insert(pair<string,AlgoExecution<Bond>>("912828N22",a3));
    algoExecution.insert(pair<string,AlgoExecution<Bond>>("912828M98",a5));
    algoExecution.insert(pair<string,AlgoExecution<Bond>>("912828M80",a7));
    algoExecution.insert(pair<string,AlgoExecution<Bond>>("912828M56",a10));
    algoExecution.insert(pair<string,AlgoExecution<Bond>>("912810RP5",a30));
    
}

BondAlgoExecutionService::BondAlgoExecutionService(const BondAlgoExecutionService& source):algoExecution(source.algoExecution),listeners(source.listeners)
{

}

BondAlgoExecutionService::~BondAlgoExecutionService()
{
    
}

AlgoExecution<Bond>& BondAlgoExecutionService::GetData(string productId)
{
    return algoExecution[productId];
}

void BondAlgoExecutionService::OnMessage(AlgoExecution<Bond> & data)
{
    string k =data.GetExecutionOrder()->GetProduct().GetProductId();
    algoExecution[k] = data;
    listeners[0]->ProcessAdd(data);
    listeners[1]->ProcessAdd(data);
}

void BondAlgoExecutionService::AddListener(ServiceListener<AlgoExecution<Bond>> & listener)
{
    listeners.push_back(&listener);
}

vector<ServiceListener<AlgoExecution<Bond>>*> BondAlgoExecutionService::GetListeners()
{
    
    return listeners;
}

BondAlgoExecutionService& BondAlgoExecutionService::operator=(BondAlgoExecutionService& source)
{
    algoExecution["912828M72"] = source.algoExecution["912828M72"];
    algoExecution["912828N22"] = source.algoExecution["912828N22"];
    algoExecution["912828M98"] = source.algoExecution["912828M98"];
    algoExecution["912828M80"] = source.algoExecution["912828M80"];
    algoExecution["912828M56"] = source.algoExecution["912828M56"];
    algoExecution["912810RP5"] = source.algoExecution["912810RP5"];
    listeners = source.listeners;
    return *this;
}

    
    
    
    
#endif /* BondAlgoExecusionService_h */
