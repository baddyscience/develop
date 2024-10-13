public class YangHui {
    public static void main(String[] args) {
        int n = 5;

        int[][] triangle = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    triangle[i][j] = 1;
                } else {
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
                }

                System.out.print("c(" + i + "," + j + ") = " + triangle[i][j] + "  ");
            }
            System.out.println();
        }
    }
}
