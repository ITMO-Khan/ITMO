package queue;

import java.util.Arrays;

import queue.Copiable;
import queue.Queue;

public class ArrayQueue extends AbstractQueue {
    private int head, tail;
    private Object elements[];

    public ArrayQueue() {
        elements = new Object[10];
        tail = head = size = 0;
    }

    private void ensureCapacity(int capacity) {
        if (size < capacity) {
            return;
        }
        Object buffer[] = new Object[elements.length * 2];
        System.arraycopy(elements, head, buffer, head + elements.length, elements.length - head);
        System.arraycopy(elements, 0, buffer, 0, tail);
        head += elements.length;
        elements = buffer;
    }

    public void enqueueImpl(Object element) {
        EnsureCapacity(elements.length);
        elements[tail] = element;
        tail = (tail + 1) % elements.length;
    }

    public void dequeueImpl() {
        head = (head + 1) % elements.length;
    }

    public Object elementImpl() {
        return elements[head];
    }

    public void clearImpl() {
        head = tail = 0;
    }
}


