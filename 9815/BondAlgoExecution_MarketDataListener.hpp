#ifndef BONDALGOEXECUTION_MARKETDATALISTENER_HPP
#define BONDALGOEXECUTION_MARKETDATALISTENER_HPP

#include "soa.hpp"
#include "BondAlgoExecutionService.hpp"
#include "BondMarketDataService.hpp"
class BondAlgoExecution_MarketDataListener : public ServiceListener<AlgoExecution<Bond>>
{
private:
    BondMarketDataService & bondMarketDataService;
public:
    BondAlgoExecution_MarketDataListener(BondMarketDataService &);
    void ProcessAdd(AlgoExecution<Bond>& data);
    void ProcessRemove(AlgoExecution<Bond>& data){}
    void ProcessUpdate(AlgoExecution<Bond>& data){}

};

BondAlgoExecution_MarketDataListener::BondAlgoExecution_MarketDataListener(BondMarketDataService& s):bondMarketDataService(s)
{

}

void BondAlgoExecution_MarketDataListener::ProcessAdd(AlgoExecution<Bond>& data)
{
    bondMarketDataService.ExecuteOrder( data);
}
#endif
