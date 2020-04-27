import java.util.*;
class Element<T>{
    T data;
    int priority;
    Element(T data , int priority){
        this.data = data;
        this.priority = priority;
    }
}

public class priorityQueue <T>{
    ArrayList<Element<T>> heap;

    priorityQueue(){
        heap = new ArrayList<>();
    }


    void insert(Element<T> el){
        heap.add(el);
        int child = heap.size()-1;
        while(child >0){
            if(heap.get(child).priority < heap.get((child-1)/2).priority){
                Element<T> temp = heap.get(child);
                heap.set(child, heap.get((child-1)/2));
                heap.set((child-1)/2 , temp);
            }
            child = (child-1)/2;
        }
    }

    boolean isEmpty(){
        if(heap.size()==0)return true;
        else return false;
    }

    int size(){
        return heap.size();
    }

    T getMin() throws priorityQueueEmptyException {
        if(heap.size()==0) throw new priorityQueueEmptyException();
        return heap.get(0).data;
    }

    void removeMin() throws priorityQueueEmptyException {
        if(heap.size()==0) throw new priorityQueueEmptyException();
        Element<T> last = heap.remove(heap.size()-1);
        if(heap.size()==0)return;
        heap.set(0, last);
        int parentIndex = 0;
        int leftChild = 2*parentIndex+1;
        int rightChild = 2*parentIndex+2;
        while(leftChild<heap.size()){
            int newIndex = -1;
            Element<T> newValue = heap.get(parentIndex);
            if(heap.get(leftChild).priority < newValue.priority){
                newIndex = leftChild;
                newValue = heap.get(leftChild);
            }
            if(rightChild <heap.size() && heap.get(rightChild).priority <newValue.priority){
                newIndex = rightChild;
                newValue = heap.get(rightChild);
            }
            if(newIndex == -1)break;
            Element<T> temp = heap.get(parentIndex);
            heap.set(parentIndex , newValue);
            heap.set(newIndex , temp);
            parentIndex = newIndex;
            leftChild = 2*parentIndex+1;
            rightChild = 2*parentIndex+2;
        }

    }
}