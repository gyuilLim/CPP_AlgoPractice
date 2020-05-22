#include <iostream>
#include <string>
using namespace std;

bool temp[4][4] = {{false}};
int p1_score = 0;
int p2_score = 0;

void fill_card(int card[][4], int version);

void init_print_card();

void print_card(int card[][4], int point1, int point2);

void card_pair(int card[][4], int point1, int point2, string whosturn);

bool end_checker();

bool error_checker(int point1, int point2);

int main() {
    int card[4][4] = {{1,2,3,4},{5,6,7,8},{8,7,6,5},{4,3,2,1}};
    string whosturn = "P1";
    int version;
    int x1, y1, x2, y2;

    cout << "input version(1:fixed, 2:randomized) : ";
    cin >> version;

    fill_card(card, version);
    
    int point1, point2;

    init_print_card();

    while (!end_checker()){
        cout << whosturn <<"'s turn, choose two cards : ";
        cin >> point1 >> point2;

        if(error_checker(point1, point2)){
            continue;
        }

        print_card(card, point1, point2);
        card_pair(card, point1, point2, whosturn);



        //turn change
        if (whosturn == "P1"){
            whosturn = "P2";
        }
        else{
            whosturn = "P1";
        }
    }
    cout << "Game finished. Final scores are P1 : " << p1_score << " and P2 : " << p2_score << endl;
    
    return 0;
}

void fill_card(int card[][4], int version){
    int count[8] = {0};
    int num;
    if (version == 2){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                while(1){
                    num = rand() % 8 + 1;
                    if (count[num-1] != 2){
                        card[i][j] = num;
                        count[num-1]++;
                        break;
                    }
                }
            }
        }
    }
}

void init_print_card(){
    cout << "    1 2 3 4" << endl;
    cout << "--+--------" << endl;
    for (int i = 0; i < 4; i++){
        cout << " " << i+1 << "|";
        for (int j = 0; j < 4; j++){
            cout << " X";
        }
        cout << "\n";
    }
}

void print_card(int card[][4], int point1, int point2){
    int x1, y1;
    int x2, y2;
    x1 = point1 / 10 - 1;
    y1 = point1 % 10 - 1;
    x2 = point2 / 10 - 1;
    y2 = point2 % 10 - 1;

    cout << "    1 2 3 4" << endl;
    cout << "--+--------" << endl;
    for (int i = 0; i < 4; i++){
        cout << " " << i+1 << "|";
        for (int j = 0; j < 4; j++){
            if (temp[i][j] == true){
                cout << " " << card[i][j];
            }
            else{
                if (i == x1 && j == y1){
                    cout << " " << card[i][j];
                }
                else if (i == x2 && j == y2){
                    cout << " " << card[i][j];
                }
                else {
                    cout << " X";
                }
            }
        }
        cout << "\n";
    }
}

void card_pair(int card[][4], int point1, int point2, string whosturn){
    int score;
    int x1 = point1 / 10 - 1;
    int y1 = point1 % 10 - 1;
    int x2 = point2 / 10 - 1;
    int y2 = point2 % 10 - 1;
    if (card[x1][y1] == card[x2][y2]){
        if (card[x1][y1] != 7){
            score = 1;
        }
        else {
            score = 2;
        }
        temp[x1][y1] = true;
        temp[x2][y2] = true;
        cout << whosturn <<" found a matching pair! ";
        if (whosturn == "P1"){
            p1_score += score;
        }
        else{
            p2_score += score;
        }
        cout << "P1's score : " << p1_score << ", P2's score : " << p2_score << endl;
    }
    else {
        cout << whosturn <<" failed to find a matching pair" << endl;
    }
}

bool end_checker(){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (temp[i][j] == false){
                return false;
            }
        }
    }
    return true;
}

bool error_checker(int point1, int point2){
    int x1 = point1 / 10 - 1;
    int y1 = point1 % 10 - 1;
    int x2 = point2 / 10 - 1;
    int y2 = point2 % 10 - 1;

    if (temp[x1][y1] == true || temp[x2][y2] == true){
        cout << "this card already fliped" << endl;
        return true;
    }
    if (x1 < 0 || x1 > 3 || y1 < 0 || y1 > 3 || x2 < 0 || x2 > 3 || y2 < 0 || y2 > 3){
        cout << "this point out of range" << endl;
        return true;
    }
    return false;
}