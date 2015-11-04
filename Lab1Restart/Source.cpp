#include <iostream>
#include "Cyclic_list.h"
#include "Single_node.h"


using namespace std;

int main()
{

	Cyclic_list<int> cyclic_list;
	auto k = cyclic_list.empty();
	cyclic_list.push_front(42);
	cyclic_list.push_front(52);
	cyclic_list.push_front(53);
	cyclic_list.push_front(54);
	cyclic_list.push_front(55);
	cyclic_list.push_front(56);
	auto m = cyclic_list.pop_front();
	auto v = cyclic_list.size();
	auto q = cyclic_list.head();
	auto p = cyclic_list.tail();
	auto wer = cyclic_list.front();
	auto woeitj = cyclic_list.back();





	return 0;
}