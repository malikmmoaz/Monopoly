#ifndef RENT_H
#define RENT_H

using namespace std;

    // $5 rent machine
    void rent5(int &balance, int &balance2, bool p1)   {

        if (p1 == false)    {
            cout << "Haye bacho, $5 rent nikaal." << endl;
            balance = balance - 5;
            balance2 = balance2 + 5;
            cout << "New balance: " << balance << " " << endl;
        }
        else    {
            cout << "You already own this property." << endl;
        }

        return;
    }

    // $10 rent machine
    void rent10(int &balance, int &balance2, bool p1)   {

        if (p1 == false)    {
            cout << "Haye bacho, $10 rent nikaal." << endl;
            balance = balance - 10;
            balance2 = balance2 + 10;
            cout << "New balance: " << balance << " " << endl;
        }
        else    {
            cout << "You already own this property." << endl;
        }

        return;
    }

    // $15 rent machine
    void rent15(int &balance, int &balance2, bool p1)   {

        if (p1 == false)    {
            cout << "Haye bacho, $15 rent nikaal." << endl;
            balance = balance - 15;
            balance2 = balance2 + 15;
            cout << "New balance: " << balance << " " << endl;
        }
        else    {
            cout << "You already own this property." << endl;
        }

        return;
    }

    // $20 rent machine
    void rent20(int &balance, int &balance2, bool p1)   {

        if (p1 == false)    {
            cout << "Haye bacho, $20 rent nikaal." << endl;
            balance = balance - 20;
            balance2 = balance2 + 20;
            cout << "New balance: " << balance << " " << endl;
        }
        else    {
            cout << "You already own this property." << endl;
        }

        return;
    }

#endif