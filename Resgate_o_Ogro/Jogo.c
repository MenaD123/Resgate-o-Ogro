#include <stdio.h>
#include <conio2.h>
#include <math.h>

#define LARGURA 80
#define ALTURA 24
#define PAREDETORRE 14
#define TETOTORRE 79
#define CHAOTORRE 79
#define POSIOGRO 79
#define OGRO 12

int main()
{
    system("MODE con cols=80 lines=26");
    int posinicial_x=5, posinicial_y=5;
    int guarda_x=2, guarda_y=2;
    int ogro_x=79, ogro_y=79;
    int jogador_x=30, jogador_y=10;
    int vidas=3;
    int tecla;

    desenhacenario();

    do
    {
        tecla=getch();
        if(tecla==-32)
            tecla=getch();

        testa_guarda(guarda_x, guarda_y, &jogador_x, &jogador_y, &vidas, posinicial_x, posinicial_y);

        gotoxy(1, ALTURA+1);
        printf("Vidas: %i", vidas);

        movimento(tecla, &jogador_x, &jogador_y);

    }
    while(tecla!=27 && vidas>0);


    return 0;
}

void movimento(int tecla, int *x, int *y)
{
    char spc=' ', p='M';

    textbackground(BLACK);

    putchxy(*x, *y, spc);

    textbackground(RED);

    switch(tecla)
    {
        case 72: if(*y>2 )  //CIMA
                    *y-=1;
        break;
        case 80: if(*y<ALTURA-1)  //BAIXO
                    *y+=1;
        break;
        case 75: if(*x>=3)  // ESQUERDA
                    *x-=1;
        break;
        case 77: if(*x<LARGURA-1)  // DIREITA
                    *x+=1;
        break;
    }
        putchxy(*x,*y,p);
        gotoxy(1,1);

    textbackground(BLACK);
}


void testa_guarda(int guarda_x, int guarda_y, int *jogador_x, int *jogador_y, int *vidas, int posinicial_x, int posinicial_y)
{
    char spc=' ', g='G';
    if(sqrt(pow((guarda_x-*jogador_x),2)+pow((guarda_y-*jogador_y) ,2))<2)
    {
        putchxy(*jogador_x,*jogador_y, spc );
       *vidas-=1;
       *jogador_x=posinicial_x;
       *jogador_y=posinicial_y;
       textbackground(RED);
    }
}







void desenhacenario()
{
    int i;
    char green=' ';
    char parede = ' ';
    char ogro_x=79, ogro_y=79;
    char spc=' ', p='O';

    textbackground(GREEN);

    for(i=1; i<LARGURA; i++)
    {

        putchxy(i,1,green);
        putchxy(i,ALTURA, green);

    }

    for(i=1; i<=ALTURA; i++)
    {

        putchxy(1,i,green);
        putchxy(LARGURA,i, green);

    }

    textbackground(BLACK);

    for(i=10;i<=PAREDETORRE;i++){
        textbackground(WHITE);
        putchxy(74,i,parede);
    }
    for(i=74;i<=TETOTORRE;i++)
        {
        textbackground(WHITE);
        putchxy(i,10,parede);
        }
         for(i=74;i<=CHAOTORRE;i++)
        {
        textbackground(WHITE);
        putchxy(i,15,parede);
        }


        for(i=78;i<POSIOGRO;i++)
        {
        textbackground(BLUE);
        putchxy(i,OGRO, p);
        }
}

