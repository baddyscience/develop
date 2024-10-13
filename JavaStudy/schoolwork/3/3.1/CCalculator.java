class CCalculator extends CTriFunc implements IFullCompute {
    public double result;
    public CCalculator()  {
    }
    public double LOG(double x)  {
        return Math.log(x);
    }
    public double LN(double x)  {
        return Math.log(x)/Math.log(Math.E);
    }
    public double Add(double a,double b)  {
        return a+b;
    }
    public double Sub(double a,double b)  {
        return a-b;
    }
    public double Mul(double a,double b)  {
        return a*b;
    }
    public double Div(double a,double b)  {
        return a/b;
    }
    public double SIN(double x) {
        return Math.sin(trans(x));
    }
    public double COS(double x) {
        return Math.cos(trans(x));
    }
    public double TAN(double x) {
        return Math.tan(trans(x));
    }
}

