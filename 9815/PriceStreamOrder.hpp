#ifndef PRICESTREAMORDER_HPP
#define PRICESTREAMORDER_HPP

class PriceStreamOrder
{
    
private:
    
    double price;
    long visibleQuantity;
    long hiddenQuantity;
    string side;
    
public:
    
    // constructor and destructo
    PriceStreamOrder();
    PriceStreamOrder(double _price, long _visibleQuantity, long _hiddenQuantity, string _side);
    PriceStreamOrder(const PriceStreamOrder&);
    ~PriceStreamOrder();
    
    //Getters
    const string& GetSide() const;
    double GetPrice() const;
    long GetVisibleQuantity() const;
    long GetHiddenQuantity() const;
    
    //operator overload
    PriceStreamOrder& operator=(PriceStreamOrder&);
    friend ostream& operator<<(ostream& os, PriceStreamOrder& source)
    {
        os<<"PriceStreamOrder: "<<source.price<<","<<source.visibleQuantity<<","<<source.hiddenQuantity<<","<<source.side<<endl;
        return os;
    }
    
};

PriceStreamOrder::PriceStreamOrder():price(0),visibleQuantity(0),hiddenQuantity(0),side("BUY")
{
    
}

PriceStreamOrder::PriceStreamOrder(double _price, long _visibleQuantity, long _hiddenQuantity, string _side):price(_price),visibleQuantity(_visibleQuantity),hiddenQuantity(_hiddenQuantity),side(_side)
{
   
}

PriceStreamOrder::PriceStreamOrder(const PriceStreamOrder& source):price(source.price),visibleQuantity(source.visibleQuantity),hiddenQuantity(source.hiddenQuantity),side(source.side)
{

}

PriceStreamOrder::~PriceStreamOrder()
{

}

double PriceStreamOrder::GetPrice() const
{
    return price;
}

long PriceStreamOrder::GetVisibleQuantity() const
{
    return visibleQuantity;
}

long PriceStreamOrder::GetHiddenQuantity() const
{
    return hiddenQuantity;
}

const string& PriceStreamOrder::GetSide() const
{
    return side;
}

PriceStreamOrder& PriceStreamOrder::operator=(PriceStreamOrder& source)
{
    price = source.price;
    hiddenQuantity = source.hiddenQuantity;
    visibleQuantity = source.visibleQuantity;
    side = source.side;
    return * this;
}
#endif /* PriceStreamOrder_h */
