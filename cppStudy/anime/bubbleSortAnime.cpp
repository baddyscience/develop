#include "read.h"

vector<int> arrays;
int nums;//测试数组的大小
int greenIndex;//当前移动的数
int is = 0;
int js = 0;//j当前所在位置
int width;// 计算矩形块的宽度
int tmp = 0;
int flag = 0;
int pos = 0;//用来记录最后一次交换的位置
int k = 0;
bool isPaused = false;//暂停判断标志

//代码运行框专设的类
class Circle {
private:
    COLORREF color;
    int style;
    int thickness;

public:
    Circle() :color(BLACK), style(PS_SOLID), thickness(1) {}//默认设置为黑色，实线，2像素

    Circle(COLORREF setColor, int setStyle, int setThickness) {
        color = setColor;
        style = setStyle;
        thickness = setThickness;
    }

    ~Circle() { }

    void draw(int x, int y) {
        setlinecolor(color);
        setlinestyle(style, thickness);
        rectangle(x, y, x + codeCirlceLongth, y + codeCirlceWidth);
    }
};

//矩形块专设的类
class Rectangles {
private:
    int i;
    int height;
    int x;
    int y;

public:
    Rectangles() : i(0), height(0), x(0), y(0) {}

    Rectangles(int ms) : i(ms) {
        height = arrays[i] * factor; // 根据数组元素的值计算矩形块的高度
        x = i * width * 2 + animeWidth; // 计算矩形块的左上角横坐标
        y = animeBotton - height;  // 计算矩形块的左上角纵坐标
    }

    ~Rectangles() { }

    void drawRectangles() {
        setlinecolor(BLACK);          // 设置边框颜色为黑色
        setlinestyle(PS_SOLID, 1);
        rectangle(x, y, x + width, animeBotton); // 绘制矩形块的边框
        fillrectangle(x + 1, y, x + width - 1, animeBotton); // 绘制矩形块
    }

};

void handleKeyboardInput() {
    // 检测是否有键盘输入
    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        // 切换暂停状态
        isPaused = !isPaused;
        // 避免重复检测同一次按键，等待按键释放
        while (GetAsyncKeyState(VK_SPACE) & 0x8000);
    }
}

void readDataFromFile() {
    ifstream infile(testDataFile);

    if (!infile) {
        cerr << "Unable to open data file " << testDataFile << endl;
        return;
    }

    infile >> nums; // 读取第一个数字，即 nums
    if (nums <= 0) {
        cerr << "Invalid number of elements: " << nums << endl;
        return;
    }

    width = aWIDTH / (nums * 2);

    arrays.resize(nums); // 动态调整数组大小
    int value;
    for (int i = 0; i < nums; ++i) {
        if (infile >> value) {
            arrays[i] = value;
        }
        else {
            cerr << "Error reading value for element " << i << endl;
            return;
        }
    }

    infile.close();
}

// 计算箭头的两个点
void drawArrow(POINT end, POINT prev, int v) {
    double angle = atan2(end.y - prev.y, end.x - prev.x); // 计算曲线末端的方向

    // 计算箭头的两个点
    POINT arrowPoint1, arrowPoint2;
    if (v == 1) {
        arrowPoint1.x = end.x - ARROW_LENGTH * cos(angle + ARROW_ANGLE);
        arrowPoint1.y = end.y - ARROW_LENGTH * sin(angle + ARROW_ANGLE);
        arrowPoint2.x = end.x - ARROW_LENGTH * cos(angle - ARROW_ANGLE);
        arrowPoint2.y = end.y - ARROW_LENGTH * sin(angle - ARROW_ANGLE);
    }
    else {
        arrowPoint1.x = end.x + ARROW_LENGTH * sin(angle + ARROW_ANGLE);
        arrowPoint1.y = end.y + ARROW_LENGTH * cos(angle + ARROW_ANGLE);
        arrowPoint2.x = end.x + ARROW_LENGTH * sin(angle - ARROW_ANGLE);
        arrowPoint2.y = end.y + ARROW_LENGTH * cos(angle - ARROW_ANGLE);
    }
    // 绘制箭头
    line(end.x, end.y, arrowPoint1.x, arrowPoint1.y);
    line(end.x, end.y, arrowPoint2.x, arrowPoint2.y);
}

