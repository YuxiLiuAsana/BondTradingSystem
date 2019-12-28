
#ifndef BONDINQUIRYSERVICE_HPP
#define BONDINQUIRYSERVICE_HPP
#include <vector>
#include "Bond.hpp"
#include "soa.hpp"
#include <map>
#include "Inquiry.hpp"


class BondInquiryService : public Service<string,Inquiry <Bond> >
{
private:
    
    map<string, Inquiry<Bond>> inquiry;
    vector<ServiceListener<Inquiry<Bond>>*> listeners;
    vector<Connector<Inquiry<Bond>>* > connectors;
    
public:
    
    //constructor and destructor
    BondInquiryService();
    BondInquiryService(const BondInquiryService& );
    ~BondInquiryService();
    
    //virtual functions
    void OnMessage(Inquiry <Bond> & data);
    Inquiry <Bond>& GetData(string key);
    void AddListener(ServiceListener<Inquiry <Bond>>& listener);
    vector<ServiceListener<Inquiry <Bond>>*> GetListeners();
    void AddConnector(Connector<Inquiry <Bond>>& connector);
    vector<Connector<Inquiry <Bond>>*> GetConnectors();
    
    //function overload
    BondInquiryService& operator=(BondInquiryService&);
    friend ostream& operator<<(ostream& os, BondInquiryService& source)
    {
        os<<"BondInquiryService: "<<source.inquiry["912828M72"]<<source.inquiry["912828N22"]<<source.inquiry["912828M98"]<<source.inquiry["912828M80"]<<source.inquiry["912828M56"]<<source.inquiry["912810RP5"];
        return os;
    }
    
};

BondInquiryService::BondInquiryService()
{
    Bond y2("912828M72","CUSIP","T",0,date(2017,Dec,1));
    Bond y3("912828N22","CUSIP","T",0,date(2018,Dec,1));
    Bond y5("912828M98","CUSIP","T",0,date(2019,Dec,1));
    Bond y7("912828M80","CUSIP","T",0,date(2022,Dec,1));
    Bond y10("912828M56","CUSIP","T",0,date(2025,Dec,1));
    Bond y30("912810RP5","CUSIP","T",0,date(2045,Dec,1));
    Inquiry<Bond> i2("T2", y2, "BUY", 0, 100, "RECEIVED");
    Inquiry<Bond> i3("T3", y3, "BUY", 0, 100, "RECEIVED");
    Inquiry<Bond> i5("T5", y5, "BUY", 0, 100, "RECEIVED");
    Inquiry<Bond> i7("T7", y7, "BUY", 0, 100, "RECEIVED");
    Inquiry<Bond> i10("T10", y10, "BUY", 0, 100, "RECEIVED");
    Inquiry<Bond> i30("T30", y30, "BUY", 0, 100, "RECEIVED");
    inquiry.insert(pair<string, Inquiry<Bond>>("912828M72",i2));
    inquiry.insert(pair<string, Inquiry<Bond>>("912828N22",i3));
    inquiry.insert(pair<string, Inquiry<Bond>>("912828M98",i5));
    inquiry.insert(pair<string, Inquiry<Bond>>("912828M80",i7));
    inquiry.insert(pair<string, Inquiry<Bond>>("912828M56",i10));
    inquiry.insert(pair<string, Inquiry<Bond>>("912810RP5",i30));

}

BondInquiryService::BondInquiryService(const BondInquiryService& source):inquiry(source.inquiry),listeners(source.listeners)
{

}

BondInquiryService::~BondInquiryService()
{

}

void BondInquiryService::OnMessage(Inquiry <Bond> & data)
{
    string k = data.GetProduct().GetProductId();
    Inquiry<Bond> temp(data.GetInquiryId(),data.GetProduct(),data.GetSide(),data.GetQuantity(),data.GetPrice(),"QUOTED");
    
    inquiry[k] = temp;
    connectors[0]->Publish(temp);
    
    
}

Inquiry<Bond>& BondInquiryService::GetData(string key)
{
    return inquiry[key];
}

void BondInquiryService::AddListener(ServiceListener<Inquiry <Bond>>& listener)
{
    listeners.push_back(&listener);
}

vector<ServiceListener<Inquiry <Bond>>*> BondInquiryService::GetListeners()
{
    return listeners;
}

void BondInquiryService::AddConnector(Connector<Inquiry <Bond>>& connector)
{
    connectors.push_back(& connector);
}

vector<Connector<Inquiry <Bond>>*> BondInquiryService::GetConnectors()
{
    return connectors;
}


BondInquiryService& BondInquiryService::operator=(BondInquiryService& source)
{
    inquiry["912828M72"] = source.inquiry["912828M72"];
    inquiry["912828N22"] = source.inquiry["912828N22"];
    inquiry["912828M98"] = source.inquiry["912828M98"];
    inquiry["912828M80"] = source.inquiry["912828M80"];
    inquiry["912828M56"] = source.inquiry["912828M56"];
    inquiry["912810RP5"] = source.inquiry["912810RP5"];
    listeners = source.listeners;
    return *this;
}






#endif
