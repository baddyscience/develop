public class CRect extends CShape{
    public CRect(){
        number = 4;
        totalAngle = (this.number - 2) * 180;
    }

    @Override
    public int angle()
    {
        return totalAngle/number;
    }
}
