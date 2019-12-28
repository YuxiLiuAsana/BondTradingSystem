#ifndef BONDEXECUTION_HISTORICALDATALISTENER_HPP
#define BONDEXECUTION_HISTORICALDATALISTENER_HPP
#include "BondHistoricalDataService.hpp"
#include <fstream>
using namespace std;
class BondExecution_HistoricalDataListener : public ServiceListener<ExecutionOrder<Bond> >
{
private:
    BondHistoricalDataService<ExecutionOrder<Bond>> & bondHistoricalDataService;
public:
    BondExecution_HistoricalDataListener(BondHistoricalDataService<ExecutionOrder<Bond>> &);
    void ProcessAdd(ExecutionOrder<Bond> & data);
    void ProcessRemove(ExecutionOrder<Bond> & data){}
    void ProcessUpdate(ExecutionOrder<Bond> & data){}
    
};
BondExecution_HistoricalDataListener:: BondExecution_HistoricalDataListener(BondHistoricalDataService<ExecutionOrder<Bond>> & s):bondHistoricalDataService(s)
{
    
}

void BondExecution_HistoricalDataListener::ProcessAdd(ExecutionOrder<Bond> & data)
{
    ofstream o( "/Users/YuxiLIU/Desktop/9815/9815/executions.txt ",ios::app);
    o<<data<<endl;
    string k = data.GetProduct().GetProductId();
    bondHistoricalDataService.bond[k] = data;

}


#endif
