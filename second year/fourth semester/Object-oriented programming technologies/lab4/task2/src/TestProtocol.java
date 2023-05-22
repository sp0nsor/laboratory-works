import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class TestProtocol {
    private static final String CSV_FILE_PATH = "D:\\laboratory-works\\second year\\fourth semester\\Object-oriented programming technologies\\lab4\\task2\\src\\file.csv";

    public static void main(String[] args) {
        // Чтение данных из CSV-файла
        List<TestResult> testResults = readTestDataFromCSV(CSV_FILE_PATH);

        // Заданная дата и дисциплина для формирования протокола
        String desiredDate = "2023-05-18";
        String desiredDiscipline = "Компьютерщик";

        // Формирование протокола тестирования
        List<TestResult> protocol = generateTestProtocol(testResults, desiredDate, desiredDiscipline);

        // Сортировка протокола по фамилии тестируемого
        Collections.sort(protocol, Comparator.comparing(TestResult::getLastName));

        // Вывод протокола тестирования
        for (TestResult result : protocol) {
            System.out.println(result.getLastName() + " " + result.getInitials() +
                    ": " + formatPercentage(result.getPercentage()));
        }
    }

    private static List<TestResult> readTestDataFromCSV(String filePath) {
        List<TestResult> testResults = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] data = line.split(",");
                String lastName = data[0]; // Извлекаем фамилию из данных
                String initials = data[1]; // Извлекаем инициалы из данных
                String date = data[2]; // Извлекаем дату из данных
                String discipline = data[3]; // Извлекаем дисциплину из данных
                int totalQuestions = Integer.parseInt(data[4]); // Извлекаем общее количество вопросов из данных
                int correctAnswers = Integer.parseInt(data[5]); // Извлекаем количество правильных ответов из данных

                // Создаем объект TestResult с извлеченными данными и добавляем его в список testResults
                TestResult testResult = new TestResult(lastName, initials, date, discipline, totalQuestions, correctAnswers);
                testResults.add(testResult);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return testResults; // Возвращаем список результатов тестирования
    }

    public static List<TestResult> generateTestProtocol(List<TestResult> testResults, String desiredDate, String desiredDiscipline) {
        List<TestResult> protocol = new ArrayList<>();

        for (TestResult result : testResults) {
            // Проверяем, соответствуют ли дата и дисциплина результату тестирования
            if (result.getDate().equals(desiredDate) && result.getDiscipline().equals(desiredDiscipline)) {
                protocol.add(result); // Добавляем результат в протокол
            }
        }

        return protocol; // Возвращаем сформированный протокол тестирования
    }

    public static String formatPercentage(double percentage) {
        DecimalFormat decimalFormat = new DecimalFormat("0.0");
        return decimalFormat.format(percentage) + "%"; // Форматируем процент и добавляем символ "%"
    }
}

class TestResult {
    private String lastName;
    private String initials;
    private String date;
    private String discipline;
    private int totalQuestions;
    private int correctAnswers;

    public TestResult(String lastName, String initials, String date, String discipline, int totalQuestions, int correctAnswers) {
        this.lastName = lastName;
        this.initials = initials;
        this.date = date;
        this.discipline = discipline;
        this.totalQuestions = totalQuestions;
        this.correctAnswers = correctAnswers;
    }

    public String getLastName() {
        return lastName;
    }

    public String getInitials() {
        return initials;
    }

    public String getDate() {
        return date;
    }

    public String getDiscipline() {
        return discipline;
    }

    public int getTotalQuestions() {
        return totalQuestions;
    }

    public int getCorrectAnswers() {
        return correctAnswers;
    }

    public double getPercentage() {
        return (double) correctAnswers / totalQuestions * 100;
    }
}