#ifndef BONDSTREAMING_HISTORICALDATALISTENER_HPP
#define BONDSTREAMING_HISTORICALDATALISTENER_HPP
#include "BondHistoricalDataService.hpp"
#include <fstream>
using namespace std;
class BondStreaming_HistoricalDataListener : public ServiceListener<PriceStream<Bond> >
{
private:
    BondHistoricalDataService<PriceStream<Bond> > & bondHistoricalDataService;
public:
    BondStreaming_HistoricalDataListener(BondHistoricalDataService<PriceStream<Bond> > &);
    void ProcessAdd(PriceStream<Bond> & data);
    void ProcessRemove(PriceStream<Bond> & data){}
    void ProcessUpdate(PriceStream<Bond> & data){}
    
};
BondStreaming_HistoricalDataListener:: BondStreaming_HistoricalDataListener(BondHistoricalDataService<PriceStream<Bond> >& s):bondHistoricalDataService(s)
{
    
}

void BondStreaming_HistoricalDataListener::ProcessAdd(PriceStream<Bond> & data)
{
    ofstream o( "/Users/YuxiLIU/Desktop/9815/9815/streaming.txt ",ios::app);
    o<<data<<endl;
    string k = data.GetProduct().GetProductId();
    bondHistoricalDataService.bond[k] = data;

}


#endif