#include "../include/Order.h"

Order :: Order(int id, OrderType type, int price, int quantity){

    this->id= id;
    this->type =type;
    this->price = price;
    this->quantity= quantity;
    this->timestamp = 0;
}