#include "carta.h"


void ordena_mao(TJogador &jogador){

    for(int j = 0; j < 4; j++)
        for(int i = 0; i < 4; i++)
            if(jogador.cartas[i].valorInt>jogador.cartas[i+1].valorInt){
                TCarta temp = jogador.cartas[i];
                jogador.cartas[i] = jogador.cartas[i+1];
                jogador.cartas[i+1] = temp;
            }
}

void verifica_par(TJogador &jogador){
    int j;
    for(int i = 0; i < 4; i ++){
        j = i+1;
        while(j < 5){
            if(jogador.cartas[i].valorInt == jogador.cartas[j].valorInt){
                jogador.par = true;
                jogador.valor_par = i;
            }
            j++;
        }
    }
}

void verifica_dois_pares(TJogador &jogador){
    if(jogador.par){
        if(jogador.cartas[0].valorInt == jogador.cartas[1].valorInt and jogador.cartas[2].valorInt == jogador.cartas[3].valorInt){
            jogador.dois_pares = true;
            if(jogador.cartas[2].valorInt>jogador.cartas[0].valorInt){
                jogador.valor_par = jogador.cartas[2].valorInt;
                jogador.valor_par2 = jogador.cartas[0].valorInt;
            } else {
            jogador.valor_par = jogador.cartas[0].valorInt;
            jogador.valor_par2 = jogador.cartas[2].valorInt;
            }
        }else if(jogador.cartas[1].valorInt == jogador.cartas[2].valorInt and jogador.cartas[3].valorInt == jogador.cartas[4].valorInt){
            if(jogador.cartas[3].valorInt>jogador.cartas[1].valorInt){
                jogador.valor_par = jogador.cartas[3].valorInt;
                jogador.valor_par2 = jogador.cartas[1].valorInt;
            } else {
                jogador.dois_pares = true;
                jogador.valor_par = jogador.cartas[1].valorInt;
                jogador.valor_par2 = jogador.cartas[3].valorInt;
            }
        } else if(jogador.cartas[0].valorInt == jogador.cartas[1].valorInt and jogador.cartas[3].valorInt == jogador.cartas[4].valorInt){
            if(jogador.cartas[3].valorInt>jogador.cartas[0].valorInt){
                jogador.valor_par = jogador.cartas[3].valorInt;
                jogador.valor_par2 = jogador.cartas[0].valorInt;
            } else {
                jogador.dois_pares = true;
                jogador.valor_par = jogador.cartas[0].valorInt;
                jogador.valor_par2 = jogador.cartas[3].valorInt;
            }
        }
    }
}

void verifica_trinca(TJogador &jogador){
    if(jogador.par){
        if((jogador.cartas[0].valorInt == jogador.cartas[1].valorInt and jogador.cartas[0].valorInt == jogador.cartas[2].valorInt)
                or (jogador.cartas[1].valorInt == jogador.cartas[2].valorInt and jogador.cartas[1].valorInt == jogador.cartas[3].valorInt)
                or (jogador.cartas[2].valorInt == jogador.cartas[3].valorInt and jogador.cartas[2].valorInt == jogador.cartas[4].valorInt)){
            jogador.trinca = true;
            jogador.valor_trio = jogador.cartas[2].valorInt;
        }
    }
}

void verifica_quadra(TJogador &jogador){
    if(jogador.par)
        if(jogador.trinca)
            if((jogador.cartas[0].valorInt == jogador.cartas[1].valorInt and jogador.cartas[0].valorInt == jogador.cartas[2].valorInt and jogador.cartas[0].valorInt == jogador.cartas[3].valorInt)
                or (jogador.cartas[1].valorInt == jogador.cartas[2].valorInt and jogador.cartas[1].valorInt == jogador.cartas[3].valorInt and jogador.cartas[1].valorInt == jogador.cartas[4].valorInt)){
                jogador.quadra = true;
                jogador.valor_quadra = jogador.cartas[1].valorInt;
            }
}

