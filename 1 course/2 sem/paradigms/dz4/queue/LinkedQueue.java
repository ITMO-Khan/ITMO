package queue;


public class LinkedQueue extends AbstractQueue {
    private Node head, tail;

    public LinkedQueue() {
        head = tail = null;
        size = 0;
    }

    private static class Node {
        Object value;
        Node next;

        Node(Object value, Node next) {
            assert value != null;
            this.value = value;
            this.next = next;
        }
    }


    public void enqueueImpl(Object element) {
        if (size == 0) {
            tail = head = new Node(element, null);
        } else {
            Node newTail = new Node(element, null);
            tail.next = newTail;
            tail = newTail;
        }
    }

    public void dequeueImpl() {
        head = head.next;
    }

    public Object elementImpl() {
        return head.value;
    }

    public void clearImpl() {
        head = tail = null;
    }
}