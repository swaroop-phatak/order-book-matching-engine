# order-book-matching-engine
A C++ based order book matching engine simulating buy and sell order execution using OOP and priority queues

# Order Book Matching Engine (C++)

This project simulates how a stock exchange matches buy and sell orders.

## Features
- Matches buy and sell orders based on best price
- Supports partial order execution
- Maintains separate order books for buy and sell sides
- Displays best buy and sell prices

## Concepts Used
- Object-Oriented Programming (OOP)
- Priority Queues (Heaps)
- Basic system design

## How it works
- Buy orders are stored in a max heap (highest price first)
- Sell orders are stored in a min heap (lowest price first)
- Orders are matched when buy price >= sell price

## Sample Input
BUY 100 10  
SELL 95 5  

## Output
Trade executed: 5 at price 95

## Tech Stack
- C++
- STL (priority_queue, vector)
