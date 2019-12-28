#ifndef BONDALGOSTREAMING_STREAMINGLISTENER_HPP
#define BONDALGOSTREAMING_STREAMINGLISTENER_HPP

class BondAlgoStreaming_StreamingListener : public ServiceListener<AlgoStream<Bond>>
{
private:
    BondStreamingService & bondStreamingService;
public:
    BondAlgoStreaming_StreamingListener(BondStreamingService &);
    void ProcessAdd(AlgoStream<Bond>& data);
    void ProcessRemove(AlgoStream<Bond>& data){}
    void ProcessUpdate(AlgoStream<Bond>& data){}
    
};

BondAlgoStreaming_StreamingListener::BondAlgoStreaming_StreamingListener(BondStreamingService& s):bondStreamingService(s)
{
    
}

void BondAlgoStreaming_StreamingListener::ProcessAdd(AlgoStream<Bond>& data)
{
    bondStreamingService.PublishPrice( data);
}

#endif /* BondAlgoStreaming_StreamingListener_h */
