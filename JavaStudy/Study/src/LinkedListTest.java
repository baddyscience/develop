import java.util.LinkedList;
public class LinkedListTest {
    public static void main(String[] args) {
        LinkedList<String> list = new LinkedList<>();
        list.add("第一个字符串");
        list.add("第二个字符串");
        list.addLast("第三个字符串");
        list.addFirst("第四个字符串");
        String first = list.removeFirst();//将第一个链移除
        String last = list.removeLast(); //将最后一个链移除
        System.out.println(first);
        System.out.println(last);
        first = list.getFirst();
        last = list.getLast();
        System.out.println(first);
        System.out.println(last);
    }
}


