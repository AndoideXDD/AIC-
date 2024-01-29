#include "C:\Users\andre\UniCode\AIForC++\constants\constants.h"
// neuron.h
#ifndef NEURON_h
#define NEURON_h


class neuron {
private:
    double* weights = new double[NumMaxNeuronWeight];
    double* input = new double[NumMaxNeuronWeight*MaxDatasetExemples];
    double* outPut = new double[MaxDatasetExemples];
    double variableNumber = 0;
public:
    void SetupRandomNeuron();  // Constructor
    void printWeights(int maxWeughtUsed);
    double LinearRegresion(double* inputs, int lenghInput);
    double ActivationFunctionSigmoid(double input);
    double TrainingOUTPUTcalculator(double* inputs ,int lenghInput,int numData);
    void derivateEndLayer(int maxWeught,double* realOutput, int lenghInput, double* mistakeEndLayer);
    void derivateNormalLayer();
    //double regresionOperation(double* inputs, int lenghInput, double maxPosibleOut, int exempleNum);
    /*double regresionOperation(double* inputs, int lenghInput, double maxPosibleOut, int exempleNum);
    double ACTHyperbolicTangent(double* inputs, int lenghInput, int exempleNum);
    void derivateCostFunctionEndlayer(double* activationFD, double precision, double* mistakeBackLayer);
    double derivateCostFunctionNormalLayer(double* mistakeBackLayer, double precision);
    double derivateCostFunctionFirstLayer(double* mistakeBackLayer, double precision, double* input);*/
};

#endif // NEURON_h