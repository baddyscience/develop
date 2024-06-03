#include "config.h"
#include <tchar.h>
#include <wchar.h>
#undef UNICODE

using namespace std;

int arrays[2048];
int d, h, nums;//���ɵ�������ķ�Χ������
int greenIndex;//��ǰ�ƶ�����
int redIndex = 0;//δ������ɵ���

void Randomness( ) {
    srand(time(0)); 
    int range = h - d + 1;
    for (int i = 0; i < nums; ++i) {
        arrays[i] = rand() % range + d;
    }
}

void showCode() {
    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
    outtextxy(10, 10, (LPCTSTR)"ð������");
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

    int width = 400 / (nums * 2);// ������ο�Ŀ��
    cleardevice();       // �����Ļ
    for (int i = 0; i < nums; ++i)
    {
        int height = arrays[i] * 3; // ��������Ԫ�ص�ֵ������ο�ĸ߶�
        int x = i * width * 2 + 100; // ������ο�����ϽǺ�����
        int y = 600 - height - 50;   // ������ο�����Ͻ�������
        setfillcolor(RGB(255, 0, 0)); // ���þ��ο�������ɫΪ��ɫ
        setlinecolor(BLACK);          // ���ñ߿���ɫΪ��ɫ
        setlinestyle(PS_SOLID, 1);    // ���ñ߿���ʽΪʵ�ߣ����Ϊ2����
        rectangle(x, y, x + width, 600); // ���ƾ��ο�ı߿�
        fillrectangle(x + 1, y, x + width - 1, 600); // ���ƾ��ο�
    }
    FlushBatchDraw();
}

void codeAnime01() {
    BeginBatchDraw();
    
    int width = 400 / (nums * 2);// ������ο�Ŀ��
    cleardevice();       // �����Ļ
    for (int i = 0; i < nums; ++i)
    {
        int height = arrays[i] * 3; // ��������Ԫ�ص�ֵ������ο�ĸ߶�
        int x = i * width * 2 + 100; // ������ο�����ϽǺ�����
        int y = 600 - height - 50;   // ������ο�����Ͻ�������
        setfillcolor(RGB(0, 0, 255)); // ���þ��ο�������ɫΪ��ɫ
        setlinecolor(BLACK);          // ���ñ߿���ɫΪ��ɫ
        setlinestyle(PS_SOLID, 1);    // ���ñ߿���ʽΪʵ�ߣ����Ϊ2����
        rectangle(x, y, x + width, 600); // ���ƾ��ο�ı߿�
        if (i < nums - redIndex)
        {
            setfillcolor(RGB(255, 0, 0)); // ������Ϊ redIndex ��������Ϊ��ɫ
        }
        fillrectangle(x + 1, y, x + width - 1, 600); // ���ƾ��ο�
    }

    outtextxy(10, 10, (LPCTSTR)"ð������");
    settextcolor(GREEN); // �����ı���ɫΪ��ɫ
    outtextxy(600, 200, (LPCTSTR)"for (int i = 0; i < nums - 1; ++i, ++redIndex ) {");
    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
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
    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
    outtextxy(10, 10, (LPCTSTR)"ð������");
    outtextxy(600, 200, (LPCTSTR)"for (int i = 0; i < nums - 1; ++i, ++redIndex ) {");
    settextcolor(GREEN); // �����ı���ɫΪ��ɫ
    outtextxy(600, 240, (LPCTSTR)"    for (int j = 0; j < nums - i - 1; ++j ) {");
    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
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
    outtextxy(10, 10, (LPCTSTR)"ð������");
    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
    outtextxy(600, 200, (LPCTSTR)"for (int i = 0; i < nums - 1; ++i, ++redIndex ) {");
    outtextxy(600, 240, (LPCTSTR)"    for (int j = 0; j < nums - i - 1; ++j ) {");
    settextcolor(GREEN); // �����ı���ɫΪ��ɫ
    outtextxy(600, 280, (LPCTSTR)"    if (arrays[ j ] > arrays[j + 1]) {");
    outtextxy(600, 320, (LPCTSTR)"        int temp = arrays[ j ];");
    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
    outtextxy(600, 360, (LPCTSTR)"        arrays[ j ] = arrays[j + 1];");
    outtextxy(600, 400, (LPCTSTR)"        arrays[j + 1] = temp;");
    outtextxy(600, 440, (LPCTSTR)"        }");
    outtextxy(600, 480, (LPCTSTR)"    }");
    outtextxy(600, 520, (LPCTSTR)"}");
    FlushBatchDraw();
    Sleep(100);

    BeginBatchDraw();
    clearShowCode();
    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
    outtextxy(10, 10, (LPCTSTR)"ð������");
    outtextxy(600, 200, (LPCTSTR)"for (int i = 0; i < nums - 1; ++i, ++redIndex ) {");
    outtextxy(600, 240, (LPCTSTR)"    for (int j = 0; j < nums - i - 1; ++j ) {");
    outtextxy(600, 280, (LPCTSTR)"    if (arrays[ j ] > arrays[j + 1]) {");
    settextcolor(GREEN); // �����ı���ɫΪ��ɫ
    outtextxy(600, 320, (LPCTSTR)"        int temp = arrays[ j ];");
    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
    outtextxy(600, 360, (LPCTSTR)"        arrays[ j ] = arrays[j + 1];");
    outtextxy(600, 400, (LPCTSTR)"        arrays[j + 1] = temp;");
    outtextxy(600, 440, (LPCTSTR)"        }");
    outtextxy(600, 480, (LPCTSTR)"    }");
    outtextxy(600, 520, (LPCTSTR)"}");
    FlushBatchDraw();
    Sleep(100);

    BeginBatchDraw();
    clearShowCode();
    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
    outtextxy(10, 10, (LPCTSTR)"ð������");
    outtextxy(600, 200, (LPCTSTR)"for (int i = 0; i < nums - 1; ++i, ++redIndex ) {");
    outtextxy(600, 240, (LPCTSTR)"    for (int j = 0; j < nums - i - 1; ++j ) {");
    outtextxy(600, 280, (LPCTSTR)"    if (arrays[ j ] > arrays[j + 1]) {");
    outtextxy(600, 320, (LPCTSTR)"        int temp = arrays[ j ];");
    settextcolor(GREEN); // �����ı���ɫΪ��ɫ
    outtextxy(600, 360, (LPCTSTR)"        arrays[ j ] = arrays[j + 1];");
    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
    outtextxy(600, 400, (LPCTSTR)"        arrays[j + 1] = temp;");
    outtextxy(600, 440, (LPCTSTR)"        }");
    outtextxy(600, 480, (LPCTSTR)"    }");
    outtextxy(600, 520, (LPCTSTR)"}");
    FlushBatchDraw();
    Sleep(100);

    BeginBatchDraw();
    clearShowCode();
    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
    outtextxy(10, 10, (LPCTSTR)"ð������");
    outtextxy(600, 200, (LPCTSTR)"for (int i = 0; i < nums - 1; ++i, ++redIndex ) {");
    outtextxy(600, 240, (LPCTSTR)"    for (int j = 0; j < nums - i - 1; ++j ) {");
    outtextxy(600, 280, (LPCTSTR)"    if (arrays[ j ] > arrays[j + 1]) {");
    outtextxy(600, 320, (LPCTSTR)"        int temp = arrays[ j ];");
    outtextxy(600, 360, (LPCTSTR)"        arrays[ j ] = arrays[j + 1];");
    settextcolor(GREEN); // �����ı���ɫΪ��ɫ
    outtextxy(600, 400, (LPCTSTR)"        arrays[j + 1] = temp;");
    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
    outtextxy(600, 440, (LPCTSTR)"        }");
    outtextxy(600, 480, (LPCTSTR)"    }");
    outtextxy(600, 520, (LPCTSTR)"}");
    FlushBatchDraw();
    Sleep(100);
}   

