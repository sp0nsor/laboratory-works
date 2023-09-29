import java.awt.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class GraphicsApp {
    public static void main(String[] args) {
        Drawing drawing = new Drawing();

        final String FILE_NAME = "graphics_data.txt";

        try{
            BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME));
            String line;

            while ((line = reader.readLine()) != null){
                String[] parts = line.split(",");

                String type = parts[0];
                double x = Double.parseDouble(parts[1]);
                double y = Double.parseDouble(parts[2]);
                double width = Double.parseDouble(parts[3]);
                double height = Double.parseDouble(parts[4]);
                Color borderColor = new Color(Integer.parseInt(parts[5]));
                Color fillColor = new Color(Integer.parseInt(parts[6]));
                int layer = Integer.parseInt(parts[7]);

                GraphicPrimitive<?> graphicPrimitive = null;

                if ("ellipse".equals(type)) {
                    Ellipse2D ellipse = new Ellipse2D.Double(x, y, width, height);
                    graphicPrimitive = new GraphicPrimitive<>(ellipse, borderColor, fillColor, layer);
                } else if ("rectangle".equals(type)) {
                    Rectangle2D rectangle = new Rectangle2D.Double(x, y, width, height);
                    graphicPrimitive = new GraphicPrimitive<>(rectangle, borderColor, fillColor, layer);
                }
                if(graphicPrimitive != null){
                    drawing.addPrimitive(graphicPrimitive);
                }
            }
            reader.close();
        }catch (IOException e){
            e.printStackTrace();
        }
        JFrame frame = new JFrame("Graphics App");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);

        JPanel panel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                drawing.draw((Graphics2D) g);
            }
        };

        frame.add(panel);
        frame.setVisible(true);
    }
}
