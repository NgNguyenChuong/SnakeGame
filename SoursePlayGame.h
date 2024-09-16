#pragma once
#include "Global.h"
#include<iostream>
using namespace std;



#define MAX 100
int diem_ky_luc = 0;
int x_nhen = 30;
int sl = 6;
bool gameover = true;
int toa_do_X[MAX], toa_do_Y[MAX];
int x = 50, y = 13;
int x_qua = 0, y_qua = 0;
int Check_Direction = 2;
int y_chuong_ngai_1 = 3, y_chuong_ngai_1_cu = 3;
int y_chuong_ngai_2 = 25, y_chuong_ngai_2_cu = 25;
int direction_1 = 0;
int direction_2 = 1;
int x_chuong_ngai_1 = 30;
int x_hoa = 5, y_hoa = 12;
int x_hoa_cu = 5, y_hoa_cu = 12;
int hoa = 0;


void text_animation(string a);
void Play_Game();
void ve_tuong_tren();
void ve_tuong_duoi();
void ve_tuong_trai();
void ve_tuong_phai();
void ve_tuong();
void khoi_tao_ran(int toa_do_X[], int toa_do_Y[]);
void ve_ran(int toa_do_X[], int toa_do_Y[]);
void xu_li_ran_di_chuyen(int toa_do_X[], int toa_do_Y[], int x, int y, int& x_qua, int& y_qua, int y_chuong_ngai_1);
void them_toa_do_dau(int a[], int x);
void xoa_toa_do_cuoi(int a[], int vi_tri);
void xoa_du_lieu_cu(int toa_do_X[], int toa_do_Y[]);
bool check_ran_cham_tuong(int x0, int y0);
bool check_ran_can_duoi(int toa_do_X[], int toa_do_Y[]);
bool check_gameover(int toa_do_X[], int toa_do_Y[], int y_chuong_ngai_1);
void tao_qua(int& x_qua, int& y_qua, int toa_do_X[], int toa_do_Y[]);
bool check_ran_de_qua(int toa_do_X[], int toa_do_Y[], int x_qua, int y_qua);
bool check_ran_an_qua(int toa_do_dau_ran_X, int toa_do_dau_ran_Y, int x_qua, int y_qua);
bool check_ran_cham_chuong_ngai(int toa_do_X[], int toa_do_Y[], int y_chuong_ngai_1);
void xu_li_chuong_ngai_1(int& y_chuong_ngai_1, int& direction_1, int& y_chuong_ngai_1_cu);
void xu_li_chuong_ngai_de_hoa();
void xu_li_chuong_ngai_de_qua(int& x_qua, int& y_qua, int y_chuong_ngai_1, int toa_do_X[], int toa_do_Y[]);
void Drawing_Spider(int y_nhen, int& y_nhen_cu);
bool check_qua_de_chuong_ngai(int x_qua, int y_qua, int y_chuong_ngai_1);
void ve_tuong1();
void Ve_Hoa();
bool check_hoa_de_qua();
void Tao_Hoa();
bool check_ran_an_hoa();
void Display_Point();
void END_GAME();
// ve tuong
void ve_tuong_tren() {
    int x = 10, y = 1;
    while (x < 100) {
        gotoXY(x, y);
        cout << char(196);
        x++;
    }
}
void ve_tuong_duoi() {
    int x = 10, y = 26;
    while (x < 100) {
        gotoXY(x, y);
        cout << char(196);
        x++;
    }
}
void ve_tuong_trai() {
    int x = 10, y = 1;
    while (y < 26) {
        gotoXY(x, y);
        cout << char(179);
        y++;
    }
}
void ve_tuong_phai() {
    int x = 100, y = 1;
    while (y < 26) {
        gotoXY(x, y);
        cout << char(179);
        y++;
    }
}
void ve_tuong() {
    ve_tuong_tren();
    ve_tuong_duoi();
    ve_tuong_trai();
    ve_tuong_phai();
    gotoXY(10, 1);
    cout << char(218);
    gotoXY(100, 1);
    cout << char(191);
    gotoXY(10, 26);
    cout << char(192);
    gotoXY(100, 26);
    cout << char(217);
}
// ve ran va khoi tao ran
void khoi_tao_ran(int toa_do_X[], int toa_do_Y[]) {
    int x = 50, y = 13;

    for (int i = 0; i < sl; i++) {
        toa_do_X[i] = x;
        toa_do_Y[i] = y;
        x--;
    }
}
void ve_ran(int toa_do_X[], int toa_do_Y[]) {
    for (int i = 0; i < sl; i++) {
        gotoXY(toa_do_X[i], toa_do_Y[i]);
        if (i == 0) {
            cout << (char)79;
        }
        else cout << (char)248;
    }
}
void xoa_du_lieu_cu(int toa_do_X[], int toa_do_Y[]) {
    for (int i = 0; i < sl; i++) {
        gotoXY(toa_do_X[i], toa_do_Y[i]);
        cout << ' ';
    }
}
// di chuyen ran
void xu_li_ran_di_chuyen(int toa_do_X[], int toa_do_Y[], int x, int y, int& x_qua, int& y_qua, int y_chuong_ngai_1) {
    //b1: them toa do moi vao dau mang
    them_toa_do_dau(toa_do_X, x);
    them_toa_do_dau(toa_do_Y, y);
    if (check_ran_an_qua(toa_do_X[0], toa_do_Y[0], x_qua, y_qua) == true) {
        sl++;
        tao_qua(x_qua, y_qua, toa_do_X, toa_do_Y);
    }
    if (check_ran_an_hoa()) {
        hoa++;
        Tao_Hoa();
    }
    if (check_ran_cham_chuong_ngai(toa_do_X, toa_do_Y, y_chuong_ngai_1)) {
        sl--;
    }
    //b2: xoa toa do cuoi manng
    xoa_toa_do_cuoi(toa_do_X, sl - 1);
    xoa_toa_do_cuoi(toa_do_Y, sl - 1);
    //b3: ve ran
    ve_ran(toa_do_X, toa_do_Y);
}
void them_toa_do_dau(int a[], int x) {
    for (int i = sl; i > 0; i--) {
        a[i] = a[i - 1];
    }
    a[0] = x;
    sl++;
}
void xoa_toa_do_cuoi(int a[], int vi_tri) {
    for (int i = vi_tri; i < sl; i++) {
        a[i] = a[i + 1];
    }
    sl--;
}
bool check_ran_cham_tuong(int x0, int y0) {
    if (y0 == 1 && (x0 >= 10 && x0 <= 100)) { // ran cham tuong tren
        return true;
    }
    else if (y0 == 26 && (x0 >= 10 && x0 <= 100)) {//ran cham tuong duoi
        return true;
    }
    else if (x0 == 10 && (y0 >= 1 && y0 <= 26)) {// ran cham tuong trai
        return true;
    }
    else if (x0 == 100 && (y0 >= 1 && y0 <= 26)) {// ran cham tuong trai
        return true;
    }
    return false;
}
bool check_ran_can_duoi(int toa_do_X[], int toa_do_Y[]) {
    for (int i = 1; i < sl; i++) {
        if (toa_do_X[0] == toa_do_X[i] && toa_do_Y[0] == toa_do_Y[i]) {
            return true;
        }
    }
    return false;
}
bool check_ran_cham_chuong_ngai(int toa_do_X[], int toa_do_Y[], int y_chuong_ngai_1) {
    for (int i = 0; i < sl; i++) {
        if (toa_do_Y[i] == y_chuong_ngai_1) {
            if (toa_do_X[i] == x_nhen) return true;
            if (toa_do_X[i] == x_nhen - 1) return true;
            if (toa_do_X[i] == x_nhen - 2) return true;
            if (toa_do_X[i] == x_nhen - 3) return true;
            if (toa_do_X[i] == x_nhen - 4) return true;
            if (toa_do_X[i] == x_nhen + 1) return true;
            if (toa_do_X[i] == x_nhen + 2) return true;
            if (toa_do_X[i] == x_nhen + 3) return true;
            if (toa_do_X[i] == x_nhen + 4) return true;
        }
        if (toa_do_Y[i] == y_chuong_ngai_1 + 1) {
            if (toa_do_X[i] == x_nhen - 1) return true;
            if (toa_do_X[i] == x_nhen - 2) return true;
            if (toa_do_X[i] == x_nhen - 3) return true;
            if (toa_do_X[i] == x_nhen + 1) return true;
            if (toa_do_X[i] == x_nhen + 2) return true;
            if (toa_do_X[i] == x_nhen + 3) return true;
        }
        if (toa_do_Y[i] == y_chuong_ngai_1 + 2) {
            if (toa_do_X[i] == x_nhen - 2) return true;
            if (toa_do_X[i] == x_nhen + 2) return true;
        }
        if (toa_do_Y[i] == y_chuong_ngai_1 - 1) {
            if (toa_do_X[i] == x_nhen) return true;
            if (toa_do_X[i] == x_nhen - 2) return true;
            if (toa_do_X[i] == x_nhen + 2) return true;
        }
    }
    return false;
}
bool check_gameover(int toa_do_X[], int toa_do_Y[], int y_chuong_ngai_1) {
    bool check_tuong = check_ran_cham_tuong(toa_do_X[0], toa_do_Y[0]);
    bool check_can_duoi = check_ran_can_duoi(toa_do_X, toa_do_Y);
    if (check_tuong || check_can_duoi || sl <= 1) {
        return true;
    }
    return false;
}
void tao_qua(int& x_qua, int& y_qua, int toa_do_X[], int toa_do_Y[]) {

    do {
        x_qua = rand() % (99 - 11 + 1) + 11;
        y_qua = rand() % (25 - 2 + 1) + 2;
    } while (check_ran_de_qua(toa_do_X, toa_do_Y, x_qua, y_qua) || check_hoa_de_qua());
    SetColor(4);
    gotoXY(x_qua, y_qua);
    cout << (char)162;
    SetColor(15);
}
void Tao_Hoa() {
    do {
        x_hoa = rand() % (95 - 15 + 1) + 15;
        y_hoa = rand() % (22 - 4 + 1) + 4;
    } while (check_hoa_de_qua());
    Ve_Hoa();

}
bool check_hoa_de_qua() {
    if (y_qua == y_hoa) {
        if (x_qua == x_hoa) return true;
        if (x_qua == x_hoa - 1) return true;
        if (x_qua == x_hoa - 2) return true;
        if (x_qua == x_hoa - 3) return true;
        if (x_qua == x_hoa + 1) return true;
        if (x_qua == x_hoa + 2) return true;
        if (x_qua == x_hoa + 3) return true;

    }
    else if (y_qua == y_hoa + 1) {
        if (x_qua == x_hoa) return true;
        if (x_qua == x_hoa - 1) return true;
        if (x_qua == x_hoa - 2) return true;
        if (x_qua == x_hoa - 3) return true;
        if (x_qua == x_hoa + 1) return true;
        if (x_qua == x_hoa + 2) return true;
        if (x_qua == x_hoa + 3) return true;
    }
    else if (y_qua == y_hoa + 2) {
        if (x_qua == x_hoa) return true;
        if (x_qua == x_hoa + 1) return true;
        if (x_qua == x_hoa - 1) return true;
    }
    else if (y_qua == y_hoa - 1) {
        if (x_qua == x_hoa) return true;
        if (x_qua == x_hoa + 1) return true;
        if (x_qua == x_hoa - 1) return true;
        if (x_qua == x_hoa + 3) return true;
        if (x_qua == x_hoa - 3) return true;
    }
    else if (y_qua == y_hoa - 2) {
        if (x_qua == x_hoa) return true;
        if (x_qua == x_hoa + 1) return true;
        if (x_qua == x_hoa + 2) return true;
        if (x_qua == x_hoa - 1) return true;
        if (x_qua == x_hoa - 2) return true;
    }

    return false;
}
bool check_chuong_ngai_de_hoa() {
    if (y_chuong_ngai_1 == y_qua) {
        if (x_hoa - 2 == x_chuong_ngai_1) return true;
        if (x_hoa - 2 == x_chuong_ngai_1 - 1) return true;
        if (x_hoa - 2 == x_chuong_ngai_1 - 2) return true;
        if (x_hoa - 2 == x_chuong_ngai_1 - 3) return true;
        if (x_hoa - 2 == x_chuong_ngai_1 - 4) return true;
        if (x_hoa - 2 == x_chuong_ngai_1 + 1) return true;
        if (x_hoa - 2 == x_chuong_ngai_1 + 2) return true;
        if (x_hoa - 2 == x_chuong_ngai_1 + 3) return true;
        if (x_hoa - 2 == x_chuong_ngai_1 + 4) return true;
        if (x_hoa + 2 == x_chuong_ngai_1) return true;
        if (x_hoa + 2 == x_chuong_ngai_1 - 1) return true;
        if (x_hoa + 2 == x_chuong_ngai_1 - 2) return true;
        if (x_hoa + 2 == x_chuong_ngai_1 - 3) return true;
        if (x_hoa + 2 == x_chuong_ngai_1 - 4) return true;
        if (x_hoa + 2 == x_chuong_ngai_1 + 1) return true;
        if (x_hoa + 2 == x_chuong_ngai_1 + 2) return true;
        if (x_hoa + 2 == x_chuong_ngai_1 + 3) return true;
        if (x_hoa + 2 == x_chuong_ngai_1 + 4) return true;
        if (x_hoa - 3 == x_chuong_ngai_1) return true;
        if (x_hoa - 3 == x_chuong_ngai_1 - 1) return true;
        if (x_hoa - 3 == x_chuong_ngai_1 - 2) return true;
        if (x_hoa - 3 == x_chuong_ngai_1 - 3) return true;
        if (x_hoa - 3 == x_chuong_ngai_1 - 4) return true;
        if (x_hoa - 3 == x_chuong_ngai_1 + 1) return true;
        if (x_hoa - 3 == x_chuong_ngai_1 + 2) return true;
        if (x_hoa - 3 == x_chuong_ngai_1 + 3) return true;
        if (x_hoa - 3 == x_chuong_ngai_1 + 4) return true;
        if (x_hoa + 3 == x_chuong_ngai_1) return true;
        if (x_hoa + 3 == x_chuong_ngai_1 - 1) return true;
        if (x_hoa + 3 == x_chuong_ngai_1 - 2) return true;
        if (x_hoa + 3 == x_chuong_ngai_1 - 3) return true;
        if (x_hoa + 3 == x_chuong_ngai_1 - 4) return true;
        if (x_hoa + 3 == x_chuong_ngai_1 + 1) return true;
        if (x_hoa + 3 == x_chuong_ngai_1 + 2) return true;
        if (x_hoa + 3 == x_chuong_ngai_1 + 3) return true;
        if (x_hoa + 3 == x_chuong_ngai_1 + 4) return true;
    }
    return false;
}
void xu_li_chuong_ngai_de_hoa() {
    if (check_chuong_ngai_de_hoa()) Tao_Hoa();
}
bool check_ran_de_qua(int toa_do_X[], int toa_do_Y[], int x_qua, int y_qua) {
    for (int i = 0; i < sl; i++) {
        if ((x_qua == toa_do_X[i]) && (y_qua == toa_do_Y[i])) {
            return true;
        }
    }
    return false;
}

