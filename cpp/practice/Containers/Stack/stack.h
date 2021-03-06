#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include <vector>


template <typename T>
class Stack;

template <typename T>
std::ostream& operator<<(std::ostream &output, const Stack<T> &inS);

template <typename T>
class Stack
{
	public:
		Stack();
		Stack(int inSize);
		Stack(const Stack<T> &inS);
		virtual ~Stack();
		void Push(int elem);
		int Pop();
		int Peek(); const
		int getTop(); const
		int getSize(); const
		friend std::ostream& operator<<<T>(std::ostream& output, const Stack &inS);
	private:
		int top;
		int size;
		std::vector<T> elems;			
		const int DEFAULT_SIZE = 10;
};


template <typename T>
Stack<T>::Stack():top(-1),
                size(Stack::DEFAULT_SIZE),
                elems(Stack::DEFAULT_SIZE)
{
	std::cout <<"Inside default constructor" <<std::endl;
}


template <typename T>
Stack<T>::Stack(int inSize):top(-1),
                        size(inSize),
                        elems(inSize)
{
	std::cout <<"Inside parameterized constructor" <<std::endl;
}


template <typename T>
Stack<T>::Stack(const Stack<T> &inS):top(inS.getTop()),
				     size(inS.getSize()),
				     elems(inS.getElems())
{
	std::cout <<"Inside copy constructor" <<std::endl;
}

template <typename T>
Stack<T>::~Stack()
{
	std::cout <<"Inside destructor" <<std::endl;
}

template <typename T>
void
Stack<T>::Push(int elem)
{
	elems.push_back(elem);
}


template <typename T>
int
Stack<T>::Pop()
{
	if (top == -1)
	{
		std::cout <<"Empty stack" <<std::endl;
		return -1;
	}
	int temp = elems[top];
	elems.pop_back();
	top--;
	return temp;
}


template <typename T>
int
Stack<T>::Peek() const
{
	return elems.back();
}


template <typename T>
int
Stack<T>::getTop() const
{
	return top;
}


template <typename T>
int
Stack<T>::getSize() const
{
	return size;
}

template <typename T>
std::ostream& 
operator<<(std::ostream& output, const Stack<T>& inS)
{
	for (i = elems.size() - 1; i >= 0; i--)
	{
		output << elems[i] << " ";
	}
	output <<endl;
	return output;
}
	
#endif
