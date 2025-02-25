#include <stdio.h>

struct parcel {
    int orientation;
    int x;
};

int place1 (int j, int i);
int place2 (int j, int i);

int main(void) {
    int parcel_no, i = 0, j = 0, actmax;
    char boolplaced = 'n';
    scanf("%d", &parcel_no);
    int max = parcel_no * 2 + 1;
    char xy[max][7];
    struct parcel parcels[parcel_no];
    while (i < parcel_no) {
        scanf("%d %d", &parcels[i].orientation, &parcels[i].x);
        i++;
    }

    i = 0;
    while (i <= max) {
        while (j <= 6) {
            xy[i][j] = '_';
            //printf("%c", xy[i][j]);
            j++;
        }
        j = 0;
        //printf("\n");
        i++;
    }
    i = 0;
    while (i < parcel_no) {
        j = i * 2;
        if (parcels[i].orientation == 1) {
            while (j >= 0) {
                if (xy[j][parcels[i].x] == '*') {
                    xy[j + 1][parcels[i].x] = '*';
                    xy[j + 2][parcels[i].x] = '*';
                    j = 0;
                    boolplaced = 'y';
                }
                j--;
            }
            if (boolplaced == 'n') {
                xy[0][parcels[i].x] = '*';
                xy[1][parcels[i].x] = '*';
            }
        }
        else {
            while (j >= 0) {
                if (xy[j][parcels[i].x] == '*' || xy[j][parcels[i].x + 1] == '*') {
                    xy[j + 1][parcels[i].x] = '*';
                    xy[j + 1][parcels[i].x + 1] = '*';
                    j = 0;
                    boolplaced = 'y';
                
                }
                j--;
            }
            if (boolplaced == 'n') {
                xy[0][parcels[i].x] = '*';
                xy[0][parcels[i].x + 1] = '*';
            }
        }
        i++;
    }
    i = max;
    j = 0;
    while (i >= 0) {
        while (j <= 6) {
            if (xy[i][j] == '*') {
                actmax = i;
                i = 0;
                j = 6;
            }
            j++;
        }
        j = 0;
        i--;
    }
    i = actmax;
    j = 0;
    while (i >= 0) {
        while (j <= 6) {
            printf("%c", xy[i][j]);
            j++;
        }
        printf("\n");
        j = 0;
        i--;
    }


    
    return 0;
}


