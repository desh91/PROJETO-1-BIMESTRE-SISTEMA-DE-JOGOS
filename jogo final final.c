#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int opcao = 0;
	srand(time(NULL));

inicio:
	printf("\n=== MENU PRINCIPAL ===\n");
	printf("1) Pergunta e Resposta\n");
	printf("2) Cobra na Caixa\n");
	printf("3) Gousmas War\n");
	printf("4) Sair\n");
	printf("Escolha: ");
	scanf("%d", &opcao);

	//jogo1
inicio2:	 
	if (opcao == 1) {
		int pontos = 0, r, jogar;

		printf("Qual a capital do Brasil?\n1) Sao Paulo \n2) Brasilia \n3) Rio de Janeiro \n4) Bahia \nR: ");
		scanf("%d", &r);
		if (r == 2) {
			pontos++;
			printf("Certa!\n");
		} else printf("Errada. Correta: 2\n");

		printf("Quanto e 5+3?\n1) 6 \n2) 7 \n3) 8 \n4) 9\nR: ");
		scanf("%d", &r);
		if (r == 3) {
			pontos++;
			printf("Certa!\n");
		} else printf("Errada. Correta: 3\n");

		printf("Linguagem usada aqui?\n1) Python \n2) Java \n3) C \n4) JS\nR: ");
		scanf("%d", &r);
		if (r == 3) {
			pontos++;
			printf("Certa!\n");
		} else printf("Errada. Correta: 3\n");

		printf("Bits em um byte?\n1) 4 \n2) 8 \n3) 16 \n4) 32\nR: ");
		scanf("%d", &r);
		if (r == 2) {
			pontos++;
			printf("Certa!\n");
		} else printf("Errada. Correta: 2\n");

		printf("Criador do C?\n1) Ritchie \n2) Gosling \n3) Guido \n4) Bjarne\nR: ");
		scanf("%d", &r);
		if (r == 1) {
			pontos++;
			printf("Certa!\n");
		} else printf("Errada. Correta: 1\n");

		printf("Acertou %d de 5!\n", pontos);
		printf("1) Jogar de novo\n2) Voltar ao menu\n");
		scanf("%d", &jogar);
		if (jogar == 1) goto inicio2;
		else goto inicio;
	}

	//jogo2
inicio3:
	if( opcao == 2){
	
	int caixa_botao, caixa_cobra;
    int caixa_escolhida;
    int vez = 0; 	
    int sorteado;
    int fim = 0;
    int pcao;
    int nome1 = 0, nome2 = 0;

    srand(time(NULL));


    printf("\n=== COBRA NA CAIXA ===\n");

    printf("Jogador 1, escolha seu nome:\n");
    printf("1)Professor 2)Toquio 3)Berlim 4)Rio 5)Denver 6)Nairobi 7)Raquel\n");
    scanf("%d", &nome1);

    printf("Jogador 2, escolha seu nome:\n");
    printf("1)Professor 2)Toquio 3)Berlim 4)Rio 5)Denver 6)Nairobi 7)Raquel\n");
    scanf("%d", &nome2);

    caixa_botao = rand() % 5 + 1;
    caixa_cobra = rand() % 5 + 1;
    if (caixa_botao == caixa_cobra) {
        caixa_cobra = (caixa_cobra % 5) + 1;
    }

    sorteado = rand() % 2; 
    vez = sorteado;

    printf("\nSorteando quem comeca...\n");
    if (vez == 0) printf("Jogador 1 comeca!\n");
    else printf("Jogador 2 comeca!\n");

turno:
    if (vez == 0) {
        printf("\nJogador 1, escolha uma caixa (1 a 5): ");
    } else {
        printf("\nJogador 2, escolha uma caixa (1 a 5): ");
    }

    scanf("%d", &caixa_escolhida);

    if (caixa_escolhida == caixa_botao) {
        if (vez == 0) printf("Jogador 1 encontrou o BOTAO! Venceu!\n");
        else printf("Jogador 2 encontrou o BOTAO! Venceu!\n");
        fim = 1;
    } else if (caixa_escolhida == caixa_cobra) {
        if (vez == 0) printf("Jogador 1 encontrou a COBRA! Perdeu!\n");
        else printf("Jogador 2 encontrou a COBRA! Perdeu!\n");
        fim = 1;
    } else {
        printf("Caixa vazia! Ninguem achou nada.\n");
        vez = (vez == 0) ? 1 : 0; 
    }

    if (fim == 0) goto turno;

    printf("\n1) Jogar novamente\n2) Voltar ao menu\n");
    scanf("%d", &pcao);
	
    if (pcao == 1) goto inicio3;
    else goto inicio;
	}

	//jogo3
