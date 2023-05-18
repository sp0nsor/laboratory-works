import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        double[] P = {0.7, 0.4, 0.8, 0.2, 0.9, 0.2};
        List<Double> bestSteps = new ArrayList<Double>();
        int N = P.length;
        int left = 0;
        int right = 3;
        while (right <= N){
            double tmp = maxOfThree(P[left],P[left + 1],P[left + 2]);
            bestSteps.add(tmp);
            left = right;
            right += 3;
        }
        System.out.println(bestSteps.toString());
    }
    private static double maxOfThree(double a, double b, double c){
        double max = a;
        if(b > max){
            max = b;
        }
        if(c > max){
            max = c;
        }
        return max;
    }
}