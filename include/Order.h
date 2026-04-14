#ifndef ORDER_H
#define ORDER_H

enum OrderType {
    BUY,
    SELL
};

class Order{
    public:
    int id;
    OrderType type;
    int price;
    int quantity;
    int timestamp;

    Order(int id, OrderType type, int price, int quantity);

};

#endif