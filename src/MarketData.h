#ifndef MARKETDATA_H
#define MARKETDATA_H

#include <string>

struct MarketData
{
    std::string symbol;
    double lastPrice;
    double bid;
    double ask;
    int volume;
    std::string timestamp;
};

// Declare simulateTradeEvents function
void simulateTradeEvents(MarketData &marketData);
#endif // MARKETDATA_H
