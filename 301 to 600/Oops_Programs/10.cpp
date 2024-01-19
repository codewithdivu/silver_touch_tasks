#include <iostream>
#include <map>

using namespace std;

class Context;

class AbstractExpression {
public:
    virtual void interpret(Context& context) const = 0;
};

class TerminalExpression : public AbstractExpression {
private:
    string value;

public:
    TerminalExpression(const string& val) : value(val) {}

    void interpret(Context& context) const override;
};

class NonTerminalExpression : public AbstractExpression {
private:
    AbstractExpression* expression;

public:
    NonTerminalExpression(AbstractExpression* expr) : expression(expr) {}

    void interpret(Context& context) const override;
};

class Context {
private:
    map<string, bool> variables;

public:
    void setVariable(const string& name, bool value) {
        variables[name] = value;
    }

    bool getVariable(const string& name) const {
        auto it = variables.find(name);
        if (it != variables.end()) {
            return it->second;
        }
        return false;
    }
};

void TerminalExpression::interpret(Context& context) const {
    cout << "Terminal Expression: " << value << " is " << context.getVariable(value) << endl;
}

void NonTerminalExpression::interpret(Context& context) const {
    expression->interpret(context);
}

int main() {
    Context context;
    context.setVariable("x", true);

    AbstractExpression* expression = new TerminalExpression("x");
    expression->interpret(context);

    AbstractExpression* nonTerminalExpression = new NonTerminalExpression(expression);
    nonTerminalExpression->interpret(context);

    delete expression;
    delete nonTerminalExpression;

    return 0;
}