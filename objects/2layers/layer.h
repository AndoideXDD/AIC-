#include "C:\Users\andre\Desktop\UniCode\AIForC++\constants\constants.h"
#include "C:\Users\andre\Desktop\UniCode\AIForC++\objects\3neurons\neurons.cpp"

// layer.h
#ifndef LAYER_h
#define LAYER_h

 

class layer {
private:
    neuron neurons[MaxNormalLayerNeurons];
    int ThisNeuronsNum;
public:
    void setupLayer(int neuronsNum);
    void showWeights(int input);
    void out(float input[], float out[], int inputNum);
    //void layerCostFunction(float activationFD[][EndLayerNeurons], float precision, float* mistakeBackLayer);
};

#endif // LAYER_h