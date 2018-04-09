class Queue {
    private int[] queue;
    private int maxSize;
    private int nElem;
    private int front;
    private int back;

    public Queue(int maxSize) {
        this.maxSize = maxSize;
        queue = new int[maxSize];
        back = -1;
        front = 0;
        nElem = 0;
    }
    public void push(int elem) {
        if (back == maxSize - 1) {
            back = -1;
        }

        queue[++back] = elem;
        nElem++;
    }
    public int pop() {
        int temp = queue[front++];

        if (front == maxSize) {
            front = 0;
        }
        nElem--;
        return temp;

    }
    public int peek() {
        return queue[front];
    }
    public boolean isEmpty() {
        return (nElem == 0);
    }
}