#include <iostream> /* cin, cout */
#include <string>   /* string */
#include <stdio.h>  /* NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <stdlib.h> /* system("cls") */
#include <fstream>  /* multiple file reading functions */
#include "compandprin.h"
#include "properties.h"
#include "rent.h"

using namespace std;

class player	{

    // access specifier
    public:

    // data members
    string piece;
    //string playerName;
    int positionx;
    int positiony;
    int balance = 200;
    int sum = 0;

    bool ehabGhar = false;
    bool osa = false;
    bool pdc = false;
    bool hss = false;
    bool lmbiCp = false;
    bool soe = false;
    bool lawSchool = false;
    bool hbaPlays = false;
    bool jawahir = false;
    bool bioMajor = false;
    bool junaidHaroon = false;
    bool cal = false;
    bool khokha = false;
    bool subway = false;
    bool cso = false;
    bool vcHouse = false;
    bool cardammom = false;
    bool zakir = false;
    bool bhattaChowk = false;
    bool a16 = false;
    bool sdsbDrRoom = false;
    bool lums = false;
    bool macNcheese = false;
    bool kohsarTiles = false;
    bool jayBees = false;
    bool johnnyJugnu = false;
    bool friday = false;
    bool sse = false;

    // member functions()

};

int main()	{

    // define board size
    int boardSize;

    // defining objects
    player player1;
    player player2;

    // initialing pieces
    player1.piece = "!!";
    player2.piece = "^^";

    // shows instructions (readme)
    char check;
    string line;
    ifstream readme("instructions");
    if (readme.is_open())    {
        while(getline(readme, line))    {
            cout << line << "\n";
        }
        readme.close();
    }

    cout << "\nPress 1 to continue or 0 to exit: ";
    cin >> check;

    if (check == '1')   {
        system("clear");
    }
    else    {
        return 0;
    }

    // prompts for board size
    cout << "Board size (recommended 20): ";
    cin >> boardSize;

    // generate required number of spaces to make board
    int spaces = (boardSize * 2);

    // defines monopoly board array and capacity
    string board[boardSize][boardSize];

    // outer board generation loop
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++)  {
            if (i == 0 || i == boardSize - 1)   {
                board[i][j] = "--";
            }
            else
            {
                board[i][0] = "==";
                for (int k = 1; k <= spaces; k++)    {
                    board[i][k] = "  ";
                }
                board[i][boardSize - 1] = "==";
                break;
            }
        }
    }

    // position tracker of players from start
    player1.positionx = boardSize - 3;
    player1.positiony = boardSize - 3;
    player2.positionx = boardSize - 3;
    player2.positiony = boardSize - 4;

    // declaring objects and spawning at start position
    board[player1.positionx][player1.positiony] = player1.piece;
    board[player2.positionx][player2.positiony] = player2.piece;

    // board branding is a must
    board[9][7] = "L ";
    board[9][9] = "U ";
    board[9][11] = "M ";
    board[9][13] = "S ";
    board[10][10] = "X ";
    board[11][7] = "G ";
    board[11][8] = "R ";
    board[11][9] = "O ";
    board[11][10] = "U ";
    board[11][11] = "P ";
    board[11][12] = "4 ";
    board[11][13] = "5 ";



    // board printer
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }


    // game loop
    while(true) {

        srand (time(NULL));

        string roll;
        int random, checker = 0;

/*
    ================================================================
*/

        do {
            cout << "(player1) type roll to roll: ";
            cin >> roll;
        }
        while(roll != "roll");

		roll = "reset";

        random = rand() % 6 + 1;
        if (random == 1)    {
            random = 2;
        }

        player1.sum += random;

        if (player1.sum > 60)   {
            player1.balance = player1.balance + 50;
            player1.sum = player1.sum % 30;
        }

        // bottom row piece mover
        if (player1.positionx == 17 && player1.positiony != 2)    {

            system("clear");
            board[player1.positionx][player1.positiony] = "  ";
            bottomRow(player1.positionx, player1.positiony, random);
            board[player1.positionx][player1.positiony] = player1.piece;

            for (int i = 0; i < boardSize; i++) {
            	for (int j = 0; j < boardSize; j++) {
            		cout << board[i][j];
            	}
                cout << endl;
            }

            cout << "You rolled: " << random << endl;

        }

        // left column piece mover
        else if (player1.positiony == 2 && player1.positionx != 2) {

            system("clear");
            board[player1.positionx][player1.positiony] = "  ";
            leftColumn(player1.positionx, player1.positiony, random);
            board[player1.positionx][player1.positiony] = player1.piece;

            for (int i = 0; i < boardSize; i++) {
            	for (int j = 0; j < boardSize; j++) {
            		cout << board[i][j];
            	}
                cout << endl;
            }

            cout << "You rolled: " << random << endl;

        }

        // top row piece mover
        else if (player1.positionx == 2 && player1.positiony != 17) {

            system("clear");
            board[player1.positionx][player1.positiony] = "  ";
            topRow(player1.positionx, player1.positiony, random);
            board[player1.positionx][player1.positiony] = player1.piece;

            for (int i = 0; i < boardSize; i++) {
            	for (int j = 0; j < boardSize; j++) {
            		cout << board[i][j];
            	}
                cout << endl;
            }

            cout << "You rolled: " << random << endl;

        }

        // right colum piece mover
        else  {

            system("clear");
            board[player1.positionx][player1.positiony] = "  ";
            rightColumn(player1.positionx, player1.positiony, random);
            board[player1.positionx][player1.positiony] = player1.piece;

            for (int i = 0; i < boardSize; i++) {
            	for (int j = 0; j < boardSize; j++) {
            		cout << board[i][j];
            	}
                cout << endl;
            }

            cout << "You rolled: " << random << endl;

        }

        // property finder and buyer
        // starting block
        if (player1.positionx == 17 && (player1.positiony == 17 || player1.positiony == 16))    {
            cout << "Welcome to the start - $50 has been added to your balance. Good luck!" << endl;
        }

        // ehab's ghar
        if (player1.positionx == 17 && (player1.positiony == 15 || player1.positiony == 14))    {
            if (player1.ehabGhar == false && player2.ehabGhar == false)   {
                if  (player1.balance >= 10) {
                    ehabGhar(player1.balance, player1.ehabGhar);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent5(player1.balance, player2.balance, player1.ehabGhar);
            }
        }

        // osa
        if (player1.positionx == 17 && (player1.positiony == 13 || player1.positiony == 12))    {
            if (player1.osa == false && player2.osa == false)   {
                if  (player1.balance >= 10) {
                    osa(player1.balance, player1.osa);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent5(player1.balance, player2.balance, player1.osa);
            }
        }

        // pdc
        if (player1.positionx == 17 && (player1.positiony == 11 || player1.positiony == 10))    {
            if (player1.pdc == false && player2.pdc == false)   {
                if  (player1.balance >= 10) {
                    pdc(player1.balance, player1.pdc);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent5(player1.balance, player2.balance, player1.pdc);
            }
        }

        // hss
        if (player1.positionx == 17 && (player1.positiony == 9 || player1.positiony == 8))    {
            if (player1.hss == false && player2.hss == false)   {
                if  (player1.balance >= 10) {
                    hss(player1.balance, player1.hss);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent5(player1.balance, player2.balance, player1.hss);
            }
        }

        // lmbiCp
        if (player1.positionx == 17 && (player1.positiony == 7 || player1.positiony == 6))    {
            if (player1.lmbiCp == false && player2.lmbiCp == false)   {
                if  (player1.balance >= 10) {
                    lmbiCp(player1.balance, player1.lmbiCp);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent5(player1.balance, player2.balance, player1.lmbiCp);
            }
        }

        // soe
        if (player1.positionx == 17 && (player1.positiony == 5 || player1.positiony == 4))    {
            if (player1.soe == false && player2.soe == false)   {
                if  (player1.balance >= 10) {
                    soe(player1.balance, player1.soe);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent5(player1.balance, player2.balance, player1.soe);
            }
        }

        // lawSchool
        if (player1.positionx == 17 && (player1.positiony == 3 || player1.positiony == 2))    {
            if (player1.lawSchool == false && player2.lawSchool == false)   {
                if  (player1.balance >= 10) {
                    lawSchool(player1.balance, player1.lawSchool);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent5(player1.balance, player2.balance, player1.lawSchool);
            }
        }

        // hbaPlays
        if (player1.positiony == 2 && (player1.positionx == 16 || player1.positionx == 15))    {
            if (player1.hbaPlays == false && player2.hbaPlays == false)   {
                if  (player1.balance >= 20) {
                    hbaPlays(player1.balance, player1.hbaPlays);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent10(player1.balance, player2.balance, player1.hbaPlays);
            }
        }

        // jawahir
        if (player1.positiony == 2 && (player1.positionx == 14 || player1.positionx == 13))    {
            if (player1.jawahir == false && player2.jawahir == false)   {
                if  (player1.balance >= 20) {
                    jawahir(player1.balance, player1.jawahir);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent10(player1.balance, player2.balance, player1.jawahir);
            }
        }

        // bioMajor
        if (player1.positiony == 2 && (player1.positionx == 12 || player1.positionx == 11))    {
            if (player1.bioMajor == false && player2.bioMajor == false)   {
                if  (player1.balance >= 20) {
                    bioMajor(player1.balance, player1.bioMajor);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent10(player1.balance, player2.balance, player1.bioMajor);
            }
        }

        // junaidHaroon
        if (player1.positiony == 2 && (player1.positionx == 10 || player1.positionx == 9))    {
            if (player1.junaidHaroon == false && player2.junaidHaroon == false)   {
                if  (player1.balance >= 20) {
                    junaidHaroon(player1.balance, player1.junaidHaroon);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent10(player1.balance, player2.balance, player1.junaidHaroon);
            }
        }

        // cal
        if (player1.positiony == 2 && (player1.positionx == 8 || player1.positionx == 7))    {
            if (player1.cal == false && player2.cal == false)   {
                if  (player1.balance >= 20) {
                    cal(player1.balance, player1.cal);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent10(player1.balance, player2.balance, player1.cal);
            }
        }

        // khokha
        if (player1.positiony == 2 && (player1.positionx == 6 || player1.positionx == 5))    {
            if (player1.khokha == false && player2.khokha == false)   {
                if  (player1.balance >= 20) {
                    khokha(player1.balance, player1.khokha);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent10(player1.balance, player2.balance, player1.khokha);
            }
        }

        // subway
        if (player1.positiony == 2 && (player1.positionx == 4 || player1.positionx == 3))    {
            if (player1.subway == false && player2.subway == false)   {
                if  (player1.balance >= 20) {
                    subway(player1.balance, player1.subway);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent10(player1.balance, player2.balance, player1.subway);
            }
        }

        // jail
        if (player1.positionx == 2 && (player1.positiony == 2 || player1.positiony == 3))    {
            cout << "Haye bacho pakray gaye. Ab to DC lagay ge aur $20 ka chalan hoga!" << endl;
            player1.balance = player1.balance - 20;
            cout << "New balance: " << player1.balance << " " << endl;
        }

        // cso
        if (player1.positionx == 2 && (player1.positiony == 4 || player1.positiony == 5))    {
            if (player1.cso == false && player2.cso == false)   {
                if  (player1.balance >= 30) {
                    cso(player1.balance, player1.cso);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent15(player1.balance, player2.balance, player1.cso);
            }
        }

        // vcHouse
        if (player1.positionx == 2 && (player1.positiony == 6 || player1.positiony == 7))    {
            if (player1.vcHouse == false && player2.vcHouse == false)   {
                if  (player1.balance >= 30) {
                    vcHouse(player1.balance, player1.vcHouse);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent15(player1.balance, player2.balance, player1.vcHouse);
            }
        }

        // cardammom
        if (player1.positionx == 2 && (player1.positiony == 8 || player1.positiony == 9))    {
            if (player1.cardammom == false && player2.cardammom == false)   {
                if  (player1.balance >= 30) {
                    cardammom(player1.balance, player1.cardammom);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent15(player1.balance, player2.balance, player1.cardammom);
            }
        }

        // zakir
        if (player1.positionx == 2 && (player1.positiony == 10 || player1.positiony == 11))    {
            if (player1.zakir == false && player2.zakir == false)   {
                if  (player1.balance >= 30) {
                    zakir(player1.balance, player1.zakir);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent15(player1.balance, player2.balance, player1.zakir);
            }
        }

        // bhattaChowk
        if (player1.positionx == 2 && (player1.positiony == 12 || player1.positiony == 13))    {
            if (player1.bhattaChowk == false && player2.bhattaChowk == false)   {
                if  (player1.balance >= 30) {
                    bhattaChowk(player1.balance, player1.bhattaChowk);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent15(player1.balance, player2.balance, player1.bhattaChowk);
            }
        }

        // a16
        if (player1.positionx == 2 && (player1.positiony == 14 || player1.positiony == 15))    {
            if (player1.a16 == false && player2.a16 == false)   {
                if  (player1.balance >= 30) {
                    a16(player1.balance, player1.a16);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent15(player1.balance, player2.balance, player1.a16);
            }
        }

            // sdsbDrRoom
        if (player1.positionx == 2 && (player1.positiony == 16 || player1.positiony == 17))    {
            if (player1.sdsbDrRoom == false && player2.sdsbDrRoom == false)   {
                if  (player1.balance >= 30) {
                    sdsbDrRoom(player1.balance, player1.sdsbDrRoom);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent15(player1.balance, player2.balance, player1.sdsbDrRoom);
            }
        }

        // lums
        if (player1.positiony == 17 && (player1.positionx == 3 || player1.positionx == 4))    {
            if (player1.lums == false && player2.lums == false)   {
                if  (player1.balance >= 40) {
                    lums(player1.balance, player1.lums);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent20(player1.balance, player2.balance, player1.lums);
            }
        }

        // macNcheese
        if (player1.positiony == 17 && (player1.positionx == 5 || player1.positionx == 6))    {
            if (player1.macNcheese == false && player2.macNcheese == false)   {
                if  (player1.balance >= 40) {
                    macNcheese(player1.balance, player1.macNcheese);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent20(player1.balance, player2.balance, player1.macNcheese);
            }
        }

        // kohsarTiles
        if (player1.positiony == 17 && (player1.positionx == 7 || player1.positionx == 8))    {
            if (player1.kohsarTiles == false && player2.kohsarTiles == false)   {
                if  (player1.balance >= 40) {
                    kohsarTiles(player1.balance, player1.kohsarTiles);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent20(player1.balance, player2.balance, player1.kohsarTiles);
            }
        }

        // jayBees
        if (player1.positiony == 17 && (player1.positionx == 9 || player1.positionx == 10))    {
            if (player1.jayBees == false && player2.jayBees == false)   {
                if  (player1.balance >= 40) {
                    jayBees(player1.balance, player1.jayBees);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent20(player1.balance, player2.balance, player1.jayBees);
            }
        }

        // johnnyJugnu
        if (player1.positiony == 17 && (player1.positionx == 11 || player1.positionx == 12))    {
            if (player1.johnnyJugnu == false && player2.johnnyJugnu == false)   {
                if  (player1.balance >= 40) {
                    johnnyJugnu(player1.balance, player1.johnnyJugnu);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent20(player1.balance, player2.balance, player1.johnnyJugnu);
            }
        }

        // friday
        if (player1.positiony == 17 && (player1.positionx == 13 || player1.positionx == 14))    {
            if (player1.friday == false && player2.friday == false)   {
                if  (player1.balance >= 40) {
                    friday(player1.balance, player1.friday);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent20(player1.balance, player2.balance, player1.friday);
            }
        }

        // sse
        if (player1.positiony == 17 && (player1.positionx == 15 || player1.positionx == 16))    {
            if (player1.sse == false && player2.sse == false)   {
                if  (player1.balance >= 40) {
                    sse(player1.balance, player1.sse);
                    cout << "New balance: " << player1.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent20(player1.balance, player2.balance, player1.sse);
            }
        }

        // check if lost
        if (player1.balance < 0)    {
            cout << "Player 1, tun mera putr chutti kar!" << endl;
            break;
        }

/*
    ================================================================
*/

        do {
                cout << "(player 2) type roll to roll: ";
                cin >> roll;
            }
            while(roll != "roll");

    		roll = "reset";

            random = rand() % 6 + 1;
            if (random == 1)    {
                random = 2;
            }

            player2.sum += random;

            if (player2.sum > 60)   {
                player2.balance = player2.balance + 50;
                player2.sum = player2.sum % 30;
            }

        // bottom row piece mover
        if (player2.positionx == 17 && player2.positiony != 2)    {

            system("clear");
            board[player2.positionx][player2.positiony] = "  ";
            bottomRow(player2.positionx, player2.positiony, random);
            board[player2.positionx][player2.positiony] = player2.piece;

            for (int i = 0; i < boardSize; i++) {
            	for (int j = 0; j < boardSize; j++) {
            		cout << board[i][j];
            	}
                cout << endl;
            }

            cout << "You rolled: " << random << endl;

        }

        // left column piece mover
        else if (player2.positiony == 2 && player2.positionx != 2) {

            system("clear");
            board[player2.positionx][player2.positiony] = "  ";
            leftColumn(player2.positionx, player2.positiony, random);
            board[player2.positionx][player2.positiony] = player2.piece;

            for (int i = 0; i < boardSize; i++) {
            	for (int j = 0; j < boardSize; j++) {
            		cout << board[i][j];
            	}
                cout << endl;
            }

            cout << "You rolled: " << random << endl;

        }

        // top row piece mover
        else if (player2.positionx == 2 && player2.positiony != 17) {

            system("clear");
            board[player2.positionx][player2.positiony] = "  ";
            topRow(player2.positionx, player2.positiony, random);
            board[player2.positionx][player2.positiony] = player2.piece;

            for (int i = 0; i < boardSize; i++) {
            	for (int j = 0; j < boardSize; j++) {
            		cout << board[i][j];
            	}
                cout << endl;
            }

            cout << "You rolled: " << random << endl;

        }

        // left colum piece mover
        else  {

            system("clear");
            board[player2.positionx][player2.positiony] = "  ";
            rightColumn(player2.positionx, player2.positiony, random);
            board[player2.positionx][player2.positiony] = player2.piece;

            for (int i = 0; i < boardSize; i++) {
            	for (int j = 0; j < boardSize; j++) {
            		cout << board[i][j];
            	}
                cout << endl;
            }

            cout << "You rolled: " << random << endl;

        }

        // property finder and buyer
        // starting block
        if (player2.positionx == 17 && (player2.positiony == 17 || player2.positiony == 16))    {
            cout << "Welcome to the start - $50 has been added to your balance. Good luck!" << endl;
        }

        // ehab's ghar
        if (player2.positionx == 17 && (player2.positiony == 15 || player2.positiony == 14))    {
            if (player1.ehabGhar == false && player2.ehabGhar == false)   {
                if  (player2.balance >= 10) {
                    ehabGhar(player2.balance, player2.ehabGhar);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent5(player2.balance, player1.balance, player2.ehabGhar);
            }
        }

        // osa
        if (player2.positionx == 17 && (player2.positiony == 13 || player2.positiony == 12))    {
            if (player1.osa == false && player2.osa == false)   {
                if  (player2.balance >= 10) {
                    osa(player2.balance, player2.osa);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent5(player2.balance, player1.balance, player2.osa);
            }
        }

        // pdc
        if (player2.positionx == 17 && (player2.positiony == 11 || player2.positiony == 10))    {
            if (player1.pdc == false && player2.pdc == false)   {
                if  (player2.balance >= 10) {
                    pdc(player2.balance, player2.pdc);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent5(player2.balance, player1.balance, player2.pdc);
            }
        }

        // hss
        if (player2.positionx == 17 && (player2.positiony == 9 || player2.positiony == 8))    {
            if (player1.hss == false && player2.hss == false)   {
                if  (player2.balance >= 10) {
                    hss(player2.balance, player2.hss);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent5(player2.balance, player1.balance, player2.hss);
            }
        }

        // lmbiCp
        if (player2.positionx == 17 && (player2.positiony == 7 || player2.positiony == 6))    {
            if (player1.lmbiCp == false && player2.lmbiCp == false)   {
                if  (player2.balance >= 10) {
                    lmbiCp(player2.balance, player2.lmbiCp);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent5(player2.balance, player1.balance, player2.lmbiCp);
            }
        }

        // soe
        if (player2.positionx == 17 && (player2.positiony == 5 || player2.positiony == 4))    {
            if (player1.soe == false && player2.soe == false)   {
                if  (player2.balance >= 10) {
                    soe(player2.balance, player2.soe);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent5(player2.balance, player1.balance, player2.soe);
            }
        }

        // lawSchool
        if (player2.positionx == 17 && (player2.positiony == 3 || player2.positiony == 2))    {
            if (player1.lawSchool == false && player2.lawSchool == false)   {
                if  (player2.balance >= 10) {
                    lawSchool(player2.balance, player2.lawSchool);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent5(player2.balance, player1.balance, player2.lawSchool);
            }
        }

        // hbaPlays
        if (player2.positiony == 2 && (player2.positionx == 16 || player2.positionx == 15))    {
            if (player1.hbaPlays == false && player2.hbaPlays == false)   {
                if  (player2.balance >= 20) {
                    hbaPlays(player2.balance, player2.hbaPlays);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent10(player2.balance, player1.balance, player2.hbaPlays);
            }
        }

        // jawahir
        if (player2.positiony == 2 && (player2.positionx == 14 || player2.positionx == 13))    {
            if (player1.jawahir == false && player2.jawahir == false)   {
                if  (player2.balance >= 20) {
                    jawahir(player2.balance, player2.jawahir);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent10(player2.balance, player1.balance, player2.jawahir);
            }
        }

        // bioMajor
        if (player2.positiony == 2 && (player2.positionx == 12 || player2.positionx == 11))    {
            if (player1.bioMajor == false && player2.bioMajor == false)   {
                if  (player2.balance >= 20) {
                    bioMajor(player2.balance, player2.bioMajor);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent10(player2.balance, player1.balance, player2.bioMajor);
            }
        }

        // junaidHaroon
        if (player2.positiony == 2 && (player2.positionx == 10 || player2.positionx == 9))    {
            if (player1.junaidHaroon == false && player2.junaidHaroon == false)   {
                if  (player2.balance >= 20) {
                    junaidHaroon(player2.balance, player2.junaidHaroon);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent10(player2.balance, player1.balance, player2.junaidHaroon);
            }
        }

        // cal
        if (player2.positiony == 2 && (player2.positionx == 8 || player2.positionx == 7))    {
            if (player1.cal == false && player2.cal == false)   {
                if  (player2.balance >= 20) {
                    cal(player2.balance, player2.cal);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent10(player2.balance, player1.balance, player2.cal);
            }
        }

        // khokha
        if (player2.positiony == 2 && (player2.positionx == 6 || player2.positionx == 5))    {
            if (player1.khokha == false && player2.khokha == false)   {
                if  (player2.balance >= 20) {
                    khokha(player2.balance, player2.khokha);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent10(player2.balance, player1.balance, player2.khokha);
            }
        }

        // subway
        if (player2.positiony == 2 && (player2.positionx == 4 || player2.positionx == 3))    {
            if (player1.subway == false && player2.subway == false)   {
                if  (player2.balance >= 20) {
                    subway(player2.balance, player2.subway);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent10(player2.balance, player1.balance, player2.subway);
            }
        }

        // jail
        if (player2.positionx == 2 && (player2.positiony == 2 || player2.positiony == 3))    {
            cout << "Haye bacho pakray gaye. Ab to DC lagay ge aur $20 ka chalan hoga!" << endl;
            player2.balance = player2.balance - 20;
            cout << "New balance: " << player2.balance << " " << endl;
        }

        // cso
        if (player2.positionx == 2 && (player2.positiony == 4 || player2.positiony == 5))    {
            if (player1.cso == false && player2.cso == false)   {
                if  (player2.balance >= 30) {
                    cso(player2.balance, player2.cso);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent15(player2.balance, player1.balance, player2.cso);
            }
        }

        // vcHouse
        if (player2.positionx == 2 && (player2.positiony == 6 || player2.positiony == 7))    {
            if (player1.vcHouse == false && player2.vcHouse == false)   {
                if  (player2.balance >= 30) {
                    vcHouse(player2.balance, player2.vcHouse);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent15(player2.balance, player1.balance, player2.vcHouse);
            }
        }

        // cardammom
        if (player2.positionx == 2 && (player2.positiony == 8 || player2.positiony == 9))    {
            if (player1.cardammom == false && player2.cardammom == false)   {
                if  (player2.balance >= 30) {
                    cardammom(player2.balance, player2.cardammom);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent15(player2.balance, player1.balance, player2.cardammom);
            }
        }

        // zakir
        if (player2.positionx == 2 && (player2.positiony == 10 || player2.positiony == 11))    {
            if (player1.zakir == false && player2.zakir == false)   {
                if  (player2.balance >= 30) {
                    zakir(player2.balance, player2.zakir);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent15(player2.balance, player1.balance, player2.zakir);
            }
        }

        // bhattaChowk
        if (player2.positionx == 2 && (player2.positiony == 12 || player2.positiony == 13))    {
            if (player1.bhattaChowk == false && player2.bhattaChowk == false)   {
                if  (player2.balance >= 30) {
                    bhattaChowk(player2.balance, player2.bhattaChowk);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent15(player2.balance, player1.balance, player2.bhattaChowk);
            }
        }

        // a16
        if (player2.positionx == 2 && (player2.positiony == 14 || player2.positiony == 15))    {
            if (player1.a16 == false && player2.a16 == false)   {
                if  (player2.balance >= 30) {
                    a16(player2.balance, player2.a16);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent15(player2.balance, player1.balance, player2.a16);
            }
        }

        // sdsbDrRoom
        if (player2.positionx == 2 && (player2.positiony == 16 || player2.positiony == 17))    {
            if (player1.sdsbDrRoom == false && player2.sdsbDrRoom == false)   {
                if  (player2.balance >= 30) {
                    sdsbDrRoom(player2.balance, player2.sdsbDrRoom);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent15(player2.balance, player1.balance, player2.sdsbDrRoom);
            }
        }

        // lums
        if (player2.positiony == 17 && (player2.positionx == 3 || player2.positionx == 4))    {
            if (player1.lums == false && player2.lums == false)   {
                if  (player2.balance >= 40) {
                    lums(player2.balance, player2.lums);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent20(player2.balance, player1.balance, player2.lums);
            }
        }

        // macNcheese
        if (player2.positiony == 17 && (player2.positionx == 5 || player2.positionx == 6))    {
            if (player1.macNcheese == false && player2.macNcheese == false)   {
                if  (player2.balance >= 40) {
                    macNcheese(player2.balance, player2.macNcheese);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent20(player2.balance, player1.balance, player2.macNcheese);
            }
        }

        // kohsarTiles
        if (player2.positiony == 17 && (player2.positionx == 7 || player2.positionx == 8))    {
            if (player1.kohsarTiles == false && player2.kohsarTiles == false)   {
                if  (player2.balance >= 40) {
                    kohsarTiles(player2.balance, player2.kohsarTiles);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent20(player2.balance, player1.balance, player2.kohsarTiles);
            }
        }

        // jayBees
        if (player2.positiony == 17 && (player2.positionx == 9 || player2.positionx == 10))    {
            if (player1.jayBees == false && player2.jayBees == false)   {
                if  (player2.balance >= 40) {
                    jayBees(player2.balance, player2.jayBees);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent20(player2.balance, player1.balance, player2.jayBees);
            }
        }

        // johnnyJugnu
        if (player2.positiony == 17 && (player2.positionx == 11 || player2.positionx == 12))    {
            if (player1.johnnyJugnu == false && player2.johnnyJugnu == false)   {
                if  (player2.balance >= 40) {
                    johnnyJugnu(player2.balance, player2.johnnyJugnu);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent20(player2.balance, player1.balance, player2.johnnyJugnu);
            }
        }

        // friday
        if (player2.positiony == 17 && (player2.positionx == 13 || player2.positionx == 14))    {
            if (player1.friday == false && player2.friday == false)   {
                if  (player2.balance >= 40) {
                    friday(player2.balance, player2.friday);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent20(player2.balance, player1.balance, player2.friday);
            }
        }

        // sse
        if (player2.positiony == 17 && (player2.positionx == 15 || player2.positionx == 16))    {
            if (player1.sse == false && player2.sse == false)   {
                if  (player2.balance >= 40) {
                    sse(player2.balance, player2.sse);
                    cout << "New balance: " << player2.balance << " " << endl;
                }
                else {
                    cout << "Insufficent funds" << endl;
                }
            }
            else    {
                rent20(player2.balance, player1.balance, player2.sse);
            }
        }

        // check if lost
        if (player2.balance < 0)    {
            cout << "Player 2, tun mera putr chutti kar!" << endl;
            break;
        }

    }

        cout << "Better luck next time!" << endl;

        return 0;
    }