import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;

public class ex2 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("商品列表");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);

        String[] columnNames = {"编号", "商品名称", "价格", "促销品"};

        Object[][] product = {
                {"A0001", "牙刷", new Integer(55), new Boolean(true)},
                {"B0003", "洗发精", new Integer(375), new Boolean(true)},
                {"A1258", "可樂", new Integer(25), new Boolean(false)},
                {"B1534", "抹布", new Integer(80), new Boolean(false)},
                {"B5582", "电池", new Integer(60), new Boolean(false)},
                {"B1752", "铅笔", new Integer(12), new Boolean(true)}
        };

        DefaultTableModel model = new DefaultTableModel(product, columnNames);

        JTable table = new JTable(model);

        JScrollPane scrollPane = new JScrollPane(table);

        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);

        frame.add(scrollPane, BorderLayout.CENTER);

        frame.setVisible(true);
    }
}
