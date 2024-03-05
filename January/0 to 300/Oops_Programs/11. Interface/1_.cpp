#include <iostream>

class Drawable
{
public:
    virtual void draw() const = 0;
    virtual ~Drawable() = default;
};

int main()
{

    return 0;
}
