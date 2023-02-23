#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap 
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	
	std::vector<T> heap_;
	int m_;
	PComparator c_;

};

// Add implementation of member functions here

/**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
	m_ = m;
	c_ = c;
}


template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
	heap_.push_back(item);

	int curr = heap_.size() - 1;
	int parent = (curr - 1)/m_;

	// trickle up
	while(c_(heap_[curr], heap_[parent])){ // first term has priority
		// swapping values in heap_
		T old_parent = heap_[parent];
		heap_[parent] = heap_[curr];
		heap_[curr] = old_parent;

		// re-evaluating new curr and parent
		curr = parent;
		parent = (curr - 1)/m_;
	}

}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

	return heap_.front();

}


template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================

		throw std::underflow_error("heap is empty");
  }

	// swapping top and last in heap_
	T old_top = top();
	heap_[0] = heap_[heap_.size() - 1];
	heap_[heap_.size() - 1] = old_top;
	heap_.pop_back();

	// defining new indexes to be tracked
	unsigned int curr = 0;
	unsigned int child = m_ * curr + 1;
	unsigned int best;
	bool best_found = false;

	while (child < heap_.size()){
		// find best path to trickle down
		for (unsigned int i = 0; (i < (unsigned int) m_) && (child + i < heap_.size()); i++){
			// if child has priority over curr parent AND
			// if child is better option than current best route/node
			// when best already defined vs when it is not
			if (!best_found 
				&& c_(heap_[child + i], heap_[curr])){
				best_found = true;
				best = child + i;
			}
			else if (best_found 
				&& c_(heap_[child + i], heap_[curr]) 
				&& c_(heap_[child + i], heap_[best])){
				best = child + i;
			}
		}

		if (best_found){ // to swap
			T old_parent = heap_[curr];
			heap_[curr] = heap_[best];
			heap_[best] = old_parent;

			curr = best;
			child = m_ * curr + 1;
			best_found = false;
		}
		else { // no more swaps can be made
			break;
		}

	}

}


template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
	if (heap_.empty()){
		return true;
	}
	return false;
}


template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
	return heap_.size();
}


#endif

