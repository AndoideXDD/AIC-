#include <iostream>
#include <chrono>
using namespace std;
#include "functions/timeFunction.h"
#include "C:\Users\andre\Desktop\UniCode\AIForC++\objects\3neurons\neurons.cpp"
 

int main() {
     
    neuron firstNeuron;
    firstNeuron.SetupRandomNeuron();
    firstNeuron.printWeights(2);
}