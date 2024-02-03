#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>

char Chess_Board[19][37];
int player;
char name1[15], name2[15];

void Print_Chess_Board();
int Valid_Integer_Input(int min_value, int max_value, char statement[]);
char Valid_Character_Input(char min_value, char max_value, char statement[]);
void ClearBuffer();
void swap(char *c1, char *c2);
bool Valid_Move(char piece, int X[], int Y[]);
bool Valid_Path(char piece, int X[], int Y[]);
void NewWindow();
bool Check();
bool Check_Path(char piece, int x, int y, int a, int b);
bool Check_Mate(int X[], int Y[]);

int main()
{
    for(int i=0; i<19; i++)
    {
        for(int j=0; j<37; j++)
        {
            for(char k='1', x=3; k<='8', x<=17; k++, x+=2)
            {
                Chess_Board[x][2] = k;
            }
            for(char k='A', x=6; k<='H', x<=34; k++, x+=4)
            {
                Chess_Board[1][x] = k;
            }
            if((i==2 || i==18) && (j>=4 && j<=36))
            {
                Chess_Board[i][j] = '=';
            }
            else if((j==4 || j==36) && (i>=3 && i<=17))
            {
                Chess_Board[i][j] = '|';
            }
            else if(!(i%2 == 0) && (j%4 == 0) && (j>4) && (i>2))
            {
                Chess_Board[i][j] = '|';
            }
            else if((i>2) && (j>4) && ((i%2 == 0) && !(j%4 == 0)))
            {
                Chess_Board[i][j] = '-';
            }
            else if((i%2 == 0) && (j%4 == 0) && (i>2) && (j>4))
            {
                Chess_Board[i][j] = '+';
            }
            else
            {
                Chess_Board[i][j] = ' ';
            }
        }
    }

    Chess_Board[3][6] = 'E';
    Chess_Board[3][34] = 'E';
    Chess_Board[3][10] = 'H';
    Chess_Board[3][30] = 'H';
    Chess_Board[3][14] = 'C';
    Chess_Board[3][26] = 'C';
    Chess_Board[3][18] = 'K';
    Chess_Board[3][22] = 'Q';
    Chess_Board[5][6] = 'X';
    Chess_Board[5][34] = 'X';
    Chess_Board[5][10] = 'X';
    Chess_Board[5][30] = 'X';
    Chess_Board[5][14] = 'X';
    Chess_Board[5][26] = 'X';
    Chess_Board[5][18] = 'X';
    Chess_Board[5][22] = 'X';

    Chess_Board[17][6] = 'e';
    Chess_Board[17][34] = 'e';
    Chess_Board[17][10] = 'h';
    Chess_Board[17][30] = 'h';
    Chess_Board[17][14] = 'c';
    Chess_Board[17][26] = 'c';
    Chess_Board[17][18] = 'q';
    Chess_Board[17][22] = 'k';
    Chess_Board[15][6] = 'y';
    Chess_Board[15][34] = 'y';
    Chess_Board[15][10] = 'y';
    Chess_Board[15][30] = 'y';
    Chess_Board[15][14] = 'y';
    Chess_Board[15][26] = 'y';
    Chess_Board[15][18] = 'y';
    Chess_Board[15][22] = 'y';

    int row_number[19], column_number[37];
    int position_X[2], position_Y[2];

       

    int m=1;
    for(int x=3; x<=17; x+=2)
    {
        row_number[x] = m;
        m++;
    }

    char n = 'A';
    for(int y=6; y<=34; y+=4, n++)
    {
        column_number[y] = n;
    }

    char column, col1=0, col2=0;
    int row, row1=0, row2=0;
    char statement[100];

    printf("\nUppercase Latter for Player 1.\nLowercase Latter for Player 2.\n");

    printf("\nEnter Name Of Player 1 : ");
    scanf("%s", name1);
    ClearBuffer();

    printf("\nEnter Name Of Player 2 : ");
   scanf("%s", name2);
   ClearBuffer();

    NewWindow();

    printf("\nUppercase Latter for %s.\nLowercase Latter for %s.\n", name1, name2);

    NewWindow();

    for(int i=0; ; i++)
    {
        if(i%2 == 0)
        {
            player = 1;
        }
        else if(i%2 == 1)
        {
            player = 2;
        }

        Again :

        printf("\nOld Move : %c%d - %c%d\n", col1, row1, col2, row2);

        Print_Chess_Board();

        if(Check() == true)
        {
            printf("\nCHECK..!\n");
        }
        else if(Check_Mate(position_X, position_Y) == true)
        {
            
        }

        if(i%2 == 0)
        {
            printf("\n\n\033[1m%s's Turn :\033[0m\n", name1);
        }
        else if(i%2 == 1)
        {
            printf("\n\n\033[1m%s's Turn :\033[0m\n", name2);
        }

        Again_Selection :

        printf("\nSelect Position :\n\n");

        sprintf(statement, "Enter Column");
        column =  Valid_Character_Input('A', 'H', statement);
        col1 = column;

        sprintf(statement, "Enter Row");
        row = Valid_Integer_Input(1, 8, statement);
        row1 = row;

        for(int i=3, j=6; i<=17 && j<=34; i+=2, j+=4)
        {
            (row_number[i] == row) ? (position_X[0] = i) : (NULL);
            (column_number[j] == column) ? (position_Y[0] = j) : (NULL);
        }

        if((player == 1) && (!(Chess_Board[position_X[0]][position_Y[0]] >= 'A' && Chess_Board[position_X[0]][position_Y[0]] <= 'Z') || (Chess_Board[position_X[0]][position_Y[0]] == ' ')))
        {
            printf("\nWrong Selection..!\n\n");
            goto Again_Selection;
        }
        else if((player == 2) && (!(Chess_Board[position_X[0]][position_Y[0]] >= 'a' && Chess_Board[position_X[0]][position_Y[0]] <= 'z') || (Chess_Board[position_X[0]][position_Y[0]] == ' ')))
        {
            printf("\nWrong Selection..!\n\n");
            goto Again_Selection;
        }

        Again_Destination :

        printf("\nSelect Destination :\n\n");

        sprintf(statement, "Enter Column");
        column =  Valid_Character_Input('A', 'H', statement);
        col2 = column;

        sprintf(statement, "Enter Row");
        row = Valid_Integer_Input(1, 8, statement);
        row2 = row;

        for(int i=3, j=6; i<=17 && j<=34; i+=2, j+=4)
        {
            (row_number[i] == row) ? (position_X[1] = i) : (NULL);
            (column_number[j] == column) ? (position_Y[1] = j) : (NULL);
        }

        if((player == 1) && (Chess_Board[position_X[1]][position_Y[1]] >= 'A' && Chess_Board[position_X[1]][position_Y[1]] <= 'Z'))
        {
            printf("\nWrong Destination..!\nYou're attacking on Your Own Team..!\n\n");
            goto Again_Destination;
        }
        else if((player == 2) && (Chess_Board[position_X[1]][position_Y[1]] >= 'a' && Chess_Board[position_X[1]][position_Y[1]] <= 'z'))
        {
            printf("\nWrong Destination..!\nYou're attacking on Your Own Team..!\n\n");
            goto Again_Destination;
        }

        if(Valid_Move(Chess_Board[position_X[0]][position_Y[0]], position_X, position_Y) == true)
        {
            if(Valid_Path(Chess_Board[position_X[0]][position_Y[0]], position_X, position_Y) == true)
            {   
                if(Chess_Board[position_X[1]][position_Y[1]] == ' ')
                    {
                    swap(&Chess_Board[position_X[0]][position_Y[0]], &Chess_Board[position_X[1]][position_Y[1]]);
                }
                else
                {
                    Chess_Board[position_X[1]][position_Y[1]] = ' ';
                    swap(&Chess_Board[position_X[0]][position_Y[0]], &Chess_Board[position_X[1]][position_Y[1]]);
                }
            }
            else
            {
                if(Chess_Board[position_X[0]][position_Y[0]] == ('K' || 'k'))
                {
                    if(Check_Mate(position_X, position_Y) == true)
                    {
                        printf("\nCHECK MATE..!\n");

                        if(player == 1)
                        {
                            printf("\t%s is Winner..!\n", name2);
                        }
                        else if(player == 2)
                        {
                            printf("\t%s is Winner..!\n", name1);
                        }
                    }
                }
                else
                {
                    system("cls");
                    printf("\nInvalid Path..!\n");
                    goto Again;
                }
            }
        }
        else
        {
            if(Chess_Board[position_X[0]][position_Y[0]] == ('K' || 'k'))
            {
                if(Check_Mate(position_X, position_Y) == true)
                {
                    printf("\nCHECK MATE..!\n");

                    if(player == 1)
                    {
                        printf("\t%s is Winner..!\n", name2);
                    }
                    else if(player == 2)
                    {
                        printf("\t%s is Winner..!\n", name1);
                    }
                }
            }
            else
            {   
                system("cls");
                printf("\nInvalid Move..!\n");
                goto Again;
            }
        }

        system("cls");
    }

    getch();
    return 0;
}