// 绘制曲线并在末端添加箭头
void drawCurveWithArrow(POINT start, POINT control, POINT end, COLORREF color, int v) {
    BeginBatchDraw();
    // 设置颜色
    setlinecolor(color);
    setlinestyle(PS_SOLID, 2);

    // 绘制Bezier曲线
    POINT prev = start;
    for (double t = 0; t <= 1; t += 0.01) {
        POINT current;
        current.x = (1 - t) * (1 - t) * start.x + 2 * t * (1 - t) * control.x + t * t * end.x;
        current.y = (1 - t) * (1 - t) * start.y + 2 * t * (1 - t) * control.y + t * t * end.y;
        line(prev.x, prev.y, current.x, current.y);
        prev = current;
    }

    // 绘制箭头
    drawArrow(end, prev, v);
    FlushBatchDraw();
}

void drawTableCircle() {

    setlinecolor(BLACK);          // 设置边框颜色为黑色
    setlinestyle(PS_SOLID, 1);
    for (int i = 0; i < tableCircleNums; i++) {
        rectangle(animeWidth + tableCirclueWidth * i, circley, animeWidth + tableCirclueWidth + tableCirclueWidth * i, circley + tableCirclueWidth);
    }

}

void showCode() {
    BeginBatchDraw();
    settextcolor(BLACK); // 设置文本颜色为黑色
    outtextxy(codex, codey, (LPCTSTR)"1   void BubbleSort( ) {");

    // "int binarySearch( int arr[], int n, int target )"

    outtextxy(codex, codey + 30, (LPCTSTR)"2       int k = nums - 1;");
    outtextxy(codex, codey + 60, (LPCTSTR)"3       int pos = 0;");
    outtextxy(codex, codey + 90, (LPCTSTR)"4       int tmp = 0;");
    outtextxy(codex, codey + 120, (LPCTSTR)"5       int flag = 0;");
    outtextxy(codex, codey + 150, (LPCTSTR)"6       for (int i = 0; i < len - 1; i++) {");
    outtextxy(codex, codey + 180, (LPCTSTR)"7           pos = 0;");
    outtextxy(codex, codey + 210, (LPCTSTR)"8           flag = 0;");
    outtextxy(codex, codey + 240, (LPCTSTR)"9           for (int j = 0; j < k; j++) {");
    outtextxy(codex, codey + 270, (LPCTSTR)"10              if (arr[j] > arr[j + 1]) {");
    outtextxy(codex, codey + 300, (LPCTSTR)"11                  tmp = arr[j];");
    outtextxy(codex, codey + 330, (LPCTSTR)"12                  arr[j] = arr[j + 1];");
    outtextxy(codex, codey + 360, (LPCTSTR)"13                  arr[j + 1] = tmp;");
    outtextxy(codex, codey + 390, (LPCTSTR)"14                  flag = 1;");
    outtextxy(codex, codey + 420, (LPCTSTR)"15                  pos = j;");
    outtextxy(codex, codey + 450, (LPCTSTR)"16              }");
    outtextxy(codex, codey + 480, (LPCTSTR)"17           }");
    outtextxy(codex, codey + 510, (LPCTSTR)"18           if (flag == 0) {");
    outtextxy(codex, codey + 540, (LPCTSTR)"19               break;");
    outtextxy(codex, codey + 570, (LPCTSTR)"20           }");
    outtextxy(codex, codey + 600, (LPCTSTR)"21           k = pos;");
    outtextxy(codex, codey + 630, (LPCTSTR)"22      }");
    outtextxy(codex, codey + 660, (LPCTSTR)"23  }");
    FlushBatchDraw();
}

void clearShowCode() {
    BeginBatchDraw();
    setfillcolor(RGB(255, 255, 255));
    solidrectangle(codex - 20, codey - 20, codex + codeCirlceLongth + 20, codey + 1000);
    FlushBatchDraw();
}

