#include <iostream>
#include <vector>
#include <complex>
#include <cmath> 
#include <ctime> 
using namespace std;

using Complex = complex<double>;

// Representation of a qubit
class Qubit {
public:
    Complex state0; // |0⟩ state
    Complex state1; // |1⟩ state

    Qubit() : state0(1.0, 0.0), state1(0.0, 0.0) {}

    // Apply Hadamard gate
    void applyHadamard() {
        Complex newState0 = (state0 + state1) / sqrt(2.0);
        Complex newState1 = (state0 - state1) / sqrt(2.0);
        state0 = newState0;
        state1 = newState1;
    }

    // Apply X (NOT) gate
    void applyXGate() {
        swap(state0, state1);
    }

    // Measure the qubit (simulate collapse of superposition)
    int measure() {
        double prob0 = norm(state0);
        double prob1 = norm(state1);

        // Simulate probabilistic outcome
        double randNum = static_cast<double>(rand()) / RAND_MAX;
        if (randNum < prob0) {
            state0 = 1.0;
            state1 = 0.0;
            return 0; // Measurement result: |0⟩
        } else {
            state0 = 0.0;
            state1 = 1.0;
            return 1; // Measurement result: |1⟩
        }
    }
};

// Quantum circuit
class QuantumCircuit {
public:
    vector<Qubit> qubits;

    QuantumCircuit(int numQubits) : qubits(numQubits) {}

    // Apply Hadamard gate to all qubits
    void applyHadamardGate() {
        for (auto& qubit : qubits) {
            qubit.applyHadamard();
        }
    }

    // Apply X (NOT) gate to the first qubit
    void applyXGate() {
        if (!qubits.empty()) {
            qubits[0].applyXGate();
        }
    }

    // Measure all qubits
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

    // Create a quantum circuit with 3 qubits
    QuantumCircuit quantumCircuit(3);

    // Apply Hadamard gate to all qubits
    quantumCircuit.applyHadamardGate();

    // Apply X (NOT) gate to the first qubit
    quantumCircuit.applyXGate();

    // Measure all qubits
    vector<int> measurementResults = quantumCircuit.measureAll();

    // Display measurement results
    cout << "Measurement Results: ";
    for (int result : measurementResults) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
