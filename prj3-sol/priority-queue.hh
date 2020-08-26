#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <cassert>

class Comparable
{
public:
    virtual int compare(const Comparable& other) const = 0;
};

template<class Comparable>
class priority_queue
{
public:
    priority_queue(bool reverse=false)
        : reverse(reverse) {}

    void push(Comparable elem)
    {
        heap.emplace_back(elem);

        make_heap_upwards(size() - 1);
    }

    Comparable pop()
    {
        assert(size() > 0 && "cannot pop from empty queue");

        Comparable ret = heap.at(0);

        heap[0] = heap.back();
        heap.pop_back();

        make_heap_downwards(0);

        return ret;
    }

    size_t size()
    {
        return heap.size();
    }

    bool empty()
    {
        return size() == 0;
    }
    
private:
    std::vector<Comparable> heap;
    bool reverse;

    size_t parent(size_t i) 
    { 
        assert(i > 0 && "you cannot find the parent of the root element");
        return (i - 1) / 2; 
    }

    size_t left(size_t i) 
    { 
        return 2*i + 1; 
    }

    size_t right(size_t i) 
    { 
        return 2*i + 2; 
    }

    void make_heap_downwards(size_t i)
    {
        size_t l = left(i);
        size_t r = right(i);

        auto compare = [this](const Comparable& left, const Comparable& right) -> bool
        {
            int res = left.compare(right);

            if (reverse)
                return res < 0;
            
            return res > 0;
        };

        size_t smallest_or_largest = i;

        if (l < size() && compare(heap[l], heap[i]))
            smallest_or_largest = l;

        if (r < size() && compare(heap[r], heap[smallest_or_largest]))
            smallest_or_largest = r;

        if (smallest_or_largest != i) {
            std::swap(heap[i], heap[smallest_or_largest]);
            make_heap_downwards(smallest_or_largest);
        }
    }

    void make_heap_upwards(size_t i)
    {
        if (i)
        {
            if ((!reverse && heap[parent(i)].compare(heap[i]) < 0) ||
                (reverse && heap[parent(i)].compare(heap[i]) > 0))
            {
                std::swap(heap[i], heap[parent(i)]);
                make_heap_upwards(parent(i));
            }
        }
    }
    
};
