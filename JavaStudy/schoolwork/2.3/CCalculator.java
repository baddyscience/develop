public class CCalculator implements IBasicCompute{
    public double result;
    @Override
    public double Add(double a, double b) {
        result = a+b;
        return result;
    }

    @Override
    public double Sub(double a, double b) {
        result = a-b;
        return result;
    }

    @Override
    public double Mul(double a, double b) {
        result = a*b;
        return result;
    }

    @Override
    public double Div(double a, double b) {
        result = a/b;
        return result;
    }
}
