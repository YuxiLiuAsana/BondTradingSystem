#ifndef BONDPOSITION_HISTORICALDATALISTENER_HPP
#define BONDPOSITION_HISTORICALDATALISTENER_HPP
#include "BondHistoricalDataService.hpp"
#include <fstream>
using namespace std;
class BondPosition_HistoricalDataListener : public ServiceListener<Position<Bond>>
{
private:
    BondHistoricalDataService<Position<Bond>> & bondHistoricalDataService;
public:
    BondPosition_HistoricalDataListener(BondHistoricalDataService<Position<Bond>> &);
    void ProcessAdd(Position<Bond>& data);
    void ProcessRemove(Position<Bond>& data){}
    void ProcessUpdate(Position<Bond>& data){}

};
BondPosition_HistoricalDataListener:: BondPosition_HistoricalDataListener(BondHistoricalDataService<Position<Bond>> & s):bondHistoricalDataService(s)
{

}

void BondPosition_HistoricalDataListener::ProcessAdd(Position<Bond>& data)
{
    ofstream o( "/Users/YuxiLIU/Desktop/9815/9815/position.txt ",ios::app);
    o<<data<<endl<<"Aggregate: "<<data.GetAggregatePosition()<<endl;
    string k = data.GetProduct().GetProductId();
    bondHistoricalDataService.bond[k] = data;
}
#endif
