#ifndef BONDTRADEBOOKING_POSITIONLISTENER_H
#define BONDTRADEBOOKING_POSITIONLISTENER_H

#include "soa.hpp"
#include "Trade.hpp"
#include "Bond.hpp"
class BondTradeBooking_PositionListener:public ServiceListener<Trade <Bond>>
{
private:
    BondPositionService & bondPositionService;
public:
    BondTradeBooking_PositionListener(BondPositionService & source);
    void ProcessAdd(Trade<Bond> & data);
    void ProcessRemove(Trade<Bond> & data){}
    void ProcessUpdate(Trade<Bond> & data){}
    
};
BondTradeBooking_PositionListener::BondTradeBooking_PositionListener(BondPositionService & source):bondPositionService(source)
{

}

void BondTradeBooking_PositionListener::ProcessAdd(Trade<Bond>& data)
{
    bondPositionService.AddTrade(data);
}
#endif
