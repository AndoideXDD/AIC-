#include "C:\Users\andre\UniCode\AIForC++\constants\constants.h"
#include "C:\Users\andre\UniCode\AIForC++\objects\3neurons\neurons.cpp"

// layer.h
#ifndef LAYER_h
#define LAYER_h

 

class layer {
private:
    double mistakeLayer[MaxDatasetExemples];
    neuron neurons[MaxNormalLayerNeurons];
    double* inputExample = new double[MaxDatasetExemples*MaxNormalLayerNeurons*InputLengh];
    double* outExample = new double[MaxDatasetExemples*MaxNormalLayerNeurons*InputLengh];
    int ThisNeuronsNum;
public:
    void setupLayer(int neuronsNum);
    void showWeights(int input);
    void out(double input[], double out[], int inputNum);
    void outTrain(double input[], double out[],int inputNum,int example);
    void trainingEndLayer(double* inputs, int lenghInput);
    void trainingLayer(double* mistake, int lenghInput);
    void mistakeCalculations(double* Output,double* inputs,int lenghInput,double* mistakeLastLayer);
    void mistajeCopy(double* arrayToPutInfo);
    //void layerCostFunction(double activationFD[][EndLayerNeurons], double precision, double* mistakeBackLayer);
};

#endif // LAYER_h