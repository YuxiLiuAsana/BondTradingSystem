#ifndef BONDMARKETDATACONNECTOR_HPP
#define BONDMARKETDATACONNECTOR_HPP
#include "BondMarketDataService.hpp"
#include "Bond.hpp"

class BondMarketDataConnector: public Connector<OrderBook<Bond>>
{
    
private:
    
    BondMarketDataService & bondMarketDataService;
    
public:
    
    BondMarketDataConnector(string K, BondMarketDataService & source);
    void Publish(OrderBook<Bond> & data);
    
};

BondMarketDataConnector::BondMarketDataConnector(string K,BondMarketDataService & source):bondMarketDataService(source)
{
    
    ifstream f1(K);
    string value[11];
    int s = 6000000;
    while (s-- )
    {
        for(int i = 0; i < 10; i++)
        {
            getline(f1,value[i],',');
        }
        getline(f1,value[10]);
        
        double price[10];
        for(int i =0 ; i < 10; i++)
        {
            int size = value[i+1].size();
            if(value[i+1][size-1] == '+')
                value[i+1][size-1] = '4';
            price[i] = (double)(value[i+1][size-1]-'0')/256.0+(double)(value[i+1][size-2]-'0')/32.0 + 10.0 * (double)(value[i+1][size-3]-'0')/32.0+(double)(value[i+1][size-5]-'0')+10.0 * double(value[i+1][size-6]-'0') ;
            if(size == 7)
                price[i] += 100.0;

        }
        
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
        
        vector<Order> bid;
        vector<Order> offer;
        for(int i = 0; i < 5; i++)
        {
            Order b(price[i],(5-i)*10000000,"BUY");
            Order o(price[9-i], (5-i)*10000000,"SELL");
            bid.push_back(b);
            offer.push_back(o);
        }
        OrderBook<Bond> tb(b,bid,offer);
        //cout<<tb;
        
        bondMarketDataService.OnMessage(tb);
        
    }
    
}

void BondMarketDataConnector::Publish(OrderBook<Bond>& data)
{
    
}



#endif