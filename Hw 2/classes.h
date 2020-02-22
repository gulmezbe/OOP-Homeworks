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

Node::Node(){				//Node classý constructorý pointerlarý null yapýp int i 0 yapýyor
	data = 0;
	next = NULL;
	prev = NULL;
}

Node::~Node(){			//Node classý destructorý
	
}

ARTraverser::ARTraverser(){			//ARTraverser classý constructorý pointerý null yapýyor
	current = NULL;
}

ARTraverser::~ARTraverser(){		//ARTraverser classý destructorý

}

AdderRemover::AdderRemover(){		//AdderRemover classý constructorý pointerlarý null yapýp int i 0 yapýyor
	head = NULL;
	tail = NULL;
	traverser = NULL;
	nodeCount = 0;
}

AdderRemover::~AdderRemover(){		//AdderRemover classý destructorý
	
}

void AdderRemover::display(){
	Node* temp;
	temp = head;															//node* tipinde temp tanýmlayýp heada eþitliyor
	
	cout << name << " Node Count:" << nodeCount << endl << "------" << endl;
	
	if(nodeCount == 0){
		cout << "There is no element to print" << endl << endl;			//ödevde hiç gerçekleþmiyor hep dolu classda print var ama basacak eleman yoksa yazýyor
	}
	else{
		while(temp){
			cout << temp->data << endl;				//temp null olana kadar ielrleyerek bastýrýyor
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
	head = NULL;				//bittiðinde tail NULL olmadýgý için onuda nul lyapýyor onun yanýnda digerlerinide garanti olsun diye sýfýrladým
	tail = NULL;
	nodeCount = 0;
}

void AdderRemover::traverse(){
	cout << endl << name << " Node Count:" << nodeCount << endl << "------" << endl;
	
	if(nodeCount == 0){
		cout << "There is no element to traverse" << endl << endl;		//display fonsksiyonuyla ayný satýr
	}
	
	while(traverser->hasNode()){					//içerisi boþ olana kadar traverserle gezerek yazdýrýyor
		cout << traverser->next() << endl;			//next fonksiyonunun hem dönüþ tipi int ldugu için printliyor ayný zamanda içerisindede sýradaki node a geçiyor
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
	if(head == NULL){					//temp olusturuyor if den önce ve burada ilk node sa ilerisini gerisini nulluyor ve head ve taili buna eþitliyor
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = temp;
	}
	else{
		temp->next = head;			//sonraki durumlar için baþa ekliyor
		temp->prev = NULL;
		head->prev = temp;			//diðer first add kodu da bunun aynýsý
		head = temp;
	}
	nodeCount++;
}

void FAFR::remove(){
	Node* temp;
	temp = head;
	if(temp != NULL){				//tempi head e eþitleyip bastan silecegi için head i bir öne çekip tempi delete liyor
		head = head->next;
		if(head == NULL)			//head null a ulastýysa tail i de null yapýyor yeniden yazdýrcagý durumd asorun cýkmamasý için 
			tail = NULL;
		head->prev = NULL;			//diðer first remove kodu da bunun aynýsý
		delete temp;
	}
	else{
		cout << "There is no element to remove in FAFR" << endl;
	}
	nodeCount--;
}

void FAFR::setTraverser(){
	traverser = new ARTF(head);			//newlerken artf nin constructoruna prametre yolluyor heade eþitlemek için çünkü orda eþitleyemiyoruz protect türünde olmasý nedeniyle
}										//artl kýsýmlarýndada tail yollanýyor

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
	temp = tail;						//first remove un aynýsýnýn tail le tersteni. Asagýsý hep benzer kodlar 
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
	x = current->data; 					//degeri saklamak için x e atayýp sýradaki node a geçerek sornadan bastýrýyor
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
