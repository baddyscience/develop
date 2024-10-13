public class HanoiTower {
    public static void main(String[] args) {
        int numberOfDisks = 3;
        moveDisks(numberOfDisks, 'A', 'B', 'C');
    }

    public static void moveDisks(int n, char source, char helper, char target) {
        if (n > 0) {
            moveDisks(n - 1, source, target, helper);
            System.out.println("Disk " + n + " moved from " + source + " to " + target);
            moveDisks(n - 1, helper, source, target);
        }
    }
}
