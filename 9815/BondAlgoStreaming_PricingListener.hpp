#ifndef BONDALGOSTREAMING_PRICINGLISTENER_HPP
#define BONDALGOSTREAMING_PRICINGLISTENER_HPP

#include "soa.hpp"
#include "BondAlgoStreamingService.hpp"
#include "BondPricingService.hpp"
class BondAlgoStreaming_PricingListener : public ServiceListener<AlgoStream<Bond>>
{
private:
    BondPricingService & bondPricingService;
public:
    BondAlgoStreaming_PricingListener(BondPricingService &);
    void ProcessAdd(AlgoStream<Bond>& data);
    void ProcessRemove(AlgoStream<Bond>& data){}
    void ProcessUpdate(AlgoStream<Bond>& data){}
    
};
BondAlgoStreaming_PricingListener::BondAlgoStreaming_PricingListener(BondPricingService& s):bondPricingService(s)
{
    
}

void BondAlgoStreaming_PricingListener::ProcessAdd(AlgoStream<Bond>& data)
{
   bondPricingService.PublishPrice(data);
}


#endif
