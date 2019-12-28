#ifndef BOND_HPP
#define BOND_HPP

#include "Product.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
using namespace boost::gregorian;

class Bond : public Product
{
    
private:
    
    string productId;//912828M56
    string bondIdType;//CUSIP
    string ticker;
    float coupon;
    date maturityDate;
    
public:
    
    //constructor and destructor
    Bond();
    Bond(string _productId, string _bondIdType, string _ticker, float _coupon, date _maturityDate);
    Bond(const Bond& source);
    ~Bond();
    
    //Getters
    const string& GetProductId() const;
    const string& GetBondIdType() const;
    const string& GetTicker() const;
    float GetCoupon() const;
    const date& GetMaturityDate() const;
    
    //operator overload
    Bond& operator=(Bond& source);
    friend ostream& operator<<(ostream &output, const Bond &bond)
    {
        output<<"Bond: "<<bond.GetProductId()<<", "<<bond.GetBondIdType()<<", "<<bond.GetTicker()<<", "<<bond.GetCoupon()<<", "<<bond.GetMaturityDate()<<endl;
        return output;
    }
        
};
        
Bond::Bond():Product(),productId("912828M72"),bondIdType("CUSIP"),ticker("T"),coupon(0.02),maturityDate(date(2017,Dec,01))
{
    
}
        
Bond::Bond(string _productId, string _bondIdType, string _ticker, float _coupon, date _maturityDate) : Product(_productId, "BOND"),productId(_productId),bondIdType(_bondIdType),ticker(_ticker),coupon(_coupon),maturityDate(_maturityDate)
{
    
}

Bond::Bond(const Bond& source):Product(source.productId, "BOND"),productId(source.productId),bondIdType(source.bondIdType),coupon(source.coupon),maturityDate(source.maturityDate),ticker(source.ticker)
{

}

Bond::~Bond()
{

}

const string& Bond::GetBondIdType() const
{
    return bondIdType;
}

const string& Bond::GetProductId() const
{
    return productId;
}

const string& Bond::GetTicker() const
{
    return ticker;
}

float Bond::GetCoupon() const
{
    return coupon;
}

const date& Bond::GetMaturityDate() const
{
    return maturityDate;
}

Bond& Bond::operator=(Bond & source)
{
    productId = source.productId;
    bondIdType = source.bondIdType;
    ticker = source.ticker;
    coupon = source.coupon;
    maturityDate = source.maturityDate;
    return * this;
}

#endif /* Bond_hpp */
