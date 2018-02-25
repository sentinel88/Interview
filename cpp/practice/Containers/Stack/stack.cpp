#include "stack.h"

using namespace std;

template <typename T>
T getElem(void)
{
	T elem;
	cout <<"Enter the element to be pushed onto the stack" <<endl;
	cin >>elem;
	return elem;
}


int 
main (int argc, char *argv[])
{
	Stack<int> S(5);
	S.Push(1);
	S.Push(2);
	S.Push(3);
	S.Push(4);
	S.Push(5);
	S.Push(6);
	cout <<S;
	return 0;
}
