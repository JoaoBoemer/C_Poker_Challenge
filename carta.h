#ifndef CARTA_H
#define CARTA_H
#include <iostream>

struct TCarta{
    char valor;
    char naipe;
    int valorInt;
    int pontuacao;
};

struct TJogador{
    TCarta cartas[5];

    int valor_par = 0;
    int valor_par2 = 0;
    int valor_trio = 0;
    int valor_quadra = 0;

    bool par = false;
    bool dois_pares = false;
    bool trinca = false;
    bool straight = false;
    bool flush = false;
    bool full_house = false;
    bool quadra = false;
    bool straight_flush = false;
    bool royal_flush = false;
    bool vencedor = false;
    bool maior = false;
    bool empate = false;
};

void ordena_mao(TJogador &jogador);

void verifica_par(TJogador &jogador);

void verifica_dois_pares(TJogador &jogador);

void verifica_trinca(TJogador &jogador);

void verifica_quadra(TJogador &jogador);

void verifica_full_house(TJogador &jogador);

void verifica_flush(TJogador &jogador);

void verifica_straight(TJogador &jogador);

void verifica_straight_flush(TJogador &jogador);

void verifica_royal_flush(TJogador &jogador);

void maior_carta(TJogador &j1, TJogador &j2);

void verifica_vencedor(TJogador &jogador, TJogador &jogador2);

#endif // CARTA_H
