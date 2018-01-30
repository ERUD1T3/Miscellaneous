//#pragma once
//Templated Double linked list

#ifndef GENERICGenericDLinkedList_H
#define GENERICGenericDLinkedList_H

#include <iostream>
#include <string>
using namespace std;

//typedef string Elem;				// list element type
template<typename Type>
class GenericDNode {					// doubly linked list node
private:
	Type elem;					// node element value
	GenericDNode<Type>* prev;				// previous node in list
	GenericDNode<Type>* next;				// next node in list

	template<class Type>
	friend class GenericDLinkedList;			// allow GenericDLinkedList access
};

template<typename Type>
class GenericDLinkedList {				// doubly linked list
	public:
		GenericDLinkedList();				// constructor
		~GenericDLinkedList();				// destructor
		bool empty() const;				// is list empty?
		const Type& front() const;			// get front element
		const Type& back() const;			// get back element
		void addFront(const Type& e);		// add to front of list
		void addBack(const Type& e);		// add to back of list
		void removeFront();				// remove from front
		void removeBack();				// remove from back
		int size();
		void printList(void);
	private:					// local type definitions
		GenericDNode<Type>* header;				// list sentinels
		GenericDNode<Type>* trailer;
	protected:					// local utilities
		void add(GenericDNode<Type>* v, const Type& e);		// insert new node before v
		void remove(GenericDNode<Type>* v);			// remove node v
		int n;
};


template<typename Type>
GenericDLinkedList<Type>::GenericDLinkedList() {			// constructor
	header = new GenericDNode<Type>;				// create sentinels
	trailer = new GenericDNode<Type>;
	header->next = trailer;			// have them point to each other
	trailer->prev = header;

	header->prev = NULL;
	header->elem= "Header";
	trailer->elem= "Trailer";
	trailer->next = NULL;
	n = 0;
}

template<typename Type>
GenericDLinkedList<Type>::~GenericDLinkedList() {			// destructor
	while (!empty()) removeFront();		// remove all but sentinels
	delete header;				// remove the sentinels
	delete trailer;
}

template<typename Type>
bool GenericDLinkedList<Type>::empty() const		// is list empty?
{
	return (header->next == trailer);
}

template<typename Type>
const Type& GenericDLinkedList<Type>::front() const	// get front element
{
	return header->next->elem;
}

template<typename Type>
const Type& GenericDLinkedList<Type>::back() const		// get back element
{
	return trailer->prev->elem;
}

// insert new node before v
template<typename Type>
void GenericDLinkedList<Type>::add(GenericDNode<Type>* v, const Type& e) {
	GenericDNode<Type>* u = new GenericDNode<Type>;  u->elem = e;		// create a new node for e
	u->next = v;				// link u in between v
	u->prev = v->prev;				// ...and v->prev
	v->prev->next = u;
	v->prev = u;
	n++;
}

template<typename Type>
void GenericDLinkedList<Type>::addFront(const Type& e)	// add to front of list
{
	add(header->next, e);
}

template<typename Type>
void GenericDLinkedList<Type>::addBack(const Type& e)	// add to back of list
{
	add(trailer, e);
}

template<typename Type>
void GenericDLinkedList<Type>::remove(GenericDNode<Type>* v) {		// remove node v
	GenericDNode<Type>* u = v->prev;				// predecessor
	GenericDNode<Type>* w = v->next;				// successor
	u->next = w;				// unlink v from list
	w->prev = u;
	delete v;
	//tell me what to add;
}

template<typename Type>
void GenericDLinkedList<Type>::removeFront()		// remove from font
{
	remove(header->next);
}

template<typename Type>
void GenericDLinkedList<Type>::removeBack()		// remove from back
{
	remove(trailer->prev);
}

template<typename Type>
int GenericDLinkedList<Type>::size() {
	return n; //return size
}

template<typename Type>
void GenericDLinkedList<Type>::printList(void) { //Print then delete elements within list
	while (!this->empty()) { //while list is not empty
		cout << "Elem = " << this->front() << endl;
		this->removeFront(); 
	}
}

#endif // !1


