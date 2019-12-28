#ifndef BONDINQUIRYWRITINGCONNECT_HPP
#define BONDINQUIRYWRITINGCONNECT_HPP
class BondInquiryWritingConnector: public Connector<Inquiry<Bond>>
{

public:
    BondInquiryWritingConnector();
    void Publish(Inquiry<Bond> & data);
    
};

BondInquiryWritingConnector::BondInquiryWritingConnector()
{
        
}

void BondInquiryWritingConnector::Publish(Inquiry<Bond>& data)
{
    //cout<<data.GetInquiryId()<<","<<data.GetProduct()<<","<<data.GetSide()<<","<<data.GetQuantity()<<","<<data.GetPrice()<<", DONE"<<endl;
}




#endif
