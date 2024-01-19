#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

// Simulated UI Element Base Class
class UIElement {
public:
    virtual void render() const = 0;
};

// Simulated Button Class
class Button : public UIElement {
public:
    Button(const string& label) : label_(label) {}

    void render() const override {
        cout << "Button: " << label_ << endl;
    }

private:
    string label_;
};

// Simulated Textbox Class
class Textbox : public UIElement {
public:
    Textbox(const string& placeholder) : placeholder_(placeholder) {}

    void render() const override {
        cout << "Textbox: " << placeholder_ << endl;
    }

private:
    string placeholder_;
};

// Simulated GUI Framework
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
    // Simulate GUI Framework usage

    GUIFramework guiFramework;

    // Register button and textbox creators with the framework
    guiFramework.addUIElement("Button", []() { return new Button("Click me!"); });
    guiFramework.addUIElement("Textbox", []() { return new Textbox("Enter text..."); });

    // Create UI elements using the framework
    UIElement* button = guiFramework.createUIElement("Button");
    UIElement* textbox = guiFramework.createUIElement("Textbox");

    // Render UI elements
    if (button) button->render();
    if (textbox) textbox->render();

    // Cleanup
    delete button;
    delete textbox;

    return 0;
}
