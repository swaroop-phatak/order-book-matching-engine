#include "../include/OrderBook.h"

OrderBook :: OrderBook(){
    currentTime = 0;
}


bool BuyCompare :: operator()(Order* a, Order* b){
    // comp.operator()(a, b); 
    if(a-> price == b -> price) return a->timestamp > b->timestamp;
    return a->price < b->price;       /* a < b --> b wins --> higher price wins */  
}

bool SellCompare :: operator()(Order* a, Order* b){

    if(a-> price == b -> price) return a->timestamp > b->timestamp;
    return a->price > b->price;      /* a > b --> b wins --> lower price wins */
}

void OrderBook :: addOrder(Order* order){
        order->timestamp = currentTime++;
        
        if(order->type == BUY){
            buyOrders.push(order);
            cout<<"Added BUY [ID="<<order->id<<"] @ "<<order->price<<endl;
        }else{

            sellOrders.push(order);
            cout<<"Added SELL [ID="<<order->id<<"] @ "<<order->price<<endl;
        }

        matchOrders();
    }

void OrderBook :: matchOrders(){

        while(!buyOrders.empty()  && !sellOrders.empty() ){

            Order* buy = buyOrders.top();
            Order* sell = sellOrders.top();

            if(buy->price >= sell->price){

                int tradeQty = min(buy->quantity, sell->quantity);

                cout<<"Trade: BUY("<<buy->id<<") <-> SELL("<<sell->id<<") | Qty="<<tradeQty<<" @ "<<sell->price<<endl;

                tradeHistory.push_back({buy->id, sell->id, sell-> price , tradeQty});

                buy->quantity -= tradeQty;
                sell->quantity -= tradeQty;

                buyOrders.pop();
                sellOrders.pop();

                if(buy->quantity > 0) buyOrders.push(buy);
                if(sell->quantity > 0) sellOrders.push(sell);

            }else{

                break;

            }
        }
    }

void OrderBook :: showTop(){

     if(!buyOrders.empty()){
         cout<<"Top BUY : "<< buyOrders.top()->price<<endl;
     }else{
         cout<<"No BUY orders right now !"<<endl;
     }
     
     
     if(!sellOrders.empty()){
         cout<<"Top SELL : "<< sellOrders.top()->price<<endl;
     }else{
         cout<<"No SELL orders right now !"<<endl;
     }
}

void OrderBook :: showTrades(){
    cout<<" ----------- TRADE HISTORY ----------- "<<endl;
    for(auto &t : tradeHistory){
        cout << "BUY ID " << t.buyId
         << " <--> SELL ID " << t.sellId
         << " | Qty: " << t.quantity
         << " | Price: " << t.price << endl;
    }
}