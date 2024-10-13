public class CmyExceptionTest {

    static class CmyException extends Exception {
        public CmyException(String message) {
            super(message);
        }
    }

    // 计算 x 的 y 次方的方法
    static int powerXY(int x, int y) throws CmyException {
        if (x == 0 && y == 0) {
            throw new CmyException("0的0次方无定义，回传值将错误");
        }
        if (y < 0) {
            throw new CmyException("次方为负值,结果不为整数,回传值将错误");
        }

        int result = 1;
        for (int i = 0; i < y; i++) {
            result *= x;
        }
        return result;
    }

    public static void main(String[] args) {
        try {
            System.out.println("2的 5次方=" + powerXY(2, 5));
        } catch (CmyException e) {
            System.out.println(e.getMessage());
        }

        try {
            System.out.println("2的 0次方=" + powerXY(2, 0));
        } catch (CmyException e) {
            System.out.println(e.getMessage());
        }

        try {
            System.out.println("0的 0次方=" + powerXY(0, 0));
        } catch (CmyException e) {
            System.out.println(e.getMessage());
            System.out.println("0的 0次方=-1");
        }

        try {
            System.out.println("2的 -2次方=" + powerXY(2, -2));
        } catch (CmyException e) {
            System.out.println(e.getMessage());
            System.out.println("2的 -2次方=-1");
        }
    }
}
