#include "include/OrderBook.h"


int main() {
    OrderBook ob;

    cout << "\n--- Adding Orders ---\n";

    // Basic orders
    ob.addOrder(new Order(1, BUY, 100, 10));
    ob.addOrder(new Order(2, BUY, 105, 5));
    ob.addOrder(new Order(3, SELL, 102, 7));
    ob.addOrder(new Order(4, SELL, 99, 3));

    // Same price (timestamp test)
    ob.addOrder(new Order(5, BUY, 105, 4));   // same price as order 2
    ob.addOrder(new Order(6, SELL, 102, 2));  // same price as order 3

    // Partial matching test
    ob.addOrder(new Order(7, BUY, 110, 8));
    ob.addOrder(new Order(8, SELL, 100, 15));

    cout << "\n--- Final Top Orders ---\n";
    ob.showTop();

    cout << "\n";
    ob.showTrades();

    return 0;
}   