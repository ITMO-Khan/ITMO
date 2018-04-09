package queue;

public abstract class AbstractQueue implements Queue {
    protected abstract Object elementImpl();

    protected abstract void dequeueImpl();

    protected abstract void enqueueImpl(Object element);

    protected abstract void clearImpl();

    protected int size = 0;

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public Object element() {
        assert size > 0;
        return elementImpl();
    }

    public Object dequeue() {
        Object el = element();
        size--;
        dequeueImpl();
        return el;
    }

    public void enqueue(Object element) {
        assert element != null;
        enqueueImpl(element);
        size++;
    }

    public void clear() {
        size = 0;
        clearImpl();
    }

    //общий метод для двух списка и массива
    public Object[] toArray() {
        Object[] array = new Object[size];
        for (int i = 0; i < size; i++) {
            Object element = dequeue();
            array[i] = element;
            enqueue(element);
        }
        return array;
    }
}
