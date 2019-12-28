#ifndef BONDINQUIRYREADINGCONNECTOR_HPP
#define BONDINQUIRYREADINGCONNECTOR_HPP

class BondInquiryReadingConnector: public Connector<Inquiry<Bond>>
{
private:
    BondInquiryService & bondInquiryService;
public:
    BondInquiryReadingConnector(string K, BondInquiryService & source);
    void Publish(Inquiry<Bond> & data);
    
};

BondInquiryReadingConnector::BondInquiryReadingConnector(string K,BondInquiryService & source):bondInquiryService(source)
{
    
    ifstream f1(K);
    string value[7];
    int s = 60;
    while (s-- )
    {
        for(int i = 0; i < 6; i++)
        {
            getline(f1,value[i],',');
        }
        getline(f1,value[6]);
        
        int size = value[3].size();
        if(value[3][size-1] == '+')
            value[3][size-1] = '4';
        double price = (double)(value[3][size-1]-'0')/256.0+(double)(value[3][size-2]-'0')/32.0 + 10.0 * (double)(value[3][size-3]-'0')/32.0+(double)(value[3][size-5]-'0')+10.0 * double(value[3][size-6]-'0') ;
        if(size == 7)
            price += 100.0;
        date * maturity;
        if(value[0] == "912828M72")
        {
            maturity = new date(2017,Dec,1);
        }
        else if(value[0] == "912828N22")
        {
            maturity = new date(2018,Dec,1);
        }
        else if(value[0] == "912828M98")
        {
            maturity = new date(2020,Dec,1);
        }
        else if(value[0] == "912828M80")
        {
            maturity = new date(2022,Dec,1);
        }
        else if(value[0] == "912828M56")
        {
            maturity = new date(2025,Dec,1);
        }
        else if(value[0] == "912810RP5")
        {
            maturity = new date(2045,Dec,1);
        }
        Bond b(value[0],"CUSIP","T",0.2,*maturity);
        Inquiry<Bond> tb(value[1],b,value[5],stoi(value[4]),price,value[6]);
        bondInquiryService.OnMessage(tb);
        //cout<<tb;
        
    }
    
}

void BondInquiryReadingConnector::Publish(Inquiry<Bond>& data)
{
    
}


#endif /* BondInquiryReadingConnector_h */
