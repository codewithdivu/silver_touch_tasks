#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <thread>
using namespace std;

class ParallelAlgorithmSimulator {
public:
    ParallelAlgorithmSimulator(const vector<int>& data) : data_(data) {}

    void runParallelAlgorithm() {
        
        auto middle = data_.begin() + data_.size() / 2;
        vector<int> firstHalf(data_.begin(), middle);
        vector<int> secondHalf(middle, data_.end());

        
        thread thread1([this, &firstHalf]() {
            processHalf(firstHalf);
        });

        thread thread2([this, &secondHalf]() {
            processHalf(secondHalf);
        });

        
        thread1.join();
        thread2.join();

        
        result_ = result1_ + result2_;
    }

    int getResult() const {
        return result_;
    }

private:
    void processHalf(const vector<int>& half) {
        
        int result = accumulate(half.begin(), half.end(), 0);

        
        if (half == data_) {
            result1_ = result;
        } else {
            result2_ = result;
        }
    }

    vector<int> data_;
    int result1_;
    int result2_;
    int result_;
};

int main() {
    
    vector<int> dataset(1000000, 1);

    
    ParallelAlgorithmSimulator simulator(dataset);
    simulator.runParallelAlgorithm();

    
    cout << "Result: " << simulator.getResult() << endl;

    return 0;
}