inicio4:
	if( opcao == 3){
    int j1g1 = 1, j1g2 = 1;
    int j2g1 = 1, j2g2 = 1;
    int acao, alvo, pcao;

turno_jogador1:
    printf("\n--- GOUSMAS WAR ---\n");
    printf("Jogador 1:\n");
    printf("G1: %d de furia | G2: %d de furia\n", j1g1, j1g2);
    printf("Jogador 2:\n");
    printf("G1: %d de furia | G2: %d de furia\n", j2g1, j2g2);

    printf("\nJogador 1 - Escolha sua acao:\n");
    printf("1) Atacar com G1\n2) Atacar com G2\n3) Dividir G1\n4) Dividir G2\n");
    scanf("%d", &acao);

    if (acao == 1 && j1g1 > 0) {
        printf("Atacar Gousma do Jogador 2:\n1) G1\n2) G2\n");
        scanf("%d", &alvo);
        if (alvo == 1 && j2g1 > 0) j2g1 += j1g1;
        if (alvo == 2 && j2g2 > 0) j2g2 += j1g1;
    } else if (acao == 2 && j1g2 > 0) {
        printf("Atacar Gousma do Jogador 2:\n1) G1\n2) G2\n");
        scanf("%d", &alvo);
        if (alvo == 1 && j2g1 > 0) j2g1 += j1g2;
        if (alvo == 2 && j2g2 > 0) j2g2 += j1g2;
    } else if (acao == 3 && j1g2 == 0 && j1g1 > 1) {
        j1g2 = j1g1 / 2;
        j1g1 = j1g1 - j1g2;
    } else if (acao == 4 && j1g1 == 0 && j1g2 > 1) {
        j1g1 = j1g2 / 2;
        j1g2 = j1g2 - j1g1;
    }

    
    if (j2g1 > 5) j2g1 = 0;
    if (j2g2 > 5) j2g2 = 0;

    if (j2g1 == 0 && j2g2 == 0) {
        printf("\nJogador 1 venceu!\n");
        goto fim;
    }

turno_jogador2:
    printf("\nJogador 2 - Escolha sua acao:\n");
    printf("1) Atacar com G1\n2) Atacar com G2\n3) Dividir G1\n4) Dividir G2\n");
    scanf("%d", &acao);

    if (acao == 1 && j2g1 > 0) {
        printf("Atacar Gousma do Jogador 1:\n1) G1\n2) G2\n");
        scanf("%d", &alvo);
        if (alvo == 1 && j1g1 > 0) j1g1 += j2g1;
        if (alvo == 2 && j1g2 > 0) j1g2 += j2g1;
    } else if (acao == 2 && j2g2 > 0) {
        printf("Atacar Gousma do Jogador 1:\n1) G1\n2) G2\n");
        scanf("%d", &alvo);
        if (alvo == 1 && j1g1 > 0) j1g1 += j2g2;
        if (alvo == 2 && j1g2 > 0) j1g2 += j2g2;
    } else if (acao == 3 && j2g2 == 0 && j2g1 > 1) {
        j2g2 = j2g1 / 2;
        j2g1 = j2g1 - j2g2;
    } else if (acao == 4 && j2g1 == 0 && j2g2 > 1) {
        j2g1 = j2g2 / 2;
        j2g2 = j2g2 - j2g1;
    }

    
    if (j1g1 > 5) j1g1 = 0;
    if (j1g2 > 5) j1g2 = 0;

    if (j1g1 == 0 && j1g2 == 0) {
        printf("\nJogador 2 venceu!\n");
        goto fim;
    }

    goto turno_jogador1;

fim:
    printf("\nDeseja jogar novamente?\n1) Sim\n2) Voltar ao menu\n");
    scanf("%d", &pcao);
    if (pcao == 1) goto inicio4;
    else goto inicio;
}


	return 0;
}
