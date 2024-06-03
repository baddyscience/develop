#include "config.h"
#include <tchar.h>
#include <wchar.h>
#undef UNICODE

using namespace std;

int arrays[2048];
int d, h, nums;//生成的随机数的范围和数量
int greenIndex;//当前移动的数
int redIndex = 0;//未排序完成的数

void Randomness( ) {
    srand(time(0)); 
    int range = h - d + 1;
    for (int i = 0; i < nums; ++i) {
        arrays[i] = rand() % range + d;
    }
}

void showCode() {
    settextcolor(BLACK); // 设置文本颜色为黑色
    outtextxy(10, 10, (LPCTSTR)"冒泡排序");
    outtextxy(600, 200, (LPCTSTR)"for (int i = 0; i < nums - 1; ++i, ++redIndex ) {");
    outtextxy(600, 240, (LPCTSTR)"    for (int j = 0; j < nums - i - 1; ++j ) {");
    outtextxy(600, 280, (LPCTSTR)"    if (arrays[ j ] > arrays[j + 1]) {");
    outtextxy(600, 320, (LPCTSTR)"        int temp = arrays[ j ];");
    outtextxy(600, 360, (LPCTSTR)"        arrays[ j ] = arrays[j + 1];");
    outtextxy(600, 400, (LPCTSTR)"        arrays[j + 1] = temp;");
    outtextxy(600, 440, (LPCTSTR)"        }");
    outtextxy(600, 480, (LPCTSTR)"    }");
    outtextxy(600, 520, (LPCTSTR)"}");
}

void clearShowCode() {
    BeginBatchDraw();
    setfillcolor(RGB(255, 255, 255));
    solidrectangle(600, 150, 1200, 600);
    FlushBatchDraw();
}

void showBlocks01() {
    BeginBatchDraw();

    int width = 400 / (nums * 2);// 计算矩形块的宽度
    cleardevice();       // 清空屏幕
    for (int i = 0; i < nums; ++i)
    {
        int height = arrays[i] * 3; // 根据数组元素的值计算矩形块的高度
        int x = i * width * 2 + 100; // 计算矩形块的左上角横坐标
        int y = 600 - height - 50;   // 计算矩形块的左上角纵坐标
        setfillcolor(RGB(255, 0, 0)); // 设置矩形块的填充颜色为红色
        setlinecolor(BLACK);          // 设置边框颜色为黑色
        setlinestyle(PS_SOLID, 1);    // 设置边框样式为实线，宽度为2像素
        rectangle(x, y, x + width, 600); // 绘制矩形块的边框
        fillrectangle(x + 1, y, x + width - 1, 600); // 绘制矩形块
    }
    FlushBatchDraw();
}

void codeAnime01() {
    BeginBatchDraw();
    
    int width = 400 / (nums * 2);// 计算矩形块的宽度
    cleardevice();       // 清空屏幕
    for (int i = 0; i < nums; ++i)
    {
        int height = arrays[i] * 3; // 根据数组元素的值计算矩形块的高度
        int x = i * width * 2 + 100; // 计算矩形块的左上角横坐标
        int y = 600 - height - 50;   // 计算矩形块的左上角纵坐标
        setfillcolor(RGB(0, 0, 255)); // 设置矩形块的填充颜色为蓝色
        setlinecolor(BLACK);          // 设置边框颜色为黑色
        setlinestyle(PS_SOLID, 1);    // 设置边框样式为实线，宽度为2像素
        rectangle(x, y, x + width, 600); // 绘制矩形块的边框
        if (i < nums - redIndex)
        {
            setfillcolor(RGB(255, 0, 0)); // 将索引为 redIndex 的柱子设为红色
        }
        fillrectangle(x + 1, y, x + width - 1, 600); // 绘制矩形块
    }

    outtextxy(10, 10, (LPCTSTR)"冒泡排序");
    settextcolor(GREEN); // 设置文本颜色为绿色
    outtextxy(600, 200, (LPCTSTR)"for (int i = 0; i < nums - 1; ++i, ++redIndex ) {");
    settextcolor(BLACK); // 设置文本颜色为黑色
    outtextxy(600, 240, (LPCTSTR)"    for (int j = 0; j < nums - i - 1; ++j ) {");
    outtextxy(600, 280, (LPCTSTR)"    if (arrays[ j ] > arrays[j + 1]) {");
    outtextxy(600, 320, (LPCTSTR)"        int temp = arrays[ j ];");
    outtextxy(600, 360, (LPCTSTR)"        arrays[ j ] = arrays[j + 1];");
    outtextxy(600, 400, (LPCTSTR)"        arrays[j + 1] = temp;");
    outtextxy(600, 440, (LPCTSTR)"        }");
    outtextxy(600, 480, (LPCTSTR)"    }");
    outtextxy(600, 520, (LPCTSTR)"}");
    FlushBatchDraw();
    Sleep(100);

    BeginBatchDraw();
    clearShowCode();
    settextcolor(BLACK); // 设置文本颜色为黑色
    outtextxy(10, 10, (LPCTSTR)"冒泡排序");
    outtextxy(600, 200, (LPCTSTR)"for (int i = 0; i < nums - 1; ++i, ++redIndex ) {");
    settextcolor(GREEN); // 设置文本颜色为绿色
    outtextxy(600, 240, (LPCTSTR)"    for (int j = 0; j < nums - i - 1; ++j ) {");
    settextcolor(BLACK); // 设置文本颜色为黑色
    outtextxy(600, 280, (LPCTSTR)"    if (arrays[ j ] > arrays[j + 1]) {");
    outtextxy(600, 320, (LPCTSTR)"        int temp = arrays[ j ];");
    outtextxy(600, 360, (LPCTSTR)"        arrays[ j ] = arrays[j + 1];");
    outtextxy(600, 400, (LPCTSTR)"        arrays[j + 1] = temp;");
    outtextxy(600, 440, (LPCTSTR)"        }");
    outtextxy(600, 480, (LPCTSTR)"    }");
    outtextxy(600, 520, (LPCTSTR)"}");
    FlushBatchDraw();
    Sleep(100);
}

