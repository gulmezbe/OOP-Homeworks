#ifndef SHOP_H
#define SHOP_H

#define KDV 8
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

template <class T>
class Shop{
	public:
		float discount = 0;
		vector<T> vec; 
		Shop(T);
		~Shop();
		void add(T);
		void setDiscount(int);
		friend ostream& operator<<(ostream& os, Shop<T>& coming_T){
			float total = 0;
			float total_without_KDV;
			os << "**********************\n\nNumber of items:" << coming_T.vec.size() << '\n';
			for(int i = 0;i < coming_T.vec.size(); i++){
				os << i+1 << ": " << coming_T[i].getName() << " #" << coming_T[i].getNumber() << " Cost: " << coming_T[i].getCalculated() << '\n';
				total = total + coming_T[i].getCalculated();
			}
			total_without_KDV = total;
			total = (total * (KDV + 100)) / 100;
			os << "**********************\n\nTotal Cost: " << total << '\n';
			if(coming_T.discount == 0){
				//nothing
			}
			else if(coming_T.discount <= 30 && coming_T.discount >0){
				float discount_amount;
				float last_total;
				
				discount_amount = (total * coming_T.discount)/100;
				last_total = total - discount_amount;
				os << "Discount: " << coming_T.discount << "%\n" << "Discount amount: " << discount_amount << '\n' << "Discounted cost: " << last_total << '\n';
			}
			else{
				os << "**********************Discount rate is out of range!\n";
			}
		    return os;
		}
		T& operator[](int coming_number){
   	    if (coming_number >= vec.size())
			throw "**********************We don't have enough cookies!\n";
    	
			return vec[coming_number];
    	}
};

template <class T>
Shop<T>::Shop(T coming_data){
	vec.push_back(coming_data);
}

template <class T>
void Shop<T>::add(T coming_data){
	vec.push_back(coming_data);
}

template <class T>
void Shop<T>::setDiscount(int coming_number){
	discount = coming_number;
}

template <class T>
Shop<T>::~Shop(){
	
}








#endif
