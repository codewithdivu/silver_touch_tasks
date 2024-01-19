#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Bidder;

class Item {
public:
    string name;
    double startingPrice;
    double currentBid;
    Bidder* currentBidder;

    Item(const string& itemName, double price)
        : name(itemName), startingPrice(price), currentBid(price), currentBidder(nullptr) {}

    void placeBid(Bidder* bidder, double bidAmount);
};

class Bidder {
public:
    string name;

    Bidder(const string& bidderName) : name(bidderName) {}

    void bidOnItem(Item& item, double bidAmount);
};

class Auction {
public:
    vector<Item> items;

    void addItem(const string& itemName, double startingPrice) {
        items.emplace_back(itemName, startingPrice);
    }

    void startAuction() {
        cout << "Auction Started!" << endl;
    }

    void displayItems() {
        cout << "Auction Items:" << endl;
        for (const auto& item : items) {
            cout << "Item: " << item.name << ", Starting Price: $" << item.startingPrice << ", Current Bid: $" << item.currentBid;
            if (item.currentBidder) {
                cout << " (Bidder: " << item.currentBidder->name << ")";
            }
            cout << endl;
        }
    }
};

void Item::placeBid(Bidder* bidder, double bidAmount) {
    if (bidAmount > currentBid) {
        currentBid = bidAmount;
        currentBidder = bidder;
        cout << "Bid placed successfully by " << bidder->name << " for item " << name << " with bid amount $" << bidAmount << endl;
    } else {
        cout << "Bid amount must be greater than the current bid." << endl;
    }
}

void Bidder::bidOnItem(Item& item, double bidAmount) {
    item.placeBid(this, bidAmount);
}

int main() {
    Auction onlineAuction;

    // Adding items to the auction
    onlineAuction.addItem("Painting", 100.0);
    onlineAuction.addItem("Antique Vase", 200.0);
    onlineAuction.addItem("Gaming Console", 150.0);

    // Displaying items in the auction
    onlineAuction.displayItems();

    // Creating bidders
    Bidder bidder1("John");
    Bidder bidder2("Alice");

    // Bidding on items
    bidder1.bidOnItem(onlineAuction.items[0], 120.0);
    bidder2.bidOnItem(onlineAuction.items[0], 130.0);

    bidder2.bidOnItem(onlineAuction.items[1], 220.0);
    bidder1.bidOnItem(onlineAuction.items[1], 210.0);

    // Displaying updated items in the auction
    onlineAuction.displayItems();

    return 0;
}
