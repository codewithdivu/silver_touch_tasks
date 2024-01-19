#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
using namespace std;

class TransactionalFileSystem {
public:
    TransactionalFileSystem(const string& filename)
        : filename_(filename), buffer_(), committed_(false) {}

    // Begin a new transaction
    void begin_transaction() {
        buffer_.clear();
        committed_ = false;
    }

    // Append data to the transaction buffer
    void append_to_file(const string& data) {
        buffer_.append(data);
    }

    // Commit the current transaction, writing the buffer to the file
    void commit_transaction() {
        if (committed_) {
            throw runtime_error("Cannot commit a transaction that has already been committed");
        }

        fstream file(filename_, ios_base::out | ios_base::app);
        if (!file) {
            throw runtime_error("Failed to open file for writing");
        }

        file << buffer_;
        file.close();

        committed_ = true;
    }

    // Rollback the current transaction, discarding any changes
    void rollback_transaction() {
        buffer_.clear();
        committed_ = false;
    }

private:
    string filename_;
    string buffer_;
    bool committed_;
};

int main() {
    TransactionalFileSystem tfs("46db.txt");

    tfs.begin_transaction();
    tfs.append_to_file("Hello, world!\n");
    tfs.append_to_file("This is a test.\n");
    tfs.commit_transaction();

    tfs.begin_transaction();
    tfs.append_to_file("This transaction will be rolled back.\n");
    tfs.rollback_transaction();

    return 0;
}