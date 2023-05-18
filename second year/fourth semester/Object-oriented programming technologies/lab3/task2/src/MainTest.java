import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class MainTest {

    @Test
    public void testChangeStringCharacther() {
        StringBuffer stringBuffer = new StringBuffer("J!a!v!a!");
        int size = stringBuffer.length() + 3;
        StringBuffer expected = new StringBuffer("J!1a!2v!3a!4");
        StringBuffer actual = Main.ChangeStringCharacther(stringBuffer, size);
        assertEquals(expected.toString(), actual.toString());
    }

    @Test
    public void testChangeStringCharactherWithNoExclamationMarks() {
        StringBuffer stringBuffer = new StringBuffer("Java");
        int size = stringBuffer.length();
        StringBuffer expected = new StringBuffer("Java");
        StringBuffer actual = Main.ChangeStringCharacther(stringBuffer, size);
        assertEquals(expected.toString(), actual.toString());
    }

    @Test
    public void testChangeStringCharactherWithEmptyString() {
        StringBuffer stringBuffer = new StringBuffer("");
        int size = stringBuffer.length();
        StringBuffer expected = new StringBuffer("");
        StringBuffer actual = Main.ChangeStringCharacther(stringBuffer, size);
        assertEquals(expected.toString(), actual.toString());
    }

}