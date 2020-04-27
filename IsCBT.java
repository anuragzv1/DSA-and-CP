import java.util.*;

class treeNode<T>{
    T data;
    treeNode<T> left;
    treeNode<T> right;
    treeNode(T data){
        this.data = data;
        left = null;
        right = null;
    }
}

public class IsCBT {

    static treeNode<Integer> takeInput(){
        Scanner sc = new Scanner(System.in);
        int data = sc.nextInt();
        treeNode<Integer> root = new treeNode<Integer>(data);
        Queue<treeNode<Integer>> pendingNodes = new LinkedList<>();
        pendingNodes.add(root);
        while(!pendingNodes.isEmpty()){
            treeNode<Integer> front = pendingNodes.poll();
            int leftData = sc.nextInt();
            if(leftData != -1 ){
                front.left = new treeNode<Integer>(leftData);
                pendingNodes.add(front.left);
            }
            int rightData = sc.nextInt();
            if(rightData != -1 ){
                front.right = new treeNode<Integer>(rightData);
                pendingNodes.add(front.right);
            }
        }
        return root;
    }

    static void printTree(treeNode<Integer> root){
        if(root== null)return;

        printTree(root.left);
        System.out.print(root.data+" ");
        printTree(root.right);
    }
    public static void main(String[] args) {
        treeNode<Integer> root  = takeInput();

        // printTree(root);
        if(cbtCheck(root)==true)System.out.println("CBT");
        else System.out.println("Not CBT");

    }

    private static boolean cbtCheck(treeNode<Integer> root) {
        boolean endNodeEncountered = false;
        Queue<treeNode<Integer>>pending = new LinkedList<>();
        pending.add(root);
        while(pending.size()!=0){
            treeNode<Integer> front = pending.poll();
            if(front.left!=null){
            if(endNodeEncountered == true)return false;
            pending.add(front.left);
            }
            else{
                endNodeEncountered = true;
               // System.out.println("End node Encountered at "+front.data+"'s left'");
            } 

            if(front.right!=null){
            if(endNodeEncountered == true)return false;
                pending.add(front.right);
            }
            else{
                endNodeEncountered = true;
               // System.out.println("End node Encountered at "+front.data+"'s right");
            } 
        }
        return true;
    }
}