public class calmachine{
public static void main(String args[]) {
    CCalculator obj1 = new CCalculator();
    double a, b;
    b = Math.random() * 10;
    a = Math.random() * 20;
    System.out.println(a+" Add "+b+" = "+obj1.Add(a,b));
    System.out.println(a+" Sub "+b+" = "+obj1.Sub(a,b));
    System.out.println(a+" Mul "+b+" = "+obj1.Mul(a,b));
    System.out.println(a+" Div "+b+" = "+obj1.Div(a,b));
    }
}