public class CTriangle extends CShape{
    public CTriangle() {
        this.number = 3;
        this.totalAngle = (this.number - 2) * 180;
    }

    @Override
    public int angle()
    {
        return totalAngle/number;
    }

}
