#ifndef ALGOEXECUTION_HPP
#define ALGOEXECUTION_HPP

#include "ExecutionOrder.hpp"
#include "Bond.hpp"

template<typename T>
class AlgoExecution
{
    
private:
    
    ExecutionOrder<T> * executionOrder;
    
public:
    
    //constructor and destructor
    AlgoExecution();
    AlgoExecution(ExecutionOrder<T> & exe);
    AlgoExecution(const AlgoExecution<T>&);
    ~AlgoExecution();
    
    //getter
    ExecutionOrder<T>* GetExecutionOrder() const;
    
    //operator overload
    AlgoExecution<T>& operator=(AlgoExecution<T>&);
    friend ostream& operator<<(ostream& os, AlgoExecution<T>& source )
    {
        os<<"AlgoExecution: "<<*source.executionOrder;
        return os;
    }
    
};

template<typename T>
AlgoExecution<T>::AlgoExecution()
{

}

template<typename T>
AlgoExecution<T>::AlgoExecution(ExecutionOrder<T> & exe):executionOrder(&exe)
{
    
}

template<typename T>
AlgoExecution<T>::AlgoExecution(const AlgoExecution<T> & source):executionOrder(source.executionOrder)
{

}

template<typename T>
AlgoExecution<T>::~AlgoExecution()
{

}

template<typename T>
ExecutionOrder<T>* AlgoExecution<T>::GetExecutionOrder() const
{
    return executionOrder;
}

template<typename T>
AlgoExecution<T>& AlgoExecution<T>::operator=(AlgoExecution<T>& source)
{
    executionOrder = source.executionOrder;
    return *this;
}

#endif
