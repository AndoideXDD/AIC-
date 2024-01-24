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

void layer::out(float input[], float out[],int inputNum){
    for (int i = 0; i < ThisNeuronsNum; i++)
    {
        out[i]=neurons[i].LinearRegresion(input,inputNum);
    }
}
 