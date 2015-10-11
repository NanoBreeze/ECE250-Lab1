#include "Cyclic_list.h"


template <typename Type>
Cyclic_list<Type>::Cyclic_list() :
list_head(nullptr),
list_tail(nullptr),
list_size(0) {
	// enter your implementation here
}

//copy constructor
template <typename Type>
Cyclic_list<Type>::Cyclic_list(Cyclic_list<Type> const &list) :
list_head(nullptr),
list_tail(nullptr),
list_size(0) {
	// enter your implementation here
}

//destructor, deletes all nodes
template <typename Type>
Cyclic_list<Type>::~Cyclic_list() {
	// enter your implementation here
}

//determines the size of the cyclic list
template <typename Type>
int Cyclic_list<Type>::size() const {
	
	int count = 0;
	Single_node<Type> current_node = list_head;

	while (current_node != nullptr)
	{
			count++;
			current_node = current_node->next();
	}
	return count;
}

//determines if the cyclic list is empty or not
template <typename Type>
bool Cyclic_list<Type>::empty() const {
	if (list_head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//retrieves the element in the head node
template <typename Type>
Type Cyclic_list<Type>::front() const {
	if (list_head->retrieve() == nullptr)
	{
		throw new std::exception("front() is called and the list is null. Make sure to replace this comment with the custom exception header's underflow exception");
	}
	else
	{
		return list_head->retrieve();
	}
}

//retrieves the element in the tail node
template <typename Type>
Type Cyclic_list<Type>::back() const {

	if (list_tail->retrieve() == nullptr)
	{
		throw new std::exception("back() is called and the list is null. Make sure to replace this comment with the custom exception header's underflow exception");
	}
	else
	{
		return list_head->tail();
	}	
}

//returns the head node
template <typename Type>
Single_node<Type> *Cyclic_list<Type>::head() const {
	return list_head;
}

//returns the tail node
template <typename Type>
Single_node<Type> *Cyclic_list<Type>::tail() const {
	return list_tail;
}

//returns the number of nodes in the cyclic list storing a value equal to the parameter
template <typename Type>
int Cyclic_list<Type>::count(Type const &obj) const {
	int count = 0;

	Single_node<Type> current_node = list_head;

	while (current_node != nullptr)
	{
		if (current_node->retrieve() == obj)
		{
			count++;
		}
		current_node = current_node->next();
	}

	return count;
}


template <typename Type>
void Cyclic_list<Type>::swap(Cyclic_list<Type> &list) {
	std::swap(list_head, list.list_head);
	std::swap(list_tail, list.list_tail);
	std::swap(list_size, list.list_size);
}

template <typename Type>
Cyclic_list<Type> &Cyclic_list<Type>::operator=(Cyclic_list<Type> const &rhs) {
	Cyclic_list<Type> copy(rhs);
	swap(copy);
	return *this;
}

//creates a new node at the front. The next pointer of the last node now points to this node
template <typename Type>
void Cyclic_list<Type>::push_front(Type const &obj) {
	// enter your implementation here
}

//creates a new node at the end. Its next pointer points to the head node.
template <typename Type>
void Cyclic_list<Type>::push_back(Type const &obj) {
	// enter your implementation here
}

//delete the head node and adjust the head, and next pointer of the tail accordingly
template <typename Type>
Type Cyclic_list<Type>::pop_front() {
	// enter your implementation here
	return Type();
}

//delete the first node whose element matches the parameter. 
//Return the number of nodes deleted.
template <typename Type>
int Cyclic_list<Type>::erase(Type const &obj) {
	// enter your implementation here
	return 0;
}
