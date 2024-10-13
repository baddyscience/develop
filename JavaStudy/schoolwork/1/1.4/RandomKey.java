import java.util.HashSet;
import java.util.Set;

public class RandomKey {
    public static void main(String[] args) {
        Set<String> passwords = new HashSet<>();

        while (passwords.size() < 100) {
            String password = generatePassword();
            passwords.add(password);
        }

        String[] passwordArray = passwords.toArray(new String[0]);

        for (String password : passwordArray) {
            System.out.println(password);
        }
    }

    public static String generatePassword() {
        char[] ca = new char[6];

        for (int i = 0; i < 6; i++) {
            if (i % 2 == 0) {
                ca[i] = (char) ('0' + Math.random() * 10);
            } else {
                ca[i] = (char) ('A' + Math.random() * 26);
            }
        }

        return new String(ca);
    }
}