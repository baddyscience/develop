#include <conio.h>
#include <graphics.h>
#include <iostream>
#include <windows.h>
#include <random>
#include <thread>
#include <tchar.h>
#include <wchar.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

std::string testDataFile = "data.txt";
int Width, Height;
long backColour;
int animeWidth, animeBotton;
int aWIDTH;
int circley;
int codex, codey;
int codeCirlceLongth;
int codeCirlceWidth;
int tableCircleNums;
int factor;
int tableCirclueWidth;
int ARROW_LENGTH;
double ARROW_ANGLE;
int textHeight ,textWidth;
std::string textStyle = "黑体";
int codeCirlceWaitintTime;
int curveWaitingTime;
int rectanglesWaitingTime;

// 函数用于去除注释（从 '//' 开始的部分）
std::string removeComments(const std::string& line) {
    size_t pos = line.find("//");
    if (pos != string::npos) {
        return line.substr(0, pos);
    }
    return line;
}

void readConfig() {
    //ifstream infile("D://temp//202224111120//ConsoleApplication1//config.txt");
    ifstream infile("config.txt");
    if (!infile) {
        cerr << "Unable to open config file" << endl;
        return;
    }

    string line;

    if (getline(infile, line)) {
        line = removeComments(line);
        stringstream buffer(line);
        buffer >> testDataFile;
        testDataFile.erase(testDataFile.find_last_not_of(" \n\r\t")+1);
    }
    
    cout << "Test data file: " << testDataFile << endl;

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> Width >> Height;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> backColour;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> animeWidth >> animeBotton;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> aWIDTH;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> circley;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> codex >> codey;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> codeCirlceLongth;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> codeCirlceWidth;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> tableCircleNums;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> factor;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> tableCirclueWidth;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> ARROW_LENGTH;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> ARROW_ANGLE;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> textHeight >> textWidth;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        stringstream buffer(line);
        buffer >> textStyle;
        textStyle.erase(textStyle.find_last_not_of(" \n\r\t")+1);
    }

    cout << "Test text style: " << testDataFile << endl;

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> codeCirlceWaitintTime;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> curveWaitingTime;
    }

    if (getline(infile, line)) {
        line = removeComments(line);
        istringstream iss(line);
        iss >> rectanglesWaitingTime;
    }

    infile.close();
}