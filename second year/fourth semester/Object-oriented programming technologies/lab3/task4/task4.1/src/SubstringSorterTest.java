import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;

public class SubstringSorterTest {

    @Test
    public void testCountSubstring() {
        String str = "hello world hello";
        String substr = "hello";
        int expectedCount = 2;

        int actualCount = SubstringSorter.countSubstring(str, substr);

        Assert.assertEquals(expectedCount, actualCount);
    }

    @Test
    public void testSortWordsBySubstringCount() {
        String str = "hello world hello";
        String substr = "hello";
        String[] words = str.split(" ");
        int[] counts = new int[words.length];
        for (int i = 0; i < words.length; i++) {
            counts[i] = SubstringSorter.countSubstring(words[i], substr);
        }
        String[] expectedSortedWords = {"world", "hello", "hello"};

        String[] actualSortedWords = SubstringSorter.sortWordsBySubstringCount(words, counts);

        Assert.assertArrayEquals(expectedSortedWords, actualSortedWords);
    }
}