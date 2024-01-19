// MarketData.cpp
#include "MarketData.h"
#include "RandomGenerator.h"
#include "TimestampGenerator.h"
#include <iostream>
#include <cmath>
#include <vector>

// Define a vector of symbols
std::vector<std::string> symbols = {"AAPL", "GOOGL", "MSFT", "AMZN", "TSLA", "FB", "NFLX", "NVDA", "PYPL", "IBM", "INTC", "CSCO", "AMD", "SPY", "V"};
// Function to get a random symbol from the vector
std::string getRandomSymbol()
{
    int index = rand() % symbols.size();
    return symbols[index];
}
// Function to initialize market data with default values
void initializeMarketData(MarketData &marketData, const std::string &symbol, double initialPrice)
{
    marketData.symbol = symbol;
    marketData.lastPrice = initialPrice;
    marketData.bid = initialPrice - 1.0; // Example initial bid (adjust as needed)
    marketData.ask = initialPrice + 1.0; // Example initial ask (adjust as needed)
    marketData.volume = 0;
    marketData.timestamp = ""; // Initialize timestamp as an empty string
}

// Function to update market data with random changes
void updateMarketDataRandomly(MarketData &marketData)
{
    // Simulate random price changes
    marketData.lastPrice = generateRandomPrice(marketData.lastPrice);

    // Simulate trade events
    simulateTradeEvents(marketData);

    // Update bid and ask based on last price (example: +/- 1.0)
    marketData.bid = marketData.lastPrice - 1.0;
    marketData.ask = marketData.lastPrice + 1.0;

    // Update timestamp
    marketData.timestamp = getCurrentTimestamp();
}

// Function to display market data
void displayMarketData(const MarketData &marketData)
{
    std::cout << "Symbol: " << marketData.symbol << " | "
              << "Last Price: " << marketData.lastPrice << " | "
              << "Bid: " << marketData.bid << " | "
              << "Ask: " << marketData.ask << " | "
              << "Volume: " << marketData.volume << " | "
              << "Timestamp: " << marketData.timestamp << std::endl;
}

// Function to simulate trade events with varying symbols
void simulateTradeEvents(MarketData &marketData)
{
    // Simulate a price trend with random fluctuations
    double trend = 0.1;       // Example: 10% price increase over time
    double volatility = 0.02; // Example: 2% volatility

    // Generate a random price change within the specified volatility
    double randomChange = (rand() % 1000) / 1000.0 * volatility;

    // Apply the trend and random change to the last price
    marketData.lastPrice = marketData.lastPrice * (1.0 + trend + randomChange);

    // Simulate bid and ask prices based on the last price
    marketData.bid = marketData.lastPrice - 0.5; // Example: Bid is 0.5 lower than last price
    marketData.ask = marketData.lastPrice + 0.5; // Example: Ask is 0.5 higher than last price

    // Simulate trade events with varying volumes
    int maxVolumeChange = 100; // Increase the maximum volume change
    int volumeChange = rand() % (2 * maxVolumeChange + 1) - maxVolumeChange;
    // Ensure the volume doesn't go below zero
    marketData.volume = std::max(0, marketData.volume + volumeChange);

    // Randomly select a symbol for each market data entry
    marketData.symbol = getRandomSymbol();
}