bool check_ran_an_qua(int toa_do_dau_ran_X, int toa_do_dau_ran_Y, int x_qua, int y_qua) {
    if ((toa_do_dau_ran_X == x_qua) && (toa_do_dau_ran_Y == y_qua)) {
        return true;
    }
    return false;
}
bool check_ran_an_hoa() {
    int x = toa_do_X[0];
    int y = toa_do_Y[0];
    if (y == y_hoa) {
        if (x == x_hoa - 3 || x == x_hoa + 3) return true;
    }
    else if (y == y_hoa + 1) {
        if (x == x_hoa - 3) return true;
        if (x == x_hoa - 2) return true;
        if (x == x_hoa + 3) return true;
        if (x == x_hoa + 2) return true;
    }
    else if (y == y_hoa + 2) {
        if (x == x_hoa - 1) return true;
        if (x == x_hoa) return true;
        if (x == x_hoa + 1) return true;
    }
    else if (y == y_hoa - 1) {
        if (x == x_hoa - 3) return true;
        if (x == x_hoa + 3) return true;
    }
    else if (y == y_hoa - 2) {
        if (x == x_hoa) return true;
        if (x == x_hoa - 1) return true;
        if (x == x_hoa - 2) return true;
        if (x == x_hoa + 1) return true;
        if (x == x_hoa + 2) return true;
    }
    return false;
}

