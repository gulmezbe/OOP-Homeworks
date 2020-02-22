/*
* Student Name: Behlül Gülmez
* Student ID : 150140113
* Date: 28.3.2017
*/


//bazý istenen fonksiyonlar mainde kullanýmý yoktu yazdým denedim yorum satýrýna aldým


#include<iostream>
#include"SmallVector.h"

using namespace std;

void printSmallVector(const char* const message, const SmallVector& in_vector) {
	cout << message << ": ";
	for (int i = 0; i < in_vector.getSize(); i++)
	{
		cout << in_vector[i] << " ";
	}
	cout << endl;
}

int main() {
	int temp[35];
	for (int i = 0; i < 35; i++) {
		temp[i] = i;
	}
	SmallVector test(temp, 10); // Creating SmallVector with 10 elements
	SmallVector test2(temp, 35); // Creating SmallVector with 35 elements
	// print test in reverse order
	printSmallVector("Printing test in reverse", test.reverse());
	SmallVector test3; // Empty SmallVector
	test3 = test2 + test; // Concatenate two SmallVectors
	printSmallVector("Printing test3", test3);
	SmallVector test4(test); // Copy SmallVector
	//printSmallVector("Printing test4", test4);
	SmallVector test5(temp, 2);
	test5 = test5 * 5; // Replicate elements
	test5.push_back(12); // Add 12 at the end
	//test5.push_back(temp, 10);
	test5[0] = 4; // Modify the first element of test5
	cout << "Printing test5 in reverse: ";
	for (int i = 1; i < test5.getSize() + 1; i++)
	{
		// Testing negative numbers as indices
		cout << test5[-i] << " ";
	}
	//cout << endl << test5.pop_back();
	return 0;
}
