import java.io.FileWriter;
import java.io.IOException;

public class ex3 {
    public static void main(String[] args) {

        String fileName = "ex1out.txt";

        try (FileWriter writer = new FileWriter(fileName)) {

            writer.write("The 9 by 9 times tables\n");

            for (int i = 1; i <= 9; i++) {
                for (int j = 1; j <= 9; j++) {
                    writer.write(i + "*" + j + "=" + (i * j) + "\t");
                }
                writer.write("\n"); // 换行
            }
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }
}

