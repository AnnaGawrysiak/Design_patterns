#ifndef NOTIFIER
#define NOTIFIER

#include <vector>
#include <list>
#include <SubscribersInterface.hpp>

class SubjectInterface
{
    public:
        virtual ~SubjectInterface(){};
        virtual void subscribe(SubscribersInterface* subsrciber)=0;
        virtual void unsubscribe(SubscribersInterface* subsriber)=0;
        virtual void notify()=0;
};

class Subject : public SubjectInterface
{
public:
    virtual ~Subject(){};
    void subscribe(SubscribersInterface* subscriber) override{
        subscribers.push_back(subscriber);
    }
    void unsubscribe(SubscribersInterface* subscriber)override{
        subscribers.remove(subscriber);
    }
    void notify() override{
        if(subscribers.empty())
            return;
        for(const auto& s: subscribers)
        {
            s->update();
        }
    }
private:
    std::list<SubscribersInterface*> subscribers;
};

#endif