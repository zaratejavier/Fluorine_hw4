// file: Florine_HW4.cpp
// Created by Andrew Bills/Javier Zarate on 10/16/2017 for CS1410. Florine

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

class HouseInfo{ 
	private:
		int streetNumber;
		string streetName;
		double Price;
		int houseOrderEntered;
	public:
		HouseInfo() : streetNumber(0),streetName(""), Price(0.0) {}
		
		//getter///////////////////////////////////
		int getPrice(){return Price;}
		
		
		void printMarketAnalysis();
		//returns a string on which house you should purchase
		string youShouldBuy(){return "House number"+houseOrderEntered;}
		//aquireing the info from the user////////
		void aquirehouseInfo(int i);
}

void HouseInfo::printMarketAnalysis();
{
			cout << houseOrderEntered << " House " << streetNumber << " " 
			 << streetName << fixed << setprecision(2) << " [$" << Price << "]" << endl;
}
//aquireing the info from the user////////
void aquirehouseInfo(int i)
{
	cout << "Enter info for " << i << " house" << endl  << "Please enter the street Number:" << endl;
	cin >> streetNumber;
	cout << "Please enter the street Name:" << endl;
	cin.ignore();
	getline(cin, streetName);
	cout << "Please enter the Price:" << endl;
	cin >> Price;
	cout << endl << endl;
	houseOrderEntered=i;
}



//this function compares the prices of each house and prints them out from least to greatest and tell you one is the cheapest
void comparePrices(HouseInfo h[2]);


// Main function ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
	HouseInfo house_array[3]; //array of objects
	for(int i=1; i<4; i++)house_array[(i-1)].aquirehouseInfo(i);
	comparePrices(house_array);
	return 0;
}

void comparePrices(HouseInfo h[2])
{
    cout << "Your Market analysis is as follows:" << endl;
    for(int i=0; i<3; i++)
    	h[i].printMarketAnalysis();	
    for(int i=0;i<3;i++)
        for (int j=0; j<3;j++)
			if(h[i].getPrice()>h[j].getPrice())
				swap(h[i], h[j]);
    cout << "You should buy:";
    for(int i=0; i<3; i++) 
		if(h[0].getPrice() == h[i].getPrice()) 
			cout << h[i].youShouldBuy();
}
