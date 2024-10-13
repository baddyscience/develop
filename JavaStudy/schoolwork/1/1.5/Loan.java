import java.text.DecimalFormat;

public class Loan {
    // 计算单利
    public static double calculateSimpleInterest(double principal, double dailyRate, int days) {
        return principal + principal * dailyRate * days;
    }

    public static double calculateCompoundInterest(double principal, double dailyRate, int days) {
        return principal * Math.pow(1 + dailyRate, days);
    }

    public static void main(String[] args) {
        double principal = 10000;
        double dailyRate = 0.001;
        int[] years = {1, 2, 3, 4, 5};
        DecimalFormat df = new DecimalFormat("#.##");  // 保留两位小数

        for (int year : years) {
            int days = year * 365;  // 1年按365天算

            double simpleInterest = calculateSimpleInterest(principal, dailyRate, days);
            double compoundInterest = calculateCompoundInterest(principal, dailyRate, days);

            System.out.println(year + " 年后的单利还款金额: " + df.format(simpleInterest) + " 元");
            System.out.println(year + " 年后的复利还款金额: " + df.format(compoundInterest) + " 元");
            System.out.println();
        }
    }
}
