#include <stdio.h>
#include <pthread.h>

#define N 10000

struct params { char c; int n; };

void *char_print(void *p){
    struct params *par = (struct params *) p; // Cast del puntatore
    for(int i = 0; i < par->n; i++) printf("%c", par->c); // Stampa del carattere
    return NULL;
}

int main(){
    pthread_t tid1, tid2, tid3, tid4, tid5;
    struct params par1 = {'a', N}, par2 = {'e', N}, par3 = {'i', N}, par4 = {'o', N}, par5 = {'u', N};

    // Creazione dei thread
    pthread_create(&tid1, NULL, &char_print, &par1);
    pthread_create(&tid2, NULL, &char_print, &par2);
    pthread_create(&tid3, NULL, &char_print, &par3);
    pthread_create(&tid4, NULL, &char_print, &par4);
    pthread_create(&tid5, NULL, &char_print, &par5);
    getchar(); // Pausa forzata

    // Attesa della terminazione dei thread
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    pthread_join(tid5, NULL);

    // Stampa di conferma
    printf("\nTutti i thread hanno terminato l'esecuzione.\n");

    return 0;
}
