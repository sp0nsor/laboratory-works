package by.vsu.mf.ai.ssd.strings;

public class ExclamationMarkJob implements Job {
    //@Override
    public void perform(StringBuilder str) {
        int count = 1;
        for (int i = 0; i < str.length(); i++) {
            char currentChar = str.charAt(i);
            if (currentChar == '!') {
                str.insert(i + 1, count);
                count++;
                i++;
            }
        }
    }
}
