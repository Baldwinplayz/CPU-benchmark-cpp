#include <vector>
#include <chrono>
#include <iostream>

using namespace std;

vector<unsigned long long> memory;

unsigned long long ullong = 18446744073709551615ULL;

double vectorMemoryTest() {
    clock_t start, end;
    start = clock();

    for (int j = 0; j < 20; j++) {
        memory = std::vector<unsigned long long>();
        for (int i = 0; i < 10000000; i++) {
            memory.push_back(ullong);
        }
    }

    end = clock();

    double ULLPerTick = 200000000.0 / double(end - start);

    std::cout << "ULL appended per CPU Tick (higher is better): " << ULLPerTick;
    std::cout << std::endl;
    std::cout << "Total CPU time: " << end - start;
    std::cout << std::endl;

    return ULLPerTick;
}
