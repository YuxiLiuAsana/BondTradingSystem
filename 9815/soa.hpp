#ifndef SOA_HPP
#define SOA_HPP
#include <vector>
using namespace std;
//***************************************************************************************


template<typename V>
class ServiceListener
{

public:
  virtual void ProcessAdd(V &data) {}
  virtual void ProcessRemove(V &data) {}
  virtual void ProcessUpdate(V &data) {}

};


//***************************************************************************************
template<typename V>
class Connector
{
    
public:
    virtual void Publish(V &data) = 0;
    
};




//*************************************************************************************

template<typename K, typename V>
class Service
{
    
public:
    
    virtual V& GetData(K  key) = 0;
    virtual void OnMessage(V &data) = 0;
    virtual void AddListener(ServiceListener<V> &listener) = 0;
    virtual vector< ServiceListener<V> *> GetListeners() = 0;
   
    
};





//**************************************************************************************

#endif
