#include <iostream>
using namespace std;

class TextEditor
{
public:
    virtual string getText() const = 0;
    virtual ~TextEditor() = default;
};

class Text : public TextEditor
{
public:
    string getText() const override
    {
        return "Text";
    }
};

// decorator class

class TextEditorDecorator : public TextEditor
{
protected:
    TextEditor *text;

public:
    TextEditorDecorator(TextEditor *text) : text(text) {}

    string getText() const override
    {
        return text->getText();
    }
};

class BoldDecorator : public TextEditorDecorator
{
public:
    BoldDecorator(TextEditor *text) : TextEditorDecorator(text) {}

    string getText() const override
    {
        return text->getText() + " is Bold";
    }
};
class ItalicDecorator : public TextEditorDecorator
{
public:
    ItalicDecorator(TextEditor *text) : TextEditorDecorator(text) {}

    string getText() const override
    {
        return text->getText() + " is Italic";
    }
};

int main()
{
    TextEditor *myText = new Text();
    cout << "Text: " << myText->getText() << endl;

    TextEditor *boldText = new BoldDecorator(myText);
    cout << "Text: " << boldText->getText() << endl;

    TextEditor *ItalicText = new ItalicDecorator(myText);
    cout << "Text: " << ItalicText->getText() << endl;

    return 0;
}