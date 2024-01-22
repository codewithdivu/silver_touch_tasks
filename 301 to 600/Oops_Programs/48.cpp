#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;


class UIElement {
public:
    virtual void render() const = 0;
};


class Button : public UIElement {
public:
    Button(const string& label) : label_(label) {}

    void render() const override {
        cout << "Button: " << label_ << endl;
    }

private:
    string label_;
};


class Textbox : public UIElement {
public:
    Textbox(const string& placeholder) : placeholder_(placeholder) {}

    void render() const override {
        cout << "Textbox: " << placeholder_ << endl;
    }

private:
    string placeholder_;
};


class GUIFramework {
public:
    void addUIElement(const string& id, const function<UIElement*()>& creator) {
        elementCreators_[id] = creator;
    }

    UIElement* createUIElement(const string& id) const {
        auto it = elementCreators_.find(id);
        return (it != elementCreators_.end()) ? it->second() : nullptr;
    }

private:
    unordered_map<string, function<UIElement*()>> elementCreators_;
};

int main() {
    

    GUIFramework guiFramework;

    
    guiFramework.addUIElement("Button", []() { return new Button("Click me!"); });
    guiFramework.addUIElement("Textbox", []() { return new Textbox("Enter text..."); });

    
    UIElement* button = guiFramework.createUIElement("Button");
    UIElement* textbox = guiFramework.createUIElement("Textbox");

    
    if (button) button->render();
    if (textbox) textbox->render();

    
    delete button;
    delete textbox;

    return 0;
}
