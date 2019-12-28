#ifndef BONDRISK_HISTORICALDATALISTENER_HPP
#define BONDRISK_HISTORICALDATALISTENER_HPP
#include "BondHistoricalDataService.hpp"
#include <fstream>
using namespace std;
class BondRisk_HistoricalDataListener : public ServiceListener<PV01 <Bond> >
{
private:
    BondHistoricalDataService<PV01<Bond>> & bondHistoricalDataService;
public:
    BondRisk_HistoricalDataListener(BondHistoricalDataService<PV01<Bond>> &);
    void ProcessAdd(PV01 <Bond> & data);
    void ProcessRemove(PV01 <Bond> & data){}
    void ProcessUpdate(PV01 <Bond> & data){}
    
};
BondRisk_HistoricalDataListener:: BondRisk_HistoricalDataListener(BondHistoricalDataService<PV01<Bond>> & s):bondHistoricalDataService(s)
{
    
}

void BondRisk_HistoricalDataListener::ProcessAdd(PV01 <Bond> & data)
{
    ofstream o( "/Users/YuxiLIU/Desktop/9815/9815/risk.txt ",ios::app);
    o<<data<<endl;
    string k = data.GetProduct().GetProductId();
    bondHistoricalDataService.bond[k] = data;
}



#endif
