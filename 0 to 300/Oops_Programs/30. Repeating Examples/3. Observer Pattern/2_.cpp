#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Observer
{
public:
    virtual void update(const string &stockSymbol, double stockPrice) = 0;
    virtual ~Observer() {}
};

class Subject
{
public:
    virtual void registerObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() {}
};

class Trader : public Observer
{
private:
    string name;

public:
    Trader(const string &name) : name(name) {}

    void update(const string &stockSymbol, double stockPrice) override
    {
        cout << "Trader " << name << " received update for " << stockSymbol << ": $" << stockPrice << endl;
    }
};

class StockMarket : public Subject
{
private:
    vector<Observer *> observers;
    string stockSymbol;
    double stockPrice;

public:
    StockMarket(const string &stockSymbol, double initialPrice)
        : stockSymbol(stockSymbol), stockPrice(initialPrice) {}

    void registerObserver(Observer *observer) override
    {
        observers.push_back(observer);
    }

    void removeObserver(Observer *observer) override
    {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() override
    {
        for (Observer *observer : observers)
        {
            observer->update(stockSymbol, stockPrice);
        }
    }

    void setStockPrice(double newPrice)
    {
        if (newPrice != stockPrice)
        {
            stockPrice = newPrice;
            notifyObservers();
        }
    }
};

int main()
{
    StockMarket stockMarket("Nifty", 150.0);
    Trader trader1("Divyesh");
    Trader trader2("Parikshit");

    stockMarket.registerObserver(&trader1);
    stockMarket.registerObserver(&trader2);

    stockMarket.setStockPrice(155.0);

    stockMarket.removeObserver(&trader1);

    stockMarket.setStockPrice(160.0);

    return 0;
}
