#include <iostream>
using namespace std;

class Document
{
public:
    virtual void print() const = 0;
    virtual ~Document() = default;
};

class PDFDocument : public Document
{
public:
    void print() const override
    {
        cout << "Printing a PDF Document\n";
    }
};

class WordDocument : public Document
{
public:
    void print() const override
    {
        cout << "Printing a Word Document\n";
    }
};

class DocumentFactory
{
public:
    virtual Document *createDocument() const = 0;
    virtual ~DocumentFactory() = default;
};

class PDFDocumentFactory : public DocumentFactory
{
public:
    Document *createDocument() const override
    {
        return new PDFDocument();
    }
};

class WordDocumentFactory : public DocumentFactory
{
public:
    Document *createDocument() const override
    {
        return new WordDocument();
    }
};

int main()
{
    DocumentFactory *pdfFactory = new PDFDocumentFactory();
    Document *pdfDocument = pdfFactory->createDocument();
    pdfDocument->print();

    DocumentFactory *wordFactory = new WordDocumentFactory();
    Document *wordDocument = wordFactory->createDocument();
    wordDocument->print();

    return 0;
}