void xu_li_chuong_ngai_1(int& y_chuong_ngai_1, int& direction_1, int& y_chuong_ngai_1_cu) {
    if (y_chuong_ngai_1 == 3) {
        direction_1 = 0;
    }
    else if (y_chuong_ngai_1 == 23) {
        direction_1 = 1;
    }

    if (direction_1 == 0) {
        y_chuong_ngai_1++;
    }
    else if (direction_1 == 1) {
        y_chuong_ngai_1--;
    }
    Drawing_Spider(y_chuong_ngai_1, y_chuong_ngai_1_cu);
}

void xu_li_chuong_ngai_de_qua(int& x_qua, int& y_qua, int y_chuong_ngai_1, int toa_do_X[], int toa_do_Y[]) {
    if (check_qua_de_chuong_ngai(x_qua, y_qua, y_chuong_ngai_1)) tao_qua(x_qua, y_qua, toa_do_X, toa_do_Y);
}
bool check_qua_de_chuong_ngai(int x_qua, int y_qua, int y_chuong_ngai_1) {
    if (y_qua == y_chuong_ngai_1) {
        if (x_qua == x_nhen) return true;
        if (x_qua == x_nhen - 1) return true;
        if (x_qua == x_nhen - 2) return true;
        if (x_qua == x_nhen - 3) return true;
        if (x_qua == x_nhen - 4) return true;
        if (x_qua == x_nhen + 1) return true;
        if (x_qua == x_nhen + 2) return true;
        if (x_qua == x_nhen + 3) return true;
        if (x_qua == x_nhen + 4) return true;
    }
    if (y_qua == y_chuong_ngai_1 + 1) {
        if (x_qua == x_nhen - 1) return true;
        if (x_qua == x_nhen - 2) return true;
        if (x_qua == x_nhen - 3) return true;
        if (x_qua == x_nhen + 1) return true;
        if (x_qua == x_nhen + 2) return true;
        if (x_qua == x_nhen + 3) return true;
    }
    if (y_qua == y_chuong_ngai_1 + 2) {
        if (x_qua == x_nhen - 2) return true;
        if (x_qua == x_nhen + 2) return true;
    }
    if (y_qua == y_chuong_ngai_1 - 1) {
        if (x_qua == x_nhen) return true;
        if (x_qua == x_nhen - 2) return true;
        if (x_qua == x_nhen + 2) return true;
    }
    return false;
}
void Play_Game() {
    noCursorType();
    srand(time(NULL));
    ve_tuong1();
    khoi_tao_ran(toa_do_X, toa_do_Y);
    ve_ran(toa_do_X, toa_do_Y);
    tao_qua(x_qua, y_qua, toa_do_X, toa_do_Y);
    Tao_Hoa();
    int time = 150;
    while (!gameover) {
        if (_kbhit()) {
            char ki_tu_dieu_khien = _getch();
            if (ki_tu_dieu_khien == 'p') {
                while (1) {
                    if (_kbhit()) {
                        char c = _getch();
                        if (c == 'r') break;
                    }
                }
            }
            if (ki_tu_dieu_khien == -32) {
                ki_tu_dieu_khien = _getch();
                if (ki_tu_dieu_khien == 72 && Check_Direction != 0) { // di len
                    Check_Direction = 1;
                }
                else if (ki_tu_dieu_khien == 80 && Check_Direction != 1) { // di xuong
                    Check_Direction = 0;
                }
                else if (ki_tu_dieu_khien == 77 && Check_Direction != 3) { // qua phai
                    Check_Direction = 2;
                }
                else if (ki_tu_dieu_khien == 75 && Check_Direction != 2) { // qua trai
                    Check_Direction = 3;
                }
            }
        }
        // ========= thuc hien di chuyen===============
        if (Check_Direction == 0) { // ran di xuong
            y++;
        }
        else if (Check_Direction == 1) { // ran di len
            y--;
        }
        else if (Check_Direction == 2) { // ran di qua phai
            x++;
        }
        else if (Check_Direction == 3) { // ran di qua trai
            x--;
        }
        xu_li_chuong_ngai_1(y_chuong_ngai_1, direction_1, y_chuong_ngai_1_cu);
        xoa_du_lieu_cu(toa_do_X, toa_do_Y);
        xu_li_ran_di_chuyen(toa_do_X, toa_do_Y, x, y, x_qua, y_qua, y_chuong_ngai_1);
        xu_li_chuong_ngai_de_hoa();
        xu_li_chuong_ngai_de_qua(x_qua, y_qua, y_chuong_ngai_1, toa_do_X, toa_do_Y);
        Display_Point();

        // =========== kiem tra gameover ==================

        gameover = check_gameover(toa_do_X, toa_do_Y, y_chuong_ngai_1);
        if (gameover) {
            if (sl > diem_ky_luc) 
                diem_ky_luc = sl;
           system("cls");
           END_GAME();
        
        }
        
        Sleep(time);
    }
    //ve_ran(toa_do_X, toa_do_Y);

    _getch();
}

