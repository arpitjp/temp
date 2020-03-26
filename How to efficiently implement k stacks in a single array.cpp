//k stacks push, pop
#include<bits/stdc++.h>
using namespace std;

class kstack {
    int k;
    int sz;
    int n;
    int fre;
    unique_ptr<int[]> array;
    unique_ptr<int[]> top;
    unique_ptr<int[]> next;

    public:
    kstack(int k, int n);
    void push(int s, int val);
    void pop(int s);
    bool isfull();
    bool isempty(int s);
};

kstack::kstack(int k, int n)
    : k(k),
      sz(0),
      n(n),
      fre(0),
      array(new int[n]),
      next(new int[n]),
      top(new int[k])
      {
        for (int i = 0; i < n-1; i++)
            next[i] = i + 1;
        next[n - 1] = -1;
        for (int i = 0; i < k; i++)
            top[i] = -1;
      };
//

bool kstack::isfull()
{
    return (fre == -1);
}

bool kstack::isempty(int s)
{
    return (top[s] == -1);
}

void kstack::push(int val, int s)
{
    if(isfull())
    {
        cout << "overflow :/" << endl;
        return;
    }
    int temp = next[fre];
    array[fre] = val;
    next[fre] = top[s];
    top[s] = fre;
    fre = temp;
    cout << "successfully puhed\t" << val << "\tin\t" << s << endl;
}

void kstack::pop(int s)
{
    if(isempty(s))
    {
        cout << "underflow :/" << endl;
        return;
    }
    int temp = top[s];
    top[s] = next[temp];
    next[temp] = fre;
    fre = temp;
    cout << "successfully popped\t" << array[temp] << "\tfrom\t" << s << endl;
}

int main()
{
    int k = 3, n = 10;
    kstack ks(k, n);

    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);

    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    ks.pop(2);
    ks.pop(1);
    ks.pop(0);

    return 0;
}
