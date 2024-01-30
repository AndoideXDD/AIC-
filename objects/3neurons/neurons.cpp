#include "neuron.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

void neuron::SetupRandomNeuron(){
    std::srand(std::time(0));
    int randomInteger;
    double randomDouble;
    for (int i = 0; i < NumMaxNeuronWeight; i++)
    {
        randomInteger = std::rand();
        // Random number between 0 and 1
        randomDouble = static_cast<double>(randomInteger) / RAND_MAX;
        this->weights[i]=randomDouble;
    }
    randomDouble = static_cast<double>(randomInteger) / RAND_MAX;
    variableNumber = randomDouble;
}

void neuron::printWeights(int maxWeughtUsed){
    std::cout << "\n{" << weights[0];
    for (int i = 1; i < maxWeughtUsed; i++)
    {
        std::cout << "," << weights[i];
    }
    std::cout << ",The independent value:" << variableNumber ;
    std::cout << "}";
    
}

double neuron::LinearRegresion(double* inputs, int lenghInput){
    double result=0;
    for (int i = 0; i < lenghInput; i++)
    {   
         
        result=this->weights[i]*inputs[i]+result;
    }
    return (result+this->variableNumber);
}

double neuron::ActivationFunctionSigmoid(double input){
    double result;
    if (input >= acrtivationFunctionLimit) result = 1.;
    else if (input <= -acrtivationFunctionLimit) result = 0.;
    else result = 1. / (1. + exp(-input));
    
    return result;
}

// numData must start at 0
double neuron::TrainingOUTPUTcalculator(double* inputs ,int lenghInput, int numData){
    double result=0;
    for (int i = 0; i < lenghInput; i++)
    {   
        input[i+numData*lenghInput] = inputs[i];
        result=weights[i]*inputs[i]+result;
    }
    result+=variableNumber;
    if (result >= acrtivationFunctionLimit) result = 1.;
    else if (result <= -acrtivationFunctionLimit) result = 0.;
    else result = 1. / (1. + exp(-result));
    outPut[numData] = result;
    return result;
}
// Put the MaxNumData
void neuron::derivateEndLayer( int maxWeught  , double* mistakeEndLayer,double* inputExample){
    double* derivateValue = new double[maxWeught+1]; 
    double independentMistake=0;
    for (int i = 0; i < maxWeught; i++){derivateValue [i] = 0;}
    for (int numData = 0; numData < MaxDatasetExemples; numData++)
    {
        for (int i = 0; i < maxWeught; i++)
        {
            derivateValue[i]= precisionnnnnnn *mistakeEndLayer[numData]*inputExample[i+numData*maxWeught]+derivateValue[i];
        }
        independentMistake = precisionnnnnnn *mistakeEndLayer[numData]+ independentMistake;
    }
    for (int i = 0; i < maxWeught; i++){
        derivateValue[i] = derivateValue [i]/MaxDatasetExemples;
        weights[i]= weights[i]-derivateValue[i];
    }
    variableNumber = variableNumber - independentMistake/MaxDatasetExemples;
    // Free the space of the variable 
    delete[] derivateValue;
}


void neuron::derivateNormalLayer( int maxWeught  , double* mistakeLastLayer,double* inputExample,double* outExample){
    double* derivateValue = new double[maxWeught+1]; 
    double independentMistake=0;
    double sumWeights=0;
    for (int i = 0; i < maxWeught; i++){derivateValue [i] = 0;}
    for (int numData = 0; numData < MaxDatasetExemples; numData++)
    {
        for (int i = 0; i < maxWeught; i++)
        {
            derivateValue[i]= precisionnnnnnn *mistakeLastLayer[numData]*weights[i]*inputExample[i+numData*maxWeught]*(outExample[numData]*(1-outExample[numData]))+derivateValue[i];
            sumWeights+=weights[i];
        }
        // The independent value will be calculeted by multipling the sum of all weights
        independentMistake = precisionnnnnnn *mistakeLastLayer[numData]*sumWeights*(outExample[numData]*(1-outExample[numData]))+ independentMistake;
        mistakeLastLayer[numData]= mistakeLastLayer[numData]*sumWeights*(outExample[numData]*(1-outExample[numData]));
        sumWeights=0;
    }
    for (int i = 0; i < maxWeught; i++){
        derivateValue[i] = derivateValue [i]/MaxDatasetExemples;
        weights[i]= weights[i]-derivateValue[i];
    }
    variableNumber = variableNumber - independentMistake/MaxDatasetExemples;
    // Free the space of the variable 
    delete[] derivateValue;
}