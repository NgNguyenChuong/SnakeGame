#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "SoursePlayGame.h"
#include <vector>
#include<fstream>
using namespace std;

#define MAX 100 //so luong khung
#define T_COLOR 37 //Mau vien menu
#define B_COLOR 3
#define B_COLOR_SANG 62 //Mau moi khung lua chon
#define WIDTH 30
#define HEIGHT 2

int g = 45;//toa do ngang
int h = 10;//toa do doc
void box(int g, int h, int w, int ht, int t_color, int b_color, const string& nd);
void n_box(int g, int h, int w, int ht, int t_color, int b_color, string nd[], int num);
void menu();
void thanh_sang(int g, int h, int w, int ht, int b_color, const string& nd);
void batdau();
void ten_game();
void NSX();
void thongtin();
void thoat_game();
void thanhtuu();
//void  END_GAME();
string nd[] = { "START GAME", "SETTING ","ACHIEVEMENT", "INFORMATION", "EXIT" };
int num = 5;//so luong khung cua menu
int gp = g, hp = h; // vi tri hien tai
int gcu = gp, hcu = hp;

vector<int> diem_cao; //day se la cho tong hop cac diem cao



int lay_highest() {
    fstream Myfile;
    int highest_score;
    Myfile.open("C:\\git\\Snake_Game\\HighestScore.h", ios::in);
    Myfile >> highest_score;
    Myfile.close();
    return highest_score;
}

void box(int g, int h, int w, int ht, int t_color, int b_color, const string& nd) {
    SetColor(b_color);
    for (int ih = h + 1; ih <= h + ht - 1; ih++) {
        for (int ig = g + 1; ig <= g + w - 1; ig++) {
            gotoXY(ig, ih);
            cout << " ";
        }
    }

    SetColor(4); //Mau chu
    gotoXY(g + 10, h + 1);
    cout << nd;

    SetColor(1);
    Background_color(t_color);
    if (ht <= 1 || w <= 1) return;

    for (int ig = g; ig <= g + w; ig++) {
        gotoXY(ig, h);
        cout << char(196); //Thanh ngang tung khung
        gotoXY(ig, h + ht);
        cout << char(196); //Thanh ngang cuoi
    }
    for (int ih = h; ih <= h + ht; ih++) {
        gotoXY(g, ih);
        cout << char(179); //thanh doc trai
        gotoXY(g + w, ih);
        cout << char(179); //thanh doc phai
    }

    gotoXY(g, h);
    cout << char(218);
    gotoXY(g + w, h);
    cout << char(191);
    gotoXY(g, h + ht);
    cout << char(192);
    gotoXY(g + w, h + ht);
    cout << char(217);
}

void n_box(int g, int h, int w, int ht, int t_color, int b_color, string nd[], int num) {
    for (int i = 0; i < num; i++) {
        box(g, h + (i * 2), w, ht, t_color, b_color, nd[i]);
        if (i != 0) {
            gotoXY(g, h + (i * 2));
            cout << char(195);
            gotoXY(g + w, h + (i * 2));
            cout << char(180);
        }
    }
}

void thanh_sang(int g, int h, int w, int ht, int b_color, const string& nd) {
    SetColor(b_color);
    for (int ih = h + 1; ih <= h + ht - 1; ih++) {
        for (int ig = g + 1; ig <= g + w - 1; ig++) {
            gotoXY(ig, ih);
            cout << " ";
        }
    }
    Background_color(4); //Mau chu

    gotoXY(g + 10, h + 1);
    cout << nd;
}

void batdau() {
    clrscr();
    thanh_sang(g, h, WIDTH, HEIGHT, B_COLOR, " ");
    SetColor(6);
    gameover = false;
    sl = 5;
    x = 50;
    y = 13;
    Play_Game();
    diem_cao.push_back(diem_ky_luc);
   
    _getch();
}

void caidat() {
    clrscr();
    thanh_sang(gcu, hcu, WIDTH, HEIGHT, B_COLOR, " ");
    SetColor(6);
    gotoXY(45, 10);
    cout << "Put setting code here...";
    _getch();
    return;
}

