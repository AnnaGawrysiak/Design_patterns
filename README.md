# Design_patterns
Observer Design Pattern Implementation

The application can monitor fuel prices. 
There are objects which take action when some prices change in the fuel price database (FuelPriceDb).
These objects get data directly from FuelPriceDb.

About observer design pattern:
The observer behavioral pattern is a software design pattern in which an object, named the subject, 
maintains a list of its dependents, called observers, and notifies them automatically 
of any state changes, usually by calling one of their methods. 

Observer allows to notify all kinds of clients (OCP).
We have possibility to subscribe objects in runtime.

n reality, this mechanism consists of:
1) an array field for storing a list of references to subscriber objects and 
2) several public methods which allow adding subscribers to and removing them from that list.

It’s crucial that all subscribers implement the same interface and that the publisher communicates 
with them only via that interface. This interface should declare the notification method (e.g. update()).

