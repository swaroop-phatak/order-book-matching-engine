#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "Order.h"
#include "Trade.h"
#include <bits/stdc++.h>
using namespace std;

struct BuyCompare
{ 
    bool operator() (Order* a,Order* b);
};

struct SellCompare
{
    bool operator() (Order* a,Order* b);
};


class OrderBook{

    priority_queue<Order*, vector<Order*>, BuyCompare> buyOrders;
    priority_queue<Order*, vector<Order*>, SellCompare> sellOrders;
    int currentTime = 0;
    vector<Trade> tradeHistory;

    public:

    OrderBook();

    

    void addOrder(Order* order);

    void matchOrders();

    void showTop();

    void showTrades();

};


#endif