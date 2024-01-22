#include <iostream>
#include <vector>
#include <complex>
#include <cmath> 
#include <ctime> 
using namespace std;

using Complex = complex<double>;


class Qubit {
public:
    Complex state0; 
    Complex state1; 

    Qubit() : state0(1.0, 0.0), state1(0.0, 0.0) {}

    
    void applyHadamard() {
        Complex newState0 = (state0 + state1) / sqrt(2.0);
        Complex newState1 = (state0 - state1) / sqrt(2.0);
        state0 = newState0;
        state1 = newState1;
    }

    
    void applyXGate() {
        swap(state0, state1);
    }

    
    int measure() {
        double prob0 = norm(state0);
        double prob1 = norm(state1);

        
        double randNum = static_cast<double>(rand()) / RAND_MAX;
        if (randNum < prob0) {
            state0 = 1.0;
            state1 = 0.0;
            return 0; 
        } else {
            state0 = 0.0;
            state1 = 1.0;
            return 1; 
        }
    }
};


class QuantumCircuit {
public:
    vector<Qubit> qubits;

    QuantumCircuit(int numQubits) : qubits(numQubits) {}

    
    void applyHadamardGate() {
        for (auto& qubit : qubits) {
            qubit.applyHadamard();
        }
    }

    
    void applyXGate() {
        if (!qubits.empty()) {
            qubits[0].applyXGate();
        }
    }

    
    vector<int> measureAll() {
        vector<int> results;
        for (auto& qubit : qubits) {
            results.push_back(qubit.measure());
        }
        return results;
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    
    QuantumCircuit quantumCircuit(3);

    
    quantumCircuit.applyHadamardGate();

    
    quantumCircuit.applyXGate();

    
    vector<int> measurementResults = quantumCircuit.measureAll();

    
    cout << "Measurement Results: ";
    for (int result : measurementResults) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