void claerCircle() {
    BeginBatchDraw();
    setfillcolor(RGB(255, 255, 255));
    solidrectangle(animeWidth - 30, 50, animeWidth + codeCirlceLongth + 20, animeBotton + 30);
    FlushBatchDraw();
}

void clearOneCircle(int x, int y) {
    BeginBatchDraw();
    setfillcolor(RGB(255, 255, 255));
    solidrectangle(x + 2, y + 3, x + width / 2, y + width - 3);
    FlushBatchDraw();
}

void showCircleMore() {
    outtextxy(20, 100, (LPCTSTR)"arr[]");

    char ch[20];
    sprintf_s(ch, "%d", tmp);
    outtextxy(animeWidth + width * nums, circley - tableCirclueWidth - 75, (LPCTSTR)"tmp");
    outtextxy(animeWidth + width * nums + tableCirclueWidth / 2 - tableCirclueWidth / 4, circley - tableCirclueWidth - 50, (LPCTSTR)ch);
    rectangle(animeWidth + width * nums, circley - tableCirclueWidth - 53, animeWidth + width * nums + tableCirclueWidth + 3, circley -  53);

    sprintf_s(ch, "%d", flag);
    outtextxy(animeWidth + width * nums + tableCirclueWidth * 2, circley - tableCirclueWidth - 75, (LPCTSTR)"flag");
    outtextxy(animeWidth + width * nums + tableCirclueWidth / 4 + tableCirclueWidth * 2, circley - tableCirclueWidth - 50, (LPCTSTR)ch);
    rectangle(animeWidth + width * nums + tableCirclueWidth * 2, circley - tableCirclueWidth - 53, animeWidth + width * nums + tableCirclueWidth + 3 + tableCirclueWidth * 2, circley - 53);

    sprintf_s(ch, "%d", pos);
    outtextxy(animeWidth + width * nums - tableCirclueWidth * 2, circley - tableCirclueWidth - 75, (LPCTSTR)"pos");
    outtextxy(animeWidth + width * nums + tableCirclueWidth / 4 - tableCirclueWidth * 2, circley - tableCirclueWidth - 50, (LPCTSTR)ch);
    rectangle(animeWidth + width * nums - tableCirclueWidth * 2, circley - tableCirclueWidth - 53, animeWidth + width * nums + tableCirclueWidth + 3 - tableCirclueWidth * 2, circley - 53);

    sprintf_s(ch, "%d", k);
    outtextxy(animeWidth + width * nums - tableCirclueWidth * 4, circley - tableCirclueWidth - 75, (LPCTSTR)"k");
    outtextxy(animeWidth + width * nums + tableCirclueWidth / 4 - tableCirclueWidth * 4, circley - tableCirclueWidth - 50, (LPCTSTR)ch);
    rectangle(animeWidth + width * nums - tableCirclueWidth * 4, circley - tableCirclueWidth - 53, animeWidth + width * nums + tableCirclueWidth + 3 - tableCirclueWidth * 4, circley - 53);
}

void showBlocks01() {
    BeginBatchDraw();

    settextcolor(BLACK); // 设置文本颜色为黑色
    cleardevice();       // 清空屏幕
    for (int i = 0; i < nums; ++i)
    {
        Rectangles ones(i);
        setfillcolor(RGB(255, 0, 0)); // 设置矩形块的填充颜色为红色
        drawTableCircle();//绘制上方的小方格
        if (i == is) {
            outtextxy(animeWidth + tableCirclueWidth * i + tableCirclueWidth / 4, circley - tableCirclueWidth, (LPCTSTR)"i");
        }
        if (i == js) {
            outtextxy(animeWidth + tableCirclueWidth * i + tableCirclueWidth / 4, circley + tableCirclueWidth + (tableCirclueWidth / 2) + 20, (LPCTSTR)"j");
        }
        char ch[20];
        sprintf_s(ch, "%d", arrays[i]);
        outtextxy(animeWidth + tableCirclueWidth * i + 2, circley + 2, (LPCTSTR)ch);
        outtextxy(i * width * 2 + animeWidth, animeBotton - arrays[i] * factor - width * 2, (LPCTSTR)ch);
        sprintf_s(ch, "%d", i);
        outtextxy(animeWidth + tableCirclueWidth * i + (tableCirclueWidth / 4), circley + tableCirclueWidth + (tableCirclueWidth / 2), (LPCTSTR)ch);
        ones.drawRectangles();
    }
    showCircleMore();

    FlushBatchDraw();
}

