#include <vector>
#include <stexcept>
#include "stack.h"
using namespace std;

template <typename T>
Stack<T>::Stack()
{

}

template <typename T>
Stack<T>::~Stack()
{

}

template <typename T>
bool Stack<T>::empty() const
{
	return std::vector<T>::empty();
}

template <typename T>
size_t Stack<T>::size() const
{
	return std::vector<T>::size();
}

template <typename T>
void Stack<T>::push(const T& item)
{
	std::vector<T>::insert(std::vector<T>::begin(), item);
}

template <typename T>
void Stack<T>::pop()
{
	if (empty()){
		// throws std::underflow_error if empty
		throw std::underflow_error("stack is empty");
	}
	else{
		std::vector<T>::erase(std::vector<T>::begin());
	}
}

template <typename T>
const T& Stack<T>::top() const
{
	if (empty()){
		// throws std::underflow_error if empty
		throw std::underflow_error("stack is empty");
	}
	else{
		return std::vector<T>::front();
	}
}

