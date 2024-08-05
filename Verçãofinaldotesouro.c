#include<stdio.h>   //biblioteca_001 (responsavel pela leitura e exibição de dados);
#include<stdlib.h>  //biblioteca_002 (responsavel pela  manipulação de memória e geração de números aleatórios);
#include<string.h>  //biblioteca_003 (responsavel por conter uma cadeia de characteres contidos no char);
#include<locale.h>  //biblioteca_004 (responsavel pela configuração da linguagem para o português);
//Objetivo: Que se programe um jogo caça ao tesouro;

//Voids ();
void mensagem_derrota(void); //Mensagem de derrota;
void mensagem_vitoria(void); //Mensagem de vitoria;
void posicao(void); //Modulo de escolha de posicao;
void timer(void); //tempo limite para o jogo acabar;
void ranking(void); //Modulo de classificacao no Ranking;
void facil(void); //Mapa no modo facil;
void medio(void); //Mapa no modo medio;
void dificil(void); //Mapa no modo dificil;
void dificuldade(void); //Modulo para escolha de dificuldade;
void nome(void); //Modulo de leitura de nome dos jogadores;
void escolha(void); //Modulo para seleção de jogadores e nome;
void regras(void); //Modulo pra explicar as regras do jogo;
void gerador_armadilha(void); //Coloca aleatoriamente a posição das armadilhas;
void gerador_pistas(void); //Coloca aleatoriamente a posição das pistas;
void grid(void); //Gera o grid para o jogo;
void grid2(void);
void gerador_armadilha(void);
void contador_pontos(void);
void gerador_diamantes(void);
void ordem(void);
void mensagem_armadilha1(void);
void mensagem_armadilha2(void);
void mensagem_pista1(void);
void mensagem_pista2(void);
void De_novo(void);

int x, y, n, t, q, i, j, k;
int X, Y;
char denovo, c;
float diff;
int n;
int Tempo = 0;
int num_jog = 0;
int armadilhas = 0;
int armadilha1 = 0;
int armadilha2 = 0;
int pistas = 0;
int pista1 = 0;
int pista2 = 0;
int base_armadilha =0;
int diamantes = 0;
int diamante1 = 0;
char nome1[100];
char nome2[100];
char nome3[100];
char nome4[100];
int Mina[30][30];                                     
int Mina_vazia[30][30];                                
int Mina_result[30][30];
int jog1=0;
int jog2=0;
int jog3=0;
int jog4=0;

int main(){ //Int Main;
    setlocale(LC_ALL, "Portuguese"); //Muda as configuraçôes para a lingua portuguesa;
    printf("\t\tBem vindo a caça ao tesouro!\n"); //Introdução ao jogo;
    regras(); 
    return 0;   
}

void regras(void) {
    printf("\t As jogadas devem ser intercaladas entre os jogadores. São 36 jogadas possíveis, um múltiplo perfeito\n");
    printf("para que 2, 3 ou 4 jogadores tenham 18, 12 ou 9 jogadas, respectivamente.\n");
    printf("Em cada quadro da mina, pode existir um diamante com um número aleatório de quilates.\n");
    printf("Na mina, existem armadilhas e pistas. Distribua aleatoriamente pistas (em 5 porcento dos quadros) e dois\n");
    printf("tipos diferentes de armadilha (10 porcento dos quadros), como por exemplo:\n");
    printf("○ Túneis sem saída (identificados por O): ao sair do túnel, o jogador perde 5 ou 10 de seus diamantes;\n");
    printf("○ Esconderijo secreto (identificados por -): o jogador fica invisível e desconta 5 quilates do(s)\n");
    printf("oponente(s);\n");
    printf("○ Prossiga (identificados por +): como o jogador está no caminho certo, seus quilates são acrescidos em 3 pontos.\n");
    printf("Cada vez que um quadro é escolhido, ele deve ser assinalado conforme a identificação do jogador e,\n");
    printf("se for o caso, da armadilha ou da pista.\n");
    escolha();
}

