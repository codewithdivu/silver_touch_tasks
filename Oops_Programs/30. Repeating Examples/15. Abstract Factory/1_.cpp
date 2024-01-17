#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Button
{
public:
    virtual void render() const = 0;
    virtual ~Button() = default;
};

class DesktopButton : public Button
{
public:
    void render() const override
    {
        cout << "Rendering Desktop Button\n";
    }
};

class MobileButton : public Button
{
public:
    void render() const override
    {
        cout << "Rendering Mobile Button\n";
    }
};

class Checkbox
{
public:
    virtual void render() const = 0;
    virtual ~Checkbox() = default;
};

class DesktopCheckbox : public Checkbox
{
public:
    void render() const override
    {
        cout << "Rendering Desktop Checkbox\n";
    }
};

class MobileCheckbox : public Checkbox
{
public:
    void render() const override
    {
        cout << "Rendering Mobile Checkbox\n";
    }
};

class UIComponentFactory
{
public:
    virtual Button *createButton() = 0;
    virtual Checkbox *createCheckbox() = 0;
    virtual ~UIComponentFactory() = default;
};

class DesktopUIComponentFactory : public UIComponentFactory
{
public:
    Button *createButton() override
    {
        return new DesktopButton();
    }

    Checkbox *createCheckbox() override
    {
        return new DesktopCheckbox();
    }
};

class MobileUIComponentFactory : public UIComponentFactory
{
public:
    Button *createButton() override
    {
        return new MobileButton();
    }

    Checkbox *createCheckbox() override
    {
        return new MobileCheckbox();
    }
};

int main()
{

    return 0;
}
