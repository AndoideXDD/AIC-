#include "layer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void layer::setupLayer(int neuronsNum){
    ThisNeuronsNum = neuronsNum;
    for (int i = 0; i < neuronsNum; i++)
    {
        neurons[i].SetupRandomNeuron();
    }
}

void layer::showWeights(int input){
    // Input define the num of the last layer where 
    for (int i = 0; i < ThisNeuronsNum; i++)
    {
        neurons[i].printWeights(input);
    }
}

void layer::out(double input[], double out[],int inputNum){
    for (int i = 0; i < ThisNeuronsNum; i++)
    {
        out[i]=neurons[i].ActivationFunctionSigmoid(neurons[i].LinearRegresion(input,inputNum));
    }
}
 
void layer::training(double* realOutput,double* inputs, int lenghInput){
    double inputExample[InputLengh];
    for (int example = 0; example < MaxDatasetExemples; example++)
    {
        for (int i = 0; i < InputLengh; i++)
        {
            
            inputExample[i]=inputs[i+example*InputLengh];
        }
        for (int neuron = 0; neuron < ThisNeuronsNum; neuron++)
        {
            neurons[neuron].TrainingOUTPUTcalculator(inputExample,lenghInput,example);
        }
    }

    for (int i = 0; i < ThisNeuronsNum; i++)
    {
        neurons[i].derivateEndLayer(ThisNeuronsNum,realOutput,lenghInput,mistakeLayer);
    }
    
    //derivateEndLayer(int MaxNumData, int maxNeuronsUsed, double* realOutput, int lenghInput , double* mistakeEndLayer)
}