void codeAnimeStart() {
    showBlocks01();
    for (int i = 0; i < 5; i++) {
        Circle stream;
        clearShowCode();
        showCode();
        BeginBatchDraw();
        stream.draw(codex - 10, codey - 10 + i * 30);
        FlushBatchDraw();
        Sleep(codeCirlceWaitintTime);
    }
}

void codeAnime01() {

    for (int i = 0; i < 4; i++) {
    start:
        handleKeyboardInput();
        if (isPaused) {
            goto start;
        }
        Circle stream;
        clearShowCode();
        showCode();
        BeginBatchDraw();
        stream.draw(codex - 10, codey + 150 - 10 + i * 30);
        FlushBatchDraw();
        Sleep(codeCirlceWaitintTime);
    }
}

void codeAnime02() {

    for (int i = 0; i < 7; i++) {
    start00: // 空格暂停
        handleKeyboardInput();
        if (isPaused) {
            goto start00;
        }

        Circle stream;
        clearShowCode();
        showCode();
        BeginBatchDraw();
        stream.draw(codex - 10, codey + 270 - 10 + i * 30);
        FlushBatchDraw();
        Sleep(codeCirlceWaitintTime);
    }

start01: // 空格暂停
    handleKeyboardInput();
    if (isPaused) {
        goto start01;
    }

    char ch[20];

    POINT start = { js * tableCirclueWidth + animeWidth + tableCirclueWidth / 2, circley };
    POINT control = { js * tableCirclueWidth / 2 + width * nums / 2 + animeWidth + tableCirclueWidth - 30, (circley + circley - 53) / 2 - 30 };
    POINT end = { animeWidth + width * nums + tableCirclueWidth / 2, circley - 53 };
    // 设置颜色 (例如红色)
    COLORREF curveColor = RED;
    // 绘制带箭头的曲线
    drawCurveWithArrow(start, control, end, curveColor, 1);
    Sleep(curveWaitingTime);

    clearOneCircle(animeWidth + width * nums, circley - tableCirclueWidth - 53);
    BeginBatchDraw();
    sprintf_s(ch, "%d", arrays[js]);
    settextcolor(RED);
    outtextxy(animeWidth + width * nums + tableCirclueWidth / 2 - tableCirclueWidth / 4, circley - tableCirclueWidth - 50, (LPCTSTR)ch);
    FlushBatchDraw();
    Sleep(curveWaitingTime);
    clearOneCircle(animeWidth + width * nums + tableCirclueWidth / 2 - tableCirclueWidth / 4, circley - tableCirclueWidth - 53);
    BeginBatchDraw();
    settextcolor(BLACK);
    outtextxy(animeWidth + width * nums + tableCirclueWidth / 2 - tableCirclueWidth / 4, circley - tableCirclueWidth - 50, (LPCTSTR)ch);
    FlushBatchDraw();

start02: // 空格暂停
    handleKeyboardInput();
    if (isPaused) {
        goto start02;
    }

    start = { (js + 1) * tableCirclueWidth + animeWidth + tableCirclueWidth / 2, circley + tableCirclueWidth + 3 };
    control = { (js + 1) * tableCirclueWidth / 2 + js * tableCirclueWidth / 2 + animeWidth + tableCirclueWidth / 2, circley + tableCirclueWidth + 23 };
    end = { js * tableCirclueWidth + animeWidth + tableCirclueWidth / 2, circley + tableCirclueWidth + 3 };
    // 绘制带箭头的曲线
    drawCurveWithArrow(start, control, end, curveColor, 0);
    Sleep(curveWaitingTime);

    clearOneCircle(js * tableCirclueWidth + animeWidth, circley);
    BeginBatchDraw();
    sprintf_s(ch, "%d", arrays[js + 1]);
    settextcolor(RED);
    outtextxy(js * tableCirclueWidth + animeWidth + 2, circley + 2, (LPCTSTR)ch);
    FlushBatchDraw();
    Sleep(curveWaitingTime);
    clearOneCircle(js * tableCirclueWidth + animeWidth, circley);
    BeginBatchDraw();
    settextcolor(BLACK);
    outtextxy(js * tableCirclueWidth + animeWidth + 2, circley + 2, (LPCTSTR)ch);
    FlushBatchDraw();

start03: // 空格暂停
    handleKeyboardInput();
    if (isPaused) {
        goto start03;
    }

    start = { animeWidth + width * nums + tableCirclueWidth / 2, circley - 53 };
    control = { ((js + 1) * tableCirclueWidth + animeWidth + tableCirclueWidth + animeWidth + width * nums) / 2 + 30, circley - 26 - 30 };
    end = { (js + 1) * tableCirclueWidth + animeWidth + tableCirclueWidth / 2, circley };
    // 绘制带箭头的曲线
    drawCurveWithArrow(start, control, end, curveColor, 1);
    Sleep(curveWaitingTime);

    clearOneCircle((js + 1) * tableCirclueWidth + animeWidth, circley);
    BeginBatchDraw();
    sprintf_s(ch, "%d", arrays[js]);
    settextcolor(RED);
    outtextxy((js + 1) * tableCirclueWidth + animeWidth + 2, circley + 2, (LPCTSTR)ch);
    FlushBatchDraw();
    Sleep(curveWaitingTime);

start04: // 空格暂停
    handleKeyboardInput();
    if (isPaused) {
        goto start04;
    }
}

