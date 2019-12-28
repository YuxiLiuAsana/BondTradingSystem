#ifndef BONDINQUIRY_HISTORICALDATALISTENER_HPP
#define BONDINQUIRY_HISTORICALDATALISTENER_HPP
#include "BondHistoricalDataService.hpp"
#include <fstream>
using namespace std;
class BondInquiry_HistoricalDataListener : public ServiceListener<Inquiry<Bond> >
{
private:
    BondHistoricalDataService<Inquiry<Bond> > & bondHistoricalDataService;
public:
    BondInquiry_HistoricalDataListener(BondHistoricalDataService<Inquiry<Bond> > &);
    void ProcessAdd(Inquiry<Bond> & data);
    void ProcessRemove(Inquiry<Bond> & data){}
    void ProcessUpdate(Inquiry<Bond> & data){}
    
};
BondInquiry_HistoricalDataListener:: BondInquiry_HistoricalDataListener(BondHistoricalDataService<Inquiry<Bond> > & s):bondHistoricalDataService(s)
{
    
}

void BondInquiry_HistoricalDataListener::ProcessAdd(Inquiry<Bond> & data)
{
    ofstream o( "/Users/YuxiLIU/Desktop/9815/9815/allinquiries.txt ",ios::app);
    o<<data<<endl;
    string k = data.GetProduct().GetProductId();
    bondHistoricalDataService.bond[k] = data;

}


#endif /* BondInquiry_HistoricalDataListener_h */
