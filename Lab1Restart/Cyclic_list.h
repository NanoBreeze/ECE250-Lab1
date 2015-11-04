/*****************************************
* Instructions
*  - Replace 'uwuserid' with your uWaterloo User ID
*  - Select the current calendar term and enter the year
*  - List students with whom you had discussions and who helped you
*
* uWaterloo User ID:  l43cheng @uwaterloo.ca
* Submitted for ECE 250
* Department of Electrical and Computer Engineering
* University of Waterloo
* Calender Term of Submission:  (Fall) 2015
*
* By submitting this file, I affirm that
* I am the author of all modifications to
* the provided code.
*
* The following is a list of uWaterloo User IDs of those students
* I had discussions with in preparing this project:
*    -
*
* The following is a list of uWaterloo User IDs of those students
* who helped me with this project (describe their help; e.g., debugging):
*    -
*****************************************/


#ifndef CYCLIC_LIST_H
#define CYCLIC_LIST_H

#ifndef nullptr
#define nullptr 0
#endif

#include "ece250.h"
#include "Single_node.h"
#include "Exception.h"


template <typename Type>
class Cyclic_list 
{
private:
	Single_node<Type> *list_head;
	Single_node<Type> *list_tail;
	int list_size;

public:
	Cyclic_list() ;
	Cyclic_list(Cyclic_list const &);
	~Cyclic_list();

	// Accessors

	int size() const;
	bool empty() const;

	Type front() const;
	Type back() const;

	Single_node<Type> *head() const;
	Single_node<Type> *tail() const;

	int count(Type const &) const;

	// Mutators

	void swap(Cyclic_list &);
	Cyclic_list &operator=(Cyclic_list const &);

	void push_front(Type const &);
	void push_back(Type const &);

	Type pop_front();

	int erase(Type const &);
};


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
	
	if (!list.empty())
	{
		int sizeOfList = list.size();

		Single_node<Type>* original_current_node = list.list_head;
		list_head = new Single_node<Type>;
		list_head->element = original_current_node->element;
		list_head->next_node = new Single_node < Type > ;
		original_current_node = original_current_node->next();

		Single_node<Type>* current = list_head->next();

		for (int i = 0; i < sizeOfList -1; i++)
		{
			current->element = original_current_node->element;
			if (i != sizeOfList - 2)
			{
				current->next_node = new Single_node < Type > ;
				current = current->next();
				original_current_node = original_current_node->next();
			}
			if (i == sizeOfList - 2)
			{
				list_tail = current;
				list_tail->next_node = list_head;
			}
		}

		
	}

}

//destructor, deletes all nodes
template <typename Type>
Cyclic_list<Type>::~Cyclic_list() {
	
	delete list_head;

	//Single_node<Type>* current = list_head;
	//Single_node<Type>* ahead = list_head->next();

	//int sizeOfList = size();

	//for (int i = 0; i < sizeOfList; i++)
	//{
	//	delete current;
	//	current = ahead;
	//	ahead = ahead->next();
	//}
}

//determines the size of the cyclic list. Start at head, stop counting when at tail. Thus, +1 to count
template <typename Type>
int Cyclic_list<Type>::size() const {
	
	int count = 0;
	Single_node<Type>* current_node = list_head;
	
	while (current_node != list_tail)
	{
			count++;
			current_node = current_node->next();
	}
	return count + 1;
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
	if (list_head == nullptr)
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

	if (list_tail == nullptr)
	{
		throw new std::exception("back() is called and the list is null. Make sure to replace this comment with the custom exception header's underflow exception");
	}
	else
	{
		return list_tail->retrieve();
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
	Single_node<Type>* current_node = list_head;

	int sizeOfList = size();

	for (int i = 0; i < sizeOfList; i++)
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
	if (empty())
	{
		list_head = new Single_node<Type> ;
		list_head->element = obj;
		list_tail = list_head;
		list_tail->next_node = list_head;
	}
	else
	{
		Single_node<Type>* temp = new Single_node<Type>;
		temp->element = obj;
		temp->next_node = list_head;
		list_head = temp;
		list_tail->next_node = list_head;
	}
}

//creates a new node at the end. Its next pointer points to the head node.
template <typename Type>
void Cyclic_list<Type>::push_back(Type const &obj) {
	if (empty())
	{
		list_head = new Single_node<Type>;
		list_head->element = obj;
		list_tail = list_head;
	}
	else
	{
		Single_node<Type>* temp = new Single_node<Type>;
		temp->element = obj;
		list_tail->next_node = temp;
		list_tail = temp;
		list_tail->next_node = list_head;
	}
}

//delete the head node and adjust the head, and next pointer of the tail accordingly
template <typename Type>
Type Cyclic_list<Type>::pop_front() {
	Single_node<Type>* temp = list_head;
	Type element = temp->retrieve();
	list_head = list_head->next();
	list_tail->next_node = list_head;
	delete temp;
	return element;
}

//delete the first node whose element matches the parameter. 
//Return the number of nodes deleted.
template <typename Type>
int Cyclic_list<Type>::erase(Type const &obj) {


	Single_node<Type>* current = list_head;
	Single_node<Type>* ahead = list_head->next();

	if (current->retrieve() == obj)
	{
		pop_front();
		return 1;
	}

	int s = size();

	for (int i = 0; i < s -1; i++)
	{
		if (ahead->retrieve() == obj)
		{
			current->next_node = ahead->next();
			delete ahead;
			return 1;
		}
		else
		{
			current = ahead;
			ahead = ahead->next();
		}
	}
	return 0;
}


template <typename T> std::ostream &operator<< (std::ostream &out, Cyclic_list<T> const &list)
{
	out << "head";
	int counter = 0;

	for (Single_node<T> *ptr = list.head(); counter < list.size(); ptr = ptr->next())
	{
		out << "->" << ptr->retrieve();

		counter++;
	}

	return out;
}


#endif