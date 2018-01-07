#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T>
class TPQueue {
private:
    T*      arr;
    int  cnt;
    int  mem;
public:

    TPQueue(void): arr(NULL), cnt(0), mem(16){}
    /*~TPQueue() {
        this->clear();
    }*/


public:

    bool push(const T& val) {
        int  index, parent;
        T tmp;
        if(! this->_alloc())
            return false;
        arr[cnt] = val;
//        cout << arr[cnt] << " ";
        index = cnt;
        if (! index)
            parent = 0;
        else
            parent = (index - 1) >> 1;

        while((index > 0) && ! (arr[parent] >= arr[index])) {
            tmp    = arr[index];
            arr[index] = arr[parent];
            arr[parent] = tmp;
            index = parent--;
            if(! index)
                break;
            parent >>= 1;
        }

        ++cnt;
        return true;
    }

    int  pop(void) {
        int top;
        if(cnt >= 1) {
            top = arr[0];
            arr[0] = arr[--cnt];
            this->heapify(0);
            return top;
        } else
            cnt = 0;
    }

    bool empty(void) const { return (! cnt); }


    /*void clear(void) {
        delete[] arr;
        arr = NULL;
        cnt = 0;
        mem = 16;
    }*/

private:

    bool _alloc(void) {
        int tmem;
        T* tmp;

        if(arr == NULL) {
            arr = new T[mem];
            if(arr == NULL)
                return false;
        }

        if((cnt + 1) >= mem) {
            tmem = cnt*2;
            tmp  = new T[tmem];
            /*if(tmp == NULL)
                return false;*/
            for(int i = 0; i < cnt; ++i)
                tmp[i] = arr[i];
            delete[] arr;
            arr = tmp;
            mem = tmem;
        }
        return true;
    }

    void  heapify(int index) {
        int l, r, bigest;
        T  tmp;

        for(;;){
            l = (index << 1) + 1;
            r = (index << 1) + 2;

            if((l < cnt) && (arr[l] >= arr[index]))
                bigest = l;
            else
                bigest = index;

            if((r < cnt) && (arr[r] >= arr[bigest]))
                bigest = r;

            if(bigest != index) {
                tmp = arr[index];
                arr[index] = arr[bigest];
                arr[bigest]   = tmp;
                index = bigest;
            } else
                break;
        }
    }
};



int main(void){
    TPQueue<int> pq;

    for(int i = 0; i < 3; ++i)
        pq.push(i);

    while(! pq.empty()){
        cout << pq.pop() << " ";//printf("%d ", pq.pop());
    }
    return 0;
}
