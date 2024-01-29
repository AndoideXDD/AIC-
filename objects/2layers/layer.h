#include "C:\Users\andre\UniCode\AIForC++\constants\constants.h"
#include "C:\Users\andre\UniCode\AIForC++\objects\3neurons\neurons.cpp"

// layer.h
#ifndef LAYER_h
#define LAYER_h

 

class layer {
private:
    double mistakeLayer[MaxDatasetExemples];
    neuron neurons[MaxNormalLayerNeurons];
    int ThisNeuronsNum;
public:
    void setupLayer(int neuronsNum);
    void showWeights(int input);
    void out(double input[], double out[], int inputNum);
    void training(double* realOutput,double* inputs, int lenghInput);
    //void layerCostFunction(double activationFD[][EndLayerNeurons], double precision, double* mistakeBackLayer);
};

#endif // LAYER_h