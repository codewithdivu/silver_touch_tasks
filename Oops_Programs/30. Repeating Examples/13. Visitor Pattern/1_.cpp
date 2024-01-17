#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Paragraph;
class Image;

class Visitor
{
public:
    virtual void visit(Paragraph &paragraph) = 0;
    virtual void visit(Image &image) = 0;
    virtual ~Visitor() = default;
};

class DocumentElement
{
public:
    virtual void accept(Visitor &visitor) = 0;
    virtual ~DocumentElement() = default;
};

class Paragraph : public DocumentElement
{
public:
    void accept(Visitor &visitor) override
    {
        visitor.visit(*this);
    }
};

class Image : public DocumentElement
{
public:
    void accept(Visitor &visitor) override
    {
        visitor.visit(*this);
    }
};

class OperationVisitor : public Visitor
{
public:
    void visit(Paragraph &paragraph) override
    {
        cout << "Performing operation on Paragraph\n";
    }

    void visit(Image &image) override
    {
        cout << "Performing operation on Image\n";
    }
};

class Document
{
private:
    vector<DocumentElement *> elements;

public:
    void addElement(DocumentElement *element)
    {
        elements.push_back(element);
    }

    void accept(Visitor &visitor)
    {
        for (auto &element : elements)
        {
            element->accept(visitor);
        }
    }

    ~Document()
    {
        for (auto &element : elements)
        {
            delete element;
        }
    }
};

int main()
{

    return 0;
}
