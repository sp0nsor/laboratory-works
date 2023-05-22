public class Stack<T> {

    private Node<T> top; // вершина стека

    private static class Node<T> {
        private T data;
        private Node<T> next;

        public Node(T data) {
            this.data = data;
        }
    }

    public boolean isEmpty() {
        return top == null;
    }

    public void push(T data) {
        Node<T> newNode = new Node<>(data);
        newNode.next = top;
        top = newNode;
        System.out.println("Элемент " + newNode + " добавлен в стек");
    }

    public T pop() {
        if (isEmpty()) {
            throw new NullPointerException("Стек пуст");
        }
        T data = top.data;
        top = top.next;
        return data;
    }

    public T peek() {
        if (isEmpty()) {
            throw new NullPointerException("Стек пуст");
        }
        return top.data;
    }
}
