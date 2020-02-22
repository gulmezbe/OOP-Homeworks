#ifndef COOKIE_H
#define COOKIE_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Cookie{
	string name;
	float number;
	float price;
	float calculated;
	public:
		Cookie(string, float, float);
		~Cookie();
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
			return ((price/12) * number);
		}
};

Cookie::Cookie(string coming_name, float coming_number, float coming_price){
	name = coming_name;
	number = coming_number;
	price = coming_price;
}

Cookie::~Cookie(){
	
}







#endif
