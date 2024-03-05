#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stock {
public:
    string symbol;
    double price;

    Stock(const string& s, double p) : symbol(s), price(p) {}
};

class Transaction {
public:
    Stock stock;
    int quantity;
    bool isBuy;

    Transaction(const Stock& s, int q, bool buy) : stock(s), quantity(q), isBuy(buy) {}
};

class Portfolio {
private:
    vector<Transaction> transactions;

public:
    void executeTransaction(const Transaction& transaction) {
        transactions.push_back(transaction);
        cout << "Transaction executed: " << (transaction.isBuy ? "Buy" : "Sell") << " " << transaction.quantity << " shares of " << transaction.stock.symbol << endl;
    }

    double calculatePortfolioValue() const {
        double portfolioValue = 0.0;

        for (const auto& transaction : transactions) {
            portfolioValue += (transaction.isBuy ? 1 : -1) * transaction.quantity * transaction.stock.price;
        }

        return portfolioValue;
    }
};

int main() {
    Stock appleStock("AAPL", 150.0);
    Stock googleStock("GOOGL", 2500.0);

    Portfolio portfolio;

    Transaction buyApple(appleStock, 10, true);
    Transaction sellGoogle(googleStock, 5, false);

    portfolio.executeTransaction(buyApple);
    portfolio.executeTransaction(sellGoogle);

    double portfolioValue = portfolio.calculatePortfolioValue();
    cout << "Portfolio Value: $" << portfolioValue << endl;

    return 0;
}