void escolha(void){ 
    printf("\t\tDigite o numero de jogadores, 2-4:\n"); 
    scanf("%d", &n);
    switch(n){
        case 2:printf("\tSELECIONADO: 2 Jogadores.\n");
        num_jog=2;
        nome();
        break; 
        case 3:printf("\tSELECIONADO: 3 Jogadores.\n");
        num_jog=3;
        nome();
        break;
        case 4:printf("\tSELECIONADO: 4 Jogadores.\n");
        num_jog=4;
        nome();
        break;
        default:printf("\tVALOR INVALIDO\n");break;
    }
}

void nome(void) {
    printf("\tDigite o nome do jogador 01: ");
    fflush(stdin);
    scanf("%s", nome1);
    printf("\tDigite o nome do jogador 02: ");
    fflush(stdin);
    scanf("%s", nome2);
    if (n == 2) {
        dificuldade();
    } else if (n == 3) {
        printf("\tDigite o nome do jogador 03: ");
        fflush(stdin);
        scanf("%s", nome3);
        dificuldade();
    } else if (n == 4) {
        printf("\tDigite o nome do jogador 03: ");
        fflush(stdin);
        scanf("%s", nome3);
        printf("\tDigite o nome do jogador 04: ");
        fflush(stdin);
        scanf("%s", nome4);
        dificuldade();
    }
}

void dificuldade(void){
    printf("\tNivel facil: 36 quadros, taxa de 90 porcento de diamantes 5 porcento de minas e 5 porcento de pistas, não pussui timer\n");
    printf("\tNivel medio: 81 quadros, taxa de 80 porcento de diamantes e 10 porcento de minas e 10 porcento de pistas, possui um timer\n");
    printf("\tNivel dificil: 144 quadros, taxa de 70 porcento de diamantes e 20 porcento de minas e 10 porcento de pistas, possui um timer\n");
    printf("\t\tEscolha o nivel de dificuldade, 1 para facil, 2 para medio e 3 para dificil: \n");
    scanf("%c", &c);
     switch(c){
        case 1:printf("\t\tSELECIONADO: Nivel Facil.\n");
        printf("\tVocês são exploradores que infelizmente ficaram presos em uma caverna, coletem o maximo de pontos para escapar \n");
        Tempo=1000;
        facil(); //Mapa no modo facil;
        break; 
        case 2:printf("\t\tSELECIONADO: Nivel Medio.\n");
        printf("\tVocês são exploradores que infelizmente ficaram presos em uma caverna, coletem o maximo de pontos para escapar \n");
        printf("\tA caverna parece estar desmoronando atinjam o numero maximo de pontos antes que desmorone \n");
        Tempo=25;
        medio(); //Mapa no modo medio;
        break;
        case 3:printf("\t\tSELECIONADO: Nivel Dificil.\n");
        printf("\tVocês são exploradores que infelizmente ficaram presos em uma caverna, coletem o maximo de pontos para escapar \n");
        printf("\tA caverna parece estar desmoronando atinjam o numero maximo de pontos antes que desmorone \n");
        Tempo=70;
        dificil(); //Mapa no modo dificil;
        break;
        default:printf("\t\tVALOR INVALIDO\n");break;
    }
    
}

void facil(void){
    X = 6;
    Y = 6;
    gerador_armadilha();
    gerador_pistas();
    gerador_diamantes();
    ranking();
    grid2();
    ordem();
}
void medio(void){
    X = 9;
    Y = 9;
    gerador_armadilha();
    gerador_pistas();
    gerador_diamantes();
    ranking();
    grid2();
    ordem();
}
void dificil(void){
    X = 12;
    Y = 12;
    gerador_armadilha();
    gerador_pistas();
    gerador_diamantes();
    ranking();
    grid2();
    ordem();
}

