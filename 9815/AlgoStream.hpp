#ifndef ALGOSTREAM_HPP
#define ALGOSTREAM_HPP

#include "PriceStream.hpp"
template<typename T>
class AlgoStream
{
    
private:
    
    PriceStream<T> * priceStream;
    
public:
    
    //constructor and destructor
    AlgoStream();
    AlgoStream(PriceStream<T> & exe);
    AlgoStream(const AlgoStream<T>&);
    ~AlgoStream();
    
    //getter
    PriceStream<T>* GetPriceStream() const;
    
    //operator overload
    AlgoStream<T>& operator=(AlgoStream<T>&);
    friend ostream& operator<<(ostream& os, AlgoStream<T>& source )
    {
        os<<"AlgoStream: "<<*source.priceStream;
        return os;
    }
    
};

template<typename T>
AlgoStream<T>::AlgoStream()
{
    
}

template<typename T>
AlgoStream<T>::AlgoStream(PriceStream<T> & exe):priceStream(&exe)
{
    
}

template<typename T>
AlgoStream<T>::AlgoStream(const AlgoStream<T> & source):priceStream(source.priceStream)
{
    
}

template<typename T>
AlgoStream<T>::~AlgoStream()
{
    
}

template<typename T>
PriceStream<T>* AlgoStream<T>::GetPriceStream() const
{
    return priceStream;
}

template<typename T>
AlgoStream<T>& AlgoStream<T>::operator=(AlgoStream& source)
{
    priceStream = source.priceStream;
    return *this;
}


#endif
