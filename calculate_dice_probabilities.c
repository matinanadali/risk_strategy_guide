#include <stdio.h>
#include <math.h>
int main() {
    int win32 = 0;
    int los32 = 0;
    int tie32 = 0;

    int win22 = 0;
    int los22 = 0;
    int tie22 = 0;
    
    //simulate all possible outcomes (1296) when playing 2 vs 2 dices (varibles i,j - k,z)
    //and when playing 3 vs 2 dices (7776 possible outcomes) (varibles t,i,j - k,z)
    for (int t = 1; t <= 6; t++) {
        for (int i = 1; i <= 6; i ++) {
            for (int j = 1; j <= 6; j++) {
                int my_max32 = fmax(t,fmax(i,j));
                int my_min32 = t + i + j - fmin(t,fmin(i,j)) - my_max32;
                
                int my_max22 = fmax(i,j);
                int my_min22 = fmin(i,j);
                for (int k = 1; k <= 6; k++) {
                    for (int z = 1; z <= 6; z++) {
                        int opp_min = fmin(k,z);
                        int opp_max = fmax(k,z);
                        if (my_max32 > opp_max && my_min32 > opp_min) {
                            win32 ++;
                        } else if (my_max32 <= opp_max && my_min32 <= opp_min) {
                            los32 ++;
                        } else {
                            tie32 ++;
                        }
                        //only for the first iteration of the outer loop
                        if (t == 1) {
                            if (my_max22 > opp_max && my_min22 > opp_min) {
                                win22 ++;
                            } else if (my_max22 <= opp_max && my_min22 <= opp_min) {
                                los22 ++;
                            } else {
                                tie22 ++;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("When playing 2 vs 2 dices: \nProbability of winning= %f\nProbability of losing= %f\nProbability of tie= %f\n", win22/1296.0, los22/1296.0, tie22/1296.0);
    printf("When playing 3 vs 2 dices: \nProbability of winning= %f\nProbability of losing= %f\nProbability of tie %f\n", win32/7776.0, los32/7776.0, tie32/7776.0);
    
    int win31 = 0;
    int los31 = 0;

    int win21 = 0;
    int los21 = 0;

    for (int i = 1; i<= 6; i++) {
        for (int j = 1; j <=6; j++) {
            for (int k=1; k<=6; k++) {
                for (int z=1; z<=6;z++) {
                    int my_max31 = fmax(i,fmax(j,k));
                    int my_max21 = fmax(j,k);
                    if (my_max31 > z) {
                        win31++;
                    } else {
                        los31++;
                    }
                    if (i == 1) {
                        if (my_max21 > z) {
                            win21++;
                        } else {
                            los21++;
                        }
                    }
                }
            }
        }
    }
    

    printf("When playing 2 vs 1 dices: \nProbability of winning= %f\nProbability of losing= %f\n", win21/216.0, los21/216.0);
    printf("When playing 3 vs 1 dices: \nProbability of winning= %f\nProbability of losing= %f\n", win31/1296.0, los31/1296.0);

    int win12 = 0;
    int los12 = 0;

    int win11 = 0;
    int los11 = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                int opp_max21 = fmax(j,k);
                if (i > opp_max21) {
                    win12 ++;
                } else {
                    los12 ++;
                }
                if (k == 1) {
                    if (i > j) {
                        win11 ++;
                    } else {
                        los11 ++;
                    }
                }
            }
        }
    }
    printf("When playing 1 vs 2 dices: \nProbability of winning= %f\nProbability of losing= %f\n", win12/216.0, los12/216.0);
     printf("When playing 1 vs 1 dices: \nProbability of winning= %f\nProbability of losing= %f\n", win11/36.0, los11/36.0);
    return 0;

}