void ordem(void){
    if(num_jog==2){
        
        if (t==0){
        printf("Vez do jogador: %s", nome1);
        t=1;
        posicao();
        }
        if(t==2){
        t++;
        if (t==2){
        printf("Vez do jogador: %s", nome2);
        t=2;
        posicao();
        }
        }
    }
    if(num_jog==3){
        if (t!=1){
        printf("Vez do jogador: %s", nome1);
        t=1;
        posicao();
        }
        if (t!=2){
        printf("Vez do jogador: %s", nome2);
        t=2;
        posicao();
        }
        if (t!=3){
        printf("Vez do jogador: %s", nome3);
        t=3;
        posicao();
        }

        
    }
    if(num_jog==4){
        if (t!=1){
        printf("Vez do jogador: %s", nome1);
        t=1;
        posicao();
        }
        if (t!=2){
        printf("Vez do jogador: %s", nome2);
        t=2;
        posicao();
        }
        if (t!=3){
        printf("Vez do jogador: %s", nome3);
        t=3;
        posicao();
        }
        if (t!=4){
        printf("Vez do jogador: %s", nome4);
        t=4;
        posicao();
        }
    }
}

void gerador_armadilha(void){
    if(c==1){
    base_armadilha=X*Y;
    armadilhas=base_armadilha*0.05;
    }
    if(c==2){
    base_armadilha=X*Y;
    armadilhas=base_armadilha*0.1;
    }
    if(c==3){
    base_armadilha=X*Y;
    armadilhas=base_armadilha*0.2;
    }



}

void gerador_pistas(void){
    if(c==1){
    base_armadilha=X*Y;
    pistas=base_armadilha*0.05;
    }
    if(c==2){
    base_armadilha=X*Y;
    pistas=base_armadilha*0.1;
    }
    if(c==3){
    base_armadilha=X*Y;
    pistas = base_armadilha*0.1;
    }
}

void gerador_diamantes(void){
    if(c==1){
    base_armadilha=X*Y;
    diamantes=base_armadilha*0.9;
    }
    if(c==2){
    base_armadilha=X*Y;
    diamantes=base_armadilha*0.8;
    }
    if(c==3){
    base_armadilha=X*Y;
    diamantes=base_armadilha*0.7;
    }
}


void mensagem_armadilha1(void){
    printf("Azar caiu em um tunel e perdeu 5 diamantes\n");
    if(t==1){
    jog1-=5;
    }
    if(t==2){
    jog2-=5;
    }
    if(t==3){
    jog3-=5;
    }
    if(t==4){
    jog4-=5;
    }
    ordem();
}

void mensagem_armadilha2(void){
    printf("Azar uma pedra caiu na sua cabeça e perdeu 10 dimantes\n");
    if(t==1){
    jog1-=10;
    }
    if(t==2){
    jog2-=10;
    }
    if(t==3){
    jog3-=10;
    }
    if(t==4){
    jog4-=10;
    }
    ordem();

}

void mensagem_pista1(void){
    printf("Você encontrou um artefato raro ganha 15 diamantes.\n");
    if(t==1){
    jog1+=15;
    }
    if(t==2){
    jog2+=15;
    }
    if(t==3){
    jog3+=15;
    }
    if(t==4){
    jog4+=15;
    }
    ordem();
}

void mensagem_pista2(void){
    printf("Você encontrou um artefato raro ganha 25 diamantes.\n");
    if(t==1){
    jog1+=25;
    }
    if(t==2){
    jog2+=25;
    }
    if(t==3){
    jog3+=25;
    }
    if(t==4){
    jog4+=25;
    }
    ordem();
}

void mensagem_vitoria(void){
    printf("Parabéns!!! o jogador com mais pontos conseguiu sair da caverna com vida!\n");
    ranking();
    De_novo();
}

void mensagem_derrota(void){
    printf("Infelizmente o tempo acabou e a mina acabou desmoronando, tente da proxima vez!\n");
    ranking();
    De_novo();
}

void timer(void){
    if(Tempo != 0){
        printf("O tempo esta acabando... %d\n", Tempo - 1);
    }
    ordem();
}

