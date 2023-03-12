public class Main {

    public static double factorial(int val){
        int Res = 1;
        while (val >= 1){
            Res *= val;
            val--;
        }
        return Res;
    }
    public static double expression(double x, double eps){
        double sum = 0;
        double buf;
        double tmp;
        int n = 1;
        do{
            buf = Math.pow(x, (2 * n) + 1)/ factorial((2 * n) + 1);
            tmp = Math.pow(x, 2 * (n - 1) + 1)/ factorial(2 * (n - 1) + 1);
            sum += buf;
            n++;
        }while (Math.abs(buf - tmp) > eps);
        return sum;
    }
    public static void main(String[] args) {
        double x = Double.parseDouble(args[0]);
        double eps = Double.parseDouble(args[1]);
        System.out.println("Сумма ряда = " + expression(x, eps));
        System.out.println("Знчение из функции = " + Math.sinh(x));
    }
}