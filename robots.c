/*Progama: Robots.c(ex27);
Funcao: Rodar o jogo Robots;
Autores: Jorge Edson Ribeiro da Silva Neto & Joao Gabriel Gouveia de Souza Brito;
Contatos: jorge.ed.ribeiro00@gmail.com & gabriel.gouveia@live.com;*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


/*===============Defines========================*/
#define MAXLINS 16
#define MAXCOLS 16

/*===============variaveis globais===============*/
char joy;
char map[MAXLINS][MAXCOLS];
int loose=0, o=0, energy=1, quit=0, value_r=1, n, win=0, temp_life, lvl=1, enable_mv=0, score=0;
struct gamer{
    int x, y;
    int alive;

};
struct gamer player;
struct gamer robot_slow[100];
struct gamer robot_fast[100];


void help()/*Manual do jogo*/
{
    printf("\n\nEste eh o jogo Robots, seu objetivo eh simples, destrua todos os robos.\nPara isso voce deve se movimentar pelo campo com sua inteligencia, a cada movimento todos os robos irao se mover uma casa na sua direcao, sobreviva e passe de nivel, boa sorte.\n\n");
    printf("Comandos:\n\n*Movimentacao*\nw: cima;\nx: baixo;\nd: direita;\na: esquerda;\ne: diagonal direita acima;\nq: diagonal esquerda acima;\nc: diagonal direita abaixo;\nz: diagonal esquerda abaixo;\ns: comando neutro, nao se mover;\n\n");
    printf("t: teleporte aleatorio, sera sorteado a posicao em que voce reaparecera (numero ilimitado de utilizacoes);\ng: teletransporte seguro, voce tem a opcao de escolher a posicao onde ira reaparecer, apenas confirme e siga as instrucoes (apenas um uso por energia, escolha com sabedoria);\nv: vaporizacao, uma explosao que destroi todos os robos nas casas adjacentes (apenas um uso por energia, nao desperdice, sua vida depende disso.\nctrl+c: comando de saida\n\n");
    printf("Regras:\n1o: So se pode mover uma casa por vez e a cada movimentos todos os robos irao na sua direcao;\n2o: A unica forma de se matar um robo eh fazendo ele se chocar contra outro robo ou contra o lixo e, em ultimo caso, utilizando a vaporizacao;\n3o: Existem dois tipos de robos, os que andam apenas uma casa na sua direcao a cada jogada e aqueles que andam duas, esses sao os robos rapidos, os mais perigosos;\n4o: Sempre que um robo eh destruido forma-se lixo ali, nem voce nem os outros robos podem mover o lixo ou subir nele (caso tente o movimento sera invalido, a jogada sera dada como feita, os robos irao na sua direcao e voce continuara no mesmo local);\n5o: Ha apenas uma energia em cada nivel e essa energia carrega a vaporizacao ou o transporte seguro. Essa energia nao pode ser acumulada de um nivel para o outro, ou seja, em todos os niveis voce tera que escolher se ussa ou nao um dos dois (isso, claro, se voce sobreviver ate la)\n.");
}


