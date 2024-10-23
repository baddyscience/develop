import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ex4 {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new Ex4Frame());
    }
}

class Ex4Frame extends JFrame {
    private JPanel colorDisplay;
    private JSlider sliderR, sliderG, sliderB;
    private JSpinner spinnerH, spinnerS, spinnerBValue;

    public Ex4Frame() {
        setTitle("Color Palette");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 300);
        setLayout(new BorderLayout());

        colorDisplay = new JPanel();
        colorDisplay.setPreferredSize(new Dimension(400, 100));
        add(colorDisplay, BorderLayout.NORTH);

        // RGB Sliders
        JPanel rgbPanel = new JPanel(new GridLayout(3, 2));
        rgbPanel.add(new JLabel("R:"));
        sliderR = new JSlider(0, 255, 0);
        sliderR.addChangeListener(e -> updateColor());
        rgbPanel.add(sliderR);

        rgbPanel.add(new JLabel("G:"));
        sliderG = new JSlider(0, 255, 0);
        sliderG.addChangeListener(e -> updateColor());
        rgbPanel.add(sliderG);

        rgbPanel.add(new JLabel("B:"));
        sliderB = new JSlider(0, 255, 0);
        sliderB.addChangeListener(e -> updateColor());
        rgbPanel.add(sliderB);

        add(rgbPanel, BorderLayout.CENTER);

        // HSB Spinners
        JPanel hsbPanel = new JPanel(new GridLayout(3, 2));
        hsbPanel.add(new JLabel("Hue (0-360):"));
        spinnerH = new JSpinner(new SpinnerNumberModel(0, 0, 360, 1));
        spinnerH.addChangeListener(e -> updateColorFromHSB());
        hsbPanel.add(spinnerH);

        hsbPanel.add(new JLabel("Saturation (0-100):"));
        spinnerS = new JSpinner(new SpinnerNumberModel(100, 0, 100, 1));
        spinnerS.addChangeListener(e -> updateColorFromHSB());
        hsbPanel.add(spinnerS);

        hsbPanel.add(new JLabel("Brightness (0-100):"));
        spinnerBValue = new JSpinner(new SpinnerNumberModel(100, 0, 100, 1));
        spinnerBValue.addChangeListener(e -> updateColorFromHSB());
        hsbPanel.add(spinnerBValue);

        add(hsbPanel, BorderLayout.SOUTH);

        JButton colorButton = new JButton("Choose Color");
        colorButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Color selectedColor = JColorChooser.showDialog(null, "Choose a Color", colorDisplay.getBackground());
                if (selectedColor != null) {
                    sliderR.setValue(selectedColor.getRed());
                    sliderG.setValue(selectedColor.getGreen());
                    sliderB.setValue(selectedColor.getBlue());
                    updateColor();
                }
            }
        });
        add(colorButton, BorderLayout.EAST);

        setVisible(true);
    }

    private void updateColor() {
        Color color = new Color(sliderR.getValue(), sliderG.getValue(), sliderB.getValue());
        colorDisplay.setBackground(color);
        float[] hsb = Color.RGBtoHSB(color.getRed(), color.getGreen(), color.getBlue(), null);
        spinnerH.setValue((int) (hsb[0] * 360));
        spinnerS.setValue((int) (hsb[1] * 100));
        spinnerBValue.setValue((int) (hsb[2] * 100));
    }

    private void updateColorFromHSB() {
        int h = (int) spinnerH.getValue();
        int s = (int) spinnerS.getValue();
        int b = (int) spinnerBValue.getValue();
        Color color = Color.getHSBColor(h / 360f, s / 100f, b / 100f);
        sliderR.setValue(color.getRed());
        sliderG.setValue(color.getGreen());
        sliderB.setValue(color.getBlue());
        colorDisplay.setBackground(color);
    }
}
