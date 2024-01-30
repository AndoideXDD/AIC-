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

void layer::outTrain(double input[], double out[],int inputNum,int example){
    for (int i = 0; i < ThisNeuronsNum; i++)
    {
        for (int j = 0; j < inputNum; j++)
        {
            inputExample[j+example*inputNum]=input[j];
        }
        out[i]=neurons[i].ActivationFunctionSigmoid(neurons[i].LinearRegresion(input,inputNum));
        outExample[example]=out[i];
    }
}
 

void layer::trainingEndLayer(double* mistake, int lenghInput){
    for (int i = 0; i < ThisNeuronsNum; i++)
    {
        neurons[i].derivateEndLayer(lenghInput,mistake,inputExample);
    }
    
    //derivateEndLayer(int MaxNumData, int maxNeuronsUsed, double* realOutput, int lenghInput , double* mistakeEndLayer)
}

void layer::trainingLayer(double* mistake, int lenghInput){
    
    for (int i = 0; i < ThisNeuronsNum; i++)
    {
        neurons[i].derivateNormalLayer(lenghInput,mistake,inputExample,outExample);
    }
}