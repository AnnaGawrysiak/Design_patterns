#ifndef CALC
#define CALC

#include <iostream>
#include <FuelPriceDb.hpp>
#include <DbClient.hpp>
#include <SubscribersInterface.hpp>

class Calculator : public DbClient, public SubscribersInterface
{
public:
    Calculator(FuelPriceDb& db)
        :DbClient(db)
    {
    }

    void recalculate()
    {
        std::cout << "Calculator::recalculate()  new price of diesel " << database.getPriceOf(Diesel) << "\n";
    }

    void update() override{
        recalculate();
    }
    ~Calculator(){};
};

#endif