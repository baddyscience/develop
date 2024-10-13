import java.math.BigDecimal;
import java.util.Scanner;

public class Money {
    private static final char[] ca = {'零', '壹', '贰', '叁', '肆', '伍', '陆', '柒', '捌', '玖'};
    private static final String[] ma = {"分", "角", "", "拾", "佰", "仟", "万", "拾万", "佰万", "仟万", "亿"};

    public static String toChinese(BigDecimal money) {
        long amount = money.multiply(BigDecimal.valueOf(100)).longValue();
        String zhen = zhengsu(String.valueOf(amount / 100));
        String xiao = xiaosu(String.valueOf(amount % 100));

        return zhen + "元" + xiao;
    }

    private static String zhengsu(String zhen) {
        StringBuilder result = new StringBuilder();
        char[] digits = zhen.toCharArray();
        int length = digits.length;

        boolean zeroFlag = false;
        boolean hasValue = false;
        for (int i = 0; i < length; i++) {
            int num = digits[i] - '0';
            int pos = (length - 1 - i) % 4;
            int group = (length - 1 - i) / 4;

            if (num == 0) {
                zeroFlag = true;
            } else {
                if (zeroFlag) {
                    result.append(ca[0]);
                    zeroFlag = false;
                }
                result.append(ca[num]).append(ma[pos + 2]);
                hasValue = true;
            }

            if (pos == 0 && hasValue) {
                if (group > 0) {
                    result.append(ma[6 + group - 1]); 
                }
                hasValue = false;
            }
        }

        return result.length() > 0 ? result.toString() : String.valueOf(ca[0]);
    }

    private static String xiaosu(String xiao) {
        StringBuilder result = new StringBuilder();

        char jiao = xiao.charAt(0);
        if (jiao != '0') {
            result.append(ca[jiao - '0']).append(ma[1]);
        }

        char fen = xiao.charAt(1);
        if (fen != '0') {
            result.append(ca[fen - '0']).append(ma[0]);
        }

        return result.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入金额：");
        BigDecimal money = scanner.nextBigDecimal();
        System.out.println("金额大写：" + toChinese(money));
    }
}
