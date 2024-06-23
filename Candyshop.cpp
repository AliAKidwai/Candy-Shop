#include <iostream>
using namespace std;

class cashregister {
public:
    int currentbalance() {
        return cashonhand;
    }
    void acceptamount(int amountin) {
        cashonhand += amountin;
    }
    cashregister(int cashin = 500) {
        cashonhand = (cashin >= 0) ? cashin : 500;
    }
private:
    int cashonhand; 
};

class dispensertype {
public:
    int count() {
        return numberofitems;
    }
    int productcost() {
        return cost;
    }
    void makesale() {
        numberofitems--;
    }
    dispensertype(int setofitems = 50, int setcost = 50) {
        numberofitems = (setofitems >= 0) ? setofitems : 50;
        cost = (setcost >= 0) ? setcost : 50;
    }
private:
    int numberofitems;
    int cost;
};

void showselection() {
    cout << "Welcome to Shelly's Candy Shop!" << endl;
    cout << "1: Candy" << endl;
    cout << "2: Chips" << endl;
    cout << "3: Gum" << endl;
    cout << "4: Cookies" << endl;
    cout << "9: Exit" << endl;
    cout << "Please choose an option: ";
}

void sellproduct(dispensertype& product, cashregister& pcounter) {
    if (product.count() > 0) {
        int productCost = product.productcost();
        int amount;
        cout << "Please deposit " << productCost << " cents: ";
        cin >> amount;

        while (amount < productCost) {
            cout << "Insufficient deposit. Please deposit another " << (productCost - amount) << " cents: ";
            int additionalAmount;
            cin >> additionalAmount;
            amount += additionalAmount;
        }

        if (amount >= productCost) {
            pcounter.acceptamount(amount);
            product.makesale();
            cout << "Collect your item at the bottom and enjoy." << endl;
        } else {
            cout << "The amount is not enough. Collect your deposited amount." << endl;
        }
    } else {
        cout << "Sorry, this item is sold out." << endl;
    }
}

int main() {
    cashregister counter;
    dispensertype candy(100, 50);
    dispensertype chips(100, 65);
    dispensertype gum(75, 45);
    dispensertype cookies(100, 85);

    int choice;
    showselection();
    cin >> choice;
    while (choice != 9) {
        switch (choice) {
            case 1:
                sellproduct(candy, counter);
                break;
            case 2:
                sellproduct(chips, counter);
                break;
            case 3:
                sellproduct(gum, counter);
                break;
            case 4:
                sellproduct(cookies, counter);
                break;
            default:
                cout << "Invalid selection, please try again." << endl;
        }
        showselection();
        cin >> choice;
    }

    cout << "Thank you for visiting Shelly's Candy Shop!" << endl;
    return 0;
}
