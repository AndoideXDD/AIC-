#include <iostream>
#include <chrono>
using namespace std;
// Use the function by puting  --- > timefunction(FunctionName);
// Theres no need to decleare its type 
template <typename functionTipe>
void timeExecution(functionTipe (*func)()) {
    auto start_time = std::chrono::high_resolution_clock::now();
    func(); // Corrected: You need to call the function by using func();
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    std::cout << "\n\nTiempo de ejecucion: " << duration.count() << " nanoseconds\n";
}