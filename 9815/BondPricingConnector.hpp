#ifndef BONDPRICINGCONNECTOR_HPP
#define BONDPRICINGCONNECTOR_HPP
#include "soa.hpp"
#include "BondPricingService.hpp"
#include <string>
#include "Price.hpp"
#include "Bond.hpp"
class BondPricingConnector : public Connector<Price <Bond>>
{
private:
    BondPricingService& bondPricingService;
public:
    BondPricingConnector(string K,BondPricingService& source);
    void Publish(Price<Bond>& data);
};

BondPricingConnector::BondPricingConnector(string K,BondPricingService& source):bondPricingService(source)
{
    ifstream f1(K);
    string value[3];
    int s = 6000000;
    while (s-- )
    {
        for(int i = 0; i < 2; i++)
        {
            getline(f1,value[i],',');
        }
        getline(f1,value[2]);
        
        int size = value[1].size();
        if(value[1][size-1] == '+')
            value[1][size-1] = '4';
        double price = (double)(value[1][size-1]-'0')/256.0+(double)(value[1][size-2]-'0')/32.0 + 10.0 * (double)(value[1][size-3]-'0')/32.0+(double)(value[1][size-5]-'0')+10.0 * double(value[1][size-6]-'0') ;
        if(size == 7)
            price += 100.0;
        double gap = (double)(value[2][value[2].size()-1]-'0')/256.0;
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
        Price<Bond> tb(b,price,gap);
        //cout<<tb;
        bondPricingService.OnMessage(tb);
        
    }
}

void BondPricingConnector::Publish(Price<Bond>& data)
{

}
#endif