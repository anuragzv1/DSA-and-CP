import java.util.Scanner;

class Node<T> {
    T data;
    Node<T> next;

    Node(T data) {
        this.data = data;
    }
}

class LLinJava {

    private static Node<Integer> createLL(int n) {
        Scanner sc = new Scanner(System.in);
        int data = sc.nextInt();
        Node<Integer> head = new Node<Integer>(data);
        Node<Integer>tail = head;

        for(int i =1 ;i<n;i++){
            data = sc.nextInt();
            Node<Integer> newNode = new Node<Integer>(data);
            tail.next = newNode;
            tail = newNode;
        }

        sc.close();
        return head;
    }

    public static void printLL(Node<Integer> head){

        Node<Integer> temp = head;

        while(temp!=null){
            System.out.print(temp.data+" ");
            temp=temp.next;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of Nodes");
        int n = sc.nextInt();

        Node<Integer> head = createLL(n);

        printLL(head);
        sc.close();

    }
}
