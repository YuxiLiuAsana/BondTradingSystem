#ifndef HISTORICALDATASERVICE_HPP
#define HISTORICALDATASERVICE_HPP
#include "Bond.hpp"
#include "soa.hpp"
#include <vector>
#include <map>

template<typename T>
class BondHistoricalDataService : public Service<string,T>
{
private:
    
    vector<ServiceListener<T>*> listeners;
public:
    map<string,T> bond;
    T& GetData(string  key) {return bond[key];}
    void OnMessage(T &data) {}
    void AddListener(ServiceListener<T> &listener){}
    vector< ServiceListener<T> *> GetListeners() {return listeners;}
};





#endif
