#include <iostream>

#include <assert.h>

template <typename T>
class stack
{
public:
    stack()
    {
        idx = -1;
        stk = new T[MAX_SIZE];
    }

    ~stack()
    {
        delete[] stk;
    }

    void push(T e)
    {
        if (idx + 1 >= MAX_SIZE - 1)
        {
            std::cerr << "stack is full, cannot push" << std::endl;

            return;
        }

        stk[++idx] = e;
    }

    T pop()
    {
        assert(idx >= 0);

        return stk[idx--];
    }

    unsigned size()
    {
        return idx + 1;
    }

    static const int MAX_SIZE = 16;

private:
    T* stk;
    int idx;
};
