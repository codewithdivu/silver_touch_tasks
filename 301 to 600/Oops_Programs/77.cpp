#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Ingredient {
public:
    string name;

    Ingredient(const string& n) : name(n) {}
};

class Recipe {
public:
    string name;
    vector<Ingredient> ingredients;

    Recipe(const string& n) : name(n) {}

    void addIngredient(const Ingredient& ingredient) {
        ingredients.push_back(ingredient);
    }
};

class Cookbook {
private:
    vector<Recipe> recipes;

public:
    void addRecipe(const Recipe& recipe) {
        recipes.push_back(recipe);
        cout << "Added recipe: " << recipe.name << endl;
    }
};

int main() {
    Ingredient sugar("Sugar");
    Ingredient flour("Flour");

    Recipe cakeRecipe("Chocolate Cake");
    cakeRecipe.addIngredient(sugar);
    cakeRecipe.addIngredient(flour);

    Cookbook cookbook;
    cookbook.addRecipe(cakeRecipe);

    return 0;
}
