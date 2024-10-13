public class CB implements IMyPrime{
    @Override
    public void prime(int X) {
        int count = 0;
        for (int num = 2; num <= X; num++) {
            if (isPrime(num)) {
                p[count++] = num;
            }
        }
    }

    private boolean isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}
