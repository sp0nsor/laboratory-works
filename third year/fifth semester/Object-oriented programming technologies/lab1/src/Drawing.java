import java.awt.*;
import java.util.ArrayList;
import java.util.List;

class Drawing {
    private List<GraphicPrimitive<?>> primitives = new ArrayList<>();

    public void addPrimitive(GraphicPrimitive<?> primitive) {
        primitives.add(primitive);
    }

    public void draw(Graphics2D g2d) {
        primitives.sort((p1, p2) -> Integer.compare(p1.getLayer(), p2.getLayer()));

        for (GraphicPrimitive<?> primitive : primitives) {
            g2d.setColor(primitive.getBorderColor());
            g2d.draw(primitive.getShape());

            if (primitive.getFillColor() != null) {
                g2d.setColor(primitive.getFillColor());
                g2d.fill(primitive.getShape());
            }
        }
    }
}