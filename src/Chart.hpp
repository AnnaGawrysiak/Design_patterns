#ifndef CRT
#define CRT

#include <iostream>
#include <FuelPriceDb.hpp>
#include <DbClient.hpp>
#include <SubscribersInterface.hpp>

class Chart : public DbClient,  public SubscribersInterface
{
public:
    Chart(FuelPriceDb& db)
        :DbClient(db)
    {
    }

    void plot()
    {
        std::cout << "Chart::plot()              new price of petrol " << database.getPriceOf(Petrol) << "\n";
    }

    void update() override{
        plot();
    }
    ~Chart(){};
};

#endif