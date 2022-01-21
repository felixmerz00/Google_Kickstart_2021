#include <stdio.h>
#include <stdlib.h>

/*Lösungsansatz:
1. Segmente zählen:
    Falls Wert = 0 -> In der Zeile ein Feld weiter gehen
    Falls Wert = 1 ->
        1. Testen ob Felder rechts davon auch den Wert 1 haben.
        2. Testen ob Felder nach unten den Wert 1 haben.
2. Falls ein Segment gefunden wird, num_L_shapes variable erhöhen*/

int count_l_shapes(int rows, int columns, int field[4][3]);
struct Sequence *find_sequence(int x_start, int y_start, int field[4][3], char direction);
int rows;
int columns;

int main()
{
    int array[4][3] = {{1, 0, 1}, {1, 0, 1}, {1, 0, 1}, {1, 1, 1}};
    rows = 4;
    columns = 3;
    display(rows, columns, array);
    int num = count_l_shapes(4, 3, &array);
    printf("The array has %d L-shapes.", num);
    return 0;
}

/*Finds, counts and returns the number of L-shapes.*/
int count_l_shapes(int rows, int columns, int field[4][3])
{
    int num_L_shapes = 0;
    /*Scan the field for sequences.*/
    for(int zeile = 0; zeile < rows; zeile++){
        for(int spalte = 0; spalte < columns; spalte++){
            /*checks if the current field is part of a sequence*/
            if(field[zeile][spalte] == 1){
                num_L_shapes += test_current_position(zeile, spalte, field);
            }
        }
    }
    return num_L_shapes;
}

/*tests weather one field is part of an L*/
int test_current_position(int current_row, int current_column, int field[4][3])
{
    int num_of_L = 0;
    int width = 1;
    int height = 1;
    /*checking for sequences horizontally first*/
    for(int i = current_column + 1; i < columns; i++){
        if(field[current_row][i] == 1){
            width++;
            /*test weather it shapes an L*/
            for(int j = current_row + 1; j < rows; j++){
                if(field[j][i] == 1){
                    height++;
                    if(2 * height == width || height == 2 * width){
                    num_of_L++;
                    height = 1;
                    break; /*inner for-loop should be broken, outer for-loop should continue*/
                    }
                    else{break;}
                }

            }
        }
        else{break;}
    }

    width = 1; height = 1;
    /*checking for sequences vertically first*/
    for(int j = current_row + 1; j < rows; j++){
        if(field[j][current_column] == 1){
            height++;
            /*test weather it shapes an L*/
            for(int i = current_column + 1; i < columns; i++){
                if(field[j][i] == 1){
                    width++;
                    if(2 * height == width || height == 2 * width){
                        num_of_L++;
                        width = 1;
                        break; /*inner for-loop should be broken, outer for-loop should continue*/
                    }
                }
                else{break;}
            }
        }
        else{break;}
    }
    return num_of_L;
}

void display(int rows, int columns, int A[4][3])
{
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