void verifica_full_house(TJogador &jogador){
    if(jogador.cartas[0].valorInt == jogador.cartas[1].valorInt and
        jogador.cartas[0].valorInt == jogador.cartas[2].valorInt and
        jogador.cartas[3].valorInt == jogador.cartas[4].valorInt)
    {
        jogador.full_house = true;
        jogador.valor_trio = jogador.cartas[2].valorInt;
        jogador.valor_par = jogador.cartas[3].valorInt;
}
    if(jogador.cartas[0].valorInt == jogador.cartas[1].valorInt and
        jogador.cartas[2].valorInt == jogador.cartas[3].valorInt and
        jogador.cartas[2].valorInt == jogador.cartas[4].valorInt)
    {
        jogador.full_house = true;
        jogador.valor_trio = jogador.cartas[2].valorInt;
        jogador.valor_par = jogador.cartas[0].valorInt;
    }
}

void verifica_flush(TJogador &jogador){

    if(jogador.cartas[0].naipe == jogador.cartas[1].naipe and jogador.cartas[0].naipe == jogador.cartas[2].naipe and jogador.cartas[0].naipe == jogador.cartas[3].naipe
            and jogador.cartas[0].naipe == jogador.cartas[4].naipe)
        jogador.flush = true;
}

void verifica_straight(TJogador &jogador){

    if(jogador.cartas[0].valorInt == 1 and jogador.cartas[1].valorInt == 10 and jogador.cartas[2].valorInt == 11 and jogador.cartas[3].valorInt == 12 and jogador.cartas[4].valorInt == 13)
        jogador.straight = true;

    if(jogador.cartas[0].valorInt + 1 == jogador.cartas[1].valorInt and
            jogador.cartas[1].valorInt + 1 == jogador.cartas[2].valorInt and
            jogador.cartas[2].valorInt + 1 == jogador.cartas[3].valorInt and
            (jogador.cartas[3].valorInt + 1 == jogador.cartas[4].valorInt or (jogador.cartas[3].valorInt == 13 and jogador.cartas[4].valorInt == 1)))
        jogador.straight = true;
}

void verifica_straight_flush(TJogador &jogador){
    if(jogador.flush and jogador.straight)
        jogador.straight_flush = true;
}

void verifica_royal_flush(TJogador &jogador){
    if(jogador.flush)
        if(jogador.cartas[0].valorInt == 1 and jogador.cartas[1].valorInt == 10 and jogador.cartas[2].valorInt == 11 and jogador.cartas[3].valorInt == 12 and jogador.cartas[4].valorInt == 13)
            jogador.royal_flush = true;
}

void maior_carta(TJogador &j1, TJogador &j2){
    for(int i = 0; i < 5; i ++){
        if(j1.cartas[i].valorInt == 1 and j2.cartas[i].valorInt != 1)
            j1.maior = true;
        else if(j1.cartas[i].valorInt != 1 and j2.cartas[i].valorInt == 1)
            j2.maior = true;
        else{
            if(j1.cartas[i].valorInt > j2.cartas[i].valorInt)
                j1.maior = true;
            else if(j2.cartas[i].valorInt > j1.cartas[i].valorInt)
                j2.maior = true;
            else if(j1.cartas[i].valorInt == j2.cartas[i].valorInt){
                j1.empate = true;
                j2.empate = true;
            }
        }
    }
}

