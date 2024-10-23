import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.DefaultTableModel;
import java.awt.*;

public class ex3 {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new Ex3Frame());
    }
}

class Ex3Frame extends JFrame {
    private JTable table;
    private JTextField textFieldName;
    private JTextField textFieldAge;
    private JComboBox<String> comboBoxCity;
    private JTextField textFieldSalary;
    private JComboBox<String> comboBoxDepartment;

    public Ex3Frame() {
        setTitle("Extended Table Example");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 400);
        setLayout(new BorderLayout());

        String[] columnNames = {"Name", "Age", "City", "Salary", "Department"};
        Object[][] data = {
                {"Alice", 30, "New York", 70000.00, "Engineering"},
                {"Bob", 25, "Los Angeles", 60000.50, "Marketing"},
                {"Charlie", 35, "Chicago", 80000.75, "Sales"},
                {"David", 28, "Miami", 55000.00, "HR"},
                {"Eva", 32, "Seattle", 72000.25, "Finance"},
                {"Frank", 40, "Austin", 90000.00, "Engineering"},
                {"Grace", 27, "Boston", 48000.50, "Marketing"},
                {"Hannah", 45, "San Francisco", 95000.00, "Sales"}
        };

        DefaultTableModel model = new DefaultTableModel(data, columnNames);
        table = new JTable(model);
        JScrollPane scrollPane = new JScrollPane(table);
        add(scrollPane, BorderLayout.CENTER);

        textFieldName = new JTextField(10);
        textFieldAge = new JTextField(5);
        comboBoxCity = new JComboBox<>();
        textFieldSalary = new JTextField(10);
        comboBoxDepartment = new JComboBox<>();

        JPanel panel = new JPanel(new FlowLayout());
        panel.add(new JLabel("Selected Name:"));
        panel.add(textFieldName);
        panel.add(new JLabel("Age:"));
        panel.add(textFieldAge);
        panel.add(new JLabel("City:"));
        panel.add(comboBoxCity);
        panel.add(new JLabel("Salary:"));
        panel.add(textFieldSalary);
        panel.add(new JLabel("Department:"));
        panel.add(comboBoxDepartment);
        add(panel, BorderLayout.SOUTH);

        table.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    int selectedRow = table.getSelectedRow();
                    if (selectedRow != -1) {
                        String name = (String) table.getValueAt(selectedRow, 0);
                        int age = (int) table.getValueAt(selectedRow, 1);
                        String city = (String) table.getValueAt(selectedRow, 2);
                        double salary = (double) table.getValueAt(selectedRow, 3);
                        String department = (String) table.getValueAt(selectedRow, 4);

                        textFieldName.setText(name);
                        textFieldAge.setText(String.valueOf(age));
                        comboBoxCity.removeAllItems();
                        comboBoxCity.addItem(city);
                        textFieldSalary.setText(String.valueOf(salary));
                        comboBoxDepartment.removeAllItems();
                        comboBoxDepartment.addItem(department);
                    }
                }
            }
        });

        setVisible(true);
    }
}
