#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <tuple>

using namespace std;

double prime = 10888869450418352160768000001.0;

std::tuple<double, double, double, double> mathTest() {
    std::clock_t start, end;

    start = std::clock();

    for (int i = 0; i < 2000000000; i++) {
        prime + prime + prime + prime + prime - prime - prime - prime - prime - prime;
    }

    end = std::clock();

    double ArthPerTick = 2000000000 / double(end - start);

    std::cout << "ArithmeTick operation per CPU Tick (higher is better): " << ArthPerTick;
    std::cout << std::endl;
    std::cout << "Total CPU time: " << end - start;
    std::cout << std::endl;

    start = std::clock();
    
    for (int i = 0; i < 100000000; i++) {
        std::pow(prime, 2);
    }

    end = std::clock();

    double GeoPerTick = 100000000 / double(end - start);

    std::cout << "Geometric operations per CPU Tick (higher is better): " << GeoPerTick;
    std::cout << std::endl;
    std::cout << "Total CPU time: " << end - start;
    std::cout << std::endl;

    start = std::clock();

    for (int i = 0; i < 1000000000; i++) {
        random();
    }

    end = std::clock();

    double RandPerTick = 1000000000 / double(end - start);

    std::cout << "Random integers generated per CPU Tick (higher is better): " << RandPerTick;
    std::cout << std::endl;
    std::cout << "Total CPU time: " << end - start;
    std::cout << std::endl;

    start = std::clock();
    
    for (int i = 0; i < 100000000; i++) {
        std::sqrt(prime);
        std::asin(prime);
        std::acos(prime);
        std::atan(prime);
        std::log(prime);
    }

    end = std::clock();

    double FuncPerTick = 100000000 / double(end - start);

    std::cout << "Square root, sine, cosine, tangent, and natural logarith operations per CPU Tick (higher is better): " << FuncPerTick;
    std::cout << std::endl;
    std::cout << "Total CPU time: " << end - start;
    std::cout << std::endl;

    return std::make_tuple(ArthPerTick, GeoPerTick, RandPerTick, FuncPerTick);
}