import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.TreeMap;
public class ex4 {
    public static void main(String[] args)  throws Exception  {
        try {
            TreeMap<String, Integer> tm=new TreeMap<String, Integer>();
            TreeMap<Character, Integer> tm1=new TreeMap<Character, Integer>();
            Scanner sc=new Scanner(new File("EndOfTheWorld.txt"));
            String s;
            String []sa;
            System.out.println("*****The original content:*****");
            while(sc.hasNextLine()) {
                s = sc.nextLine();
                System.out.println(s);

                //字符统计
                for (char c : s.toCharArray()) {
                    c = Character.toLowerCase(c);
                    if (tm1.containsKey(c)) {
                        tm1.put(c, tm1.get(c) + 1);
                    } else {
                        tm1.put(c, 1);
                    }
                }

                sa=s.split("\\s|,|[?]|\\.|\"|“|”|\\(|\\)"); // 分解单词

                // 单词统计
                for (String word : sa) {
                    if (!word.isEmpty()) {
                        word = word.toLowerCase();
                        if (tm.containsKey(word)) {
                            tm.put(word, tm.get(word) + 1);
                        } else {
                            tm.put(word, 1);
                        }
                    }
                }
            }
            System.out.println("*****Statistical results of each character：*****");
            System.out.println(tm1);
            System.out.println("*****Statistical results of each word：*****");
            System.out.println(tm);
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
