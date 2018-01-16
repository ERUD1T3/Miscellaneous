//#include <iostream>
//using namespace std;
#ifdef SINGLY_LIST_H
#define SINGLY_LIST_H


template<class Type>
class List {
	private:
		struct Node {
			Type data;
			Node* nextp;
		};

		size_t size;
		Node* head;
        Node* tail;

	public:
    //Basic functions
		List(void): size(0), head(nullptr); //default constructor
		List(int _size) : head(nullptr); //parameterized constructor: size init
        ~List(void); //destructor
    
    //Update methods
		void insertFront(Type _data); //append nodes to the head
		void insertBack(Type _data); //append nodes to the tail
        void insert(unsigned short pos, Type _data); //appends nodes at designated position
        void removeFront(); //deletes nodes from head
		void removeBack(); //deletes nodes from tail
        void remove(unsigned short pos); //deletes nodes from designated position
		size_t getSize(void) const ; //return the size of List
        size_t checkSize(void) const ; //return the size of List
        bool empty() const; //return true when List is empty and false otherwise

    //Iterators
        Node* begin() const;
        Node* end() const;		
};

template<class Type>
List<Type>::List(void) {}

template<class Type>
List<Type>::List(int _size) : head(nullptr) {
    size = _size;
}
		
template<class Type>
void List<Type>::insertFront(Type _data) {
    Node* tmpp = new Node;
    tmpp->data = _data;
    tmpp->nextp = head;
    head = tmpp;
    size++;
}

template<class Type>
void List<Type>::insertBack(Type _data) {
    if(head == nullptr) {
        head = new Node;
        head->data = _data;
        head->nextp = nullptr;
    }
    else { 
        Node* tmpp = head;
        while(tmpp->nextp != nullptr) {
            tmpp = tmpp->nextp;
        }
        Node* tail = new Node;
        tmpp->nextp = tail;
        tail->data = _data;
    }
    size++;
}
		
template<class Type>
void List<Type>::insert(unsigned short pos, Type _data) { 
    if(pos == 0)
        this->insertBack(_data);
    else {
        Node* tmpp = head;
        for(unsigned short i = 0; i < pos-1; ++i) 
            tmpp = tmpp->nextp;
    
        Node* new_adrs = new Node;
        new_adrs->data = _data;
        new_adrs->nextp = tmpp->nextp;
        tmpp->nextp = new_adrs;
    }
    size++;
}

template<class Type>
void List<Type>::removeBack() {
    Node* tmpp = head;
    while((tmpp->nextp)->nextp != nullptr)
        tmpp = tmpp->nextp;

    tail = tmpp;
    tmpp = tmpp->nextp;
    tail->nextp = nullptr;
    delete tmpp;
    size--;
}

template<class Type>
void List<Type>::removeFront() {
    Node* tmpp = head;
    head = tmpp->nextp;
    delete tmpp;
    size--;
}

template<class Type>
void List<Type>::remove(unsigned short pos) {
    if(pos == 0) {
        this->removeFront();
    } else {
        Node* tmpp = head;
        for(unsigned short i = 0; i < pos -1; ++i)
            tmpp = tmpp->nextp;

        Node* to_del = tmpp->nextp;
        tmpp->nextp = to_del->nextp;
        delete to_del;
    }
    size--;
}

template<class Type>
int List<Type>::getSize(void) const { 
    return size; 
}

template<class Type>
int List<Type>::checkSize(void) const { 
    Node* tmpp = head;
        while(tmpp->nextp != nullptr) {
            size++;
            tmpp = tmpp->nextp;
        }
    return size; 
}

template<class Type>
bool List<Type>::empty(void) const { 
    if(!this->checkSize())
        return true;
    else
        return false;
}

template<class Type>
List<Type>::~List(void) {
    Node* tmpp = head;
    while(tmpp->nextp != nullptr) {
        delete head;
        head = tmpp = tmpp->nextp;
    }
}

#endif