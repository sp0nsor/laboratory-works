import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;

public class LastSubstringPositionSorterTest {

    @Test
    public void testFindLastSubstringPosition() {
        String str = "hello world hello hello world";
        String substr = "hello";
        int expectedLastIndex = 18;

        int actualLastIndex = LastSubstringPositionSorter.findLastSubstringPosition(str, substr);

        Assert.assertEquals(expectedLastIndex, actualLastIndex);
    }

    @Test
    public void testMergeSortByLastSubstringPosition() {
        String str = "hello world hello hello world";
        String substr = "world";
        String[] words = str.split(" ");
        String[] expectedSortedWords = {"world", "world", "hello", "hello", "hello"};

        LastSubstringPositionSorter.mergeSortByLastSubstringPosition(words, substr);

        Assert.assertArrayEquals(expectedSortedWords, words);
    }
}