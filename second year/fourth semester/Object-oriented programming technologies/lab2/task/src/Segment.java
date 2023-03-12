public class Segment {
    private Point begin;
    private Point end;

    public Segment(Point begin, Point end){
        this.begin = begin;
        this.end = end;
    }

    public Point getBegin() {
        return begin;
    }

    public Point getEnd() {
        return end;
    }
    public double getLength(){
        return Math.sqrt(Math.pow(this.end.getX() - this.begin.getX(), 2) + (Math.pow(this.end.getY() - this.begin.getY(), 2)));
    }
}
