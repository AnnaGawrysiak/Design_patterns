#ifndef MAIL
#define MAIL

#include <iostream>
#include <FuelPriceDb.hpp>
#include <DbClient.hpp>
#include <SubscribersInterface.hpp>

class EmailSender : public DbClient,  public SubscribersInterface
{
public:
    EmailSender(FuelPriceDb& db)
        :DbClient(db)
    {
    }

    void send()
    {
        std::cout << "EmailSender::send()        new price of lpg    " << database.getPriceOf(Lpg) << "\n";
    }

     void update() override{
        send();
    }
    ~EmailSender(){};
};

#endif