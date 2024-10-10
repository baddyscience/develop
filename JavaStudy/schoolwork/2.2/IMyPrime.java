public interface IMyPrime {
    int[] p = new int[10086];

    void prime(int X);

    default void output() {
        for (int i = 0; i < p.length; i++) {
            if (p[i] != 0) {
                System.out.print(p[i]);
                System.out.print(" ");
            }
        }
    }
}