void move()/*in Progress*/
{
    joy='\0';
    scanf("%s", &joy);

    switch(joy)
    {
        case 'q':/*Cima e esquerda (Diagonal)*/
            {
                if(map[(player.x-1)][(player.y-1)]!='@' && map[(player.x-1)][(player.y-1)]!='+')
                {
                    player.x--;
                    player.y--;
                    enable_mv=1;
                }
                else
                {
                    printf("\nComando invalido\n");
                    __fpurge(stdin);
                    getchar();
                }

                break;
            }
        case 'w':/*Cima*/
            {
                if(map[(player.x-1)][(player.y)]!='@' && map[(player.x-1)][(player.y)]!='+')
                {
                    player.x--;
                    enable_mv=1;
                }
                else
                {
                    printf("\nComando invalido\n");
                    __fpurge(stdin);
                    getchar();
                }
                break;
            }
        case 'e':/*Cima e direita (Diagonal)*/
            {
                if(map[(player.x-1)][(player.y+1)]!='@' && map[(player.x-1)][(player.y+1)]!='+')
                {
                    player.x--;
                    player.y++;
                    enable_mv=1;
                }
                else
                {
                    printf("\nComando invalido\n");
                    __fpurge(stdin);
                    getchar();
                }
                break;
            }
        case 'a':/*esquerda*/
            {
                if(map[(player.x)][(player.y-1)]!='@' && map[(player.x)][(player.y-1)]!='+')
                {
                    player.y--;
                    enable_mv=1;
                }
                else
                {
                    printf("\nComando invalido\n");
                    __fpurge(stdin);
                    getchar();

                }
                break;
            }
        case 'd':/*direita*/
            {
                if(map[(player.x)][(player.y+1)]!='@' && map[(player.x)][(player.y+1)]!='+' )
                {
                    player.y++;
                    enable_mv=1;
                }
                else
                {
                    printf("\nComando invalido\n");
                    __fpurge(stdin);
                    getchar();
                }
                break;
            }
        case 'z':/*Baixo e Esquerda (diagonal)*/
            {
                if(map[(player.x+1)][(player.y-1)]!='@' &&  map[(player.x+1)][(player.y-1)]!='+')
                {
                    player.x++;
                    player.y--;
                    enable_mv=1;
                }
                else
                {
                    printf("\nComando invalido\n");
                    __fpurge(stdin);
                    getchar();
                }
                break;
            }
        case 'x':/*Baixo*/
            {
                if(map[(player.x+1)][(player.y)]!='@' && map[(player.x+1)][(player.y)]!='+')
                {
                    player.x++;
                    enable_mv=1;
                }
                else
                {
                    printf("\nComando invalido\n");
                    __fpurge(stdin);
                    getchar();
                }
                break;
            }
        case 'c':/*Baixo e Direita (Diagonal)*/
            {   
                if(map[(player.x+1)][(player.y+1)]!='@' && map[(player.x+1)][(player.y+1)]!='+')
                {
                    player.x++;
                    player.y++;
                    enable_mv=1;
                }
                else
                {
                    printf("\nComando invalido\n");
                    __fpurge(stdin);
                    getchar();
                }
                break;
            }
        case 't':/*teleporte aleatorio*/
            {
                player.x=rand()%MAXLINS;
                player.y=rand()%MAXCOLS;
                enable_mv=1;
                break;
            }
        case 's':
            {
                printf("\nFicou parado\n");
                enable_mv=1;
                __fpurge(stdin);
                getchar();
                break;
            }
        /*case 'g':/*teleporte em segurança*/
           /* {
                if(energy>0)
                {
                    energy=0;
                    printf("\nEscolha uma linha: ");
                    scanf("%d", &player.x);
                    printf("Escolha uma coluna: ");
                    scanf("%d", &player.y);
                    player.x--;
                    player.y--;
                    enable_mv=1;
                }
                else
                    printf("\nVoce nao possui energia\n");
                __fpurge(stdin);
                getchar();
                break;
            }*/
        case 'h':/*manual do jogo*/
            {
                help();
                __fpurge(stdin);
                getchar();
                break;
            }
        default:
            {
                printf("\nComando Invalido\n");
                __fpurge(stdin);
                getchar();
                break;
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

void print_map(int eni) /*In progress*/
{
    //system("clear");
    printf("\e[H\e[2J");
    int i,j;
    for(i=0;i<MAXLINS;i++)
    {
        for(j=0;j<MAXCOLS;j++)
        {


            for(n=0;n<(eni/2);n++)
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
                    break;                
                }
                else  if(i==robot_slow[n].x && j==robot_slow[n].y && robot_slow[n].alive==1)
                {
                    map[i][j]='+';
                    break; 
                }
                else if(i==robot_fast[n].x  && j==robot_fast[n].y && robot_fast[n].alive==1)
                {
                    map[i][j]='@';
                    break;
                }
                else if(i==robot_slow[n].x && j==robot_slow[n].y && robot_slow[n].alive==0)
                {
                    map[i][j]='*';
                    break;
                }
                /*else if(i==robot_fast[n].x && j==robot_fast[n].y && robot_fast[n].alive==0)
                {
                    map[i][j]='*';
                    break;
                }*/
                else if(player.x==robot_slow[n].x && player.y==robot_slow[n].y && robot_slow[n].alive==1)
                    map[i][j]='X';
                else if(player.x==robot_fast[n].x && player.y==robot_fast[n].y && robot_fast[n].alive==1)
                    map[i][j]='X';
                else
                    map[i][j]=' ';

            }



        }
    }
    /*system("clear");*/
    printf("\t\t\t\t\t");
    for(i=0;i<(2*MAXCOLS+2);i++)
    {
        printf("-");
    }
    printf("\n");
    for(i=0;i<MAXLINS;i++)
    {
        printf("\t\t\t\t\t");
        printf("|");
        for(j=0;j<MAXCOLS;j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("\t\t\t\t\t");
    for(i=0;i<(2*MAXCOLS+2);i++)
    {
        printf("-");
    }

    
    printf("\n\n");
    printf("\nJoystick:\t\t\t\tLevel: %d\t\t\tScore: %d\n\t\tq w e\n\t\ta . d\n\t\tz x c\n", lvl, score);
    printf("\ns->ficar parado");
    printf("\nt->teletransporte aleatorio\n");
    //printf("g->teletransporte seguro\n");
    //printf("h->ajuda\n");
    printf("Comando: ");
}

void move_enemies(int mv_eni)
{
    int a;
    if(enable_mv==1)
    {
        enable_mv=0;
        for(a=0;a<(mv_eni/2);a++)
        {
            if(robot_slow[a].alive==1)
            {
                if(player.x>robot_slow[a].x)
                    robot_slow[a].x++;
                else if(player.x<robot_slow[a].x)
                    robot_slow[a].x--;

                if(player.y>robot_slow[a].y)
                    robot_slow[a].y++;
                else if(player.y<robot_slow[a].y)
                    robot_slow[a].y--;
            }
            int b;
            /*for(b=0;b<2;b++)
            {
               *if(robot_fast[a].alive==1)
                  {
                    if(player.x>robot_fast[a].x)
                        robot_fast[a].x++;
                    else if(player.x<robot_fast[a].x)
                        robot_fast[a].x--;

                    if(player.y>robot_fast[a].y)
                        robot_fast[a].y++;
                    else if(player.y<robot_fast[a].y)
                        robot_fast[a].y--;
                    int teste;
                    for(teste=0;teste<mv_eni/2;teste++)
                    {
                        if(robot_slow[b].x==robot_slow[teste].x && robot_slow[b].y==robot_slow[teste].y && b!=teste)
                        {
                            robot_slow[b].alive=0;
                            robot_slow[teste].alive=0;

                        }
                        if(robot_slow[b].x==robot_fast[teste].x && robot_slow[b].y==robot_fast[teste].y)
                        {
                            robot_slow[b].alive=0;
                            //robot_fast[teste].alive=0;

                        }
                       if(robot_fast[b].x==robot_fast[teste].x && robot_fast[b].y==robot_fast[teste].y && b!=teste)
                        {
                            robot_fast[b].alive=0;
                            robot_fast[teste].alive=0;

                        }
                    }



                }
            }*/
        }
    }


}

int main()
{   
    srand(time(NULL));
    int temp_score=0, first_kill=1;


   // energy=0;
    /* struct gamer fast_robots[value_fr];//registro do robo rapido*/
    player.x=rand()%MAXLINS;
    player.y=rand()%MAXCOLS; /*inicializa o player numa posição qualquer*/
    int q=0;
    do
    {
        if(loose==1)
        {
            q=0;
            loose=0;
        }
        q+=2;
        //energy++;
        int f;
        win=q;
        for(f=0;f<q/2;f++)
        {

            robot_slow[f].x=rand()%MAXLINS;
            robot_slow[f].y=rand()%MAXCOLS;
            robot_slow[f].alive=1;
            robot_fast[0].x=rand()%MAXLINS;
            robot_fast[0].y=rand()%MAXCOLS;
            robot_fast[0].alive=1;
        }
        do /*loop onde vai rodar o programa principal*/
        {   
            temp_life=0;
            print_map(q);
            move();
            move_enemies(q);

            for(f=0;f<(q/2);f++)
            {
                if(robot_slow[f].x==player.x && robot_slow[f].y==player.y && robot_slow[f].alive==1)
                    loose=1;
                if(robot_fast[f].x==player.x && robot_fast[f].y==player.y && robot_fast[f].alive==1)
                    loose=1;

                int teste;    
                for(teste=0;teste<q/2;teste++)
                {
                    if(robot_slow[f].x==robot_slow[teste].x && robot_slow[f].y==robot_slow[teste].y && f!=teste)
                    {
                        robot_slow[f].alive=0;
                        robot_slow[teste].alive=0;

                    }
                    if(robot_slow[f].x==robot_fast[teste].x && robot_slow[f].y==robot_fast[teste].y)
                    {
                        robot_slow[f].alive=0;
                        robot_fast[teste].alive=0;

                    }
                    if(robot_fast[f].x==robot_fast[teste].x && robot_fast[f].y==robot_fast[teste].y && f!=teste)
                    {
                        robot_fast[f].alive=0;
                        robot_fast[teste].alive=0;

                    }

                }
                temp_life+=robot_slow[f].alive;

            }

            if(temp_life!=temp_score && temp_score!=0)
                if(first_kill==1)
                {
                    score+=2;
                    first_kill=0;
                }
                else
                    score++;
            temp_score=temp_life;


        }while(temp_life!=0 && loose!=1 && lvl<6);
        print_map(q);
        if(loose==1)
        {
            printf("\nVocê perdeu\n");
            lvl=1;
            score=0;
            printf("\nDeseja continuar? 0-Sim e 1-Nao   ");
            scanf("%d", &quit);
        }
        else
        {
            printf("\nPassou de level!\n");
            lvl++;
            first_kill=1;
        }
        if(lvl==6)
        {
            printf("\n O jogo terminou, voce passou do ultimo lvl, parabens!\n");
        }
        __fpurge(stdin);
        getchar();
    }while(quit!=1 && lvl<6);
}

