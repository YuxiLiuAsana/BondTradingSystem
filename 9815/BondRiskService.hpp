#ifndef RISKSERVICE_HPP
#define RISKSERVICE_HPP

#include "soa.hpp"
#include "Bond.hpp"
#include "PV01.hpp"
#include "BucketedSector.hpp"

class BondRiskService : public Service<string,PV01 <Bond> >
{
    
private:
    
    map<string,PV01<Bond>> pv01;
    vector<ServiceListener<PV01<Bond>>*> listeners;
    
public:
    
    //constructor and destructor
    BondRiskService();
    BondRiskService(const BondRiskService&);
    ~BondRiskService();
    
    //virtual fucntions
    PV01<Bond>& GetData(string key);
    void OnMessage(PV01<Bond> & data);
    void AddListener(ServiceListener<PV01<Bond>> & listener);
    vector<ServiceListener<PV01<Bond>>*>  GetListeners();
    
    //Operator Overload
    BondRiskService& operator=(BondRiskService&);
    friend ostream& operator<<(ostream& os, BondRiskService& source)
    {
        os<<"BondRiskService: "<<endl<<source.pv01["912828M72"]<<source.pv01["912828N22"]<<source.pv01["912828M98"]<<source.pv01["912828M80"]<<source.pv01["912828M56"]<<source.pv01["912810RP5"];
        return os;
    }
    
    //other function
    void AddPosition(Position<Bond> &position);
    double GetBucketedRisk(BucketedSector<Bond> &sector);
    
};

BondRiskService::BondRiskService()
{
    Bond y2("912828M72","CUSIP","T",0,date(2017,Dec,1));
    Bond y3("912828N22","CUSIP","T",0,date(2018,Dec,1));
    Bond y5("912828M98","CUSIP","T",0,date(2019,Dec,1));
    Bond y7("912828M80","CUSIP","T",0,date(2022,Dec,1));
    Bond y10("912828M56","CUSIP","T",0,date(2025,Dec,1));
    Bond y30("912810RP5","CUSIP","T",0,date(2045,Dec,1));
    PV01<Bond> b2(y2,2.0,0);
    PV01<Bond> b3(y2,3.0,0);
    PV01<Bond> b5(y2,5.0,0);
    PV01<Bond> b7(y2,7.0,0);
    PV01<Bond> b10(y2,10.0,0);
    PV01<Bond> b30(y2,30.0,0);
    pv01.insert(pair<string,PV01<Bond>>("912828M72",b2));
    pv01.insert(pair<string,PV01<Bond>>("912828N22",b3));
    pv01.insert(pair<string,PV01<Bond>>("912828M98",b5));
    pv01.insert(pair<string,PV01<Bond>>("912828M80",b7));
    pv01.insert(pair<string,PV01<Bond>>("912828M56",b10));
    pv01.insert(pair<string,PV01<Bond>>("912810RP5",b30));
   
}

BondRiskService::BondRiskService(const BondRiskService& source):pv01(source.pv01),listeners(source.listeners)
{
    
}

BondRiskService::~BondRiskService()
{

}

PV01<Bond>& BondRiskService::GetData(string key)
{
    return pv01[key];
}

void BondRiskService::OnMessage(PV01<Bond> & data)
{
    
}

void BondRiskService::AddListener(ServiceListener<PV01<Bond>> & listener)
{
    listeners.push_back(&listener);
}

vector<ServiceListener<PV01<Bond>>*>  BondRiskService::GetListeners()
{
    return listeners;
}

BondRiskService& BondRiskService::operator=(BondRiskService&  source)
{
    pv01["912828M72"] = source.pv01["912828M72"];
    pv01["912828N22"] = source.pv01["912828N22"];
    pv01["912828M98"] = source.pv01["912828M98"];
    pv01["912828M80"] = source.pv01["912828M80"];
    pv01["912828M56"] = source.pv01["912828M56"];
    pv01["912810RP5"] = source.pv01["912810RP5"];
    listeners = source.listeners;
    return * this;
}

void BondRiskService::AddPosition(Position<Bond> & position)
{
    string key = position.GetProduct().GetProductId();
    string s1 = "TRSY1";
    string s2 = "TRSY2";
    string s3 = "TRSY3";
    int sum = position.GetPosition(s1)+ position.GetPosition(s2) + position.GetPosition(s3);
    
    pv01[key].SetQuantity(sum);
    //cout<<pv01[key];
}

double BondRiskService::GetBucketedRisk(BucketedSector<Bond>& source)
{
    double sum = 0;
    for(int i = 0; i < source.GetProducts().size();i++)
    {
        string k = source.GetProducts()[i].GetProductId();
        sum += pv01[k].GetPV01() * pv01[k].GetQuantity();
    }
    return sum;
}
//

#endif /* RiskService_h */
