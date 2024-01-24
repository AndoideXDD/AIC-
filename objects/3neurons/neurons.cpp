#include "neuron.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void neuron::SetupRandomNeuron(){
    std::srand(std::time(0));
    int randomInteger;
    float randomDouble;
    for (int i = 0; i < NumMaxNeuronWeight; i++)
    {
        randomInteger = std::rand();
        // Random number between 0 and 1
        randomDouble = static_cast<float>(randomInteger) / RAND_MAX;
        this->weights[i]=randomDouble;
    }
    randomDouble = static_cast<float>(randomInteger) / RAND_MAX;
    variableNumber = randomDouble;
}

void neuron::printWeights(int maxWeughtUsed){
    std::cout << "\n{" << weights[0];
    for (int i = 1; i < maxWeughtUsed; i++)
    {
        std::cout << "," << weights[i];
    }
    std::cout << "}";
}

float neuron::LinearRegresion(float* inputs, int lenghInput){
    float result=0;
    for (int i = 0; i < lenghInput; i++)
    {   
        result=this->weights[i]*inputs[i]+result;
    }
    return (result+this->variableNumber);
}
//float regresionOperation(float* inputs, int lenghInput, float maxPosibleOut, int exempleNum);
float neuron::TrainingLinearRegresion(){
    
}
 