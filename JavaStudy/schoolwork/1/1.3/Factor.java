import java.util.Scanner;
import java.util.ArrayList;

public class Factor {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入一个整数:");
        int number = scanner.nextInt();
        int renumber = number;
        scanner.close();

        ArrayList<Integer> factors = new ArrayList<>();

        while (number % 2 == 0) {
            factors.add(2);
            number /= 2;
        }
        while (number % 3 == 0) {
            factors.add(3);
            number /= 3;
        }

        for (int i = 5; i * i <= number; i += 6) {
            while (number % i == 0) {
                factors.add(i);
                number /= i;
            }
            while (number % (i + 2) == 0) {
                factors.add(i + 2);
                number /= (i + 2);
            }
        }

        if (number > 2) {
            factors.add(number);
        }

        if (!factors.isEmpty()) {
            StringBuilder result = new StringBuilder();
            result.append(renumber).append(" = 1 * ");

            for (int i = 0; i < factors.size(); i++) {
                result.append(factors.get(i));
                if (i < factors.size() - 1) {
                    result.append(" * ");
                }
            }

            System.out.println(result.toString());
        } else {
            System.out.println(number);
        }
    }
}
