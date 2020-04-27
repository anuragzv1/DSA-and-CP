import java.util.*;
public class priorityQueueUse {
    public static void main(String[] args) throws priorityQueueEmptyException {
        priorityQueue<String> queue = new priorityQueue<>();
        queue.insert(new Element<String>("Anurag" , 100));
        queue.insert(new Element<String>("aditi" , 94));
        queue.insert(new Element<String>("karan" , 95));
        queue.insert(new Element<String>("Devyani" , 92));
        queue.insert(new Element<String>("vineet" , 94));
        

        while(queue.size()!=0){
            System.out.println(queue.getMin());
            queue.removeMin();
        }
    }
}