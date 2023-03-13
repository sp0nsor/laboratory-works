// 0 8 -6 0 2 -6 8 2 квадрат
// 2 -5 -2 1 1 5 5 -1 параллелограмм
// 1 -2 3 1 1 4 -1 1 ромб

public class Main {
    public static boolean boolCheckSquare(double lengthD1, double lengthD2){
        if (lengthD1 == lengthD1){
            return true;
        }
        else{
            return false;
        }
    }
    public static boolean boolCheckRhomb(double lengthD1, double lengthD2){
        if (lengthD1 != lengthD2){
            return true;
        }
        else{
            return false;
        }
    }
    public static boolean boolCheckParallelogram(double lengthS1, double lengthS2, double lengthS3, double lengthS4){
        if(lengthS1 == lengthS3 && lengthS2 == lengthS4 && lengthS1 != lengthS4){
            return true;
        }
        else{
            return false;
        }
    }
    public static void main(String[] args){

        double x1 = Double.parseDouble(args[0]);
        double y1 = Double.parseDouble(args[1]);
        double x2 = Double.parseDouble(args[2]);
        double y2 = Double.parseDouble(args[3]);
        double x3 = Double.parseDouble(args[4]);
        double y3 = Double.parseDouble(args[5]);
        double x4 = Double.parseDouble(args[6]);
        double y4 = Double.parseDouble(args[7]);

        Point point1 = new Point(x1, y1);
        Point point2 = new Point(x2, y2);
        Point point3 = new Point(x3, y3);
        Point point4 = new Point(x4, y4);

        Segment segment1 = new Segment(point1, point2);
        Segment segment2 = new Segment(point2, point3);
        Segment segment3 = new Segment(point3, point4);
        Segment segment4 = new Segment(point4, point1);

        Segment diagonal1 = new Segment(point1, point3);
        Segment diagonal2 = new Segment(point2, point4);

        double lengthS1 = segment1.getLength();
        double lengthS2 = segment2.getLength();
        double lengthS3 = segment3.getLength();
        double lengthS4 = segment4.getLength();

        double lengthD1 = diagonal1.getLength();
        double lengthD2 = diagonal2.getLength();

        if (lengthS1 == lengthS2 && lengthS3 == lengthS4 && lengthS1 == lengthS3){
            if (lengthD1 == lengthD2){
                System.out.println("Данный четырёхугольник квадрат.");

            } else if (lengthD1 != lengthD2) {
                System.out.println("Данный четырёхугольник ромб.");
            }
        } else if (lengthS1 == lengthS3 && lengthS2 == lengthS4 && lengthS1 != lengthS4) {
            System.out.println("Данный четырёхугольник параллелограмм.");
        }
    }

}