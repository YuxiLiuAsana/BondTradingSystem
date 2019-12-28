#ifndef BONDPOSITION_RISKLISTENER_HPP
#define BONDPOSITION_RISKLISTENER_HPP
#include "BondRiskService.hpp"
#include "Position.hpp"
#include "Bond.hpp"

class BondPosition_RiskListener: public ServiceListener<Position<Bond>>
{
private:
    BondRiskService & bondriskService;
public:
    BondPosition_RiskListener(BondRiskService& );
    void ProcessAdd(Position<Bond> &data) ;
    void ProcessRemove(Position<Bond> &data) {}
    void ProcessUpdate(Position<Bond> &data) {}
};

BondPosition_RiskListener::BondPosition_RiskListener(BondRiskService& source):bondriskService(source)
{
    
}

void BondPosition_RiskListener::ProcessAdd(Position<Bond>& data)
{
    bondriskService.AddPosition(data);
}

#endif /* BondPosition_RiskListener_h */
