#include <iostream>
#include "carta.h"
using namespace std;

int main()
{
    TCarta carta[10];
    char valor;
    char naipe;
    char valor10;

    TJogador j1, j2;

    cout << "Escreva o valor e o naipe das cartas da mao do jogador 1: \n\n";
    for(int i = 0; i < 10; i++){
        if(i == 5)
            cout << "\nEscreva respectivamente o valor e o naipe das cartas da mao do jogador 2: \n";

        cout << "Carta " << i+1 << ":\n";
        cout << "\nO valor e 10? S / N\n";
        cin >> valor10;
        while(valor10 != 83 and valor10 != 115 and valor10 != 78 and valor10 != 110){ /// valor10 != S ou s ou N ou n
            cout << "Valor invalido. Digite novamente. \nO Valor e 10? S / N\n";
            cin >> valor10;
        }

        if(valor10 == 83 or valor10 == 115){
            carta[i].valorInt = 10;
            valor = 48;
        }
        else{
            cout << "\nValor: ";
            cin >> valor;
            while(valor != 49 and valor != 50 and valor != 51 and valor != 52 and valor != 53 and valor != 54 and valor != 55 and valor != 56 and valor != 57 and valor != 58 and valor != 65 and valor != 97 and valor != 75 and valor != 107 and valor != 81 and valor != 113 and valor != 74 and valor != 106){
                cout << "Valor invalido. Insira outro valor: ";
                cin >> valor;
            }
        }
        cout << "Naipe: ";
        cin >> naipe;

        /// Muda o valor da struct.valorInt para 13, 12 ou 11 caso o char seja K, Q ou J ou para um valor de 0 a 10.

        if(valor10 != 83 and valor10 != 115){
            if(valor == 75 or valor == 107) /// 75 == K // 107 == k
                carta[i].valorInt = 13;
            else if(valor == 81 or valor == 113) /// 81 == Q // 113 == q
                carta[i].valorInt = 12;
            else if(valor == 74 or valor == 106) /// 74 == J / 106 = j
                carta[i].valorInt = 11;
            else if(valor == 65 or valor == 97)
                carta[i].valorInt = 1;
            else {
                carta[i].valorInt = valor - 48;
            }
        }

        carta[i].valor = valor;
        carta[i].naipe = naipe;
    }

    for(int i = 0; i < 5; i++){
        j1.cartas[i] = carta[i];
        j2.cartas[i] = carta[i+5];
    }


    ordena_mao(j1);
    ordena_mao(j2);

        /// Caso Deseje verificar a mão dos jogadores.


    for(int i = 0; i < 5; i++){
        cout << "\nJogador 1 - Valor : " << j1.cartas[i].valor;
        cout << "\nJogador 1 - Naipe: " << j1.cartas[i].naipe << endl;
        cout << "Jogador valorint: " << j1.cartas[i].valorInt << endl;
    }


    for(int i = 0; i < 5; i++){
        cout << "\nJogador 2 - Valor: " << j2.cartas[i].valor;
        cout << "\nJogador 2 - Naipe: " << j2.cartas[i].naipe << endl;
        cout << "Jogador valorInt: " << j2.cartas[i].valorInt << endl;
    }


    verifica_vencedor(j1, j2);

    /// Caso deseje verificar os resultados de cada jogador.

    cout << "\n\nJogador 1 Possui:\n";
    cout << "\nVerifica Par: " << j1.par;
    cout << "\nVerifica Dois_pares: " << j1.dois_pares;
    cout << "\nTrinca: " << j1.trinca;
    cout << "\nStraight: " << j1.straight;
    cout << "\nFlush: " << j1.flush;
    cout << "\nFull_House: " << j1.full_house;
    cout << "\nQuadra: " << j1.quadra;
    cout << "\nStraight Flush: " << j1.straight_flush;
    cout << "\nRoyal Flush: " << j1.royal_flush;

    cout << "\nJogador 2 Possui:\n";
    cout << "\nVerifica Par: " << j2.par;
    cout << "\nVerifica Dois_pares: " << j2.dois_pares;
    cout << "\nTrinca: " << j2.trinca;
    cout << "\nStraight: " << j2.straight;
    cout << "\nFlush: " << j2.flush;
    cout << "\nFull_House: " << j2.full_house;
    cout << "\nQuadra: " << j2.quadra;
    cout << "\nStraight Flush: " << j2.straight_flush;
    cout << "\nRoyal Flush: " << j2.royal_flush;


    if(j1.vencedor)
        cout << "\nJogador 1 Venceu!\n";
    else if(j2.vencedor)
        cout << "\nJogador 2 Venceu!\n";
    else if(j1.empate)
        cout << "\nEmpate :O";

    return 0;
}
