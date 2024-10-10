import java.util.Scanner;

public class CelsiusToFahrenheit {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("请输入摄氏温度: ");
        double celsius = scanner.nextDouble();

        double fahrenheit = (9.0 / 5.0) * celsius + 32;

        System.out.printf("%.2f 摄氏度等于 %.2f 华氏度\n", celsius, fahrenheit);

        scanner.close();
    }
}
