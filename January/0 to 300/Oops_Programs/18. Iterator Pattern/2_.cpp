#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Iterator
{
public:
    virtual int next() = 0;
    virtual bool hasNext() = 0;
    virtual ~Iterator() {}
};

class ConcreteIterator : public Iterator
{
private:
    vector<int> data;
    size_t position;

public:
    ConcreteIterator(const vector<int> &collection) : data(collection), position(0) {}

    int next() override
    {
        if (hasNext())
        {
            return data[position++];
        }
        else
        {
            throw out_of_range("No more elements");
        }
    }

    bool hasNext() override
    {
        return position < data.size();
    }
};

class Aggregate
{
public:
    virtual Iterator *createIterator() = 0;
    virtual void addElement(int element) = 0;
    virtual ~Aggregate() {}
};

class ConcreteAggregate : public Aggregate
{
private:
    vector<int> elements;

public:
    Iterator *createIterator() override
    {
        return new ConcreteIterator(elements);
    }

    void addElement(int element) override
    {
        elements.push_back(element);
    }
};

int main()
{
    ConcreteAggregate collection;
    collection.addElement(1);
    collection.addElement(2);
    collection.addElement(3);

    Iterator *iterator = collection.createIterator();

    while (iterator->hasNext())
    {
        cout << iterator->next() << " ";
    }

    delete iterator;
    return 0;
}