void ranking(void){
    printf("Pontos de jogador1 %s\n", nome1);
    printf("%d\n", jog1);
    printf("Pontos de jogador2 %s\n", nome2);
    printf("%d\n", jog2);
    printf("Pontos de jogador3 %s\n", nome3);
    printf("%d\n", jog3);
    printf("Pontos de jogador4 %s\n", nome4);
    printf("%d\n", jog4);
    
    
}

void grid2(void)
{
    int i = 0, j = 0, z = 0;
    while( z < X )                                         
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < Y )                                                                   
    {   
        printf("|%d|\t", j);
        while( i < X)
        {
            if( Mina_vazia[i][j] == '_')
            {
                printf("|%c|\t", Mina_vazia[i][j]);

            }
            else if( Mina[i][j] == 0 )                 
            {
                Mina_vazia[i][j] = 'B';                
                printf("|%c|\t", Mina_vazia[i][j]);
            }
            else
            {
                printf("|%d|\t", Mina_vazia[i][j]);

            }
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}

void grid(void){
    int i = 0, j = 0;

    while( j < X )                                          
    {
        while( i < Y)
        {
            Mina[i][j] = '-';
            Mina_vazia[i][j] = Mina[i][j];        
            Mina_result[i][j] = Mina[i][j];        
            i++;
        }
        i = 0;
        j++;
    }
    armadilha1 = 0;
    while( armadilha1 < armadilhas )                            
    {
        i = rand()%(X);
        j = rand()%(Y);
        if( Mina[i][j] != '*')                         
        {
            Mina[i][j] = '*';
            Mina_result[i][j] = Mina[i][j];
            armadilha2++;
        }
    }
    i = 0;
    j = 0;

    armadilha2 = 0;
    while( armadilha2 < armadilhas )                            
    {
        i = rand()%(X);
        j = rand()%(Y);
        if( Mina[i][j] != 'O')                         
        {
            Mina[i][j] = 'O';
            Mina_result[i][j] = Mina[i][j];
            armadilha2++;
        }
    }
    i = 0;
    j = 0;

    pista1 = 0;
    while( pista1 < pistas )                            
    {
        i = rand()%(X);
        j = rand()%(Y);
        if( Mina[i][j] != '+')                         
        {
            Mina[i][j] = '+';
            Mina_result[i][j] = Mina[i][j];
            pista1++;
        }
    }
    i = 0;
    j = 0;

    pista2 = 0;
    while( pista2 < pistas )                            
    {
        i = rand()%(X);
        j = rand()%(Y);
        if( Mina[i][j] != '-')                         
        {
            Mina[i][j] = '-';
            Mina_result[i][j] = Mina[i][j];
            pista2++;
        }
    }
    i = 0;
    j = 0;

    diamante1 = 0;
    while( diamante1 < diamantes )                            
    {
        i = rand()%(X);
        j = rand()%(Y);
        if( Mina[i][j] != '9')                         
        {
            Mina[i][j] = '9';
            Mina_result[i][j] = Mina[i][j];
            diamante1++;
        }
    }
    i = 0;
    j = 0;

    while( j < X )                                          
    {
        while( i < Y)
        {
            if( Mina[i][j] != '9')
            {
                Mina[i][j] = 0;
            }   
            if((Mina[i-1][j-1] == '9') && (Mina[i][j] != '9'))
            {
                Mina[i][j]++;
            }
            if((Mina[i-1][j] == '9') && (Mina[i][j] != '9'))
            {
                Mina[i][j]++;
            }
            if((Mina[i][j-1] == '9') && (Mina[i][j] != '9'))
            {
                Mina[i][j]++;
            }
            if((Mina[i-1][j+1] == '9') && (Mina[i][j] != '9'))
            {
                Mina[i][j]++;
            }
            if((Mina[i+1][j-1] == '9') && (Mina[i][j] != '9'))
            {
                Mina[i][j]++;
            }
            if((Mina[i+1][j] == '9') && (Mina[i][j] != '9'))
            {
                Mina[i][j]++;
            }
            if((Mina[i][j+1] == '9') && (Mina[i][j] != '9'))
            {
                Mina[i][j]++;
            }
            if((Mina[i+1][j+1] == '9') && (Mina[i][j] != '9'))
            {
                Mina[i][j]++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;

     while( j < X )                                          
    {
        while( i < Y)
        {
            if( Mina[i][j] != '+')
            {
                Mina[i][j] = 0;
            }   
            if((Mina[i-1][j-1] == '+') && (Mina[i][j] != '+'))
            {
                Mina[i][j]++;
            }
            if((Mina[i-1][j] == '+') && (Mina[i][j] != '+'))
            {
                Mina[i][j]++;
            }
            if((Mina[i][j-1] == '+') && (Mina[i][j] != '+'))
            {
                Mina[i][j]++;
            }
            if((Mina[i-1][j+1] == '+') && (Mina[i][j] != '+'))
            {
                Mina[i][j]++;
            }
            if((Mina[i+1][j-1] == '+') && (Mina[i][j] != '+'))
            {
                Mina[i][j]++;
            }
            if((Mina[i+1][j] == '+') && (Mina[i][j] != '+'))
            {
                Mina[i][j]++;
            }
            if((Mina[i][j+1] == '+') && (Mina[i][j] != '+'))
            {
                Mina[i][j]++;
            }
            if((Mina[i+1][j+1] == '+') && (Mina[i][j] != '+'))
            {
                Mina[i][j]++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
    

     while( j < X )                                          
    {
        while( i < Y)
        {
            if( Mina[i][j] != '-')
            {
                Mina[i][j] = 0;
            }   
            if((Mina[i-1][j-1] == '-') && (Mina[i][j] != '-'))
            {
                Mina[i][j]++;
            }
            if((Mina[i-1][j] == '-') && (Mina[i][j] != '-'))
            {
                Mina[i][j]++;
            }
            if((Mina[i][j-1] == '-') && (Mina[i][j] != '-'))
            {
                Mina[i][j]++;
            }
            if((Mina[i-1][j+1] == '-') && (Mina[i][j] != '-'))
            {
                Mina[i][j]++;
            }
            if((Mina[i+1][j-1] == '-') && (Mina[i][j] != '-'))
            {
                Mina[i][j]++;
            }
            if((Mina[i+1][j] == '-') && (Mina[i][j] != '-'))
            {
                Mina[i][j]++;
            }
            if((Mina[i][j+1] == '-') && (Mina[i][j] != '-'))
            {
                Mina[i][j]++;
            }
            if((Mina[i+1][j+1] == '-') && (Mina[i][j] != '-'))
            {
                Mina[i][j]++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;

    while( j < X )                                          
    {
        while( i < Y)
        {
            if( Mina[i][j] != '*')
            {
                Mina[i][j] = 0;
            }   
            if((Mina[i-1][j-1] == '*') && (Mina[i][j] != '*'))
            {
                Mina[i][j]++;
            }
            if((Mina[i-1][j] == '*') && (Mina[i][j] != '*'))
            {
                Mina[i][j]++;
            }
            if((Mina[i][j-1] == '*') && (Mina[i][j] != '*'))
            {
                Mina[i][j]++;
            }
            if((Mina[i-1][j+1] == '*') && (Mina[i][j] != '*'))
            {
                Mina[i][j]++;
            }
            if((Mina[i+1][j-1] == '*') && (Mina[i][j] != '*'))
            {
                Mina[i][j]++;
            }
            if((Mina[i+1][j] == '*') && (Mina[i][j] != '*'))
            {
                Mina[i][j]++;
            }
            if((Mina[i][j+1] == '*') && (Mina[i][j] != '*'))
            {
                Mina[i][j]++;
            }
            if((Mina[i+1][j+1] == '*') && (Mina[i][j] != '*'))
            {
                Mina[i][j]++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
    while( j < X )                                          
        {
        while( i < Y)
            {
                if( Mina[i][j] != 'O')
                {
                    Mina[i][j] = 0;
                }   
                if((Mina[i-1][j-1] == 'O') && (Mina[i][j] != 'O'))
                {
                    Mina[i][j]++;
                }
                if((Mina[i-1][j] == 'O') && (Mina[i][j] != 'O'))
                {
                    Mina[i][j]++;
                }
                if((Mina[i][j-1] == 'O') && (Mina[i][j] != 'O'))
                {
                    Mina[i][j]++;
                }
                if((Mina[i-1][j+1] == 'O') && (Mina[i][j] != 'O'))
                {
                    Mina[i][j]++;
                }
                if((Mina[i+1][j-1] == 'O') && (Mina[i][j] != 'O'))
                {
                    Mina[i][j]++;
                }
                if((Mina[i+1][j] == 'O') && (Mina[i][j] != 'O'))
                {
                    Mina[i][j]++;
                }
                if((Mina[i][j+1] == 'O') && (Mina[i][j] != 'O'))
                {
                    Mina[i][j]++;
                }
                if((Mina[i+1][j+1] == 'O') && (Mina[i][j] != 'O'))
                {
                    Mina[i][j]++;
                }
                i++;
            }
            i = 0;
            j++;
        }
    i = 0;
    j = 0;

}

void posicao (void){
    int i=0, j=0, partida=0;
    grid2();
    while( j < X )                                          
    {
        while( i < Y )
        {
            if(Mina[i][j] == Mina_vazia[i][j])
            {
                k++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    if( partida == ( X * Y ) - diamantes)                 
    {
        mensagem_vitoria();
    }
    printf("\nDigite o valor x espaço e o valor de y:");
    scanf("%d %d", &x, &y);                                 
    if( (x >= X) || (x < 0) || (y < 0) || (y >= Y) )
    {
        printf("\nDigite um valor dentro da mina\n");
        posicao ();
    }
    if( Mina[x][y] == '*' )                            
    {
        mensagem_armadilha1();
        posicao ();
        
    }
    if( Mina[x][y] == 'O' )                            
    {
        mensagem_armadilha2();
        posicao ();
    }
    if( Mina_vazia[x][y] != '9' )
    {
        printf("\nDiamante encontrado\n");
        posicao ();
    }
    if( Mina[x][y] == '-' )                            
    {
        mensagem_pista1();
        posicao ();
    }
    if( Mina[x][y] == '+' )                            
    {
        mensagem_pista1();
        posicao ();
    }
    if( Tempo==0 )                            
    {
        mensagem_derrota();
    }
    else                                                
    {
        Mina_vazia[x][y] = Mina[x][y];
        if( Mina[x][y] == 0 )
        {
            if( Mina[x-1][y-1] == 0 )
            {
                Mina_vazia[x-1][y] = Mina[x-1][y];
            }
            if( Mina[x-1][y] == 0 )
            {
                Mina_vazia[x-1][y] = Mina[x-1][y];
            }
            if( Mina[x][y-1] == 0 )
            {
                Mina_vazia[x][y-1] = Mina[x][y-1];
            }
            if( Mina[x-1][y+1] == 0 )
            {
                Mina_vazia[x-1][y+1] = Mina[x-1][y+1];
            }
            if( Mina[x+1][y-1] == 0 )
            {
                Mina_vazia[x+1][y-1] = Mina[x+1][y-1];
            }
            if( Mina[x+1][y] == 0 )
            {
                Mina_vazia[x+1][y] = Mina[x+1][y];
            }
            if( Mina[x][y+1] == 0 )
            {
                Mina_vazia[x][y+1] = Mina[x][y+1];
            }
            if( Mina[x+1][y+1] == 0 )
            {
                Mina_vazia[x+1][y+1] = Mina[x+1][y+1];
            }
        }
        timer();
        posicao();
    }
}

void De_novo(void)
{
    printf("Querem jogar novamente? ('S'/'N')?\n");
    fflush(stdin);
    scanf("%c", &denovo);
    if(denovo=='S'){
        escolha();
    }
    else{
        printf("Obrigado por jogar\n");
        
    }
}

