public class calpolygon {
    public static void main(String[] args) {
        CShape ObjArr[] = new CShape[3];
        ObjArr[0] = new CTriangle();
        ObjArr[1]=new CRect();
        ObjArr[2]=new CPentagon();
        for(int i = 0 ;i < ObjArr.length; i++)
            ObjArr[i].angle();
        for(int i=0; i < ObjArr.length; i++)
            System.out.println(ObjArr[i].toString());
    }
}
