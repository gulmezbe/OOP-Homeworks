#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		Node();
		~Node();
};

class ARTraverser{
	protected:
		Node* current;
	public:
		ARTraverser();
		~ARTraverser();
		virtual bool hasNode() = 0;
		virtual int next() = 0;
};

class AdderRemover{
	friend class ARTraverser;
	protected:
		ARTraverser* traverser;
		Node* head;
		Node* tail;
		int nodeCount;
		string name;
	public:
		AdderRemover();
		~AdderRemover();
		virtual void add(int) = 0;
		virtual void remove() = 0;
		virtual void setTraverser() = 0;
		void display();
		void removeAll();
		void traverse();
};

class FAFR : public AdderRemover{
	public:
		FAFR();
		~FAFR();
		void add(int);
		void remove();
		void setTraverser();
};

class FALR : public AdderRemover{
	public:
		FALR();
		~FALR();
		void add(int);
		void remove();
		void setTraverser();
};

class LAFR : public AdderRemover{
	public:
		LAFR();
		~LAFR();
		void add(int);
		void remove();
		void setTraverser();
};

class LALR : public AdderRemover{
	public:
		LALR();
		~LALR();
		void add(int);
		void remove();
		void setTraverser();
};

class ARTF : public ARTraverser{
	public:
		ARTF(Node*);
		~ARTF();
		bool hasNode();
		int next();
};

class ARTL : public ARTraverser{
	public:
		ARTL(Node*);
		~ARTL();
		bool hasNode();
		int next();
};

Node::Node(){				//Node class� constructor� pointerlar� null yap�p int i 0 yap�yor
	data = 0;
	next = NULL;
	prev = NULL;
}

Node::~Node(){			//Node class� destructor�
	
}

ARTraverser::ARTraverser(){			//ARTraverser class� constructor� pointer� null yap�yor
	current = NULL;
}

ARTraverser::~ARTraverser(){		//ARTraverser class� destructor�

}

AdderRemover::AdderRemover(){		//AdderRemover class� constructor� pointerlar� null yap�p int i 0 yap�yor
	head = NULL;
	tail = NULL;
	traverser = NULL;
	nodeCount = 0;
}

AdderRemover::~AdderRemover(){		//AdderRemover class� destructor�
	
}

void AdderRemover::display(){
	Node* temp;
	temp = head;															//node* tipinde temp tan�mlay�p heada e�itliyor
	
	cout << name << " Node Count:" << nodeCount << endl << "------" << endl;
	
	if(nodeCount == 0){
		cout << "There is no element to print" << endl << endl;			//�devde hi� ger�ekle�miyor hep dolu classda print var ama basacak eleman yoksa yaz�yor
	}
	else{
		while(temp){
			cout << temp->data << endl;				//temp null olana kadar ielrleyerek bast�r�yor
			temp = temp->next;
		}
		cout << endl << endl;
	}
}

void AdderRemover::removeAll(){
	while(head){					//head null olana kadar ileri giderek siliyor
		Node* temp;
		temp = head;
		head = head->next;
		delete temp;
	}
	head = NULL;				//bitti�inde tail NULL olmad�g� i�in onuda nul lyap�yor onun yan�nda digerlerinide garanti olsun diye s�f�rlad�m
	tail = NULL;
	nodeCount = 0;
}

void AdderRemover::traverse(){
	cout << endl << name << " Node Count:" << nodeCount << endl << "------" << endl;
	
	if(nodeCount == 0){
		cout << "There is no element to traverse" << endl << endl;		//display fonsksiyonuyla ayn� sat�r
	}
	
	while(traverser->hasNode()){					//i�erisi bo� olana kadar traverserle gezerek yazd�r�yor
		cout << traverser->next() << endl;			//next fonksiyonunun hem d�n�� tipi int ldugu i�in printliyor ayn� zamanda i�erisindede s�radaki node a ge�iyor
	}
}

FAFR::FAFR(){
	name = "FAFR";
}

FAFR::~FAFR(){
	
}

