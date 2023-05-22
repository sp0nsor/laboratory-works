import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class StackTest {
    private Stack<Integer> stack;

    @BeforeEach
    void setUp() {
        stack = new Stack<>();
    }

    @Test
    void testPush() {
        stack.push(1);
        stack.push(2);
        stack.push(3);

        Assertions.assertEquals(3, stack.peek());
    }

    @Test
    void testPop() {
        stack.push(1);
        stack.push(2);
        stack.push(3);

        int item1 = stack.pop();
        int item2 = stack.pop();

        Assertions.assertEquals(3, item1);
        Assertions.assertEquals(2, item2);
        Assertions.assertEquals(1, stack.peek());
    }

    @Test
    void testIsEmpty() {
        Assertions.assertTrue(stack.isEmpty());

        stack.push(1);

        Assertions.assertFalse(stack.isEmpty());
    }

    @Test
    void testPeek() {
        stack.push(1);
        stack.push(2);
        stack.push(3);

        Assertions.assertEquals(3, stack.peek());

        stack.pop();

        Assertions.assertEquals(2, stack.peek());
    }
}