#include <FuelPriceDb.hpp>
#include <EmailSender.hpp>
#include <Calculator.hpp>
#include <Chart.hpp>
#include <FuelPriceNotifier.hpp>
#include <SubscribersInterface.hpp>


int main()
{
    FuelPriceDb database;
    Subject notifier;

    Chart chart(database);
    Calculator calculator(database);
    EmailSender emailSender(database);

    database.initialize(&chart, &calculator, &emailSender);

    notifier.subscribe(&chart);
    notifier.subscribe(&calculator);
    notifier.subscribe(&emailSender);

    database.risePrices(5.55, 5.45, 1.90);

    notifier.unsubscribe(&calculator);

    database.risePrices(0.45, 0.55, 1.60);
}
