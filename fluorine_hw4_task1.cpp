// file: Real_SaltLake_HW3_task2.cpp
// Created by Daryl Adams on 9/26/17 for CS1410. Real SaltLake
// Copyright (c) 2017 WSU

//


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
	public:
		HouseInfo() : streetNumber(0),streetName(""), Price(0.0) {}
		
		//getter/////////////////////////
		int getPrice(){return Price;}
		
		int printMarketAnalysis(int i)
		{
			cout << (i+1) << " House " << streetNumber << " " 
			 << streetName << fixed << setprecision(2) << " [$" << Price << "]" << endl;
		}
		
		
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
    		}
};

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
	for(int i=0;i<3;i++)
        for (int j=0; j<3;j++)
			if(h[i].getPrice()>h[j].getPrice()) 
				swap(h[i], h[j]);
    cout << "Your Market analysis is as follows:" << endl;
    for(int i=0; i<3; i++) 
    	h[i].printMarketAnalysis(i);	
}
