import java.lang.Integer;
import java.util.Scanner;

public class BODH {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();

        String binaryString = Integer.toBinaryString(number);
        String octalString = Integer.toOctalString(number);
        String hexString = Integer.toHexString(number);

        System.out.println("二进制: " + binaryString);
        System.out.println("十进制: " + number);
        System.out.println("八进制: " + octalString);
        System.out.println("十六进制: " + hexString);
    }
}
