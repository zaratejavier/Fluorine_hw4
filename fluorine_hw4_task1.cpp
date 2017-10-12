// file: Real_SaltLake_HW3_task2.cpp
// Created by Daryl Adams on 9/26/17 for CS1410. Real SaltLake
// Copyright (c) 2017 WSU

//


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class HouseInfo{ 
	private:
		int streetNumber;
		string streetName;
		double Price;
	public:
		HouseInfo() : streetNumber(0),streetName(""), Price(0.0) {}
		
		
		//getters/////////////////////////
		int getStreetNumber()
		{
			return streetNumber;
		}
		string getStreetName()
		{
			return streetName;
		}
		double getPrice()
		{
			return Price;
		}
		
		
		
		//setters/////////////////////////
		void setPrice(double temp)
		{
			Price = temp;
	 	}
	 	void setStreetName(string temp)
		{
			streetName = temp;
	 	}
	 	int setStreetNumber(int temp)
		{
			streetNumber = temp;
		}
	 	
	 	
	 	
	 	//getting input from the user//////
		void aquireString()
		{
			cin.ignore();
	        getline(cin, streetName);
	        cin.clear();
        }
		void aquirehouseInfo(int i, HouseInfo h)
		{
        	cout << "Enter info for " << i << " house" << endl;
			cout << "Please enter the street Number:" << endl;
        	cin >> streetNumber;
        	cout << "Please enter the street Name:" << endl;
        	aquireString();
        	cout << "Please enter the Price:" << endl;
        	cin >> Price;
        	cout << endl << endl;
    	}
};

void comparePrices(HouseInfo h[2]);

// Main function ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
	HouseInfo house_array[3]; //array of objects
	for(int i=0; i<3; i++)house_array[i].aquirehouseInfo(i,house_array[i]);
	comparePrices(house_array);
	return 0;
}

void comparePrices(HouseInfo h[2])
{
	cout << "Your Market analysis is as follows:" << endl;
	for(int i=0;i<3;i++)
	{
        for (int j=0; j<3;j++)
		{
            if(h[i].getPrice()>h[j].getPrice())
			{
                double temp;     
				temp = h[i].getPrice();         
                h[i].setPrice(h[j].getPrice());
                h[j].setPrice(temp);
                
                string temp1 = h[i].getStreetName();              
                h[i].setStreetName(h[j].getStreetName());
                h[j].setStreetName(temp1);
                
                int temp2 = h[i].getStreetNumber();              
                h[i].setStreetNumber(h[j].getStreetNumber());
                h[j].setStreetNumber(temp2);
            }
        }
    }
    for(int i=0; i<3; i++) cout << i << " House " << h[i].getStreetNumber() << " " << h[i].getStreetName()  << " [$" << h[i].getPrice() << "]" << endl;
}
