//binary heap
// heapify, getmin, extractmin, decreasekey, insert, delete

#include<bits/stdc++.h>
using namespace std;

void swap(int* x, int* y)
{
    int temp = *x; 
    *x = *y; 
    *y = temp;
}
class minheap
{
    int capacity;
    int size;
    unique_ptr<int[]> array;

    public:
        minheap(int capacity);
        bool isempty()
        {
            return (size == 0);
        }
        bool isfull()
        {
            return (size == capacity);
        }
        int left(int i)
        {
            return (2 * i + 1);
        }
        int right(int i)
        {
            return (2 * i + 2);
        }
        int parent(int i)
        {
            return ((i - 1) / 2);
        }
//
        int getmin();
        int extractmin();
        void heapify(int i);
        void decreasekey(int i, int val);
        void insertkey(int val);
        void deletekey(int i);
};
minheap::minheap(int capacity)
    : capacity(capacity),
      size(0),
      array(new int[capacity]){};
//
int minheap::getmin()
{
    if(isempty())
    {
        return INT_MIN;
    }
    return array[0];
}
int minheap::extractmin()
{
    if(isempty())
    {
        return INT_MIN;
    }
    if(size==1)
    {
        size--;
        return array[0];
    }
    int temp = array[0];
    array[0] = array[--size];
    heapify(0);
    return temp;
}
void minheap::heapify(int i)
{
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if(l<size && array[i]>array[l])
        smallest = l;
    if(r<size && array[smallest]>array[r])
        smallest = r;
    if(smallest != i)
    {
        swap(&array[smallest], &array[i]);
        heapify(smallest);
    }
}
void minheap::decreasekey(int i, int val)
    {
    array[i] = val;

    while(parent(i) >= 0 && array[i]<array[parent(i)])
    {
        swap(&array[i], &array[parent(i)]);
        i = parent(i);
    }
}
void minheap::insertkey(int val)
{
    if(isfull())
    {
        cout << "overflow :/" << endl;
        return;
    }
    array[size] = val;
    int i = size;
    size++;
    while (parent(i) >= 0 && array[i] < array[parent(i)])
    {
        swap(&array[i], &array[parent(i)]);
        i = parent(i);
    }
}
void minheap::deletekey(int i)
{
    array[i] = INT_MIN;
    while(parent(i) >= 0 && array[i]<array[parent(i)])
    {
        swap(&array[i], &array[parent(i)]);
        i = parent(i);
    }
    extractmin();
}

int main()
{
    minheap h(7);
    h.insertkey(1); 
    h.insertkey(2);
    h.insertkey(3);
    h.insertkey(4); 
    h.insertkey(5); 
    h.insertkey(6); 
    h.insertkey(7);
    h.insertkey(8);
    h.insertkey(8);
    h.insertkey(8);
    h.insertkey(8);
    h.insertkey(8);
    h.insertkey(8);
    h.insertkey(8);
    //cout << h.extractmin() << " "; 
    //cout << h.getmin() << " "; 
    //h.decreasekey(2, 1); 
    //cout << h.getmin(); 

}