void Drawing_Spider(int y_nhen, int& y_nhen_cu) {

    //==========xoa nhen cu===================
    gotoXY(x_nhen, y_nhen_cu);
    cout << ' ';
    gotoXY(x_nhen - 1, y_nhen_cu);
    cout << ' ';
    gotoXY(x_nhen - 2, y_nhen_cu);
    cout << ' ';
    gotoXY(x_nhen - 3, y_nhen_cu);
    cout << ' ';
    gotoXY(x_nhen - 4, y_nhen_cu);
    cout << ' ';
    gotoXY(x_nhen + 1, y_nhen_cu);
    cout << ' ';
    gotoXY(x_nhen + 2, y_nhen_cu);
    cout << ' ';
    gotoXY(x_nhen + 3, y_nhen_cu);
    cout << ' ';
    gotoXY(x_nhen + 4, y_nhen_cu);
    cout << ' ';
    gotoXY(x_nhen, y_nhen_cu + 1);
    cout << " ";
    gotoXY(x_nhen - 1, y_nhen_cu + 1);
    cout << ' ';
    gotoXY(x_nhen - 2, y_nhen_cu + 1);
    cout << ' ';
    gotoXY(x_nhen - 3, y_nhen_cu + 1);
    cout << ' ';
    gotoXY(x_nhen + 1, y_nhen_cu + 1);
    cout << ' ';
    gotoXY(x_nhen + 2, y_nhen_cu + 1);
    cout << ' ';
    gotoXY(x_nhen + 3, y_nhen_cu + 1);
    cout << ' ';
    gotoXY(x_nhen - 2, y_nhen_cu + 2);
    cout << ' ';
    gotoXY(x_nhen + 2, y_nhen_cu + 2);
    cout << ' ';
    gotoXY(x_nhen, y_nhen_cu - 1);
    cout << ' ';
    gotoXY(x_nhen - 2, y_nhen_cu - 1);
    cout << ' ';
    gotoXY(x_nhen + 2, y_nhen_cu - 1);
    cout << ' ';
    //===============================

    y_nhen_cu = y_nhen;

    //===========ve moi=====================
    SetColor(9);
    gotoXY(x_nhen, y_nhen);
    cout << '_';
    SetColor(15);
    gotoXY(x_nhen - 1, y_nhen);
    cout << '(';
    gotoXY(x_nhen - 2, y_nhen);
    cout << (char)92;
    gotoXY(x_nhen - 3, y_nhen);
    cout << '_';
    gotoXY(x_nhen - 4, y_nhen);
    cout << (char)92;
    gotoXY(x_nhen + 1, y_nhen);
    cout << ')';
    gotoXY(x_nhen + 2, y_nhen);
    cout << '/';
    gotoXY(x_nhen + 3, y_nhen);
    cout << '_';
    gotoXY(x_nhen + 4, y_nhen);
    cout << '/';
    gotoXY(x_nhen, y_nhen + 1);
    cout << "o";
    gotoXY(x_nhen - 1, y_nhen + 1);
    cout << '/';
    gotoXY(x_nhen - 2, y_nhen + 1);
    cout << '/';
    gotoXY(x_nhen - 3, y_nhen + 1);
    cout << '_';
    gotoXY(x_nhen + 1, y_nhen + 1);
    cout << (char)92;
    gotoXY(x_nhen + 2, y_nhen + 1);
    cout << (char)92;
    gotoXY(x_nhen + 3, y_nhen + 1);
    cout << '_';
    gotoXY(x_nhen - 2, y_nhen + 2);
    cout << '/';
    gotoXY(x_nhen + 2, y_nhen + 2);
    cout << (char)92;
    gotoXY(x_nhen, y_nhen - 1);
    cout << '_';
    gotoXY(x_nhen - 2, y_nhen - 1);
    cout << '/';
    gotoXY(x_nhen + 2, y_nhen - 1);
    cout << (char)92;

}
void ve_tuong1()
{
    // =============== Vẽ cây =================

    int y = 2;
    for (int x = 1; x <= 2; x++)
    {
        SetColor(10);
        gotoXY(5, y);
        cout << "A";
        gotoXY(4, ++y);
        cout << "/I\\";
        gotoXY(3, ++y);
        cout << "//I\\\\ ";
        gotoXY(2, ++y);
        cout << "///I\\\\\\";
        gotoXY(2, ++y);
        cout << "'//I\\\\'";
        gotoXY(4, ++y);
        SetColor(6);
        cout << "'I'";
        gotoXY(4, ++y);
        y += 2;
    }
    // ============= Vẽ chim =============
    SetColor(4);
    gotoXY(3, y);
    cout << "\\\\";
    SetColor(14);
    gotoXY(3, ++y);
    cout << "(o>";
    gotoXY(2, ++y);
    SetColor(9);
    cout << "_(()_";
    gotoXY(3, ++y);
    SetColor(9);
    cout << "||";
    y += 1;
    SetColor(4);
    gotoXY(4, y);
    cout << "\\\\";
    SetColor(14);
    gotoXY(4, ++y);
    cout << "(o>";
    gotoXY(1, ++y);
    SetColor(9);
    cout << "\\\\_//)";
    gotoXY(2, ++y);
    SetColor(9);
    cout << "\\_/_)";
    SetColor(6);
    gotoXY(3, ++y);
    cout << "_|_";


    // ===================== Vẽ đất ===============

    for (int i = 2; i <= 8; i++)
    {
        gotoXY(i, 8); cout << "+";
        gotoXY(i, 16); cout << "+";
    }

    // ===================== Vẽ khung =============

    char c = 205;
    SetColor(13);
    for (int x = 1; x <= 9; x++)
    {
        gotoXY(x, 1); cout << c;
        gotoXY(x, 27); cout << c;
    }
    for (int x = 11; x <= 99; x++)
    {
        gotoXY(x, 1); cout << c;
        gotoXY(x, 27); cout << c;
    }
    for (int x = 101; x <= 118; x++)
    {
        gotoXY(x, 1); cout << c;
        gotoXY(x, 27); cout << c;
    }
    c = 186;
    for (int y = 2; y <= 26; y++)
    {
        gotoXY(10, y); cout << c;
    }
    for (int y = 2; y <= 26; y++)
    {
        gotoXY(100, y); cout << c;
    }
    c = 204;
    gotoXY(100, 18);
    cout << c;
    c = 205;
    for (int i = 101; i <= 118; i++) {
        gotoXY(i, 18); cout << c;
    }
    gotoXY(105, 25);




    // =============== Vẽ góc cạnh ===========
    c = 203;
    gotoXY(10, 1); cout << c;
    gotoXY(100, 1); cout << c;
    c = 202;
    gotoXY(10, 27); cout << c;
    gotoXY(100, 27); cout << c;
    // ================= Vẽ khỉ ===================
    int y_dif = 2;
    SetColor(7);
    gotoXY(108, y_dif);
    cout << "_       _";
    gotoXY(107, ++y_dif);
    cout << "{ \"-   .\" }";
    SetColor(11);
    gotoXY(102, ++y_dif);
    cout << "\\_   /\\\\    //\\";
    SetColor(14);
    gotoXY(102, ++y_dif);
    cout << "  \\_| ||    || |_/";
    y_dif += 1;
    SetColor(6);
    gotoXY(108, ++y_dif);
    cout << "/   //   /";
    gotoXY(107, ++y_dif);
    cout << "/   //   /";
    gotoXY(106, ++y_dif);
    cout << "/   //   /";
    gotoXY(105, ++y_dif);
    cout << "/   //   /";
    gotoXY(104, ++y_dif);
    cout << "/   //   /";
    SetColor(14);
    gotoXY(113, y_dif);
    cout << "x";
    gotoXY(102, ++y_dif);
    cout << ".-. _______|__";
    gotoXY(102, ++y_dif);
    cout << "|=|/  tho ren \\";
    gotoXY(102, ++y_dif);
    cout << "|-|-----------|";
    SetColor(15);
    gotoXY(102, ++y_dif);
    cout << "| |_____|_\"\"__|";
    gotoXY(102, ++y_dif);
    cout << "|_|_[X]_|_____|";

}
void Ve_Hoa() {
    //========= xoa hoa cu =======================
    gotoXY(x_hoa_cu, y_hoa_cu);
    cout << ' ';
    gotoXY(x_hoa_cu - 1, y_hoa_cu);
    cout << ' ';
    gotoXY(x_hoa_cu - 2, y_hoa_cu);
    cout << ' ';
    gotoXY(x_hoa_cu - 3, y_hoa_cu);
    cout << ' ';
    gotoXY(x_hoa_cu + 1, y_hoa_cu);
    cout << ' ';
    gotoXY(x_hoa_cu + 2, y_hoa_cu);
    cout << ' ';
    gotoXY(x_hoa_cu + 3, y_hoa_cu);
    cout << ' ';
    gotoXY(x_hoa_cu - 1, y_hoa_cu + 1);
    cout << ' ';
    gotoXY(x_hoa_cu - 2, y_hoa_cu + 1);
    cout << ' ';
    gotoXY(x_hoa_cu - 3, y_hoa_cu + 1);
    cout << ' ';
    gotoXY(x_hoa_cu + 1, y_hoa_cu + 1);
    cout << ' ';
    gotoXY(x_hoa_cu + 2, y_hoa_cu + 1);
    cout << ' ';
    gotoXY(x_hoa_cu + 3, y_hoa_cu + 1);
    cout << ' ';
    gotoXY(x_hoa_cu, y_hoa_cu + 2);
    cout << ' ';
    gotoXY(x_hoa_cu - 1, y_hoa_cu + 2);
    cout << ' ';
    gotoXY(x_hoa_cu + 1, y_hoa_cu + 2);
    cout << " ";
    gotoXY(x_hoa_cu, y_hoa_cu - 1);
    cout << ' ';
    gotoXY(x_hoa_cu - 1, y_hoa_cu - 1);
    cout << ' ';
    gotoXY(x_hoa_cu - 3, y_hoa_cu - 1);
    cout << ' ';
    gotoXY(x_hoa_cu + 1, y_hoa_cu - 1);
    cout << ' ';
    gotoXY(x_hoa_cu + 3, y_hoa_cu - 1);
    cout << ' ';
    gotoXY(x_hoa_cu, y_hoa_cu - 2);
    cout << ' ';
    gotoXY(x_hoa_cu - 1, y_hoa_cu - 2);
    cout << ' ';
    gotoXY(x_hoa_cu - 2, y_hoa_cu - 2);
    cout << ' ';
    gotoXY(x_hoa_cu + 1, y_hoa_cu - 2);
    cout << ' ';
    gotoXY(x_hoa_cu + 2, y_hoa_cu - 2);
    cout << ' ';
    //=============

    y_hoa_cu = y_hoa;
    x_hoa_cu = x_hoa;

    //========== ve hoa=================
    SetColor(14);
    gotoXY(x_hoa, y_hoa);
    cout << '_';
    gotoXY(x_hoa - 1, y_hoa);
    cout << '(';
    gotoXY(x_hoa - 2, y_hoa);
    cout << '-';
    gotoXY(x_hoa - 3, y_hoa);
    cout << '>';
    gotoXY(x_hoa + 1, y_hoa);
    cout << ')';
    gotoXY(x_hoa + 2, y_hoa);
    cout << '-';
    gotoXY(x_hoa + 3, y_hoa);
    cout << '<';
    gotoXY(x_hoa - 1, y_hoa + 1);
    cout << '/';
    gotoXY(x_hoa - 2, y_hoa + 1);
    cout << '_';
    gotoXY(x_hoa - 3, y_hoa + 1);
    cout << (char)92;
    gotoXY(x_hoa + 1, y_hoa + 1);
    cout << (char)92;
    gotoXY(x_hoa + 2, y_hoa + 1);
    cout << '_';
    gotoXY(x_hoa + 3, y_hoa + 1);
    cout << '/';
    gotoXY(x_hoa, y_hoa + 2);
    cout << '-';
    gotoXY(x_hoa - 1, y_hoa + 2);
    cout << '`';
    gotoXY(x_hoa + 1, y_hoa + 2);
    cout << "'";
    gotoXY(x_hoa, y_hoa - 1);
    cout << '_';
    gotoXY(x_hoa - 1, y_hoa - 1);
    cout << (char)92;
    gotoXY(x_hoa - 3, y_hoa - 1);
    cout << '/';
    gotoXY(x_hoa + 1, y_hoa - 1);
    cout << '/';
    gotoXY(x_hoa + 3, y_hoa - 1);
    cout << (char)92;
    gotoXY(x_hoa, y_hoa - 2);
    cout << '-';
    gotoXY(x_hoa - 1, y_hoa - 2);
    cout << ',';
    gotoXY(x_hoa - 2, y_hoa - 2);
    cout << '_';
    gotoXY(x_hoa + 1, y_hoa - 2);
    cout << '.';
    gotoXY(x_hoa + 2, y_hoa - 2);
    cout << '_';
    SetColor(15);
}

void Display_Point() {
    SetColor(12);
    gotoXY(105, 20);
    cout << "GOLD : " << hoa;
    gotoXY(105, 22);
    cout << "HP : " << sl;
    SetColor(7);
}

void END_GAME() {
    SetColor(12);
    const string title[] = {
        "   ____                        ___                 _ _",
        " / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __| | |",
        "| |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__| | |",
        "| |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |  |_|_|",
        " \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|  (_|_)"
    };
    int x = 0; 
    int y = 10; 
    int screen_width = 40; 
   
    while (x < screen_width) {
        system("cls");
       
        for (int i = 0; i < 5; ++i) { 
            gotoXY(x, y + i);
            cout << title[i];
        }
        x+=5;
        Sleep(80);
    noCursorType();
    }
    gotoXY(52, 16);
    SetColor(15);
    text_animation("Press 'Space' to continue");
    
    _getch(); 
    return;
}
void text_animation(string a) {
    for (int i = 0; i < a.length(); i++) {
        cout << a[i];
        Sleep(100);
    }
}