import java.awt.*;

class GraphicPrimitive<T extends Shape> {
    private T shape;
    private Color borderColor;
    private Color fillColor;
    private int layer;

    public GraphicPrimitive(T shape, Color borderColor, Color fillColor, int layer) {
        this.shape = shape;
        this.borderColor = borderColor;
        this.fillColor = fillColor;
        this.layer = layer;
    }

    public T getShape() {
        return shape;
    }

    public Color getBorderColor() {
        return borderColor;
    }

    public Color getFillColor() {
        return fillColor;
    }

    public int getLayer() {
        return layer;
    }
}
