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

  void tickle_down(int i);
  void tickle_up(int i);

private:
  /// Add whatever helper functions and data members you need below

    std::vector<T> heap;
    int m_;
    PComparator c_;

};


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Add implementation of member functions here////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
: m_(m), c_(c)
{}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
    if(empty())
    {
        throw std::underflow_error("Heap::top(): empty Heap");
    }

    return heap[0];
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
    if (empty())
    {
        throw std::underflow_error("Heap::pop(): empty Heap");
    }

    std::swap(heap[size() - 1], heap[0]);
    heap.pop_back();

    // Tickle down
    tickle_down(0);
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
    heap.push_back(item);
    tickle_up(size() - 1);
}

// do tickle down algorithm
template <typename T, typename PComparator>
void Heap<T, PComparator>::tickle_down(int index)
{
    int smallerChild = m_ * index + 1;

    if (index == (size() - 1) || smallerChild >= size()) return;

    // find child that passes c_ among other m children

    for (int i = 2; i <= m_; i++) // 1, 2, 3 ... m
    {
        if (m_ * index + i < size() && c_(heap[m_ * index + i], (heap[smallerChild])))
        {
            smallerChild = m_ * index + i;
        }
    }

    if (c_(heap[smallerChild], heap[index]))
    {
        std::swap(heap[smallerChild], heap[index]);
        tickle_down(smallerChild);
    }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::tickle_up(int index)
{
    int parent = (index - 1) / m_;
    while (parent >= 0 && c_(heap[index], heap[parent]))
    {
        std::swap(heap[parent], heap[index]);
        index = parent;
        parent = (index - 1) / m_;
    }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
    return heap.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
    return heap.size();
}
#endif

