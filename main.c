#include<stdio.h>
#include<stdbool.h>



 /////////////           FONCTIONS           ////////////////



void draw(char l[9]){

    printf("\n\n");
    for(int i= 0; i < 6;i = i+3){
        printf("\t\t|\t\t|\t\t\n");
        printf("\t%c\t|\t%c\t|\t%c\t\n",l[i],l[i+1],l[i+2]);
        printf("_____|_____|_____\n");
    }
        printf("\t\t|\t\t|\t\t\n");
        printf("\t%c\t|\t%c\t|\t%c\t\n",l[6],l[7],l[8]);
        printf("\t\t|\t\t|\t\t\n");
        printf("\n\n");
}

void play(char l[9],int position,int player)
{
    char symb ='O';
    if(player == 1){ symb = 'X';}    //player == 1 -> player 1   'X'
                                     //player == 2  -> player 2  'O'
    l[position - 1] = symb;
}

bool win(char l[9],int player)
{

    char symb = 'O';
    if (player == 1) symb = 'X';

    // HORIZANTAL MATCH

        for(int i = 0; i <= 6 ;i++)
        {
            if(l[i] == symb && l[i+1] == symb)
            {
                if( l[i+2] == symb) return true;
            }
            i = i + 3;
        }


    // VERTICAL MATCH

        for(int i = 0; i <= 2 ; i++)
        {
            if((l[i] == symb) && (l[i+3] == symb))
            {
                if( l[i+6] == symb) return true;
            }
        }

    // DIAGONAL MATCH

       if(l[0] == symb && l[4] == symb )
       {
           if( l[8] == symb) return true;
       }

    // ANTI-DIAGONAL MATCH

        if(l[2] == symb && l[4] == symb)
        {
            if( l[6] == symb) return true;
        }

    // NO MATCH
    return false;

}

bool replay()
{
    int r;
    printf("\nREPLAY ? 1/0 :");
    scanf("%d",&r);
    if ( (r == 1)) {
        printf("%d",r);
        return true;
        }
    else
    {
        printf("\nSEE YOU SOON !!");
        return false;
    }

}

//////////////////////  L'APPEL DES FONCTIONS    ////////////////////////////////////////

void draw(char l[9]);                                // THIS FUNCTION DRAW THE GRID WITH THE POSITION NUMBERS
void play(char l[9],int position,int player);        // THIS FUNCTION PUT 'X' OR 'O' IN THE CHOSEN POSTION
bool win(char l[9],int player);                         // THIS FUNCTION DETERMIN IF A PLAYER HAS PLACED HIS SYMBOLE IN A ROW
bool replay();                                             // THIS FUNCTION ASK FOR ANOTHER GAME


//////////////////////  MAIN    ////////////////////////////////////////



int main()
{

    bool game_on;
    bool rematch = true;
    int cpt;
    int position;
    int player = 1;

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\t\tAUTHOR : OTHMANE TOZY				\n");
    printf("\t\tGROUPE 3 ~Etudiant  Ingenieurie Genie logiciel @EMSI \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");

    printf("\t\t   TIC - TAC - TOE     \n");
    printf("******************************\n");
    printf("\t\tPlayer 1 (X) - Player 2 (O)\n");

    while (rematch)
    {
                 //INITIALISER
        game_on = true;
        rematch = false;
        cpt = 0;
        // DRAWING THE GRID WITH AVAILABLE POSITIONS

        char l[9]={'1','2','3','4','5','6','7','8','9'};
        draw(l);

        while(game_on){

        // GIVE THE CHOICE

        printf("player %d -- make your choice : ",player);
        scanf("%d",&position);
        if((position > 9) || (position < 1))
        {
            printf("NON VALID INPUT !!\n");
            printf("player %d -- make your choice : ",player);
            scanf("%d",&position);
        }
        play(l,position,player);
        draw(l);

        if (win(l,player))
        {
            game_on = false;
            printf("player %d win !!!!",player);
            rematch = replay();
        }
        else
        {
            if(player == 1) player = 2;
            else    player = 1;

            cpt++;

            // END THE GAME WHEN ALL THE POSITIONS ARE PLAYED
            if (cpt == 9)
            {
                game_on = false;
                printf("DRAW GAME !!");
                rematch = replay();
            }
        }

   }
}
}
