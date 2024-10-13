public class CPentagon extends CShape{
    public CPentagon(){
        number = 5;
        totalAngle = (this.number - 2) * 180;
    }
    @Override
    public int angle(){
        return totalAngle/number;
    }
}
