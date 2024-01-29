#include <iostream>
#include <chrono>
using namespace std;
//#include "C:/Users/andre/Desktop/UniCode/AIForC++/objects/3neurons/neurons.cpp"
#include "C:\Users\andre\UniCode\AIForC++\objects\2layers\layers.cpp"
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
    double input[] = { 1,2,4,2,1 };
    double neweInput[] = { 3.5 };
    double outsss[2];
    double realOut[] = { 1,1,1,1,1 };
    layer firstlayer[layerNum];
    firstlayer[0].setupLayer(1);
    double lasOut = 0;
    for (int i = 0; i < 1000; i++)
    {
        firstlayer[0].training(realOut, input, 1);
    }
    // For show how ends the model after training
    firstlayer[0].showWeights(1);
    firstlayer[0].out(neweInput, outsss, 1);
    cout << outsss[0];



}