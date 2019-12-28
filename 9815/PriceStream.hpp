#ifndef PRICESTREAM_HPP
#define PRICESTREAM_HPP
#include "PriceStreamOrder.hpp"

template<typename T>
class PriceStream
{
    
private:
    
    T product;
    PriceStreamOrder bidOrder;
    PriceStreamOrder offerOrder;
    
public:
    
    //constructor and destructor
    PriceStream();
    PriceStream(const T &_product, const PriceStreamOrder &_bidOrder, const PriceStreamOrder &_offerOrder);
    PriceStream(const PriceStream<T> &);
    ~PriceStream();
    
    //getters
    const T& GetProduct() const;
    const PriceStreamOrder& GetBidOrder() const;
    const PriceStreamOrder& GetOfferOrder() const;
    
    //operator overload
    PriceStream<T>& operator=(PriceStream<T>&);
    friend ostream& operator<<(ostream& os, PriceStream& source)
    {
        os<<"PriceStream: "<<endl<<source.product<<source.bidOrder<<source.offerOrder;
        return os;
    }
};

template<typename T>
PriceStream<T>::PriceStream()
{
    
}

template<typename T>
PriceStream<T>::PriceStream(const T &_product, const PriceStreamOrder &_bidOrder, const PriceStreamOrder &_offerOrder) :product(_product), bidOrder(_bidOrder), offerOrder(_offerOrder)
{
    
}

template<typename T>
PriceStream<T>::PriceStream(const PriceStream<T>& source):product(source.product),bidOrder(source.bidOrder),offerOrder(source.offerOrder)
{

}

template<typename T>
PriceStream<T>::~PriceStream()
{

}

template<typename T>
const T& PriceStream<T>::GetProduct() const
{
    return product;
}

template<typename T>
const PriceStreamOrder& PriceStream<T>::GetBidOrder() const
{
    return bidOrder;
}

template<typename T>
const PriceStreamOrder& PriceStream<T>::GetOfferOrder() const
{
    return offerOrder;
}

template<typename T>
PriceStream<T>& PriceStream<T>::operator=(PriceStream<T>& source)
{
    product = source.product;
    bidOrder = source.bidOrder;
    offerOrder = source.offerOrder;
    return * this;
}
#endif /* PriceStream_h */
