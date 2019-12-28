//
//  main.cpp
//  9815
//
//  Created by LiuYuxi on 12/17/15.
//  Copyright © 2015 Yuxi Liu. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <string>
#include "stdlib.h"
#include "string.h"
#include "BondProductService.hpp"
#include "BondTradeBookingService.hpp"
#include "BondPositionService.hpp"
#include "BondTradeBookingConnector.hpp"
#include "BondTradeBooking_PositionListener.hpp"
#include "BondRiskService.hpp"
#include "BondPosition_RiskListener.hpp"
#include "BondPricingService.hpp"
#include "BondPricingConnector.hpp"
#include "BondMarketDataService.hpp"
#include "BondMarketDataConnector.hpp"
#include "BondAlgoExecutionService.hpp"
#include "BondAlgoExecution_MarketDataListener.hpp"
#include "BondExecutionService.hpp"
#include "BondAlgoExecution_ExecutionListener.hpp"
#include "AlgoStream.hpp"
#include "BondAlgoStreamingService.hpp"
#include "BondStreamingService.hpp"
#include "BondAlgoStreaming_StreamingListener.hpp"
#include "BondAlgoStreaming_PricingListener.hpp"
#include "Inquiry.hpp"
#include "BondInquiryService.hpp"
#include "BondInquiryReadingConnector.hpp"
#include "BondInquiryWritingConnect.hpp"
#include "BondPosition_HistoricalDataListener.hpp"
#include "BondRisk_HistoricalDataListener.hpp"
#include "BondExecution_HistoricalDataListener.hpp"
#include "BondStreaming_HistoricalDataListener.hpp"
#include "BondInquiry_HistoricalDataListener.h"
#include "BondHistoricalDataService.hpp"
using namespace std;



int main()
{
    //In order for my program to run, please change the following directory
    string trades_txt = "/Users/YuxiLIU/Desktop/9815/9815/trades.txt";
    string prices_txt = "/Users/YuxiLIU/Desktop/9815/9815/prices.txt";
    string marketdata_txt = "/Users/YuxiLIU/Desktop/9815/9815/marketdata.txt";
    string inquries_txt = "/Users/YuxiLIU/Desktop/9815/9815/inquiries.txt";
    
    
    //part one BondTradeBookingService
    BondRiskService r;
    BondPosition_RiskListener pr(r);
    BondPositionService p;
    p.AddListener(pr);
    BondTradeBooking_PositionListener tp(p);
    BondTradeBookingService t;
    t.AddListener(tp);
    BondTradeBookingConnector ctb(trades_txt,t);
    
    
    //part two BondPricing Service
    BondPricingService ps;
    BondPricingConnector pc(prices_txt,ps);
    
    
    //part three BondMarketDataService
    BondMarketDataService md;
    BondMarketDataConnector cmd(marketdata_txt,md);
    
    
    //part four BondAlgoExecutionService
    BondMarketDataService md1;
    BondExecutionService e;
    BondAlgoExecution_MarketDataListener aemdl(md1);
    BondAlgoExecution_ExecutionListener aeel(e);
    BondAlgoExecutionService ae;
    ae.AddListener(aemdl);
    ae.AddListener(aeel);
    
    
    //part five BondAlgoStreamingService
    
    BondPricingService md2;
    BondStreamingService e1;
    BondAlgoStreaming_PricingListener aemdl1(md2);
    BondAlgoStreaming_StreamingListener aeel1(e1);
    BondAlgoStreamingService ae1;
    ae1.AddListener(aemdl1);
    ae1.AddListener(aeel1);
    
    
    //part six BondInquiryService
    BondInquiryService i;
    BondInquiryWritingConnector iw;
    i.AddConnector(iw);
    BondInquiryReadingConnector ir(inquries_txt,i);
  
    //part seven BondHistoricalDataService
    BondHistoricalDataService<Position<Bond>> l1;
    BondPosition_HistoricalDataListener p1(l1);
    BondHistoricalDataService<PV01<Bond>> l2;
    BondRisk_HistoricalDataListener p2(l2);
    BondHistoricalDataService<ExecutionOrder<Bond>> l3;
    BondExecution_HistoricalDataListener p3(l3);
    BondHistoricalDataService<PriceStream<Bond>> l4;
    BondStreaming_HistoricalDataListener p4(l4);
    BondHistoricalDataService<Inquiry<Bond>> l5;
    BondInquiry_HistoricalDataListener p5(l5);
    
   
    
    
}