void codeAnime02() {
    BeginBatchDraw();
    clearShowCode();
    outtextxy(10, 10, (LPCTSTR)"冒泡排序");
    settextcolor(BLACK); // 设置文本颜色为黑色
    outtextxy(600, 200, (LPCTSTR)"for (int i = 0; i < nums - 1; ++i, ++redIndex ) {");
    outtextxy(600, 240, (LPCTSTR)"    for (int j = 0; j < nums - i - 1; ++j ) {");
    settextcolor(GREEN); // 设置文本颜色为绿色
    outtextxy(600, 280, (LPCTSTR)"    if (arrays[ j ] > arrays[j + 1]) {");
    outtextxy(600, 320, (LPCTSTR)"        int temp = arrays[ j ];");
    settextcolor(BLACK); // 设置文本颜色为黑色
    outtextxy(600, 360, (LPCTSTR)"        arrays[ j ] = arrays[j + 1];");
    outtextxy(600, 400, (LPCTSTR)"        arrays[j + 1] = temp;");
    outtextxy(600, 440, (LPCTSTR)"        }");
    outtextxy(600, 480, (LPCTSTR)"    }");
    outtextxy(600, 520, (LPCTSTR)"}");
    FlushBatchDraw();
    Sleep(100);

    BeginBatchDraw();
    clearShowCode();
    settextcolor(BLACK); // 设置文本颜色为黑色
    outtextxy(10, 10, (LPCTSTR)"冒泡排序");
    outtextxy(600, 200, (LPCTSTR)"for (int i = 0; i < nums - 1; ++i, ++redIndex ) {");
    outtextxy(600, 240, (LPCTSTR)"    for (int j = 0; j < nums - i - 1; ++j ) {");
    outtextxy(600, 280, (LPCTSTR)"    if (arrays[ j ] > arrays[j + 1]) {");
    settextcolor(GREEN); // 设置文本颜色为绿色
    outtextxy(600, 320, (LPCTSTR)"        int temp = arrays[ j ];");
    settextcolor(BLACK); // 设置文本颜色为黑色
    outtextxy(600, 360, (LPCTSTR)"        arrays[ j ] = arrays[j + 1];");
    outtextxy(600, 400, (LPCTSTR)"        arrays[j + 1] = temp;");
    outtextxy(600, 440, (LPCTSTR)"        }");
    outtextxy(600, 480, (LPCTSTR)"    }");
    outtextxy(600, 520, (LPCTSTR)"}");
    FlushBatchDraw();
    Sleep(100);

    BeginBatchDraw();
    clearShowCode();
    settextcolor(BLACK); // 设置文本颜色为黑色
    outtextxy(10, 10, (LPCTSTR)"冒泡排序");
    outtextxy(600, 200, (LPCTSTR)"for (int i = 0; i < nums - 1; ++i, ++redIndex ) {");
    outtextxy(600, 240, (LPCTSTR)"    for (int j = 0; j < nums - i - 1; ++j ) {");
    outtextxy(600, 280, (LPCTSTR)"    if (arrays[ j ] > arrays[j + 1]) {");
    outtextxy(600, 320, (LPCTSTR)"        int temp = arrays[ j ];");
    settextcolor(GREEN); // 设置文本颜色为绿色
    outtextxy(600, 360, (LPCTSTR)"        arrays[ j ] = arrays[j + 1];");
    settextcolor(BLACK); // 设置文本颜色为黑色
    outtextxy(600, 400, (LPCTSTR)"        arrays[j + 1] = temp;");
    outtextxy(600, 440, (LPCTSTR)"        }");
    outtextxy(600, 480, (LPCTSTR)"    }");
    outtextxy(600, 520, (LPCTSTR)"}");
    FlushBatchDraw();
    Sleep(100);

    BeginBatchDraw();
    clearShowCode();
    settextcolor(BLACK); // 设置文本颜色为黑色
    outtextxy(10, 10, (LPCTSTR)"冒泡排序");
    outtextxy(600, 200, (LPCTSTR)"for (int i = 0; i < nums - 1; ++i, ++redIndex ) {");
    outtextxy(600, 240, (LPCTSTR)"    for (int j = 0; j < nums - i - 1; ++j ) {");
    outtextxy(600, 280, (LPCTSTR)"    if (arrays[ j ] > arrays[j + 1]) {");
    outtextxy(600, 320, (LPCTSTR)"        int temp = arrays[ j ];");
    outtextxy(600, 360, (LPCTSTR)"        arrays[ j ] = arrays[j + 1];");
    settextcolor(GREEN); // 设置文本颜色为绿色
    outtextxy(600, 400, (LPCTSTR)"        arrays[j + 1] = temp;");
    settextcolor(BLACK); // 设置文本颜色为黑色
    outtextxy(600, 440, (LPCTSTR)"        }");
    outtextxy(600, 480, (LPCTSTR)"    }");
    outtextxy(600, 520, (LPCTSTR)"}");
    FlushBatchDraw();
    Sleep(100);
}   

