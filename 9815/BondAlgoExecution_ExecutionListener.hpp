#ifndef BONDALGOEXECUTION_EXECUTIONLISTENER_HPP
#define BONDALGOEXECUTION_EXECUTIONLISTENER_HPP
#include "soa.hpp"
#include "BondAlgoExecutionService.hpp"
#include "BondExecutionService.hpp"
class BondAlgoExecution_ExecutionListener : public ServiceListener<AlgoExecution<Bond>>
{
private:
    BondExecutionService & bondExecutionService;
public:
    BondAlgoExecution_ExecutionListener(BondExecutionService &);
    void ProcessAdd(AlgoExecution<Bond>& data);
    void ProcessRemove(AlgoExecution<Bond>& data){}
    void ProcessUpdate(AlgoExecution<Bond>& data){}
    
};

BondAlgoExecution_ExecutionListener::BondAlgoExecution_ExecutionListener(BondExecutionService& s):bondExecutionService(s)
{
    
}

void BondAlgoExecution_ExecutionListener::ProcessAdd(AlgoExecution<Bond>& data)
{
    bondExecutionService.ExecuteOrder( data);
}



#endif 