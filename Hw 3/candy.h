#ifndef CANDY_H
#define CANDY_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Candy{
	string name;
	float number;
	float price;
	float calculated;
	public:
		Candy(string, float, float);
		~Candy();
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

Candy::Candy(string coming_name, float coming_number, float coming_price){
	name = coming_name;
	number = coming_number;
	price = coming_price;
}

Candy::~Candy(){
	
}







#endif