void show( ) {
    BeginBatchDraw();
    cleardevice();       // 清空屏幕

    showCode();

    int width = 400 / (nums * 2);// 计算矩形块的宽度
    // 绘制每个数组元素对应的矩形块
    for (int i = 0; i < nums; ++i)
    {
        int height = arrays[i] * 3; // 根据数组元素的值计算矩形块的高度
        int x = i * width * 2 + 100; // 计算矩形块的左上角横坐标
        int y = 600 - height - 50;   // 计算矩形块的左上角纵坐标
        setfillcolor(RGB(0, 0, 255)); // 设置矩形块的填充颜色为蓝色
        setlinecolor(BLACK);          // 设置边框颜色为黑色
        setlinestyle(PS_SOLID, 1);    // 设置边框样式为实线，宽度为2像素
        rectangle(x, y, x + width, 600); // 绘制矩形块的边框
        if (i < nums - redIndex)
        {
            setfillcolor(RGB(255, 0, 0)); // 将索引为 redIndex 的柱子设为红色
        }
        if (i == greenIndex)
        {
            setfillcolor(RGB(0, 255, 0)); // 将索引为 greenIndex 的柱子设为绿色
        }
        fillrectangle(x + 1, y, x + width - 1, 600); // 绘制矩形块
        //Sleep(200); // 等待一段时间，使得矩形块一个个生成
    }
    FlushBatchDraw();
    //getch();      // 等待按键，保持窗口不关闭
    //closegraph(); // 关闭绘图窗口
}

void bubbleSort( ) {
    int codeKey = 0;
    for (int i = 0; i < nums - 1; ++i, ++redIndex) {
        codeAnime01();
        for (int j = 0; j < nums - i - 1; ++j) {
            greenIndex = j;
            if (arrays[j] > arrays[j + 1]) {
                greenIndex = j + 1;
                codeAnime02();

                // 交换 array[j] 和 array[j + 1] 的值
                int temp = arrays[j];
                arrays[j] = arrays[j + 1];
                arrays[j + 1] = temp;
            }
            show();
            Sleep(200);
        }
    }

    int width = 400 / (nums * 2);// 计算矩形块的宽度
    BeginBatchDraw();
    cleardevice();       // 清空屏幕

    showCode();

    for (int i = 0; i < nums; ++i)
    {
        int height = arrays[i] * 3; // 根据数组元素的值计算矩形块的高度
        int x = i * width * 2 + 100; // 计算矩形块的左上角横坐标
        int y = 600 - height - 50;   // 计算矩形块的左上角纵坐标
        setfillcolor(RGB(0, 0, 255)); // 设置矩形块的填充颜色为蓝色
        setlinecolor(BLACK);          // 设置边框颜色为黑色
        setlinestyle(PS_SOLID, 1);    // 设置边框样式为实线，宽度为2像素
        rectangle(x, y, x + width, 600); // 绘制矩形块的边框
        fillrectangle(x + 1, y, x + width - 1, 600); // 绘制矩形块
    }
    FlushBatchDraw();
    getch();      // 等待按键，保持窗口不关闭
    closegraph(); // 关闭绘图窗口
}

int main(){
    cout << "请输入你要生成的随机数的范围：";
    cin >> d >> h;
    cout << "请输入你要生成的随机数的数量：";
    cin >> nums;
    Randomness( );
    initgraph(1000, 600); // 初始化绘图窗口
    setbkcolor(WHITE);   // 设置背景颜色为白色
    bubbleSort( );



    return 0;
}