void Print_Chess_Board()
{
    for(int i=0; i<19; i++)
    {
        for(int j=0; j<37; j++)
        {
            printf("%c", Chess_Board[i][j]);
        }
        printf("\n");
    }
}

int Valid_Integer_Input(int min_value, int max_value, char statement[])
{
    int entered_value;

    printf("%s : ", statement);
    scanf("%d", &entered_value);
    ClearBuffer();

    while(!((entered_value >= min_value) && (entered_value <= max_value)))
    {
        printf("\nPlease Enter Valid Responce..!\n");
        printf("%s : ", statement);
        scanf("%d", &entered_value);

        if((entered_value >= min_value) && (entered_value <= max_value))
        {
            break;
        }
    }

    return entered_value;
}

char Valid_Character_Input(char min_value, char max_value, char statement[])
{
    char entered_value;

    printf("%s : ", statement);
    scanf("%c", &entered_value);
    ClearBuffer();

    while(!((entered_value >= min_value) && (entered_value <= max_value)))
    {
        printf("\nPlease Enter Valid Responce..!\n");
        printf("%s : ", statement);
        scanf("%c", &entered_value);

        if((entered_value >= min_value) && (entered_value <= max_value))
        {
            break;
        }
    }

    return entered_value;
}

void ClearBuffer()
{
    int clearBuffer;
    while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF);
}

