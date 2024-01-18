#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
using namespace std;

const int MEMORY_SIZE = 4; 

void burstsort(ifstream& inputFile, ofstream& outputFile) {
    vector<int> buffer;
    buffer.reserve(MEMORY_SIZE);

    while (!inputFile.eof()) {
        
        buffer.clear();
        buffer.insert(buffer.begin(), istream_iterator<int>(inputFile), istream_iterator<int>());
        sort(buffer.begin(), buffer.end());

      
        ofstream tempFile("tempfile.txt");
        copy(buffer.begin(), buffer.end(), ostream_iterator<int>(tempFile, " "));
        tempFile.close();

      
        ifstream tempInputFile("tempfile.txt");
        merge(
            istream_iterator<int>(tempInputFile),
            istream_iterator<int>(),
            istream_iterator<int>(outputFile),
            istream_iterator<int>(),
            ostream_iterator<int>(outputFile, " ")
        );

        tempInputFile.close();
    }
}

int main() {

    ofstream inputFile("input.txt");
    for (int i = 0; i < 20; ++i) {
        inputFile << rand() % 100 << " ";
    }
    inputFile.close();

   
    ifstream input("input.txt");
    ofstream output("output.txt");
    burstsort(input, output);

    cout << "Burstsort completed. Check 'output.txt' for the sorted data.\n";

    return 0;
}
