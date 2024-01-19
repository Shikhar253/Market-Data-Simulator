#include <iostream>
#include <thread>
#include <chrono> // Include <chrono> here
#include "MarketData.h"
#include "RandomGenerator.h"
#include "TimestampGenerator.h"

// Function declarations from MarketData.cpp
void initializeMarketData(MarketData &marketData, const std::string &symbol, double initialPrice);
void updateMarketDataRandomly(MarketData &marketData);
void displayMarketData(const MarketData &marketData);
void simulateTradeEvents(MarketData &marketData);
int main()
{
    srand(static_cast<unsigned>(time(0)));

    // Create an instance of MarketData
    MarketData simulatedMarketData;

    // Initialize market data with default values
    initializeMarketData(simulatedMarketData, "XYZ", 100.0);

    for (int i = 0; i < 10; ++i)
    {
        // Update market data randomly
        updateMarketDataRandomly(simulatedMarketData);

        // Display simulated market data
        displayMarketData(simulatedMarketData);

        // Sleep for a short duration to simulate real-time updates
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