void swap(char *c1, char *c2)
{
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

bool Valid_Move(char piece, int X[], int Y[])
{
    if(piece == 'X')
    {
        if((X[1] == X[0] + 2) && (Y[0] == Y[1]) && Chess_Board[X[1]][Y[1]] == ' ')
        {
            return true;
        }
        else if(((X[1] == X[0] + 2) && ((Y[1] == Y[0] + 4) || (Y[1] == Y[0] - 4))) && (Chess_Board[X[1]][Y[1]] != ' '))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(piece == 'y')
    {
        if((X[1] == X[0] - 2) && (Y[0] == Y[1]) && Chess_Board[X[1]][Y[1]] == ' ')
        {
            return true;
        }
        else if(((X[1] == X[0] - 2) && ((Y[1] == Y[0] + 4) || (Y[1] == Y[0] - 4))) && (Chess_Board[X[1]][Y[1]] != ' '))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(piece == 'E' || piece == 'e')
    {
        if((X[0] == X[1]) || (Y[0] == Y[1]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(piece == 'H' || piece == 'h')
    {
        if(
            (((X[1] == X[0] + 2) || (X[1] == X[0] - 2)) && ((Y[1] == Y[0] + 8) || (Y[1] == Y[0] - 8))) ||
            (((X[1] == X[0] + 4) || (X[1] == X[0] - 4)) && ((Y[1] == Y[0] + 4) || (Y[1] == Y[0] - 4)))
        )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(piece == 'C' || piece == 'c')
    {
        int count = 0;

        for(int i=2, j=4; i<=14, j<=28; i+=2, j+=4)
        {
            if(((X[1] == X[0] + i) || (X[1] == X[0] - i)) && ((Y[1] == Y[0] + j) || (Y[1] == Y[0] - j)))
            {
                count++;
            }
        }

        if(count > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(piece == 'Q' || piece == 'q')
    {
        int count = 0;

        for(int i=2, j=4; i<=14, j<=28; i+=2, j+=4)
        {
            if(((X[1] == X[0] + i) || (X[1] == X[0] - i)) && ((Y[1] == Y[0] + j) || (Y[1] == Y[0] - j)))
            {
                count++;
            }
        }

        if((X[0] == X[1]) || (Y[0] == Y[1]) || (count > 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(piece == 'K' || piece == 'k')
    {
        if(
            (((X[1] == X[0] + 2) || (X[1] == X[0] - 2)) && (Y[0] == Y[1])) ||
            (((Y[1] == Y[0] + 4) || (Y[1] == Y[0] - 4)) && (X[0] == X[1])) ||
            (((X[1] == X[0] + 2) || (X[1] == X[0] - 2)) && ((Y[1] == Y[0] + 4) || (Y[1] == Y[0] - 4)))
        )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Valid_Path(char piece, int X[], int Y[])
{
    if(piece == 'C' || piece == 'c')
    {
        if((X[1] > X[0]) && (Y[1] > Y[0]))
        {
            int count = 0;

            for(int i=X[0]+2, j=Y[0]+4; i<=X[1], j<=Y[1]; i+=2, j+=4)
            {
                if(Chess_Board[i][j] == ' ')
                {
                    count++;
                }
            }

            if(((count == ((X[1] - X[0]) / 2)) && (count == ((Y[1] - Y[0]) / 4))) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if(((count == ((X[1] - X[0]) / 2) - 1) && (count == ((Y[1] - Y[0]) / 4) - 1)) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((X[1] > X[0]) && (Y[1] < Y[0]))
        {
            int count = 0;

            for(int i=X[0]+2, j=Y[0]-4; i<=X[1], j>=Y[1]; i+=2, j-=4)
            {
                if(Chess_Board[i][j] == ' ')
                {
                    count++;
                }
            }

            if((count == ((X[1] - X[0]) / 2)) && (count == ((Y[0] - Y[1]) / 4)) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if(((count == ((X[1] - X[0]) / 2) - 1) && (count == ((Y[0] - Y[1]) / 4) - 1)) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((X[1] < X[0]) && (Y[1] > Y[0]))
        {
            int count = 0;

            for(int i=X[0]-2, j=Y[0]+4; i>=X[1], j<=Y[1]; i-=2, j+=4)
            {
                if(Chess_Board[i][j] == ' ')
                {
                    count++;
                }
            }

            if((count == ((X[0] - X[1]) / 2)) && (count == ((Y[1] - Y[0]) / 4)) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if(((count == ((X[0] - X[1]) / 2) - 1) && (count == ((Y[1] - Y[0]) / 4) - 1)) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((X[1] < X[0]) && (Y[1] < Y[0]))
        {
            int count = 0;

            for(int i=X[0]-2, j=Y[0]-4; i>=X[1], j>=Y[1]; i-=2, j-=4)
            {
                if(Chess_Board[i][j] == ' ')
                {
                    count++;
                }
            }

            if((count == ((X[0] - X[1]) / 2)) && (count == ((Y[0] - Y[1]) / 4)) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if(((count == ((X[0] - X[1]) / 2) - 1) && (count == ((Y[0] - Y[1]) / 4) - 1)) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else if(piece == 'E' || piece == 'e')
    {
        if((X[1] == X[0]) && (Y[1] > Y[0]))
        {
            int count = 0;
            for(int j=Y[0]+4; j<=Y[1]; j+=4)
            {
                if(Chess_Board[X[1]][j] == ' ')
                {
                    count++;
                }
            }

            if((count == ((Y[1] - Y[0]) / 4)) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if((count == ((Y[1] - Y[0]) / 4) - 1) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((X[1] == X[0]) && (Y[1] < Y[0]))
        {
            int count = 0;
            for(int j=Y[0]-4; j>=Y[1]; j-=4)
            {
                if(Chess_Board[X[1]][j] == ' ')
                {
                    count++;
                }
            }

            if(count == ((Y[0] - Y[1]) / 4) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if((count == ((Y[0] - Y[1]) / 4) - 1) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((Y[1] == Y[0]) && (X[1] > X[0]))
        {
            int count = 0;
            for(int i=X[0]+2; i<=X[1]; i+=2)
            {
                if(Chess_Board[i][Y[1]] == ' ')
                {
                    count++;
                }
            }

            if(count == ((X[1] - X[0]) / 2) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if((count == ((X[1] - X[0]) / 2) - 1) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((Y[1] == Y[0]) && (X[1] < X[0]))
        {
            int count = 0;
            for(int i=X[0]-2; i>=X[1]; i-=2)
            {
                if(Chess_Board[i][Y[1]] == ' ')
                {
                    count++;
                }
            }

            if(count == ((X[0] - X[1]) / 2) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if((count == ((X[0] - X[1]) / 2) - 1) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else if(piece == 'Q' || piece == 'q')
    {
        if((X[1] > X[0]) && (Y[1] > Y[0]))
        {
            int count = 0;

            for(int i=X[0]+2, j=Y[0]+4; i<=X[1], j<=Y[1]; i+=2, j+=4)
            {
                if(Chess_Board[i][j] == ' ')
                {
                    count++;
                }
            }

            if(((count == ((X[1] - X[0]) / 2)) && (count == ((Y[1] - Y[0]) / 4))) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if(((count == ((X[1] - X[0]) / 2) - 1) && (count == ((Y[1] - Y[0]) / 4) - 1)) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((X[1] > X[0]) && (Y[1] < Y[0]))
        {
            int count = 0;

            for(int i=X[0]+2, j=Y[0]-4; i<=X[1], j>=Y[1]; i+=2, j-=4)
            {
                if(Chess_Board[i][j] == ' ')
                {
                    count++;
                }
            }

            if((count == ((X[1] - X[0]) / 2)) && (count == ((Y[0] - Y[1]) / 4)) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if(((count == ((X[1] - X[0]) / 2) - 1) && (count == ((Y[0] - Y[1]) / 4) - 1)) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((X[1] < X[0]) && (Y[1] > Y[0]))
        {
            int count = 0;

            for(int i=X[0]-2, j=Y[0]+4; i>=X[1], j<=Y[1]; i-=2, j+=4)
            {
                if(Chess_Board[i][j] == ' ')
                {
                    count++;
                }
            }

            if((count == ((X[0] - X[1]) / 2)) && (count == ((Y[1] - Y[0]) / 4)) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if(((count == ((X[0] - X[1]) / 2) - 1) && (count == ((Y[1] - Y[0]) / 4) - 1)) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((X[1] < X[0]) && (Y[1] < Y[0]))
        {
            int count = 0;

            for(int i=X[0]-2, j=Y[0]-4; i>=X[1], j>=Y[1]; i-=2, j-=4)
            {
                if(Chess_Board[i][j] == ' ')
                {
                    count++;
                }
            }

            if((count == ((X[0] - X[1]) / 2)) && (count == ((Y[0] - Y[1]) / 4)) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if(((count == ((X[0] - X[1]) / 2) - 1) && (count == ((Y[0] - Y[1]) / 4) - 1)) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((X[1] == X[0]) && (Y[1] > Y[0]))
        {
            int count = 0;
            for(int j=Y[0]+4; j<=Y[1]; j+=4)
            {
                if(Chess_Board[X[1]][j] == ' ')
                {
                    count++;
                }
            }

            if((count == ((Y[1] - Y[0]) / 4)) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if((count == ((Y[1] - Y[0]) / 4) - 1) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((X[1] == X[0]) && (Y[1] < Y[0]))
        {
            int count = 0;
            for(int j=Y[0]-4; j>=Y[1]; j-=4)
            {
                if(Chess_Board[X[1]][j] == ' ')
                {
                    count++;
                }
            }

            if(count == ((Y[0] - Y[1]) / 4) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if((count == ((Y[0] - Y[1]) / 4) - 1) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((Y[1] == Y[0]) && (X[1] > X[0]))
        {
            int count = 0;
            for(int i=X[0]+2; i<=X[1]; i+=2)
            {
                if(Chess_Board[i][Y[1]] == ' ')
                {
                    count++;
                }
            }

            if(count == ((X[1] - X[0]) / 2) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if((count == ((X[1] - X[0]) / 2) - 1) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((Y[1] == Y[0]) && (X[1] < X[0]))
        {
            int count = 0;
            for(int i=X[0]-2; i>=X[1]; i-=2)
            {
                if(Chess_Board[i][Y[1]] == ' ')
                {
                    count++;
                }
            }

            if(count == ((X[0] - X[1]) / 2) && (Chess_Board[X[1]][Y[1]] == ' '))
            {
                return true;
            }
            else if((count == ((X[0] - X[1]) / 2) - 1) && (Chess_Board[X[1]][Y[1]] != ' '))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

void NewWindow()
{
    printf("\n\nPress Any Key To Continue...\n");
    getch();
    system("cls");
}

bool Check()
{
    int posx, posy;
    int i, j;

    if(player == 1)
    {   
        int count = 0;
        for(posx=3; posx<=17; posx+=2)
        {
            for(posy=6; posy<=34; posy+=4)
            {
                if(Chess_Board[posx][posy] == 'K')
                {
                    i = posx;
                    j = posy;
                    break;
                }
                else
                {
                    count++;
                }
            }
        }

        if(count == 64)
        {
            printf("\n%s looses King..!\n%s is Winner..!", name1, name2);
        }

        int count_c = 0;

        for(int a=2, b=4; a<=14, b<=28; a+=2, b+=4)
        {
            if(
                (Chess_Board[i + a][j + b] == 'c' && Check_Path('c', i+a, j+b, i, j) == true) ||
                (Chess_Board[i - a][j + b] == 'c' && Check_Path('c', i-a, j+b, i, j) == true) ||
                (Chess_Board[i + a][j - b] == 'c' && Check_Path('c', i+a, j-b, i, j) == true) ||
                (Chess_Board[i - a][j - b] == 'c' && Check_Path('c', i-a, j-b, i, j) == true)
            )
            {
                count_c++;
            }
        }

        int count_e = 0;

        for(int a=2, b=4; a<=14, b<=28; a+=2, b+=4)
        {
            if(
                (Chess_Board[i][j + b] == 'e' && Check_Path('e', i, j+b, i, j) == true) ||
                (Chess_Board[i][j - b] == 'e' && Check_Path('e', i, j-b, i, j) == true) ||
                (Chess_Board[i + a][j] == 'e' && Check_Path('e', i+a, j, i, j) == true) ||
                (Chess_Board[i - a][j] == 'e' && Check_Path('e', i-a, j, i, j) == true)
            )
            {
                count_e++;
            }
        }

        int count_q = 0;

        for(int a=2, b=4; a<=14, b<=28;  a+=2, b+=4)
        {
            if(
                (Chess_Board[i + a][j + b] == 'q' && Check_Path('q', i+a, j+b, i, j) == true) ||
                (Chess_Board[i - a][j + b] == 'q' && Check_Path('q', i-a, j+b, i, j) == true) ||
                (Chess_Board[i + a][j - b] == 'q' && Check_Path('q', i+a, j-b, i, j) == true) ||
                (Chess_Board[i - a][j - b] == 'q' && Check_Path('q', i-a, j-b, i, j) == true) ||
                (Chess_Board[i][j + b] == 'q' && Check_Path('q', i, j+b, i, j) == true) ||
                (Chess_Board[i][j - b] == 'q' && Check_Path('q', i, j-b, i, j) == true) ||
                (Chess_Board[i + a][j] == 'q' && Check_Path('q', i+a, j, i, j) == true) ||
                (Chess_Board[i - a][j] == 'q' && Check_Path('q', i-a, j, i, j) == true)
            )
            {
                count_q++;
            }
        }

        if(
            (Chess_Board[i + 2][j + 8] == 'h' || Chess_Board[i - 2][j + 8] == 'h' || 
            Chess_Board[i + 2][j - 8] == 'h' || Chess_Board[i - 2][j - 8] == 'h' ||
            Chess_Board[i + 4][j + 4] == 'h' || Chess_Board[i - 4][j + 4] == 'h' || 
            Chess_Board[i + 4][j - 4] == 'h' || Chess_Board[i - 4][j - 4] == 'h') ||

            (count_c > 0) ||

            (count_e > 0) ||

            ((Chess_Board[i + 2][j + 4] == 'y' && Check_Path('y', i+2, j+4, i, j) == true) || 
            (Chess_Board[i + 2][j - 4] == 'y' && Check_Path('y', i+2, j-4, i, j) == true)) ||

            (count_q > 0)
        )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(player == 2)
    {   
        int count =0;

        for(posx=17; posx>=3; posx-=2)
        {
            for(posy=34; posy>=6; posy-=4)
            {
                if(Chess_Board[posx][posy] == 'k')
                {
                    i = posx;
                    j = posy;
                    break;
                }
                else
                {
                    count++;
                }
            }
        }

        if(count == 64)
        {
            printf("\n%s looses King..!\n%s is Winner..!", name2, name1);
        }

        int count_C = 0;

        for(int a=2, b=4; a<=14, b<=28; a+=2, b+=4)
        {
            if(
                (Chess_Board[i + a][j + b] == 'C' && Check_Path('C', i+a, j+b, i, j) == true) ||
                (Chess_Board[i - a][j + b] == 'C' && Check_Path('C', i-a, j+b, i, j) == true) ||
                (Chess_Board[i + a][j - b] == 'C' && Check_Path('C', i+a, j-b, i, j) == true) ||
                (Chess_Board[i - a][j - b] == 'C' && Check_Path('C', i-a, j-b, i, j) == true)
            )
            {
                count_C++;
            }
        }

        int count_E = 0;

        for(int a=2, b=4; a<=14, b<=28; a+=2, b+=4)
        {
            if(
                (Chess_Board[i][j + b] == 'E' && Check_Path('E', i, j+b, i, j) == true) ||
                (Chess_Board[i][j - b] == 'E' && Check_Path('E', i, j-b, i, j) == true) ||
                (Chess_Board[i + a][j] == 'E' && Check_Path('E', i+a, j, i, j) == true) ||
                (Chess_Board[i - a][j] == 'E' && Check_Path('E', i-a, j, i, j) == true)
            )
            {
                count_E++;
            }
        }

        int count_Q = 0;

        for(int a=2, b=4; a<=14, b<=28;  a+=2, b+=4)
        {
            if(
                (Chess_Board[i + a][j + b] == 'Q' && Check_Path('Q', i+a, j+b, i, j) == true) ||
                (Chess_Board[i - a][j + b] == 'Q' && Check_Path('Q', i-a, j+b, i, j) == true) ||
                (Chess_Board[i + a][j - b] == 'Q' && Check_Path('Q', i+a, j-b, i, j) == true) ||
                (Chess_Board[i - a][j - b] == 'Q' && Check_Path('Q', i-a, j-b, i, j) == true) ||
                (Chess_Board[i][j + b] == 'Q' && Check_Path('Q', i, j+b, i, j) == true) ||
                (Chess_Board[i][j - b] == 'Q' && Check_Path('Q', i, j-b, i, j) == true) ||
                (Chess_Board[i + a][j] == 'Q' && Check_Path('Q', i+a, j, i, j) == true) ||
                (Chess_Board[i - a][j] == 'Q' && Check_Path('Q', i-a, j, i, j) == true)
            )
            {
                count_Q++;
            }
        }

        if(
            (Chess_Board[i + 2][j + 8] == 'H' || Chess_Board[i - 2][j + 8] == 'H' || 
            Chess_Board[i + 2][j - 8] == 'H' || Chess_Board[i - 2][j - 8] == 'H' ||
            Chess_Board[i + 4][j + 4] == 'H' || Chess_Board[i - 4][j + 4] == 'H' || 
            Chess_Board[i + 4][j - 4] == 'H' || Chess_Board[i - 4][j - 4] == 'H') ||

            (count_C > 0) ||

            (count_E > 0) ||

            ((Chess_Board[i + 2][j + 4] == 'X' && Check_Path('X', i+2, j+4, i, j) == true) || 
            (Chess_Board[i + 2][j - 4] == 'X' && Check_Path('X', i+2, j-4, i, j) == true)) ||

            (count_Q > 0)
        )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Check_Path(char piece, int x, int y, int a, int b)
{
    int X[2];
    int Y[2];

    X[0] = x;
    Y[0] = y;
    X[1] = a;
    Y[1] = b;

    if(Valid_Path(piece, X, Y) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Check_Mate(int X[], int Y[])
{
    if(player == 1)
    {
        if(Check() == true && (Valid_Move('K', X, Y) == false || Valid_Path('K', X, Y) == false))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(player == 2)
    {
        if(Check() == true && (Valid_Move('k', X, Y) == false || Valid_Path('k', X, Y) == false))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}