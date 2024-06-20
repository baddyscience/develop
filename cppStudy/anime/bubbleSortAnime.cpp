#include "read.h"

vector<int> arrays;
int nums;//��������Ĵ�С
int greenIndex;//��ǰ�ƶ�����
int redIndex = 0;//δ������ɵ���
int js = 0;//j��ǰ����λ��
int width;// ������ο�Ŀ��
int tmp = 0;
int flag = 0;
int pos = 0;//������¼���һ�ν�����λ��
int k = 0;
bool isPaused = false;//��ͣ�жϱ�־

//�������п�ר�����
class Circle{
private:
    COLORREF color;
    int style;
    int thickness;

public:
    Circle() :color(BLACK), style(PS_SOLID), thickness(1) {}//Ĭ������Ϊ��ɫ��ʵ�ߣ�2����

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

//���ο�ר�����
class Rectangles{
private:
    int i;
    int height;
    int x;
    int y;
    COLORREF color;

public:
    Rectangles() : i(0), height(0), x(0), y(0) {}

    Rectangles(int ms) : i(ms) {
        height = arrays[i] * factor; // ��������Ԫ�ص�ֵ������ο�ĸ߶�
        x = i * width * 2 + animeWidth; // ������ο�����ϽǺ�����
        y = animeBotton - height;  // ������ο�����Ͻ�������
    }

    ~Rectangles() { }

