#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    int price;
    int stock;
};

struct Order {
    string name;
    int qty;
    int subtotal;
};

int main() {
    Item items[5] = {
        {"Nama Chocolate", 200, 30},
        {"Original Chip", 120, 30},
        {"Chocolate Chip", 150, 30},
        {"Double Chocolate", 180, 30},
        {"Matcha Chip", 200, 30}
    };

    Order cart[100];
    int cartCount = 0;

    int choice, qty;

    while (true) {
        cout << "\n=========================\n";
        cout << "      MISS BAKES MENU\n";
        cout << "=========================\n";

        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << items[i].name
                 << " - ₱" << items[i].price
                 << " - Stock: " << items[i].stock << endl;
        }
        cout << "6. Checkout\n";
        cout << "7. Exit\n";

        cout << "\nEnter your choice (1-7): ";
        cin >> choice;

        if (choice == 7) {
            cout << "\nThanks for visiting Miss Bakes! \n";
            break;
        }

        if (choice == 6) {
            if (cartCount == 0) {
                cout << "\nYour cart is empty!\n";
                continue;
            }

            cout << "\n========== RECEIPT ==========\n";

            int grandTotal = 0;
            for (int i = 0; i < cartCount; i++) {
                cout << cart[i].qty << "x " << cart[i].name
                     << " - ₱" << cart[i].subtotal << endl;
                grandTotal += cart[i].subtotal;
            }

            cout << "-----------------------------\n";
            cout << "TOTAL: ₱" << grandTotal << endl;
            cout << "=============================\n";

            cout << "\nThank you for your purchase! \n";
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        cout << "Enter quantity: ";
        cin >> qty;

        if (qty > items[choice - 1].stock) {
            cout << "Not enough stock! Available: "
                 << items[choice - 1].stock << endl;
            continue;
        }

        items[choice - 1].stock -= qty;

        cart[cartCount].name = items[choice - 1].name;
        cart[cartCount].qty = qty;
        cart[cartCount].subtotal = qty * items[choice - 1].price;
        cartCount++;

        cout << "\nItem added to cart! \n";
        cout << "\nWould you like to add anything else? \n";
    }

    return 0;
}
