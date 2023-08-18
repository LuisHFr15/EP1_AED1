#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// elemento da lista
typedef struct estr {

        int valor;
        struct estr* prox;
} NO;



bool buscaOrdenadaSequencial (NO* inicio, NO* *anterior, int valorProcurado) {

    *anterior = NULL;
    NO* noReferencia;
    noReferencia = inicio;

    while (noReferencia != NULL) {
        
        if ((noReferencia -> valor) >= valorProcurado) break;
        
        *anterior    = noReferencia;
        noReferencia = noReferencia -> prox;
    }

    if (noReferencia != NULL) {
        
        if ((noReferencia -> valor) == valorProcurado) return false;
    }
    
    return (true);
}


// inicio = p1 ou p2
void inserirElementos (NO* *inicio, int valorAInserir) {

    NO* anterior;
    NO* noReferencia;
    bool variavelIsca; // apenas serve para implementar a função e alterar o anterior

    variavelIsca = buscaOrdenadaSequencial(*inicio, &anterior, valorAInserir);
    noReferencia = (NO*) malloc(sizeof(NO));
    noReferencia -> valor = valorAInserir;

    // primeiro elemento de todos a ser inserido
    if (*inicio == NULL) {

        noReferencia -> prox  = NULL;
        *inicio = noReferencia;
        // definindo o NO como inicio da lista
        return;
    }

    else if (anterior != NULL) {

        noReferencia -> prox = anterior -> prox;
        anterior -> prox     = noReferencia;
        return;
    }

}


void inserirElementosDistintos (NO* *inicio, int valorAInserir) {

    NO * noAInserir;
    NO * anterior;
    bool podeInserir;

    podeInserir = buscaOrdenadaSequencial (*inicio, &anterior, valorAInserir);

    if (!podeInserir) return;

    noAInserir = (NO *) malloc(sizeof (NO));
    noAInserir -> valor = valorAInserir;

    if (*inicio == NULL) {

        noAInserir -> prox = NULL;
        *inicio = noAInserir;
    }

    else {

        if (!anterior) { // inserção no início da lista

            noAInserir -> prox = *inicio;
            *inicio = noAInserir;
        }

        else { // inserção após um nó existente

            noAInserir -> prox = anterior -> prox;
            anterior -> prox = noAInserir;
        }
    }
}


void exibirLista (NO* inicio) {

    NO* noDoPrint;
    noDoPrint = inicio;

    while (noDoPrint) {

        printf("%d ", (noDoPrint -> valor));
        noDoPrint = noDoPrint -> prox;
    }
}


NO* uniao(NO* p1, NO* p2);


NO* uniao(NO* p1, NO* p2) {

	NO* resp = NULL;

    while (p1 != NULL) {
        
        inserirElementosDistintos(&resp, (p1 -> valor));
        p1 = p1 -> prox;
    }

    while (p2 != NULL) {
        
        inserirElementosDistintos(&resp, (p2 -> valor));
        p2 = p2 -> prox;
    }

	return resp;
}


int main() {
    
}
