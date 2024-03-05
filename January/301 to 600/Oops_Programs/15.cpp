#include <iostream>
using namespace std;

class Command {
public:
    virtual void execute() const = 0;
};

class Query {
public:
    virtual void execute() const = 0;
};

class CommandHandler : public Command {
public:
    void execute() const override {
        cout << "Command executed\n";
    }
};

class QueryHandler : public Query {
public:
    void execute() const override {
        cout << "Query executed\n";
    }
};

int main() {
    CommandHandler command;
    QueryHandler query;

    command.execute();
    query.execute();

    return 0;
}
