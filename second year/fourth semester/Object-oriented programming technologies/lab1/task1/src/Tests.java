import org.junit.Assert;
import org.junit.Test;

public class Tests  {
    @Test
    public void test1(){
        Assert.assertEquals(
                16,
                Main.expression(2,2, 1),
                0.01
        );
    }
    @Test
    public void test2(){
        Assert.assertEquals(
                -6.4,
                Main.expression(-10,2,0),
                0.01
        );
    }
}
