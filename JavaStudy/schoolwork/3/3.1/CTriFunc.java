class CTriFunc {
    double trans(double x) {
        return x * (Math.PI / 180);
    }//Math.PI/180 表示弧度1度为多少π（1π=180°）
    public double SIN(double x) {
        return Math.sin(trans(x));
    }
    public double COS ( double x) {
        return Math.cos(trans(x));
    }
    public double TAN ( double x) {
        return Math.tan(trans(x));
    }
}
