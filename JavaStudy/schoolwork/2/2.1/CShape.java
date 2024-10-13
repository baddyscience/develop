abstract class CShape                          //抽象类
{
  public int number;         //边数
  public int totalAngle;//内角和,公式为totalAangle=(number-2)*180
  public abstract int angle();        //抽象方法

  @Override
  public String toString()
  {
    return "正"+number+"边形每一角为"+angle()+"度";
  }
}

