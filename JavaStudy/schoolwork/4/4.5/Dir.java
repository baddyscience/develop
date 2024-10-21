import java.io.File;
import java.io.FilenameFilter;
import java.text.SimpleDateFormat;
import java.util.Date;
public class Dir {
    public static void main(String[] args) {
        File f=new File("C:\\");

        File[] fa=f.listFiles( new FilenameFilter(){
            @Override
            public boolean accept(File dir, String name){
                return true;
            }
        } );
        SimpleDateFormat sdf=new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");

        if (fa != null) {
            for (File file : fa) {
                String type = file.isDirectory() ? "<dir>" : "";
                long size = file.isDirectory() ? 0 : file.length();
                Date lastModified = new Date(file.lastModified());

                System.out.printf("%-30s %8d %5s %s\n", file.getName(), size, type, sdf.format(lastModified));
            }
        } else {
            System.out.println("无法访问指定路径或没有文件和目录。");
        }
    }
}

