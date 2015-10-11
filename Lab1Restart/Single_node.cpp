#include "Single_node.h"



template <typename Type>
Single_node<Type>::Single_node(Type const &e, Single_node<Type> *n) :
element(e),
next_node(n) {
	// empty constructor
}

//returns the element stored in the node
template <typename Type>
Type Single_node<Type>::retrieve() const {
	return element;
}

//returns the next node this node points to
template <typename Type>
Single_node<Type>* Single_node<Type>::next() const {
	return next_node;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?
