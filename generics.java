import java.util.*;

class LinkedListNode<T>{
    T data;
    LinkedListNode<T> next;
    LinkedListNode(T data){
        this.data = data;
    }
}


class generics{

    static void printLL(LinkedListNode<Integer> head){
        while(head!= null){
            System.out.print(head.data+" ");
            head = head.next;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedListNode<Integer> head = null;
        LinkedListNode<Integer> tail = null;
        
        int data;
        data = sc.nextInt();
        while(data!=-1){
            LinkedListNode<Integer> newNode = new LinkedListNode<>(data);
            if(head == null){
                head = newNode;
                tail = newNode;
            }
            else{
                tail.next = newNode;
                tail = newNode;
            }
            data = sc.nextInt();
        }
        printLL(head);
        sc.close();
    }
}
