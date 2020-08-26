#ifndef OPS_HH_
#define OPS_HH_

/** sorting operations */
class Ops {
public:

  /** return < 0, == 0, > 0 if a < b, a == b, a > b */
  virtual int compare(int a, int b);
  
  /** swap a[i] and a[j] */
  virtual void swap(int a[], int i, int j);
};


class MonitorOps : public Ops {
public:
    int num_compares = 0;
    int num_swaps = 0;

    virtual int compare(int a, int b)
    {
        num_compares++;

        return this->Ops::compare(a, b);
    }

    virtual void swap(int a[], int i, int j)
    {
        num_swaps++;

        this->Ops::swap(a, i, j);
    }
};


#endif //ifndef OPS_HH_
