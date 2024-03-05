#include <iostream>
#include <complex>
#include <vector>

using namespace std;

using QuantumRegister = vector<complex<double>>;

void hadamard(QuantumRegister &qreg, size_t qubit)
{
    size_t size = qreg.size();
    complex<double> inv_sqrt2 = 1.0 / sqrt(2.0);

    for (size_t i = 0; i < size; ++i)
    {
        if ((i & (1 << qubit)) == 0)
        {

            qreg[i] *= -1.0;
        }

        qreg[i] *= inv_sqrt2;
    }
}

void quantumWalkStep(QuantumRegister &qreg, size_t coinQubit, size_t positionQubit)
{
    size_t size = qreg.size();

    hadamard(qreg, coinQubit);

    QuantumRegister newQreg(size, 0.0);

    for (size_t i = 0; i < size; ++i)
    {
        size_t newPosition = i ^ (1 << positionQubit);
        newQreg[newPosition] += qreg[i];
    }

    qreg = newQreg;
}

void quantumWalk(QuantumRegister &qreg, size_t coinQubit, size_t positionQubit, size_t numSteps)
{
    for (size_t step = 0; step < numSteps; ++step)
    {
        quantumWalkStep(qreg, coinQubit, positionQubit);
    }
}

void printProbabilityDistribution(const QuantumRegister &qreg)
{
    size_t size = qreg.size();

    cout << "Probability Distribution:" << endl;
    for (size_t i = 0; i < size; ++i)
    {
        double probability = norm(qreg[i]);
        cout << "Position " << i << ": " << probability << endl;
    }
}

int main()
{

    size_t size = 8;
    QuantumRegister qreg(size, 0.0);

    qreg[0] = 1.0;

    size_t coinQubit = 0;
    size_t positionQubit = 1;
    size_t numSteps = 3;

    quantumWalk(qreg, coinQubit, positionQubit, numSteps);

    printProbabilityDistribution(qreg);

    return 0;
}
