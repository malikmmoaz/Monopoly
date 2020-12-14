#ifndef COMPANDPRIN_H
#define COMPANDPRIN_H

    // bottom row position computer
    void bottomRow(int &x, int &y, int random)  {

        int checker = 0;

        if (x == 17)    {
    		if (y - random < 2 && x == 17) {
                do  {
                    y--;
                    checker++;
                }
                while(y != 2);

                x = x - (random - checker);
                checker = 0;
    		}
        	else    {
                y -= random;
            }
		}

		return;
    }

	// left column position computer
    void leftColumn(int &x, int &y, int random)  {

        int checker = 0;

        if (y == 2)    {
    		if (x - random < 2 && y == 2) {
                do  {
                    x--;
                    checker++;
                }
                while(x != 2);

                y = y + (random - checker);
                checker = 0;
    		}
        	else    {
                x -= random;
            }
		}

	    return;
    }

    // top row position computer
    void topRow(int &x, int &y, int random)  {

        int checker = 0;

        if (x == 2)    {
    		if (y + random > 17 && x == 2) {
                do  {
                    y++;
                    checker++;
                }
                while(y != 17);

                x = x + (random - checker);
                checker = 0;
    		}
        	else    {
                y += random;
            }
		}

	    return;
    }

    // right column position computer
    void rightColumn(int &x, int &y, int random)  {

        int checker = 0;

        if (y == 17)    {
    		if (x + random > 17 && y == 17) {
                do  {
                    x++;
                    checker++;
                }
                while(x != 17);

                y = y - (random - checker);
                checker = 0;
    		}
        	else    {
                x += random;
            }
		}

	    return;
    }
    
    

#endif