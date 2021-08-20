#include<bits/stdc++.h>
using namespace std;

/*
    Max heap
*/
class Heap{
    private:
        int* data;
        int size;
        int capacity;
    public:
        Heap(): data(NULL), size(0), capacity(0) {}
        ~Heap(){}
        void copyFromArray(int* arr, int n) {
            this->size = n;
            this->capacity = n;
            this->data = new int[this->size];
            for (int i = 0; i < this->size; i++)
                this->data[i] = arr[i];
        }
        void print() {
            for (int i = 0; i < this->size; i++) {
                cout << this->data[i] << " ";
            }
        }
        void swap(int &a, int &b){
            int x = a;
            a = b;
            b = x;
        }
        
        void ensureCapacity(int newSize){
            if(newSize >= this->capacity){
                this->capacity += 10;
                int* newData = new int[this->capacity];
                for(int i=0;i<this->size;i++)
                    newData[i] = data[i];
                this->data = newData;
                newData = NULL;
            }
        }

        // reHeap Up from index to root
        void reHeapUp(int index){
            if(index>0){
                int parent = (index-1)/2;
                if(this->data[parent] < this->data[index])
                    swap(data[parent], data[index]);
                reHeapUp(parent);
            }
        }

        // reHeap Down from index 
        void reHeapDown(int index){
            int leftChild = index*2+1;
            if(leftChild >= this->size)
                return;
            int rightChild = index*2+2;
            if(rightChild >= this->size){
                if(data[index] < data[leftChild])
                    swap(data[index], data[leftChild]);
            }
            else{
                int child = data[leftChild] > data[rightChild] ? leftChild : rightChild;
                if(data[index] < data[child])
                    swap(data[index], data[child]);
                reHeapDown(child);
            }
        }

        //  insert new node
        void insert(int value){
            this->ensureCapacity(this->size +1);
            data[this->size] = value;
            this->size++;
            reHeapUp(this->size-1);
        }

        //  give an array -> build max heap
        void build(int *arr, int n){    
            this->copyFromArray(arr, n);
            int lastNonLeaf = n/2 -1;
            while(lastNonLeaf>=0){
                reHeapDown(lastNonLeaf);
                lastNonLeaf--;
            }
        }

        //  remove root from heap
        int remove(){
            if(this->size > 0){
                int removeElement = data[0];
                data[0] = data[size-1];
                size--;
                reHeapDown(0);
                return removeElement;
            }
            throw "Empty heap";
        }

        /*
            operator heap
        */
        //  peak : return root 
        int peak(){
            return data[0];
        }
 
        bool isEmpty(){
            return size==0? true : false;
        }

        int getSize(){
            return this->size;
        }

        bool contains(int item){
            for(int i=0;i<size;i++)
                if(data[i]==item)
                    return true;
            return false;
        }

        bool pop(){
            if(this->size > 0){
                data[0] = data[size-1];
                size--;
                reHeapDown(0);
                return true;
            }
            return false;    
        }
        //  return index of element with value
        int indexOf(int item){
            for(int i=0;i<size;i++)
                if(data[i]==item)
                    return i;
            return -1;
        }

        // remove a element with value
        /*
            pushing last element to location have key value in array
            => reHeapDown in that location    
        */
        bool removeItem(int item){
            int index = this->indexOf(item);
            if(index==-1)   return false;
            this->data[index] = this->data[size-1];
            size--;
            reHeapDown(index);
            return true;
        }

        //  clear all element on heap
        void clear(){
            delete data;
            this->capacity = 10;
            this->size = 0;
            data = new int[capacity];
        }
};


class Sorting {
    public:
        //not include end
        static void printArray(int* start, int* end){
            int size = end-start;
            for(int i=0;i<size-1;i++)
                cout<< start[i] << " ";
            cout<<start[size-1]<<endl;
        }
        
        static void heapSort(int *start, int* end){
            int size = end-start;
            Heap *h = new Heap();
            h->copyFromArray(start, size);
            h->reHeapDown(0);
            while(!h->isEmpty()){
                start[size-1] = h->remove();
                size--;
            }
            Sorting::printArray(start, end);
        }
};

int main(){
    Heap maxHeap;
int arr[] = {42,35,30,15,20,21,18,3,7,14};
for (int i = 0; i < 10; i++)
    maxHeap.insert(arr[i]);
maxHeap.removeItem(42);
maxHeap.removeItem(35);
maxHeap.removeItem(30);
maxHeap.clear();
maxHeap.print();

    return 0;
}