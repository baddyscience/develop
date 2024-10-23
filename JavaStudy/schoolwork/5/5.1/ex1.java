import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ex1 extends JFrame {
    private JList<String> leftList;
    private JList<String> rightList;
    private DefaultListModel<String> leftModel;
    private DefaultListModel<String> rightModel;

    public ex1() {
        leftModel = new DefaultListModel<>();
        rightModel = new DefaultListModel<>();

        leftModel.addElement("选项1");
        leftModel.addElement("选项2");
        leftModel.addElement("选项3");
        leftModel.addElement("选项4");
        leftModel.addElement("选项5");
        leftModel.addElement("选项6");

        leftList = new JList<>(leftModel);
        rightList = new JList<>(rightModel);

        leftList.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if (e.getClickCount() == 2) {
                    int index = leftList.locationToIndex(e.getPoint());
                    if (index != -1) {
                        String selectedValue = leftModel.get(index);
                        rightModel.addElement(selectedValue);
                    }
                }
            }
        });

        JScrollPane leftScrollPane = new JScrollPane(leftList);
        leftScrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
        leftScrollPane.getVerticalScrollBar().setValue((leftModel.getSize() - 1) / 2);

        JScrollPane rightScrollPane = new JScrollPane(rightList);

        setLayout(new GridLayout(1, 2));
        add(leftScrollPane);
        add(rightScrollPane);

        setTitle("ex1");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new ex1().setVisible(true);
        });
    }
}
