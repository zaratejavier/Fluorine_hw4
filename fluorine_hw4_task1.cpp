

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int SIZE = 3;


class HouseInfo {
private:
    int streetNumber;
    string streetName;
    double Price;
public:
    HouseInfo() : streetNumber(0), streetName(""), Price(0.0) {}


    //getters/////////////////////////
    int getStreetNumber() {
        return streetNumber;
    }

    string getStreetName() {
        return streetName;
    }

    double getPrice() {
        return Price;
    }

    //setters/////////////////////////
   /*void setPrice(double temp) {
        Price = temp;
    }

    void setStreetName(string temp) {
        streetName = temp;
    }

    int setStreetNumber(int temp) {
        streetNumber = temp;
    }*/

    //getting input from the user
    void getString()
    {
        cin.ignore();
        getline(cin, streetName);
        cin.clear();
    }

    void gethouseInfo(int i)
    {
        cout << "Enter info for " << i + 1 << " house" << endl;
        cout << "Please enter the street Number:" << endl;
        cin >> streetNumber;
        cout << "Please enter the street Name:" << endl;
        getString();
        cout << "Please enter the Price:" << endl;
        cin >> Price;
        cout << endl << endl;
    }
};

void comparePrices(HouseInfo h[2]);

// Main function ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    HouseInfo house_array[SIZE]; //array of objects

    for (int i = 0; i < SIZE; i++)
    {
        house_array[i].gethouseInfo(i);
    }
    comparePrices(house_array);
    return 0;
}

void comparePrices(HouseInfo h[2]) {
    cout << "Your Market analysis is as follows:" << endl;

    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << " House: at "
             << h[i].getStreetNumber() << " "
             << h[i].getStreetName() << " for [$"
             << h[i].getPrice() << "]" << endl;
    }

    // Set the min price initially to the first house
    double minPrice = h[0].getPrice();

    // This finds you the minimum price
    for (int houseNumber = 1; houseNumber < SIZE; houseNumber++)
    {
        if (h[houseNumber].getPrice() < minPrice)
        {
            minPrice = h[houseNumber].getPrice();
        }
    }
    cout << "You should buy: ";

    // Which houses have the minimum price
    for(int houseNumber = 0; houseNumber < SIZE; houseNumber++)
    {
        if(h[houseNumber].getPrice() == minPrice)
        {
            cout<< "house number "<< houseNumber+1<<endl;
        }
    }

}