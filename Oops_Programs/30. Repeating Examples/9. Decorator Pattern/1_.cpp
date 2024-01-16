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

int main()
{

    return 0;
}