void thongtin() {
    clrscr();
    thanh_sang(gcu, hcu, WIDTH, HEIGHT, B_COLOR, " ");
    gotoXY(45, 10);
    SetColor(6);
    cout << "Showing information";
    NSX();
    _getch();
    return;
}

void thanhtuu() {
    clrscr();
    thanh_sang(gcu, hcu, WIDTH, HEIGHT, B_COLOR, " ");
    gotoXY(45, 10);
    cout << "Achievement ..." << endl;
    gotoXY(43, 12);
    SetColor(6);
    int pre_highest = lay_highest();
    int Diem_Max = 0;
    if (!diem_cao.empty()) {
        Diem_Max = *max_element(diem_cao.begin(), diem_cao.end());
        if (Diem_Max < pre_highest) {
            Diem_Max = pre_highest;
        }
        else {
            fstream Myfile;
            Myfile.open("C:\\Users\\admin\\Documents\\Snake_Game\\Snake_Game\\HighestScore.h", ios::out);
            Myfile << Diem_Max;
            Myfile.close();
        }
        cout << "Highest Score: " << Diem_Max << endl;
    }
    else {
        cout << "Highest Score: " << pre_highest;
    }
    _getch();
}

void thoat_game() {
    clrscr();
    thanh_sang(gcu, hcu, WIDTH, HEIGHT, B_COLOR, " ");
    gotoXY(45, 10);
    SetColor(6);
    cout << "Exiting game. Thanks for playing!" << endl;
    _getch();
    exit(0);
}

void menu() {
    n_box(g, h, WIDTH, HEIGHT, T_COLOR, B_COLOR, nd, num);
    bool kt = true;
    while (true) {
        if (kt) {
            gotoXY(gcu, hcu);
            thanh_sang(gcu, hcu, WIDTH, HEIGHT, B_COLOR, nd[(hcu - h) / 2]);
            gcu = gp, hcu = hp;
            thanh_sang(gp, hp, WIDTH, HEIGHT, B_COLOR_SANG, "->" + nd[(hp - h) / 2]);
            kt = false;
        }

        if (_kbhit()) {
            char c = _getch();
            if (c == -32) {
                kt = true;
                c = _getch();
                if (c == 72) { // mui ten len
                    if (hp != h) {
                        hp -= 2;
                    }
                    else {
                        hp = h + HEIGHT * (num - 1);
                    }
                }
                else if (c == 80) { // mui ten xuong
                    if (hp != h + HEIGHT * (num - 1)) {
                        hp += 2;
                    }
                    else {
                        hp = h;
                    }
                }
            }
            else if (c == 13) {
                clrscr();
                switch ((hp - h) / 2) {
                case 0:
                    batdau();
                    thanh_sang(gcu, hcu, WIDTH, HEIGHT, B_COLOR, nd[(hcu - h) / 2]);
                    break;
                case 1:
                    caidat();
                    break;
                case 2:
                    thanhtuu();
                    _getch();
                    break;
                case 3:
                    thongtin();
                    break;
                case 4:
                    thoat_game();
                }
                kt = true;
                clrscr();
                ten_game();
                n_box(g, h, WIDTH, HEIGHT, T_COLOR, B_COLOR, nd, num);
            }
        }
    }
}

void ten_game() {
    SetColor(6);
    const string title = R"(                    
	                 ____  _   _    _    _  _______ _ ____     ____    _    __  __ _____ 
	                / ___|| \ | |  / \  | |/ / ____( ) ___|   / ___|  / \  |  \/  | ____|
	                \___ \|  \| | / _ \ | ' /|  _| |/\___ \  | |  _  / _ \ | |\/| |  _|  
	                 ___) | |\  |/ ___ \| . \| |___   ___) | | |_| |/ ___ \| |  | | |___ 
	                |____/|_| \_/_/   \_\_|\_\_____| |____/   \____/_/   \_\_|  |_|_____|)";

    cout << title << '\t' << endl;
}
void NSX() {
    SetColor(11);
    const string title = R"(
			/ \------------------------------------------------------, 
			\_,|                                                     |
			   |     Coder Menu:Tran Quoc An		         |   
			   | 	 Coder Gameplay: Nguyen Nguyen Chuong		 |
			   |  ,--------------------------------------------------'
			   \_/___________________________________________________/ 
)";
    cout << title << '\t' << endl;
}