void FAFR::add(int x){
	Node* temp;
	temp = new Node;
	temp->data = x;
	if(head == NULL){					//temp olusturuyor if den �nce ve burada ilk node sa ilerisini gerisini nulluyor ve head ve taili buna e�itliyor
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = temp;
	}
	else{
		temp->next = head;			//sonraki durumlar i�in ba�a ekliyor
		temp->prev = NULL;
		head->prev = temp;			//di�er first add kodu da bunun ayn�s�
		head = temp;
	}
	nodeCount++;
}

void FAFR::remove(){
	Node* temp;
	temp = head;
	if(temp != NULL){				//tempi head e e�itleyip bastan silecegi i�in head i bir �ne �ekip tempi delete liyor
		head = head->next;
		if(head == NULL)			//head null a ulast�ysa tail i de null yap�yor yeniden yazd�rcag� durumd asorun c�kmamas� i�in 
			tail = NULL;
		head->prev = NULL;			//di�er first remove kodu da bunun ayn�s�
		delete temp;
	}
	else{
		cout << "There is no element to remove in FAFR" << endl;
	}
	nodeCount--;
}

void FAFR::setTraverser(){
	traverser = new ARTF(head);			//newlerken artf nin constructoruna prametre yolluyor heade e�itlemek i�in ��nk� orda e�itleyemiyoruz protect t�r�nde olmas� nedeniyle
}										//artl k�s�mlar�ndada tail yollan�yor

FALR::FALR(){
	name = "FALR";
}

FALR::~FALR(){
	
}

void FALR::add(int x){
	Node* temp;
	temp = new Node;
	temp->data = x;
	if(head == NULL){
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = temp;
	}
	else{
		temp->next = head;
		temp->prev = NULL;
		head->prev = temp;
		head = temp;
	}
	nodeCount++;
}

void FALR::remove(){
	Node* temp;
	temp = tail;						//first remove un ayn�s�n�n tail le tersteni. Asag�s� hep benzer kodlar 
	if(temp != NULL){
		tail = tail->prev;
		if(tail == NULL)
			head = NULL;
		tail->next = NULL;
		delete temp;
	}
	else{
		cout << "There is nothing to remove in FALR" << endl;
	}
	nodeCount--;
}

void FALR::setTraverser(){
	traverser = new ARTF(head);
}

LAFR::LAFR(){
	name = "LAFR";
}

LAFR::~LAFR(){
	
}

void LAFR::add(int x){
	Node* temp;
	temp = new Node;
	temp->data = x;
	if(tail == NULL){
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = temp;
	}
	else{
		temp->prev = tail;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
	nodeCount++;
}

void LAFR::remove(){
	Node* temp;
	temp = head;
	if(temp != NULL){
		head = head->next;
		if(head == NULL)
			tail = NULL;
		head->prev = NULL;
		delete temp;
	}
	else{
		cout << "There is nothing to remove in LAFR" << endl;
	}
	nodeCount--;
}

void LAFR::setTraverser(){
	traverser = new ARTL(tail);
}

LALR::LALR(){
	name = "LALR";
}

LALR::~LALR(){
	
}

void LALR::add(int x){
	Node* temp;
	temp = new Node;
	temp->data = x;
	if(tail == NULL){
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = temp;
	}
	else{
		temp->prev = tail;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
	nodeCount++;
}

void LALR::remove(){
	Node* temp;
	temp = tail;
	if(temp != NULL){
		tail = tail->prev;
		if(tail == NULL)
			head = NULL;
		tail->next = NULL;
		delete temp;
	}
	else{
		cout << "There is nothing to remove in LALR" << endl;
	}
	nodeCount--;
}

void LALR::setTraverser(){
	traverser = new ARTL(tail);
}

ARTF::ARTF(Node* temp){
	current = temp;
}

ARTF::~ARTF(){
	
}

bool ARTF::hasNode(){
	if(current == NULL)			//current nodu konrol ediyor null mu diye
		return false;
	else
		return true;
}

int ARTF::next(){
	int x;
	x = current->data; 					//degeri saklamak i�in x e atay�p s�radaki node a ge�erek sornadan bast�r�yor
	current = current->next;
	return x;
}

ARTL::ARTL(Node* temp){
	current = temp;
}

ARTL::~ARTL(){
	
}

bool ARTL::hasNode(){
	if(current == NULL)
		return false;
	else
		return true;
}

int ARTL::next(){
	int x;
	x = current->data;
	current = current->prev;
	return x;
}


















#endif
