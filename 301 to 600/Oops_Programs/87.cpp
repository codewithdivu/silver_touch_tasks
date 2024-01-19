#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Ingredient {
public:
    string name;

    Ingredient(const string& ingredientName) : name(ingredientName) {}

    // Define equality operator for Ingredient
    bool operator==(const Ingredient& other) const {
        return name == other.name;
    }
};

class Recipe {
public:
    string name;
    vector<Ingredient> ingredients;

    Recipe(const string& recipeName, const vector<Ingredient>& recipeIngredients)
        : name(recipeName), ingredients(recipeIngredients) {}

    bool containsIngredient(const Ingredient& ingredient) const {
        return find(ingredients.begin(), ingredients.end(), ingredient) != ingredients.end();
    }
};

class User {
public:
    string name;
    vector<Ingredient> dietaryRestrictions;
    vector<Recipe> favoriteRecipes;

    User(const string& userName) : name(userName) {}

    void addDietaryRestriction(const Ingredient& restriction) {
        dietaryRestrictions.push_back(restriction);
    }

    void addFavoriteRecipe(const Recipe& recipe) {
        favoriteRecipes.push_back(recipe);
    }

    vector<Recipe> recommendRecipes(const vector<Recipe>& allRecipes) const {
        vector<Recipe> recommendedRecipes;

        for (const auto& recipe : allRecipes) {
            // Check if the recipe contains any restricted ingredient
            bool hasRestrictedIngredient = any_of(
                dietaryRestrictions.begin(),
                dietaryRestrictions.end(),
                [&recipe](const Ingredient& restriction) {
                    return recipe.containsIngredient(restriction);
                }
            );

            // Skip recipes with restricted ingredients
            if (!hasRestrictedIngredient) {
                recommendedRecipes.push_back(recipe);
            }
        }

        return recommendedRecipes;
    }
};

int main() {
    // Create ingredients
    Ingredient tomato("Tomato");
    Ingredient onion("Onion");
    Ingredient chicken("Chicken");

    // Create recipes
    Recipe salad("Salad", {tomato, onion});
    Recipe pasta("Pasta", {tomato, onion});
    Recipe chickenSoup("Chicken Soup", {chicken, onion});

    // Create a user
    User user("Alice");
    user.addDietaryRestriction(chicken);

    // Add favorite recipes to the user
    user.addFavoriteRecipe(salad);
    user.addFavoriteRecipe(pasta);

    // Get recipe recommendations for the user
    vector<Recipe> allRecipes = {salad, pasta, chickenSoup};
    vector<Recipe> recommendedRecipes = user.recommendRecipes(allRecipes);

    // Display recommended recipes
    cout << "Recommended Recipes for " << user.name << ":" << endl;
    for (const auto& recipe : recommendedRecipes) {
        cout << "- " << recipe.name << endl;
    }

    return 0;
}
