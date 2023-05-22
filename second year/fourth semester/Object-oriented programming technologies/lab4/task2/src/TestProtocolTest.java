import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

public class TestProtocolTest {
    private List<TestResult> testResults;

    @BeforeEach
    public void setup() {
        testResults = new ArrayList<>();
        testResults.add(new TestResult("Smith", "J.", "2023-05-18", "Математика", 10, 8));
        testResults.add(new TestResult("Johnson", "A.", "2023-05-18", "Математика", 10, 7));
        testResults.add(new TestResult("Williams", "K.", "2023-05-18", "Физика", 10, 9));
        testResults.add(new TestResult("Brown", "L.", "2023-05-18", "Физика", 10, 6));
    }

    @Test
    public void testGenerateTestProtocol() {
        String desiredDate = "2023-05-18";
        String desiredDiscipline = "Математика";

        List<TestResult> protocol = TestProtocol.generateTestProtocol(testResults, desiredDate, desiredDiscipline);

        Assertions.assertEquals(2, protocol.size());
        Assertions.assertTrue(protocol.contains(testResults.get(0)));
        Assertions.assertTrue(protocol.contains(testResults.get(1)));
    }

    @Test
    public void testGenerateTestProtocol_NoMatch() {
        String desiredDate = "2023-05-18";
        String desiredDiscipline = "История";

        List<TestResult> protocol = TestProtocol.generateTestProtocol(testResults, desiredDate, desiredDiscipline);

        Assertions.assertTrue(protocol.isEmpty());
    }

/*    @Test
    public void testFormatPercentage() {
        double percentage = 75.5;

        String formattedPercentage = TestProtocol.formatPercentage(percentage);

        Assertions.assertEquals("75.5%", formattedPercentage);
    }*/
}