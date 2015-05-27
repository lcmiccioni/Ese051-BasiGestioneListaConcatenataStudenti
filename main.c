#include <stdio.h>
#include <stdlib.h>

#define MAX_STRLEN 30
#define MAX_CLASSLEN 4

struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    char classe[MAX_CLASSLEN+1];
    int eta;
};

typedef struct s_studente studente;

struct s_elemento {
    studente value;
    struct s_elemento *next;
};

typedef struct s_elemento elemento;

elemento* inputStudenti(elemento* primo, studente s);
void outputStudenti(elemento* primo);
void vuotaLista(elemento* primo);

int main(int argc, char** argv) {
    studente s;
    elemento* primo = NULL;
    int scelta = 1;
    
    while(scelta!=0) {
        printf("Inserisci il nome: ");
        scanf("\n%[^\n]", s.nome);
        printf("Inserisci il cognome: ");
        scanf("\n%[^\n]", s.cognome);
        printf("Inserisci la classe: ");
        scanf("%s", s.classe);
        printf("Inserisci l'eta': ");
        scanf("%d", &(s.eta));
        
        primo = inputStudenti(primo, s);
        if(primo == NULL) {
            fprintf(stderr, "Impossibile allocare la memoria richiesta");
            exit(1);
        }
        printf("Vuoi inserire un altro studente? (0.no, 1.si)");
        scanf("%d", &scelta);
    }
    
    outputStudenti(primo);
    vuotaLista(primo);
    
    return (EXIT_SUCCESS);
}

elemento* inputStudenti(elemento* primo, studente s) {
    elemento* nuovoElemento;
    
    nuovoElemento = (elemento*) malloc(sizeof(elemento));
    if(nuovoElemento!=NULL) {
        nuovoElemento->value = s;
        nuovoElemento->next = primo;
    }
    primo = nuovoElemento;
    
    return primo;
}

void outputStudenti(elemento* primo) {
    printf("Stampa studenti: \n");
    elemento *current;
    current = primo;
    while(current!=NULL){
        printf("\nNome: %s\nCognome: %s\nClasse: %s\nEta': %d\n",
                current->value.nome,
                current->value.cognome, 
                current->value.classe,
                current->value.eta);
        current = current->next;
    }
    return;
}

void vuotaLista(elemento* primo) {
    elemento *temp;
    while(primo!=NULL) {
        temp = primo;
        primo = primo->next;
        free(temp);
    }
    return;
}