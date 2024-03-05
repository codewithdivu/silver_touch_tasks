#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class VendingMachine;

class VendingMachineState
{
public:
    virtual void insertCoin(VendingMachine &vendingMachine) = 0;
    virtual void ejectCoin(VendingMachine &vendingMachine) = 0;
    virtual void selectProduct(VendingMachine &vendingMachine) = 0;
    virtual void dispenseProduct(VendingMachine &vendingMachine) = 0;
    virtual ~VendingMachineState() = default;
};

class NoCoinState : public VendingMachineState
{
public:
    void insertCoin(VendingMachine &vendingMachine) override;
    void ejectCoin(VendingMachine &vendingMachine) override;
    void selectProduct(VendingMachine &vendingMachine) override;
    void dispenseProduct(VendingMachine &vendingMachine) override;
};

class HasCoinState : public VendingMachineState
{
public:
    void insertCoin(VendingMachine &vendingMachine) override;
    void ejectCoin(VendingMachine &vendingMachine) override;
    void selectProduct(VendingMachine &vendingMachine) override;
    void dispenseProduct(VendingMachine &vendingMachine) override;
};

class VendingMachine
{
private:
    VendingMachineState *currentState;

public:
    VendingMachine() : currentState(new NoCoinState()) {}

    void setState(VendingMachineState *newState)
    {
        currentState = newState;
    }

    void insertCoin()
    {
        currentState->insertCoin(*this);
    }

    void ejectCoin()
    {
        currentState->ejectCoin(*this);
    }

    void selectProduct()
    {
        currentState->selectProduct(*this);
    }

    void dispenseProduct()
    {
        currentState->dispenseProduct(*this);
    }

    ~VendingMachine()
    {
        delete currentState;
    }
};

void NoCoinState::insertCoin(VendingMachine &vendingMachine)
{
    cout << "Coin inserted." << endl;
    vendingMachine.setState(new HasCoinState());
}

void NoCoinState::ejectCoin(VendingMachine &vendingMachine)
{
    cout << "No coin to eject." << endl;
}

void NoCoinState::selectProduct(VendingMachine &vendingMachine)
{
    cout << "Please insert a coin first." << endl;
}

void NoCoinState::dispenseProduct(VendingMachine &vendingMachine)
{
    cout << "Please insert a coin first." << endl;
}

void HasCoinState::insertCoin(VendingMachine &vendingMachine)
{
    cout << "Coin already inserted." << endl;
}

void HasCoinState::ejectCoin(VendingMachine &vendingMachine)
{
    cout << "Coin ejected." << endl;
    vendingMachine.setState(new NoCoinState());
}

void HasCoinState::selectProduct(VendingMachine &vendingMachine)
{
    cout << "Product selected." << endl;
}

void HasCoinState::dispenseProduct(VendingMachine &vendingMachine)
{
    cout << "Product dispensed." << endl;
    vendingMachine.setState(new NoCoinState());
}

int main()
{
    VendingMachine vendingMachine;

    vendingMachine.selectProduct();
    vendingMachine.insertCoin();
    vendingMachine.ejectCoin();
    vendingMachine.ejectCoin();

    vendingMachine.selectProduct();

    vendingMachine.insertCoin();
    vendingMachine.selectProduct();
    vendingMachine.dispenseProduct();
    return 0;
}
