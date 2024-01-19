# Market Data Simulator

This C++ project simulates basic market data, including random price changes and trade events, to mimic the behavior of a financial market.

## Files and Folders

- `src/`: Contains the main application code and implementation files.
  - `main.cpp`: Main application code.
  - `MarketData.h` and `MarketData.cpp`: Header and implementation files for the MarketData structure.
  - `RandomGenerator.h` and `RandomGenerator.cpp`: Header and implementation files for random number generation functions.
  - `TimestampGenerator.h` and `TimestampGenerator.cpp`: Header and implementation files for timestamp generation functions.
- `CMakeLists.txt`: CMake configuration file.
- `.gitignore`: Git ignore file.
- `README.md`: Project documentation.

## Build Instructions

To build the project, use the following commands:

```bash
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
cd bin
./MDSTEST.exe
```

![Output ss](https://drive.google.com/file/d/1QsaRBNJBEvrpK3Nmf1crc9t3qCyQLLnz/view?usp=drive_link)
