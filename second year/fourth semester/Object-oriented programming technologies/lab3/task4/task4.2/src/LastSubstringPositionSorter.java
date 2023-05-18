public class LastSubstringPositionSorter {
    public static void main(String[] args) {
        String str = "hello world hello hello world";
        String substr = "hello";
        String[] words = str.split(" ");

        mergeSortByLastSubstringPosition(words, substr);

        System.out.println(String.join(" ", words));
    }

    public static void mergeSortByLastSubstringPosition(String[] words, String substr) {
        if (words.length <= 1) {
            return; // Базовый случай: если массив пустой или содержит только один элемент, то он уже отсортирован
        }

        int mid = words.length / 2;
        String[] left = new String[mid];
        String[] right = new String[words.length - mid];

        // Разделение массива на две половины
        System.arraycopy(words, 0, left, 0, mid);
        System.arraycopy(words, mid, right, 0, words.length - mid);

        // Рекурсивная сортировка каждой половины
        mergeSortByLastSubstringPosition(left, substr);
        mergeSortByLastSubstringPosition(right, substr);

        // Объединение отсортированных половин в один массив
        merge(words, left, right, substr);
    }

    private static void merge(String[] words, String[] left, String[] right, String substr) {
        int leftIndex = 0;
        int rightIndex = 0;
        int currentIndex = 0;

        // Сравниваем позиции последнего вхождения подстроки в каждом слове и объединяем массивы
        while (leftIndex < left.length && rightIndex < right.length) {
            int leftLastIndex = findLastSubstringPosition(left[leftIndex], substr);
            int rightLastIndex = findLastSubstringPosition(right[rightIndex], substr);

            if (leftLastIndex > rightLastIndex) {
                words[currentIndex] = left[leftIndex];
                leftIndex++;
            } else {
                words[currentIndex] = right[rightIndex];
                rightIndex++;
            }
            currentIndex++;
        }

        // Добавляем оставшиеся элементы из левой половины
        while (leftIndex < left.length) {
            words[currentIndex] = left[leftIndex];
            leftIndex++;
            currentIndex++;
        }

        // Добавляем оставшиеся элементы из правой половины
        while (rightIndex < right.length) {
            words[currentIndex] = right[rightIndex];
            rightIndex++;
            currentIndex++;
        }
    }

    public static int findLastSubstringPosition(String str, String substr) {
        int lastIndex = str.lastIndexOf(substr);
        return lastIndex != -1 ? lastIndex : Integer.MIN_VALUE; // Если подстрока не найдена, возвращаем минимальное значение
    }
}