#include <iostream>
#include <chrono>
using namespace std;
#include "functions/timeFunction.h"
//#include "C:\Users\andre\Desktop\UniCode\AIForC++\objects\3neurons\neurons.cpp"
#include "C:\Users\andre\Desktop\UniCode\AIForC++\objects\2layers\layers.cpp"
int main() {
    /*neuron firstNeuron;
    firstNeuron.SetupRandomNeuron();
    firstNeuron.printWeights(2);*/
    layer firstlayer[2];
    firstlayer[0].setupLayer(2);
    firstlayer[0].showWeights(2);
    float input[] = {1,2};
    float out[2];
    firstlayer[0].out(input,out,2);
    for (int i = 0; i < 2; i++)
    {
        cout << "\n" <<out[i];
    }
    firstlayer[1].setupLayer(2);
    firstlayer[1].showWeights(2);
    firstlayer[1].out(out,input,2);
    for (int i = 0; i < 2; i++)
    {
        cout << "\n" <<input[i];
    }
    
}