    void drawRectangles() {
        setlinecolor(BLACK);          // ���ñ߿���ɫΪ��ɫ
        setlinestyle(PS_SOLID, 1);
        rectangle(x, y, x + width, animeBotton); // ���ƾ��ο�ı߿�
        fillrectangle(x + 1, y, x + width - 1, animeBotton); // ���ƾ��ο�
    }

};

void handleKeyboardInput() {
    if (_kbhit()) {  // ����Ƿ��м�������
        char ch = _getch();  // ��ȡ����
        if (ch == ' ') {  // ����Ƿ��ǿո��
            isPaused = !isPaused;  // �л���ͣ״̬
        }
    }
}

void readDataFromFile( ) {
    ifstream infile(testDataFile);
    
    if (!infile) {
        cerr << "Unable to open data file " << testDataFile << endl;
        return;
    }

    infile >> nums; // ��ȡ��һ�����֣��� nums
    if (nums <= 0) {
        cerr << "Invalid number of elements: " << nums << endl;
        return;
    }

    width = aWIDTH / (nums * 2);

    arrays.resize(nums); // ��̬���������С
    int value;
    for (int i = 0; i < nums; ++i) {
        if (infile >> value) {
            arrays[i] = value;
        } else {
            cerr << "Error reading value for element " << i << endl;
            return;
        }
    }
    
    infile.close();
}

// �����ͷ��������
void drawArrow(POINT end, POINT prev, int v) {
    double angle = atan2(end.y - prev.y, end.x - prev.x); // ��������ĩ�˵ķ���

    // �����ͷ��������
    POINT arrowPoint1, arrowPoint2;
	if (v == 1) {
		arrowPoint1.x = end.x - ARROW_LENGTH * cos(angle + ARROW_ANGLE);
		arrowPoint1.y = end.y - ARROW_LENGTH * sin(angle + ARROW_ANGLE);
		arrowPoint2.x = end.x - ARROW_LENGTH * cos(angle - ARROW_ANGLE);
		arrowPoint2.y = end.y - ARROW_LENGTH * sin(angle - ARROW_ANGLE);
	} else {
		arrowPoint1.x = end.x + ARROW_LENGTH * sin(angle + ARROW_ANGLE);
		arrowPoint1.y = end.y + ARROW_LENGTH * cos(angle + ARROW_ANGLE);
		arrowPoint2.x = end.x + ARROW_LENGTH * sin(angle - ARROW_ANGLE);
		arrowPoint2.y = end.y + ARROW_LENGTH * cos(angle - ARROW_ANGLE);
	}
    // ���Ƽ�ͷ
    line(end.x, end.y, arrowPoint1.x, arrowPoint1.y);
    line(end.x, end.y, arrowPoint2.x, arrowPoint2.y);
}

// �������߲���ĩ����Ӽ�ͷ
void drawCurveWithArrow(POINT start, POINT control, POINT end, COLORREF color, int v) {
    BeginBatchDraw();
    // ������ɫ
    setlinecolor(color);
    setlinestyle(PS_SOLID, 2);

    // ����Bezier����
    POINT prev = start;
    for (double t = 0; t <= 1; t += 0.01) {
        POINT current;
        current.x = (1 - t) * (1 - t) * start.x + 2 * t * (1 - t) * control.x + t * t * end.x;
        current.y = (1 - t) * (1 - t) * start.y + 2 * t * (1 - t) * control.y + t * t * end.y;
        line(prev.x, prev.y, current.x, current.y);
        prev = current;
    }

    // ���Ƽ�ͷ
    drawArrow(end, prev, v);
    FlushBatchDraw();
}

void drawTableCircle() {

    setlinecolor(BLACK);          // ���ñ߿���ɫΪ��ɫ
    setlinestyle(PS_SOLID, 1);
    for (int i = 0; i < tableCircleNums; i++) {
        rectangle(animeWidth + width * i, circley, animeWidth + width + width * i , circley + width);
    }

}

void showCode() {
    BeginBatchDraw();
    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
    outtextxy(codex, codey, (LPCTSTR)"1   void BubbleSort( ) {");
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
    char ch[20];
	sprintf(ch, "%d", tmp);
    outtextxy(animeWidth + width * nums, circley - width - 75, (LPCTSTR)"tmp");
    outtextxy(animeWidth + width * nums + width / 2 - width / 4, circley - width - 50, (LPCTSTR)ch);
    rectangle(animeWidth + width * nums, circley - width - 53, animeWidth + width * nums + width + 3, circley - 53);

    sprintf(ch, "%d", flag);
    outtextxy(animeWidth + width * nums + width * 2, circley - width - 75, (LPCTSTR)"flag");
    outtextxy(animeWidth + width * nums + width / 2 + width * 2, circley - width - 50, (LPCTSTR)ch);
    rectangle(animeWidth + width * nums + width * 2, circley - width - 53, animeWidth + width * nums + width + 3 + width * 2, circley - 53);

    sprintf(ch, "%d", pos);
    outtextxy(animeWidth + width * nums - width * 2, circley - width - 75, (LPCTSTR)"pos");
    outtextxy(animeWidth + width * nums + width / 2 - width * 2, circley - width - 50, (LPCTSTR)ch);
    rectangle(animeWidth + width * nums - width * 2, circley - width - 53, animeWidth + width * nums + width + 3 - width * 2, circley - 53);

    sprintf(ch, "%d", k);
    outtextxy(animeWidth + width * nums - width * 4, circley - width - 75, (LPCTSTR)"k");
    outtextxy(animeWidth + width * nums + width / 2 - width * 4, circley - width - 50, (LPCTSTR)ch);
    rectangle(animeWidth + width * nums - width * 4, circley - width - 53, animeWidth + width * nums + width + 3 - width * 4, circley - 53);
}

void showBlocks01() {
    BeginBatchDraw();

    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
    cleardevice();       // �����Ļ
    for (int i = 0; i < nums; ++i)
    {
        Rectangles ones(i);
        setfillcolor(RGB(255, 0, 0)); // ���þ��ο�������ɫΪ��ɫ
        drawTableCircle();//�����Ϸ���С����
        if (i == redIndex) {
            outtextxy(animeWidth + width * i + width / 2, circley - width, (LPCTSTR)"i");
        }
        if (i == js) {
            outtextxy(animeWidth + width * i + width / 2, circley + width + (width / 2) + 20, (LPCTSTR)"j");
        }
        char ch[20];
	    sprintf(ch, "%d", arrays[i]);
        outtextxy(animeWidth + width * i + 2, circley + 2, (LPCTSTR)ch);
        sprintf(ch, "%d", i);
        outtextxy(animeWidth + width * i + (width / 2), circley + width + (width / 2), (LPCTSTR)ch);
        ones.drawRectangles();
    }
    showCircleMore();

    FlushBatchDraw();
}

void codeAnimeStart() {
    showBlocks01();
    for (int i = 0; i < 5; i++) {
    start:
        handleKeyboardInput();
        if(isPaused){
            goto start;
        }
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
        if(isPaused){
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
        start:
        handleKeyboardInput();
        if(isPaused){
            goto start;
        }
        Circle stream;
        clearShowCode();
        showCode();
        BeginBatchDraw();
        stream.draw(codex - 10, codey + 270 - 10 + i * 30);
        FlushBatchDraw();
        Sleep(codeCirlceWaitintTime);
    }
    start01:
        handleKeyboardInput();
        if(isPaused){
            goto start01;
        }
    char ch[20];

    POINT start = {js * width + animeWidth + width / 2, circley};
    POINT control = {js * width / 2 + width * nums / 2 + animeWidth + width - 30, (circley + circley - 53) / 2 - 30};
    POINT end = {animeWidth + width * nums + width / 2, circley - 53};
    // ������ɫ (�����ɫ)
    COLORREF curveColor = RED;
    // ���ƴ���ͷ������
    drawCurveWithArrow(start, control, end, curveColor, 1);
    Sleep(curveWaitingTime);

    clearOneCircle(animeWidth + width * nums, circley - width - 53);
    BeginBatchDraw();
    sprintf(ch, "%d", arrays[js]);
    settextcolor(RED);
    outtextxy(animeWidth + width * nums + width / 2 - width / 4, circley - width - 50, (LPCTSTR)ch);
    FlushBatchDraw();
    Sleep(curveWaitingTime);
    clearOneCircle(animeWidth + width * nums + width / 2 - width / 4, circley - width - 53);
    BeginBatchDraw();
    settextcolor(BLACK);
    outtextxy(animeWidth + width * nums + width / 2 - width / 4, circley - width - 50, (LPCTSTR)ch);
    FlushBatchDraw();
    start02:
        handleKeyboardInput();
        if(isPaused){
            goto start02;
        }
    start = {(js + 1) * width + animeWidth + width / 2, circley + width + 3};
    control = {(js + 1) * width / 2 + js * width / 2 +  animeWidth + width / 2, circley + width + 23};
    end = {js * width + animeWidth + width / 2, circley + width + 3};
    // ���ƴ���ͷ������
    drawCurveWithArrow(start, control, end, curveColor, 0);
    Sleep(curveWaitingTime);

    clearOneCircle(js * width + animeWidth, circley);
    BeginBatchDraw();
    sprintf(ch, "%d", arrays[js+1]);
    settextcolor(RED);
    outtextxy(js * width + animeWidth + 2, circley + 2, (LPCTSTR)ch);
    FlushBatchDraw();
    Sleep(curveWaitingTime);
    clearOneCircle(js * width + animeWidth, circley);
    BeginBatchDraw();
    settextcolor(BLACK);
    outtextxy(js * width + animeWidth + 2, circley + 2, (LPCTSTR)ch);
    FlushBatchDraw();
    start03:
        handleKeyboardInput();
        if(isPaused){
            goto start03;
        }
    start = {animeWidth + width * nums + width / 2, circley - 53};
    control = {((js + 1) * width + animeWidth + width + animeWidth + width * nums) / 2 + 30, circley - 26 - 30};
    end = {(js + 1) * width + animeWidth + width / 2, circley};
    // ���ƴ���ͷ������
    drawCurveWithArrow(start, control, end, curveColor, 1);
    Sleep(curveWaitingTime);

    clearOneCircle((js + 1) * width + animeWidth, circley);
    BeginBatchDraw();
    sprintf(ch, "%d", arrays[js]);
    settextcolor(RED);
    outtextxy((js + 1) * width + animeWidth + 2, circley + 2, (LPCTSTR)ch);
    FlushBatchDraw();
    Sleep(curveWaitingTime);
    start04:
        handleKeyboardInput();
        if(isPaused){
            goto start04;
        }
}  

void codeAnime03() {

    for (int i = 0; i < 3; i++) {
        start:
        handleKeyboardInput();
        if(isPaused){
            goto start;
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
        start:
        handleKeyboardInput();
        if(isPaused){
            goto start;
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
    Sleep(codeCirlceWaitintTime);
}

void show( ) {
    cleardevice();       // �����Ļ

    showCode();
    BeginBatchDraw();
    // ����ÿ������Ԫ�ض�Ӧ�ľ��ο�
    for (int i = 0; i < nums; ++i)
    {
        Rectangles ones(i);
        setfillcolor(RGB(0, 0, 255)); // ���þ��ο�������ɫΪ��ɫ
        drawTableCircle();//�����Ϸ���С����
        if (i < nums - redIndex)
        {
            setfillcolor(RGB(255, 0, 0)); // ������Ϊ redIndex ��������Ϊ��ɫ
        }
        if (i == greenIndex)
        {
            setfillcolor(RGB(0, 255, 0)); // ������Ϊ greenIndex ��������Ϊ��ɫ
        }
        if (i == redIndex) {
            outtextxy(animeWidth + width * i + width / 2, circley - width, (LPCTSTR)"i");
        }
        if (i == js) {
            outtextxy(animeWidth + width * i + width / 2, circley + width + (width / 2) + 20, (LPCTSTR)"j");
        }
        char ch[20];
	    sprintf(ch, "%d", arrays[i]);
        outtextxy(animeWidth + width * i + 2, circley + 2, (LPCTSTR)ch);
        sprintf(ch, "%d", i);
        outtextxy(animeWidth + width * i + (width / 2), circley + width + (width / 2), (LPCTSTR)ch);
        ones.drawRectangles();
    }
    showCircleMore();

    FlushBatchDraw();
}

void bubbleSort( ) {
    tmp = 0;
	flag = 0;
	pos = 0;//������¼���һ�ν�����λ��
	k = nums - 1;
    codeAnimeStart();
	for (int i = 0; i < nums - 1; i++, ++redIndex) {//ȷ����������
		codeAnime01();
        pos = 0;
		flag = 0;
        js = 0;
		for (int j = 0; j < k; j++, ++js) {//ȷ���Ƚϴ���
        start:
            handleKeyboardInput();
            if (!isPaused) {
                greenIndex = j;
                if (arrays[j] > arrays[j + 1]) {
                    greenIndex = j + 1;
                    codeAnime02();
                    //����
                    tmp = arrays[j];
                    arrays[j] = arrays[j + 1];
                    arrays[j + 1] = tmp;
                    flag = 1;//������
                    pos = j;//����Ԫ�أ���¼���һ�ν�����λ��
                }
                show();
                Sleep(rectanglesWaitingTime);
            } else {
                goto start;
            }
		}
		if (flag == 0) {//���û�н�����Ԫ�أ����Ѿ�����
            codeAnime03();
			break;
		}
        codeAnime04();
		k = pos;//��һ�αȽϵ���¼λ�ü���
	}

    BeginBatchDraw();
    cleardevice();       // �����Ļ

    showCode();

    for (int i = 0; i < nums; ++i)
    {
        Rectangles ones(i);
        setfillcolor(RGB(0, 0, 255)); // ���þ��ο�������ɫΪ��ɫ
        drawTableCircle();//�����Ϸ���С����
        if (i == redIndex) {
            outtextxy(animeWidth + width * i + width / 2, circley - width, (LPCTSTR)"i");
        }
        if (i == js) {
            outtextxy(animeWidth + width * i + width / 2, circley + width + (width / 2) + 20, (LPCTSTR)"j");
        }
        char ch[20];
	    sprintf(ch, "%d", arrays[i]);
        outtextxy(animeWidth + width * i + 2, circley + 2, (LPCTSTR)ch);
        sprintf(ch, "%d", i);
        outtextxy(animeWidth + width * i + (width / 2), circley + width + (width / 2), (LPCTSTR)ch);
        ones.drawRectangles();
    }
    showCircleMore();

    FlushBatchDraw();
    getch();      // �ȴ����������ִ��ڲ��ر�
    closegraph(); // �رջ�ͼ����
}

int main(){
    readConfig();
    readDataFromFile();
    initgraph(Width, Height); // ��ʼ����ͼ����
    HWND hwnd = GetHWnd();
    SetWindowText(hwnd, (LPCTSTR)"ð�����򶯻���ʾ");//�޸Ĵ�����
    setbkcolor(backColour);   // ���ñ�����ɫΪ��ɫ
    const char* cstr = textStyle.c_str();
    settextstyle(textHeight, textWidth, (LPCTSTR)cstr);

    bubbleSort( );

    return 0;
}