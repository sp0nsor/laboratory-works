import org.junit.Assert;
import org.junit.Test;
public class ClassesTestCase {
    @Test
    public void testSquare(){
        Assert.assertTrue(
                Main.boolCheckSquare(2, 2)
        );
    }
    @Test
    public void testRhomb(){
        Assert.assertTrue(
                Main.boolCheckRhomb(2, 4)
        );
    }
    @Test
    public void testParallelogram(){
        Assert.assertTrue(
                Main.boolCheckParallelogram(2, 4, 2, 4)
        );
    }

}
