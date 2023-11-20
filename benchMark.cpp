#include <iostream>
#include <tuple>
#include "/workspaces/CPU-benchmark-cpp/vectorMemoryTest.cpp"
#include "/workspaces/CPU-benchmark-cpp/mathTest.cpp"

int repetitions;
double vectorSum = 0;

std::tuple<double, double, double, double> mathTupleSum = std::make_tuple(0.0, 0.0, 0.0, 0.0);

int main() {
    std::cout << "How many times do you want to repeat the benchmark: ";
    std::cin >> repetitions;
    for (int i =0; i < repetitions; i++) {
        std::cout << "#############################################################################" << std::endl;
        std::cout << "Test number " << i + 1 << ": " << std::endl;
        vectorSum += vectorMemoryTest();
        std::tuple<double, double, double, double> mathTuple = mathTest();
        mathTupleSum = std::make_tuple(
            std::get<0>(mathTupleSum) + std::get<0>(mathTuple),
            std::get<1>(mathTupleSum) + std::get<1>(mathTuple),
            std::get<2>(mathTupleSum) + std::get<2>(mathTuple),
            std::get<3>(mathTupleSum) + std::get<3>(mathTuple)
        );
    }
    std::cout << "#############################################################################" << std::endl;
    std::cout << "Average Results:" << std::endl;

    std::cout << "ULL appended per CPU Tick (higher is better): " << vectorSum/repetitions << std::endl;
    std::cout << "ArithmeTic operation per CPU Tic (higher is better): " << std::get<0>(mathTupleSum)/repetitions << std::endl;
    std::cout << "Geometric operations per CPU Tick (higher is better): : " << std::get<1>(mathTupleSum)/repetitions << std::endl;
    std::cout << "Random integers generated per CPU Tic (higher is better): " << std::get<2>(mathTupleSum)/repetitions << std::endl;
    std::cout << "Square root, sine, cosine, tangent, and natural logarith operations per CPU Tic (higher is better): " << std::get<3>(mathTupleSum)/repetitions << std::endl;
}