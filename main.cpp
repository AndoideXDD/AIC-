#include <iostream>
#include <chrono>
using namespace std;
#include "functions/timeFunction.h"
//#include "C:\Users\andre\Desktop\UniCode\AIForC++\objects\3neurons\neurons.cpp"
#include "C:\Users\andre\Desktop\UniCode\AIForC++\objects\2layers\layers.cpp"
int main() {
    // Code example of using a neuron
    /*neuron firstNeuron;
    firstNeuron.SetupRandomNeuron();
    firstNeuron.printWeights(2);*/
    // -------------------------------------------------------------------------
    // Code example of using multiple layers
    /*
    double input[] = {1,2};
    double out[2];
    layer firstlayer[layerNum];
    firstlayer[0].setupLayer(2);
    firstlayer[0].out(input,out,2);
    firstlayer[1].setupLayer(2);
    firstlayer[1].out(out,input,2);
    for (int i = 0; i < 2; i++){cout << "\n" <<input[i];}*/
    // -------------------------------------------------------------------------
    // Here I put the code example for train a model 
    //Due that the lengh of the inputs is one, each number represents an example for the model
    double input[] = {1,2,4,2,1};
    double neweInput[]={3};
    double outsss[2];
    double realOut[]={1,1,1,1,1};
    double mistakeEndLayer[2];
    double out;
    layer firstlayer[layerNum];
    firstlayer[0].setupLayer(1);
    firstlayer[0].out(input,outsss,1);

    double lasOut=0;
    for (int i = 0; i < 10000; i++)
    {
        firstlayer[0].training(realOut,input,1,mistakeEndLayer);
        firstlayer[0].out(input,outsss,5);
        firstlayer[0].showWeights(5);
        cout << outsss [0];
    }
    firstlayer[0].out(neweInput,outsss,1);
    cout << outsss [0];

    

}