void codeAnime03() {

    for (int i = 0; i < 3; i++) {

    start00: // 空格暂停
        handleKeyboardInput();
        if (isPaused) {
            goto start00;
        }

        Circle stream;
        clearShowCode();
        showCode();
        BeginBatchDraw();
        stream.draw(codex - 10, codey + 510 - 10 + i * 30);
        FlushBatchDraw();
        Sleep(codeCirlceWaitintTime);
    }

}

void codeAnime04() {

    for (int i = 0; i < 2; i++) {

    start00: // 空格暂停
        handleKeyboardInput();
        if (isPaused) {
            goto start00;
        }

        Circle stream;
        clearShowCode();
        showCode();
        BeginBatchDraw();
        stream.draw(codex - 10, codey + 480 - 10 + i * 30);
        FlushBatchDraw();
        Sleep(codeCirlceWaitintTime);
    }

    clearShowCode();
    Circle stream;
    showCode();
    BeginBatchDraw();
    stream.draw(codex - 10, codey + 600 - 10);
    FlushBatchDraw();

start01: // 空格暂停
    handleKeyboardInput();
    if (isPaused) {
        goto start01;
    }
    Sleep(codeCirlceWaitintTime);

    clearShowCode();
    Circle stream01;
    showCode();
    BeginBatchDraw();
    stream01.draw(codex - 10, codey + 630 - 10);
    FlushBatchDraw();

start02: // 空格暂停
    handleKeyboardInput();
    if (isPaused) {
        goto start02;
    }
    Sleep(codeCirlceWaitintTime);
}

void show() {
    cleardevice();       // 清空屏幕

    showCode();
    BeginBatchDraw();
    // 绘制每个数组元素对应的矩形块
    for (int i = 0; i < nums; ++i)
    {
        Rectangles ones(i);
        setfillcolor(RGB(0, 0, 255)); // 设置矩形块的填充颜色为蓝色
        drawTableCircle();//绘制上方的小方格
        if (i < k + 1)
        {
            setfillcolor(RGB(255, 0, 0)); // 将索引为 redIndex 的柱子设为红色
        }
        if (i == greenIndex)
        {
            setfillcolor(RGB(0, 255, 0)); // 将索引为 greenIndex 的柱子设为绿色
        }
        if (i == is) {
            outtextxy(animeWidth + tableCirclueWidth * i + tableCirclueWidth / 4, circley - tableCirclueWidth, (LPCTSTR)"i");
        }
        if (i == js) {
            outtextxy(animeWidth + tableCirclueWidth * i + tableCirclueWidth / 4, circley + tableCirclueWidth + (tableCirclueWidth / 2) + 20, (LPCTSTR)"j");
        }
        char ch[20];
        sprintf_s(ch, "%d", arrays[i]);
        outtextxy(i * width * 2 + animeWidth, animeBotton - arrays[i] * factor - width * 2, (LPCTSTR)ch);
        outtextxy(animeWidth + tableCirclueWidth * i + 2, circley + 2, (LPCTSTR)ch);
        sprintf_s(ch, "%d", i);
        outtextxy(animeWidth + tableCirclueWidth * i + (tableCirclueWidth / 4), circley + tableCirclueWidth + (tableCirclueWidth / 2), (LPCTSTR)ch);
        ones.drawRectangles();
    }
    showCircleMore();

    FlushBatchDraw();
}

