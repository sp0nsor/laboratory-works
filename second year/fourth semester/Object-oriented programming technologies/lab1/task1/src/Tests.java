import org.junit.Assert;
import org.junit.Test;

import javax.swing.plaf.PanelUI;

public class Tests {
    @Test
    public void test1(){
        Assert.assertEquals(
                16,
                Main.expression(2,2, 1),
                0.000001
        );
    }
    public void test2(){
        Assert.assertEquals(
                Double.NEGATIVE_INFINITY,
                Main.expression(-10,2,0),
                0.000001
        );
    }
}
