import org.junit.Assert;
import org.junit.Test;

public class Tests {
    @Test
    public void test1(){
        Assert.assertEquals(
                0.029731718223833133,
                Main.expression(0.56, 0.00000001),
                0.00000001
        );
    }
    @Test
    public void test2(){
        Assert.assertEquals(
                -0.029731718223833133,
                Main.expression(-0.56, 0.00000001),
                0.00000001
        );
    }
    @Test
    public void test3(){
        Assert.assertEquals(
            Double.NEGATIVE_INFINITY,
                Main.expression(-0.045, 0),
                0.00000001
        );
    }

    @Test
    public void test4(){
        Assert.assertEquals(
                Double.POSITIVE_INFINITY,
                Main.expression(0.032, 0),
                0.00000001

        );
    }

}
