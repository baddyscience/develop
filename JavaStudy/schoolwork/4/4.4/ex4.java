import java.io.FileWriter;
import java.util.EnumSet;
import java.io.BufferedWriter;
import java.io.IOException;

enum WeekDay {
    Mon("Monday","星期一"),Tue("Tuesday","星期二"), Wed("Wednesday","星期三"),
    Thu("Thursday", "星期四"),	Fri("Friday","星期五"),Sat("Saturday","星期六"),
    Sun("Sunday", "星期日");
    private WeekDay(String en, String cn) {
        this.en = en;  this.cn = cn;
    }
    private final String en;
    private final String cn;
    public String getEn() {
        return en;
    }
    public String getCn() {
        return cn;
    }
}
public class ex4 {
    public static void main(String[] args) {
        WeekDay s1 = WeekDay.Fri;
        System.out.print(WeekDay.Tue.getCn() + "\t");
        System.out.print(s1 + ":" + s1.getCn() + "\t");
        for (WeekDay s : WeekDay.values()) {
            System.out.print(s + ":" + s.getCn() + "\t");
        }
        for (WeekDay s : EnumSet.range(WeekDay.Tue, WeekDay.Sat)) {
            System.out.print(s + "-" + s.getEn() + "\t");
        }

        try (BufferedWriter writer = new BufferedWriter(new FileWriter("ex2out.txt"))) {
            writer.write(WeekDay.Tue.getCn() + "\t");
            writer.write(s1 + ":" + s1.getCn() + "\t");
            for (WeekDay s : WeekDay.values()) {
                writer.write(s + ":" + s.getCn() + "\t");
            }
            for (WeekDay s : EnumSet.range(WeekDay.Tue, WeekDay.Sat)) {
                writer.write(s + "-" + s.getEn() + "\t");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
