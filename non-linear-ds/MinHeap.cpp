/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on June 9, 2019, 11:33 AM
 */

#include <iostream>
#include <climits>
using namespace std;

class MinHeap 
{
    int *harr;  //pointer to heap array
    int capacity; //size of the array
    int heap_size; //current size of the heap
    
public : 
    MinHeap(int capacity);
    void insertElement(int a);  
    int parentOf(int a){ return ((a-1)/2) ;}
    void printHeap()
    {
        for (int i=0;i<heap_size;i++)
        {
         cout<<harr[i]<<",";   
        }
        cout<<"\n";
    }
        //Returns the left child index
        int left(int i)
        { 
            return (2*i+1);
        }
        
        //Returns the right child index
        int right(int i)
        { 
            return (2*i+2);
        }
        
        //Extract the minimum element or the root
        int extractRoot();
        void MinHeapify(int i);
        //Decreases value at index i to val
        //assumption that val is less than the original value
        void decreaseKey(int i,int val);
        
        //Returns the value at root
        int getRootKey(){ return harr[0];}
        
        //delete key at index i
        void deleteKey(int i);
    
    };
    void MinHeap :: deleteKey(int i)
    {
        // Initialse the key with value -infinity
        harr[i] = INT_MIN;
        
        //Retain the min heap property - this will get the root to the top
       while(i!=0 && harr[parentOf(i)]>harr[i])
        {
            int temp = harr[i];
            harr[i] = harr[parentOf(i)];
            harr[parentOf(i)]= temp;
            i=parentOf(i);
        }
        
        //Extract the root now
        extractRoot();
    }
    void MinHeap :: decreaseKey(int i,int val)
    {
        harr[i]=val;
        // MinHeapify(i) - is only for the root, since here value decrease, here children do not get affected
        //But the parent may get affected
        
        //In this method, we traverse from bottom to up
        //In Heapify we traverse from up to bottom
        
        while(i!=0 && harr[parentOf(i)]>harr[i])
        {
            int temp = harr[i];
            harr[i] = harr[parentOf(i)];
            harr[parentOf(i)]= temp;
            i=parentOf(i);
        }
    }
    int MinHeap :: extractRoot()
   {
        if(heap_size <= 0)
        {
            return INT_MAX;
        }
        
        if(heap_size == 1)
        {
            int root = harr[0];
            heap_size--;
            return root;
            
        }
    
        int root = harr[0];
        harr[0]=harr[heap_size -1];
        heap_size--;
        MinHeapify(0);
        return root;
   }
    void MinHeap :: MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest =i;
        
        //left function just returns us the index of the left child, 
        //it does not verify if the left child even exists, that's why we check if it is less than the heap size
        if(l <heap_size && harr[l]<harr[i])
        {
            smallest = l;
        }
        if(r <heap_size && harr[r]<harr[smallest])
        {
            smallest = r;
        }
        if(smallest!=i)
        {
            int temp = harr[i];
            harr[i]=harr[smallest];
            harr[smallest]=temp;
            MinHeapify(smallest);
        }
        
    }
MinHeap :: MinHeap(int cap)
{
    heap_size=0;
    capacity = cap;
    harr = new int[cap]; 
}


void MinHeap :: insertElement(int a)
{
    int temp;
    if(capacity == heap_size)
    {
        cout<<"Overflowed heap ";
        return ;
    }


    harr[heap_size]=a;
    int i=heap_size;
    heap_size = heap_size+1;
    // Fixing the min heap property 
    while(i!=0 && harr[parentOf(i)]>harr[i])
    {
       
       temp = harr[i];
       harr[i]= harr[parentOf(i)];
       harr[parentOf(i)] = temp;
       
       i = parentOf(i);
      
    }
}

int main() {
    cout<<INT_MIN;
    MinHeap h (8);
    h.insertElement(10); 
    h.insertElement(9);  
    h.insertElement(8); 
    h.insertElement(11); 
    h.insertElement(7); 
    h.insertElement(15); 
    h.insertElement(5);
    h.insertElement(12);
    h.printHeap();
    h.deleteKey(2);
    h.printHeap();
    int a = h.extractRoot();
    cout<<"Root extracted is "<<a<<endl;
    h.printHeap();
    h.decreaseKey(5,0);
    h.printHeap();
    cout<<"Root is "<<h.getRootKey()<<endl;
     h.deleteKey(4);
     h.printHeap();
    
}

