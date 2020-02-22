#ifndef ICECREAM_H
#define ICECREAM_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Icecream{
	string name;
	float number;
	float price;
	float calculated;
	public:
		Icecream(string, float, float);
		~Icecream();
		string getName(){
			return name;
		}		
		float getNumber(){
			return number;
		}		
		float getPrice(){
			return price;
		}
		float getCalculated(){
			return (price * number);
		}
};

Icecream::Icecream(string coming_name, float coming_number, float coming_price){
	name = coming_name;
	number = coming_number;
	price = coming_price;
}

Icecream::~Icecream(){
	
}








#endif
