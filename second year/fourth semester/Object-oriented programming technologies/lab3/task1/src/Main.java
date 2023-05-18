//"apple", "banana", "cat", "dance", "crane", "bandana"

import java.util.Arrays;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        String _substr = "an";
        int[] counts = new int [args.length];
        System.out.print("массив до сортировки: ");
        System.out.println(Arrays.toString(args));
        for (int i  = 0; i < args.length; i++){
            counts[i] = countSubstring(args[i],_substr);
        }
        for (int i = 0; i < counts.length - 1; i++){
            for(int j = i + 1; j < counts.length; j++){
                if (counts[i] > counts[j]){
                    int tempIdx = counts[i];
                    counts[i] = counts[j];
                    counts[j] = tempIdx;
                    String tempString = args[i];
                    args[i] = args[j];
                    args[j] = tempString;
                }
            }
        }
        System.out.print("массив после первой сортировки: ");
        System.out.println(Arrays.toString(args));
        SortByLastCount(args, _substr);
        System.out.print("массив после второй сортировки: ");
        System.out.println(Arrays.toString(args));
    }
    public static int countSubstring(String _str, String _substr){
        int count = 0;
        int idx = _str.indexOf(_substr);
        while (idx != -1){
            count++;
            idx = _str.indexOf(_substr, idx + 1);
        }
        return count;
    }
    public static String[] SortByLastCount(String[] args, String _substr){
        Arrays.sort(args, Comparator.comparingInt(s -> s.lastIndexOf(_substr)));
        return args;
    }
}