void show( ) {
    BeginBatchDraw();
    cleardevice();       // �����Ļ

    showCode();

    int width = 400 / (nums * 2);// ������ο�Ŀ��
    // ����ÿ������Ԫ�ض�Ӧ�ľ��ο�
    for (int i = 0; i < nums; ++i)
    {
        int height = arrays[i] * 3; // ��������Ԫ�ص�ֵ������ο�ĸ߶�
        int x = i * width * 2 + 100; // ������ο�����ϽǺ�����
        int y = 600 - height - 50;   // ������ο�����Ͻ�������
        setfillcolor(RGB(0, 0, 255)); // ���þ��ο�������ɫΪ��ɫ
        setlinecolor(BLACK);          // ���ñ߿���ɫΪ��ɫ
        setlinestyle(PS_SOLID, 1);    // ���ñ߿���ʽΪʵ�ߣ����Ϊ2����
        rectangle(x, y, x + width, 600); // ���ƾ��ο�ı߿�
        if (i < nums - redIndex)
        {
            setfillcolor(RGB(255, 0, 0)); // ������Ϊ redIndex ��������Ϊ��ɫ
        }
        if (i == greenIndex)
        {
            setfillcolor(RGB(0, 255, 0)); // ������Ϊ greenIndex ��������Ϊ��ɫ
        }
        fillrectangle(x + 1, y, x + width - 1, 600); // ���ƾ��ο�
        //Sleep(200); // �ȴ�һ��ʱ�䣬ʹ�þ��ο�һ��������
    }
    FlushBatchDraw();
    //getch();      // �ȴ����������ִ��ڲ��ر�
    //closegraph(); // �رջ�ͼ����
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

                // ���� array[j] �� array[j + 1] ��ֵ
                int temp = arrays[j];
                arrays[j] = arrays[j + 1];
                arrays[j + 1] = temp;
            }
            show();
            Sleep(200);
        }
    }

    int width = 400 / (nums * 2);// ������ο�Ŀ��
    BeginBatchDraw();
    cleardevice();       // �����Ļ

    showCode();

    for (int i = 0; i < nums; ++i)
    {
        int height = arrays[i] * 3; // ��������Ԫ�ص�ֵ������ο�ĸ߶�
        int x = i * width * 2 + 100; // ������ο�����ϽǺ�����
        int y = 600 - height - 50;   // ������ο�����Ͻ�������
        setfillcolor(RGB(0, 0, 255)); // ���þ��ο�������ɫΪ��ɫ
        setlinecolor(BLACK);          // ���ñ߿���ɫΪ��ɫ
        setlinestyle(PS_SOLID, 1);    // ���ñ߿���ʽΪʵ�ߣ����Ϊ2����
        rectangle(x, y, x + width, 600); // ���ƾ��ο�ı߿�
        fillrectangle(x + 1, y, x + width - 1, 600); // ���ƾ��ο�
    }
    FlushBatchDraw();
    getch();      // �ȴ����������ִ��ڲ��ر�
    closegraph(); // �رջ�ͼ����
}

int main(){
    cout << "��������Ҫ���ɵ�������ķ�Χ��";
    cin >> d >> h;
    cout << "��������Ҫ���ɵ��������������";
    cin >> nums;
    Randomness( );
    initgraph(1000, 600); // ��ʼ����ͼ����
    setbkcolor(WHITE);   // ���ñ�����ɫΪ��ɫ
    bubbleSort( );



    return 0;
}