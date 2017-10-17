// file: Florine_HW4.cpp
// Created by Andrew Bills/Javier Zarate on 10/16/2017 for CS1410. Florine

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sstream>

using namespace std;

class HouseInfo{ 
	private:
		int streetNumber;
		string streetName;
		double Price;
		int houseOrderEntered;
	public:
		HouseInfo() : streetNumber(0),streetName(""), Price(0.0) {}
		
		//getter//////////////////////////////////////////////
		int getPrice(){return Price;}
		//prints out what 3 houses the user typed in//////////
		void printMarketAnalysis();
		//returns a string on which house you should purchase
		string youShouldBuy(){return "   House number "+to_string(houseOrderEntered);}
		//aquireing the info from the user///////////////////
		void aquirehouseInfo(int i);
};
//prints out what 3 houses the user typed in//////////
void HouseInfo::printMarketAnalysis()
{
			cout << houseOrderEntered << " House " << streetNumber << " " 
			 << streetName << fixed << setprecision(2) << " [$" << Price << "]" << endl;
}
//aquireing the info from the user////////
void HouseInfo::aquirehouseInfo(int i)
{
	cout << "Enter info for " << i << " house" << endl  << "Please enter the street Number:" << endl;
	cin >> streetNumber;
	cout << "Please enter the street Name:" << endl;
	cin.ignore();
	getline(cin, streetName);
	cout << "Please enter the Price:" << endl;
	cin >> Price;
	cout << endl << endl;
	houseOrderEntered=i;//this help me keep trake of the house order
}


//this function compares the prices of each house and prints them out from least to greatest and tell you one is the cheapest
void comparePrices(HouseInfo h[2]);


// Main function ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
	HouseInfo house_array[3]; //array of objects
	for(int i=1; i<4; i++)house_array[(i-1)].aquirehouseInfo(i);//calls the function that gets house information from the user
	comparePrices(house_array);// compares the price of each house
	return 0;
}
void comparePrices(HouseInfo h[2])
{
    cout << "Your Market analysis is as follows:" << endl;
    for(int i=0; i<3; i++)
    	h[i].printMarketAnalysis();	
    	
    // The code below organizes the objects according to the price of each house from least to greatest
    for(int i=0;i<3;i++)
        for (int j=0; j<3;j++)
			if(h[j].getPrice()>h[i].getPrice())
				swap(h[i], h[j]);
				
	// The code below prints out the first house that is the cheapest, and the other two if they equal the first house in the object array
    cout << "You should buy:";
    for(int i=0; i<3; i++) 
		if(h[0].getPrice() == h[i].getPrice()) 
			cout << h[i].youShouldBuy();
}
