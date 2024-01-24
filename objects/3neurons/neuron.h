#include "C:\Users\andre\Desktop\UniCode\AIForC++\constants\constants.h"
// neuron.h
#ifndef NEURON_h
#define NEURON_h

struct inputData {float lastInputs[MaxDatasetExemples][InputLengh];};

class neuron {
private:
    float* weights = new float[NumMaxNeuronWeight];
    float* outPut = new float[MaxDatasetExemples];
    float variableNumber = 0;
    inputData Input;
public:
    void SetupRandomNeuron();  // Constructor
    void printWeights(int maxWeughtUsed);
    float LinearRegresion(float* inputs, int lenghInput);
    float TrainingLinearRegresion();
    //float regresionOperation(float* inputs, int lenghInput, float maxPosibleOut, int exempleNum);
    /*float regresionOperation(float* inputs, int lenghInput, float maxPosibleOut, int exempleNum);
    float ACTHyperbolicTangent(float* inputs, int lenghInput, int exempleNum);
    void derivateCostFunctionEndlayer(float* activationFD, float precision, float* mistakeBackLayer);
    float derivateCostFunctionNormalLayer(float* mistakeBackLayer, float precision);
    float derivateCostFunctionFirstLayer(float* mistakeBackLayer, float precision, float* input);*/
};

#endif // NEURON_h