void verifica_vencedor(TJogador &j1, TJogador &j2){
    verifica_par(j1);
    verifica_par(j2);
    verifica_trinca(j1);
    verifica_trinca(j2);
    verifica_full_house(j1);
    verifica_full_house(j2);
    verifica_quadra(j1);
    verifica_quadra(j2);
    verifica_straight(j1);
    verifica_straight(j2);
    verifica_flush(j1);
    verifica_flush(j2);
    verifica_straight_flush(j1);
    verifica_straight_flush(j2);
    verifica_royal_flush(j1);
    verifica_royal_flush(j2);

    if(j1.royal_flush or j2.royal_flush){
        if(j1.royal_flush == true and j2.royal_flush == false)
            j1.vencedor = true;
        else if (j1.royal_flush == false and j2.royal_flush == true)
            j2.vencedor = true;
        else {
            j1.empate = true;
        }
    } else if(j1.straight_flush or j2.straight_flush){
        if(j1.straight_flush and !j2.straight_flush)
            j1.vencedor = true;
        else if (!j1.straight_flush and j2.straight_flush)
            j2.vencedor = true;
        else
            maior_carta(j1, j2);
    } else if(j1.quadra or j2.quadra){
        if(j1.quadra and !j2.quadra)
            j1.vencedor = true;
        else if(!j1.quadra and j2.quadra)
            j2.vencedor = true;
        else if(j1.valor_quadra > j2.valor_quadra)
            j1.vencedor = true;
        else if(j2.valor_quadra > j1.valor_quadra)
            j2.vencedor = true;
        else
            maior_carta(j1, j2);
    } else if(j1.full_house or j2.full_house){
        if(j1.full_house and !j2.full_house)
            j1.vencedor = true;
        else if(!j1.full_house and j2.full_house)
            j2.vencedor = true;
        else if(j1.valor_trio > j2.valor_trio)
            j1.vencedor = true;
        else if(j2.valor_trio > j1.valor_trio)
            j2.vencedor = true;
        else if(j1.valor_trio == j2.valor_trio and j1.valor_par > j2.valor_par)
            j1.vencedor = true;
        else if(j1.valor_trio == j2.valor_trio and j2.valor_par > j1.valor_par)
            j2.vencedor = true;
        else
            maior_carta(j1, j2);
    } else if(j1.flush or j2.flush){
        if(j1.flush and !j2.flush)
            j1.vencedor = true;
        else if(!j1.flush and j2.flush)
            j2.vencedor = true;
        else
            maior_carta(j1, j2);
    } else if(j1.straight or j2.straight){
        if(j1.straight and !j2.straight)
            j1.vencedor = true;
        else if(!j1.straight and j2.straight)
            j2.vencedor = true;
        else
            maior_carta(j1, j2);
    } else if(j1.trinca or j2.trinca){
        if(j1.trinca and !j2.trinca)
            j1.vencedor = true;
        else if(!j1.trinca and j2.trinca)
            j2.vencedor = true;
        else if(j1.valor_trio > j2.valor_trio)
            j1.vencedor = true;
        else if(j2.valor_trio > j1.valor_trio)
            j2.vencedor = true;
        else
            maior_carta(j1, j2);
    } else if(j1.dois_pares or j2.dois_pares) {
        if(j1.dois_pares and !j2.dois_pares)
            j1.vencedor = true;
        else if(!j1.dois_pares and j2.dois_pares)
            j2.vencedor = true;
        else if(j1.valor_par > j2.valor_par)
            j1.vencedor = true;
        else if(j2.valor_par2 > j1.valor_par)
            j2.vencedor = true;
        else if(j1.valor_par == j2.valor_par and j1.valor_par2 > j2.valor_par2)
            j1.vencedor = true;
        else if(j1.valor_par == j2.valor_par and j2.valor_par2 > j1.valor_par2)
            j2.vencedor = true;
        else
            maior_carta(j1, j2);
    }else if(j1.par or j2.par){
        if(j1.par and !j2.par)
            j1.vencedor = true;
        else if(!j1.par and j2.par)
            j2.vencedor = true;
        else if(j1.valor_par > j2.valor_par)
            j1.vencedor = true;
        else if(j2.valor_par > j1.valor_par)
            j2.vencedor = true;
        else
            maior_carta(j1, j2);
    } else {
        maior_carta(j1, j2);
    }

    if(!j1.vencedor or !j2.vencedor){
        if(j1.maior)
            j1.vencedor = true;
        else if(j2.maior)
            j2.vencedor = true;
    }
}
