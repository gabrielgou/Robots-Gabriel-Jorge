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
int loose=0, o=0, energy=1, quit=0;
struct gamer{
        int x, y;
};
struct gamer player;


void help()/*Manual do jogo*/
{
    printf("\n\nEste eh o jogo Robots, seu objetivo eh simples, destrua todos os robos.\nPara isso voce deve se movimentar pelo campo com sua inteligencia, a cada movimento todos os robos irao se mover uma casa na sua direcao, sobreviva e passe de nivel, boa sorte.\n\n");
    printf("Comandos:\n\n*Movimentacao*\nw: cima;\nx: baixo;\nd: direita;\na: esquerda;\ne: diagonal direita acima;\nq: diagonal esquerda acima;\nc: diagonal direita abaixo;\nz: diagonal esquerda abaixo;\ns: comando neutro, nao se mover;\n\n");
    printf("t: teleporte aleatorio, sera sorteado a posicao em que voce reaparecera (numero ilimitado de utilizacoes);\ng: teletransporte seguro, voce tem a opcao de escolher a posicao onde ira reaparecer, apenas confirme e siga as instrucoes (apenas um uso por energia, escolha com sabedoria);\nv: vaporizacao, uma explosao que destroi todos os robos nas casas adjacentes (apenas um uso por energia, nao desperdice, sua vida depende disso.\n\n");
    printf("*Regras:\n1o: So se pode mover uma casa por vez e a cada movimentos todos os robos irao na sua direcao;\n2o: A unica forma de se matar um robo eh fazendo ele se chocar contra outro robo ou contra o lixo e, em ultimo caso, utilizando a vaporizacao;\n3o: Sempre que um robo eh destruido forma-se lixo ali, nem voce nem os outros robos podem mover o lixo ou subir nele (caso tente o movimento sera invalido, a jogada sera dada como feita, os robos irao na sua direcao e voce continuara no mesmo local);\n4o: Ha apenas uma energia em cada nivel e essa energia carrega a vaporizacao ou o transporte seguro. Essa energia nao pode ser acumulada de um nivel para o outro, ou seja, em todos os niveis voce tera que escolher se ussa ou nao um dos dois (isso, claro, se voce sobreviver ate la)\n.");
}


void move()/*in Progress*/
{
    joy='\0';
    scanf("%s", &joy);
    
    switch(joy)
    {
        case 'q':/*Cima e esquerda (Diagonal)*/
        {
            player.x--;
            player.y--;
            break;
        }
        case 'w':/*Cima*/
        {
            player.x--;
            break;
        }
        case 'e':/*Cima e direita (Diagonal)*/
        {
            player.x--;
            player.y++;
            break;
        }
        case 'a':/*esquerda*/
        {
            player.y--;
            break;
        }
        case 'd':/*direita*/
        {
            player.y++;
            break;
        }
        case 'z':/*Baixo e Esquerda (diagonal)*/
        {
            player.x++;
            player.y--;
            break;
        }
        case 'x':/*Baixo*/
        {
            player.x++;
            break;
        }
        case 'c':/*Baixo e Direita (Diagonal)*/
        {
            player.x++;
            player.y++;
            break;
        }
        case 't':/*teleporte aleatorio*/
        {
            player.x=rand()%MAXLINS;
            player.y=rand()%MAXCOLS;
            break;
        }
        case 's':
        {
            printf("\nFicou parado\n");
            __fpurge(stdin);
            getchar();
            break;
        }
        case 'g':/*teleporte em segurança*/
        {
            if(energy==1)
            {
                energy=0;
                printf("\nEscolha uma linha: ");
                scanf("%d", &player.x);
                printf("Escolha uma coluna: ");
                scanf("%d", &player.y);
                player.x--;
                player.y--;
            }
           
        }
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

    void print_map() /*In progress*/
    {
        system("clear");
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
        /*system("clear");*/
        for(i=0;i<MAXLINS;i++)
        {
            printf("\t\t\t\t\t");
            for(j=0;j<MAXCOLS;j++)
            {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }
        printf("\nJoystick:\t\t\tEnergia: %d\n\t\tq w e\n\t\ta . d\n\t\tz x c\n", energy);
        printf("\ns->ficar parado");
        printf("\nt->teletransporte aleatorio\n");
        printf("g->teletransporte seguro\n");
        printf("h->ajuda\n");
        printf("Comando: ");

        
    }

    int main()
    {   
        srand(time(NULL));
       /* struct gamer robots[value_r];//registro do robo lento*/
       /* struct gamer fast_robots[value_fr];//registro do robo rapido*/

        player.x=rand()%MAXLINS;
        player.y=rand()%MAXCOLS; /*inicializa o player numa posição qualquer*/
        do
        {
            energy=1;
            do /*loop onde vai rodar o programa principal*/
            {
                print_map();
                move();
            }while(loose!=1);
        }while(quit!=1);
    }

