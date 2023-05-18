package by.vsu.mf.ai.ssd.strings;

import javax.swing.*;
import java.awt.event.ActionEvent;

public class StringProcessor implements Job {
    public static void main(String[] args) {
        Manager.createWindow(new StringProcessor());
    }

    @Override
    public void perform(StringBuilder inputString) {
        int count = 1;
        for (int i = 0; i < inputString.length(); i++) {
            char currentChar = inputString.charAt(i);
            if (currentChar == '!') {
                inputString.insert(i+1, count);
                count++;
                i++;
            }
        }
    }

    public static class Manager {
        public static void createWindow(Job job) {
            JFrame frame = new JFrame("String Processor");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            JPanel panel = new JPanel();
            panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
            JLabel label = new JLabel("Enter text:");
            panel.add(label);
            JTextArea textArea = new JTextArea(10, 40);
            JScrollPane scrollPane = new JScrollPane(textArea);
            panel.add(scrollPane);
            JButton button = new JButton("Process");
            button.addActionListener((ActionEvent e) -> {
                StringBuilder str = new StringBuilder(textArea.getText());
                job.perform(str);
                textArea.setText(str.toString());
            });
            panel.add(button);
            frame.getContentPane().add(panel);
            frame.pack();
            frame.setVisible(true);
        }
    }
}