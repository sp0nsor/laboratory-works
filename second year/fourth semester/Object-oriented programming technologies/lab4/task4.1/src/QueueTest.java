import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class QueueTest {
    private Queue<Integer> queue;

    @BeforeEach
    void setUp() {
        queue = new Queue<>(5);
    }

    @Test
    void testEnqueue() {
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);

        Assertions.assertEquals(1, queue.getQueueArray(0));
        Assertions.assertEquals(2, queue.getQueueArray(1));
        Assertions.assertEquals(3, queue.getQueueArray(2));
    }

    @Test
    void testDequeue() {
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);

        int item1 = queue.dequeue();
        int item2 = queue.dequeue();

        Assertions.assertEquals(1, item1);
        Assertions.assertEquals(2, item2);
        //Assertions.assertNull(queue.getQueueArray(0));
        ///Assertions.assertNull(queue.getQueueArray(1));
    }
    @Test
    void testIsEmpty() {
        Assertions.assertTrue(queue.isEmpty());

        queue.enqueue(1);

        Assertions.assertFalse(queue.isEmpty());
    }

    @Test
    void testIsFull() {
        Assertions.assertFalse(queue.isFull());

        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.enqueue(5);

        Assertions.assertTrue(queue.isFull());
    }
}