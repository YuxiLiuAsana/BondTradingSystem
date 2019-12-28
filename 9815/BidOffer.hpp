#ifndef BIDOFFER_HPP
#define BIDOFFER_HPP
#include "Order.hpp"

class BidOffer
{
    
private:
    
    Order bidOrder;
    Order offerOrder;
    
public:
    
    //constructor and destructor
    BidOffer();
    BidOffer(const Order &_bidOrder, const Order &_offerOrder);
    BidOffer(const BidOffer&);
    ~BidOffer();
    
    //Getters
    const Order& GetBidOrder() const;
    const Order& GetOfferOrder() const;
    
    //operator overload
    BidOffer& operator=(BidOffer&);
    friend ostream& operator<<(ostream& os, const BidOffer & source)
    {
        os<<"BidOffer: "<<endl<<source.bidOrder<<source.offerOrder;
        return os;
    }
};

BidOffer::BidOffer():bidOrder(Order()),offerOrder(Order())
{

}

BidOffer::BidOffer(const Order &_bidOrder, const Order &_offerOrder):
bidOrder(_bidOrder), offerOrder(_offerOrder)
{
    
}

BidOffer::BidOffer(const BidOffer& source):bidOrder(source.bidOrder),offerOrder(source.offerOrder)
{
    
}

BidOffer::~BidOffer()
{

}

const Order& BidOffer::GetBidOrder() const
{
    return bidOrder;
}

const Order& BidOffer::GetOfferOrder() const
{
    return offerOrder;
}

BidOffer& BidOffer::operator=(BidOffer& source)
{
    bidOrder = source.bidOrder;
    offerOrder = source.offerOrder;
    return * this;
}

#endif /* BidOffer_h */
