import java.util.Arrays;

public class SubstringSorter {
    public static void main(String[] args) {
        String str = "hello world hello";
        String substr = "hello";
        String[] words = str.split(" ");

        int[] counts = new int[words.length];
        for (int i = 0; i < words.length; i++) {
            counts[i] = countSubstring(words[i], substr);
        }

        String[] sortedWords = sortWordsBySubstringCount(words, counts);
        System.out.println(Arrays.toString(sortedWords));
    }

    public static int countSubstring(String str, String substr) {
        int lastIndex = 0;
        int count = 0;
        while (lastIndex != -1) {
            lastIndex = str.indexOf(substr, lastIndex);
            if (lastIndex != -1) {
                count++;
                lastIndex += substr.length();
            }
        }
        return count;
    }

    public static String[] sortWordsBySubstringCount(String[] words, int[] counts) {
        int n = words.length;
        String[] sortedWords = Arrays.copyOf(words, n);

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (counts[j] < counts[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(sortedWords, i, minIndex);
                swap(counts, i, minIndex);
            }
        }

        return sortedWords;
    }

    private static void swap(String[] array, int i, int j) {
        String temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}