//import java.util.Scanner;

class stackEmptyException extends Exception {
    private static final long serialVersionUID = 1L;
}

class stackFullException extends Exception {
    private static final long serialVersionUID = 1L;
}

class queueUsingArrays {
    private int data[];
    private int front;
    private int rear;
    private int size;

    queueUsingArrays(int s) {
        data = new int[s];
        front = -1;
        rear = -1;
        size = 0;
    }

    queueUsingArrays() {
        data = new int[5];
        front = -1;
        rear = -1;
        size = 0;
    }

    int size() {
        return size;
    }

    boolean isEmpty() {
        return size == 0;
    }

    int dequeue() throws stackEmptyException {
        if (size == 0) {
            throw new stackEmptyException();
        }
        int ele = data[front];
        front++;
        size--;
        if (size==0) {

            front = rear = -1;
        }

        return ele;
    }

    void enqueue(int ele) throws stackFullException {
        if (size == data.length) {
            throw new stackFullException();
        }
        if (size == 0) {
            front = 0;
        }
        size++;
        rear++;
        data[rear] = ele;
    }

    int top() throws stackEmptyException {
        if (size == 0)
            throw new stackEmptyException();

        return data[front];

    }

}

class queueUsingArraysUse {
    public static void main(String[] args) throws stackFullException, stackEmptyException {
        queueUsingArrays q = new queueUsingArrays(5);

        q.enqueue(7);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.enqueue(5);

        q.dequeue();
        while(!q.isEmpty()){
        System.out.println(q.dequeue() +" " + q.size());
        }
    }
}