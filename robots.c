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
struct gamer{
        int x, y;
};
struct gamer player;
        



void move()//in Progress*
{
    fflush(stdin);
    scanf("%s", %joy);
    if(joy=='1')//Cima e esquerda (Diagonal)
    {
        
    }
    if(joy=='2')//Cima
    {

    }
    if(joy=='3')//Cima e direita (Diagonal)
    {

    }
    if(joy=='4')//esquerda
    {

    }
    /*if(joy=='5')//nada
    {

    }*/
    if(joy=='6')//direita
    {

    }
    if(joy=='7')//Baixo e Esquerda (diagonal)
    {
        
    }
    if(joy=='8')//Baixo
    {

    }
    if(joy=='9')//Baixo e Direita (Diagonal)
    {

    }
    if(joy==' ')//teleporte seguro se possivel
    {

    }
    if(joy=='+')//teleporte em segurança
    {

    }
    if(joy=='-')//teleporte para qualquer lugar
    {

    }
}

void enimies() //In progress*
{

}

int main()
{   
    srand(time(NULL));
    struct gamer robots[value_r];//registro do robo lento
    struct gamer fast_robots[value_fr];//registro do robo rapido

    player.x=rand()%MAXLINS;
    player.y=rand()%MAXCOLS; //inicializa o player numa posição qualquer

    do //loop onde vai rodar o programa principal*
    {

    }while(sair!=1);
}

