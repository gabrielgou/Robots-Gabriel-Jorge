/*Progama: Robots.c(ex27);
Funcao: Rodar o jogo Robots;
Autores: Jorge Edson Ribeiro da Silva Neto & Joao Gabriel Gouveia de Souza Brito;
Contatos: jorge.ed.ribeiro00@gmail.com & gabriel.gouveia@live.com;*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//===============Defines========================
#define MAXLINS 16
#define MAXCOLS 16

//===============variaveis globais===============
char joy;
char map[MAXLINS][MAXCOLS];
int sair=0, o=0;
struct gamer{
        int x, y;
};
struct gamer player;




void move()//in Progress*
{
    fflush(stdin);
    scanf("%s", &joy);

    switch(joy)
    {
        case 'q'://Cima e esquerda (Diagonal)
        {
            player.x--;
            player.y--;
            break;
        }
        case 'w'://Cima
        {
            player.x--;
            break;
        }
        case 'e'://Cima e direita (Diagonal)
        {
            player.x--;
            player.y++;
            break;
        }
        case 'a'://esquerda
        {
            player.y--;
            break;
        }
        case 'd'://direita
        {
            player.y++;
            break;
        }
        case 'z'://Baixo e Esquerda (diagonal)
        {
            player.x++;
            player.y--;
            break;
        }
        case 'x'://Baixo
        {
            player.x++;
            break;
        }
        case 'c'://Baixo e Direita (Diagonal)
        {
            player.x++;
            player.y++;
            break;
        }
        case 't'://teleporte seguro se possivel
        {
            player.x=rand()%MAXLINS;
            player.y=rand()%MAXCOLS;
            break;
        }
        /*if(joy=='g')//teleporte em segurança
        {

        }
        if(joy=='b')//teleporte para qualquer lugar
        {

        }*/
        default:
        {
            printf("\nComando Invalido\n");
        }
    }
        if(player.x<0)
            player.x=0;
        if(player.x>15)
            player.x=15;
        if(player.y<0)
            player.y=0;
        if(player.y>15)
            player.y=15;
        
    }

    void print_map() //In progress*
    {
        int i,j;
        for(i=0;i<MAXLINS;i++)
        {
            for(j=0;j<MAXCOLS;j++)
            {
                
                if(i==player.x && j==player.y)
                {
                    if(o==0)
                    {
                        map[i][j]='O';
                        o=1;
                    }
                    else
                    {
                        map[i][j]='o';
                        o=0;
                    }
                           
                }
                /*else if(i==robots.x && j==robots.y)
                {
                    map[i][j]='r';
                }
                else if(i==fast_robots.x && j==fast_robots.y)
                {
                    map[i][j]='R';
                }*/
                else
                    map[i][j]='.';
                    
            }
            
        }
        system("clear");
        for(i=0;i<MAXLINS;i++)
        {
            printf("\t\t\t\t\t");
            for(j=0;j<MAXCOLS;j++)
            {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }
        printf("\nJoystick:\n\t\tq w e\n\t\ta . d\n\t\tz x c\n");
        printf("\nt->teletransporte\n");
        printf("Comando: ");

        
    }

    int main()
    {   
        srand(time(NULL));
       // struct gamer robots[value_r];//registro do robo lento
       // struct gamer fast_robots[value_fr];//registro do robo rapido

        player.x=rand()%MAXLINS;
        player.y=rand()%MAXCOLS; //inicializa o player numa posição qualquer

        do //loop onde vai rodar o programa principal*
        {
            print_map();
            move();
        }while(sair!=1);
    }