void bubbleSort() {
    tmp = 0;
    flag = 0;
    pos = 0;//用来记录最后一次交换的位置
    k = nums - 1;
    codeAnimeStart();
    for (int i = 0; i < nums - 1; i++, is++) {//确定排序趟数
        codeAnime01();
        pos = 0;
        flag = 0;
        js = 0;
        for (int j = 0; j < k; j++, ++js) {//确定比较次数
        start:
            handleKeyboardInput();
            if (!isPaused) {
                greenIndex = j;
                if (arrays[j] > arrays[j + 1]) {
                    greenIndex = j + 1;
                    codeAnime02();
                    handleKeyboardInput();
                    // 交换
                    tmp = arrays[j];
                    arrays[j] = arrays[j + 1];
                    arrays[j + 1] = tmp;
                    flag = 1;//加入标记
                    pos = j;//交换元素，记录最后一次交换的位置
                }
                handleKeyboardInput();
                show();
                Sleep(rectanglesWaitingTime);
            }
            else {
                handleKeyboardInput();
                goto start;
            }
        }
        if (flag == 0) {//如果没有交换过元素，则已经有序
            codeAnime03();
            break;
        }
        codeAnime04();
        k = pos;//下一次比较到记录位置即可
    }

    BeginBatchDraw();
    cleardevice();       // 清空屏幕

    showCode();

    for (int i = 0; i < nums; ++i)
    {
        Rectangles ones(i);
        setfillcolor(RGB(0, 0, 255)); // 设置矩形块的填充颜色为蓝色
        drawTableCircle();//绘制上方的小方格
        if (i == is) {
            outtextxy(animeWidth + tableCirclueWidth * i + tableCirclueWidth / 4, circley - tableCirclueWidth, (LPCTSTR)"i");
        }
        if (i == js) {
            outtextxy(animeWidth + tableCirclueWidth * i + tableCirclueWidth / 4, circley + tableCirclueWidth + (tableCirclueWidth / 2) + 20, (LPCTSTR)"j");
        }
        char ch[20];
        sprintf_s(ch, "%d", arrays[i]);
        outtextxy(animeWidth + tableCirclueWidth * i + 2, circley + 2, (LPCTSTR)ch);
        outtextxy(i * width * 2 + animeWidth, animeBotton - arrays[i] * factor - width * 2, (LPCTSTR)ch);
        sprintf_s(ch, "%d", i);
        outtextxy(animeWidth + tableCirclueWidth * i + (tableCirclueWidth / 4), circley + tableCirclueWidth + (tableCirclueWidth / 2), (LPCTSTR)ch);
        ones.drawRectangles();
    }
    showCircleMore();

    FlushBatchDraw();
    getchar();      // 等待按键，保持窗口不关闭
    closegraph(); // 关闭绘图窗口
}

int main() {
    readConfig();
    readDataFromFile();
    initgraph(Width, Height); // 初始化绘图窗口
    HWND hwnd = GetHWnd();
    SetWindowText(hwnd, (LPCTSTR)"冒泡排序动画演示");//修改窗口名
    setbkcolor(backColour);   // 设置背景颜色为白色
    const char* cstr = textStyle.c_str();
    settextstyle(textHeight, textWidth, (LPCTSTR)cstr);

    bubbleSort();

    return 0;
}