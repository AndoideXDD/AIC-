#include <iostream>
#include <chrono>
#include<windows.h> 
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
    // Here is the data for the model
    double input[] = { 1,2,4,2,1 };
    double realOut[] = { 1,1,1,1,1 };
    // we create the layers
    layer firstlayer[layerNum];
    firstlayer[0].setupLayer(MaxNormalLayerNeurons);
    firstlayer[1].setupLayer(MaxNormalLayerNeurons);
    firstlayer[2].setupLayer(EndLayerNeurons);
    // and create variables for a training
    // In case end layer have more neurons, put the number of neurons of the end layer
    double* output = new double[MaxNormalLayerNeurons];
    double* mistake = new double[MaxDatasetExemples];
    for (int i = 0; i < 1000; i++)
    {
        double inputExample[InputLengh];
        for (int example = 0; example < MaxDatasetExemples; example++)
        {
            for (int i = 0; i < InputLengh; i++){inputExample[i]=input[i+example*InputLengh];}
            // At the 3 argument put the num of neurons from the past layer
            firstlayer[0].outTrain(inputExample,output,InputLengh,example);
            firstlayer[1].outTrain(output,output,MaxNormalLayerNeurons,example);
            firstlayer[2].outTrain(output,output,MaxNormalLayerNeurons,example);
            for (int i = 0; i < EndLayerNeurons; i++)
            {
                mistake[i+example*EndLayerNeurons]=(output[i]-realOut[i+example*EndLayerNeurons])*output[i]*(1-output[i]);
            }
            // The second argument must be the size of the layer before the end one
            firstlayer[2].trainingEndLayer(mistake,MaxNormalLayerNeurons);
        }

        
    }
    // For show how ends the model after training
    firstlayer[0].showWeights(1);
    firstlayer[1].showWeights(2);
    firstlayer[2].showWeights(2);
    double outsss[2];
    double neweInput[] = { 3.5 };
    firstlayer[0].out(neweInput,output,InputLengh);
    firstlayer[1].out(output,output,2);
    firstlayer[2].out(output,outsss,2);
    cout << outsss[0];
}