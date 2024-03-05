#include <iostream>
#include <vector>
#include <functional>
#include <string>

using namespace std;

class TestCase {
private:
    string name;
    function<void()> testFunction;
    mutable bool isSuccess;  

public:
    TestCase(const string& name, const function<void()>& testFunction)
        : name(name), testFunction(testFunction), isSuccess(false) {}

    void run() const {
        try {
            testFunction();
            isSuccess = true;
        } catch (const exception& e) {
            cerr << "Test Case Failed: " << name << "\n  Exception: " << e.what() << endl;
            isSuccess = false;
        }
    }

    bool getResult() const {
        return isSuccess;
    }
};

class TestSuite {
private:
    vector<TestCase> testCases;

public:
    void addTestCase(const string& name, const function<void()>& testFunction) {
        testCases.emplace_back(name, testFunction);
    }

    void run() const {
        for (const auto& testCase : testCases) {
            testCase.run();
        }
    }

    void printResults() const {
        cout << "\nTest Results:\n----------------\n";
        for (const auto& testCase : testCases) {
            cout << "Test Case: " << testCase.getResult() << " - "
                 << (testCase.getResult() ? "Passed" : "Failed") << endl;
        }
        cout << "----------------\n";
    }
};

class TestRunner {
public:
    static void runTests(const TestSuite& testSuite) {
        testSuite.run();
        testSuite.printResults();
    }
};


void testAddition() {
    TestCase testCase("Test Addition", []() {
        int result = 1 + 1;
        if (result != 2) {
            throw runtime_error("Addition failed!");
        }
    });

    testCase.run();
}

void testSubtraction() {
    TestCase testCase("Test Subtraction", []() {
        int result = 3 - 1;
        if (result != 2) {
            throw runtime_error("Subtraction failed!");
        }
    });

    testCase.run();
}

void testMultiplication() {
    TestCase testCase("Test Multiplication", []() {
        int result = 2 * 3;
        if (result != 6) {
            throw runtime_error("Multiplication failed!");
        }
    });

    testCase.run();
}

int main() {
    TestSuite testSuite;
    testSuite.addTestCase("Addition", testAddition);
    testSuite.addTestCase("Subtraction", testSubtraction);
    testSuite.addTestCase("Multiplication", testMultiplication);

    TestRunner::runTests(testSuite);

    return 0;
}
