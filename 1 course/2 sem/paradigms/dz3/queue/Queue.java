package queue;

public interface Queue {
    void enqueue(Object element);
    int size();
    boolean isEmpty();
    Object dequeue();
    Object[] toArray();
    Object remove();

}
