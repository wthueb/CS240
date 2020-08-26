#ifndef DLINK_SEQ_HH_
#define DLINK_SEQ_HH_

#include "seq.hh"

#include <cassert>

template <typename E> class DLinkSeqConstIter;

template <typename E>
class DLinkSeq : public Seq<E>
{
private:
    class Node
    {
    public:
        Node* prev;
        Node* next;

        const E value;

        Node(E value)
            : value(value) {}
    };

    Node* head;
    Node* tail;

    int num_items;
  
    friend class DLinkSeqConstIter<E>;

public:
    DLinkSeq()
        : head(nullptr), tail(nullptr), num_items(0) {}
  
    static SeqPtr<E> make()
    {
        return std::make_unique<DLinkSeq<E>>();
    }
    
    virtual ~DLinkSeq()
    {
        auto cur = this->head;

        while (cur)
        {
            auto next = cur->next;
            delete cur;
            cur = next;
        }
    }
  
    /** empty out the list */
    virtual void clear()
    {
        auto cur = this->head;

        while (cur)
        {
            auto next = cur->next;
            delete cur;
            cur = next;
        }

        this->head = nullptr;
        this->tail = nullptr;

        num_items = 0;
    }
  
    /** add item to the start of this seq. */
    virtual void unshift(const E& item)
    {
        auto new_item = new Node{ item };

        new_item->prev = nullptr;
        new_item->next = this->head;

        if (new_item->next)
            new_item->next->prev = new_item;
        else
            this->tail = new_item;

        this->head = new_item;

        ++num_items;
    }
    
    /** add item at the end of this seq. */
    virtual void push(const E& item)
    {
        auto new_item = new Node{ item };

        new_item->prev = this->tail;
        new_item->next = nullptr;

        if (new_item->prev)
            new_item->prev->next = new_item;
        else
            this->head = new_item;

        this->tail = new_item;

        ++num_items;
    }
    
    /** remove and return first item from this seq. 
     *  fails with failing assert() when this seq is empty.
     */
    virtual E shift()
    {
        assert(this->head && "shift on empty dlink seq");

        auto item = this->head;

        this->head = this->head->next;
        this->head->prev = nullptr;

        E val = item->value;

        delete item;

        --num_items;

        return val;
    }
    
    /** remove and return last item from this seq. 
     *  fails with failing assert() when this seq is empty.
     */
    virtual E pop()
    {
        assert(this->tail && "pop on empty array seq");

        auto item = this->tail;

        this->tail = this->tail->prev;
        this->tail->next = nullptr;

        E val = item->value;

        delete item;

        --num_items;

        return val;
    }
  
    /** return number of elements currently in this */
    virtual int size() const
    {
        return this->num_items;
    }
  
    /** Return an iterator initialized to start of this seq */
    virtual ConstIterPtr<E> cbegin() const
    {
        const auto const_node = static_cast<const Node*>(this->head);
        return std::make_unique<DLinkSeqConstIter<E>>(const_node);
    }
  
    /** Return an iterator initialized to end of this seq */
    virtual ConstIterPtr<E> cend() const
    {
        const auto const_node = static_cast<const Node*>(this->tail);
        return std::make_unique<DLinkSeqConstIter<E>>(const_node);
    }
};

template <typename E>
class DLinkSeqConstIter : public ConstIter<E>
{
public:
    DLinkSeqConstIter(const typename DLinkSeq<E>::Node* node)
        : node(node) {}
  
    /** pre-increment */
    virtual DLinkSeqConstIter& operator++()
    {
        this->node = this->node->next;
        return *this;
    }
  
    /** pre-decrement */
    virtual DLinkSeqConstIter& operator--()
    {
        this->node = this->node->prev;
        return *this;
    }
  
    /** return true iff this pointer is not "NULL" */
    virtual operator bool()
    {
        return this->node;
    }
  
    /** Return element this is pointing to */
    virtual const E& operator*()
    {
        return this->node->value;
    }
  
    /** Return pointer to element this is pointing to */
    virtual const E* operator->()
    {
        return &this->node->value;
    }

private:
    const typename DLinkSeq<E>::Node* node;
};

#endif //ifndef ARRAY_SEQ_HH_
