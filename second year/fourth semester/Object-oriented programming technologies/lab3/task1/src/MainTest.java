import org.junit.Test;
import static org.junit.Assert.*;

public class MainTest {

    @Test
    public void testCountSubstring() {
        String str = "banana";
        String substr = "an";
        int count = Main.countSubstring(str, substr);
        assertEquals(2, count);

        str = "abcdabcd";
        substr = "cd";
        count = Main.countSubstring(str, substr);
        assertEquals(2, count);

        str = "aaaa";
        substr = "aa";
        count = Main.countSubstring(str, substr);
        assertEquals(3, count);

        str = "abcde";
        substr = "fg";
        count = Main.countSubstring(str, substr);
        assertEquals(0, count);
    }

    @Test
    public void testSortByLastCountEmptyArray() {
        String[] strings = {};
        String[] expected = {};
        String substring = "an";

        String[] result = Main.SortByLastCount(strings, substring);

        assertArrayEquals(expected, result);
    }

    @Test
    public void testSortByLastCountNoSubstring() {
        String[] strings = {"banana", "apple", "orange", "ananas", "pineapple"};
        String[] expected = {"banana", "apple", "orange", "ananas", "pineapple"};
        String substring = "zzz";

        String[] result = Main.SortByLastCount(strings, substring);

        assertArrayEquals(expected, result);
    }
/*
    @Test
    public void testSortByLastCount() {
        String[] strings = {"banana", "apple", "orange", "ananas", "pineapple"};
        String[] expected = {"orange", "apple", "banana", "pineapple", "ananas"};
        String substring = "an";

        String[] result = Main.SortByLastCount(strings, substring);

        assertArrayEquals(expected, result);
    }
*/

}