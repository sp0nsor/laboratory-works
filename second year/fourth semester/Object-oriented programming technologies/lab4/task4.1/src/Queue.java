public class Queue<T> {

    private int front; // указатель на головной элемент
    private int rear; // указатель на хвостовой элемент
    private int capacity; // емкость очереди
    private T[] queueArray; // массив для хранения элементов очереди

    public Queue(int size) {
        capacity = size;
        queueArray = (T[]) new Object[capacity];
        front = -1;
        rear = -1;
    }

    public T getQueueArray(int i) {
        return queueArray[i];
    }

    // Метод проверки очереди на пустоту
    public boolean isEmpty() {
        return front == -1;
    }

    // Метод проверки очереди на заполненность
    public boolean isFull() {
        return rear == capacity - 1;
    }

    // Метод добавления элемента в очередь
    public void enqueue(T item) {
        if (isFull()) {
            System.out.println("Очередь переполнена");
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            queueArray[rear] = item;
            System.out.println("Элемент " + item + " добавлен в очередь");
        }
    }

    // Метод удаления элемента из очереди
    public T dequeue() {
        T item;
        if (isEmpty()) {
            System.out.println("Очередь пуста");
            return null;
        } else {
            item = queueArray[front];
            if (front >= rear) {
                front = -1;
                rear = -1;
            } else {
                front++;
            }
            System.out.println("Элемент " + item + " удален из очереди");
            return item;
        }
    }
}
