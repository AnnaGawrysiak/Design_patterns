#ifndef SUBSCRIBERSI
#define SUBSCRIBERSI

class SubscribersInterface
{
public:
    virtual ~SubscribersInterface(){};
    virtual void update()=0; 
};

#endif