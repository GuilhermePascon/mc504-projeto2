#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX_ITEM 10
#define MIN_ITEM 0
#define INTERATIONS 100

// Paulo Henrique da Fonseca 138995
// Raniery Rodrigues da silva 223849
// Guilherme Henrique Pascon 235980

sem_t mutex;
int patins = 0;
int maxPatins = 10;
int totalProduzidos;
int totalVendidos;

pthread_t threads1, threads2;

void imprimir()
{
    printf(" PRATELEIRA DE PATINS:\n");
    printf("┌─────────────────────┐\n");
    printf("│                     │\n");
    for (int i = 0; i < totalProduzidos - totalVendidos; i++)
    {
        printf("│    ┌────┐           │     \n");
        printf("│    └┼┼┼┼┘           │     \n");
        printf("│     │┼┼│            │    \n");
        printf("│     │┼┼┼────┐       │         \n");
        printf("│     ├───────┴─┐     │           \n");
        printf("│     │         │     │           \n");
        printf("│     └─────────┘     │           \n");
        printf("│      @   @    @     │           \n");
        printf("├─────────────────────┤\n");
    }
    printf("│                     │\n");
    printf("└─────────────────────┘\n");

    printf("┌─┬────────────────────────────────────────────────────────────────────┬─┐\n");
    printf("│ ├────────────────────────────────────────────────────────────────────┤ │\n");
    printf("│ │   QUANTIDADE TOTAL PRODUZIDOS    QUANTIDADE TOTAL VENDIDOS         │ │\n");
    printf("│ ├──┬───────────────────────────┬─────────────────────────────────────┤ │\n");
    printf("│ │  │                           │                                     │ │\n");
    printf("│ │  │             %03d           │                  %03d                │ │\n", totalProduzidos, totalVendidos);
    printf("│ │  │                           │                                     │ │\n");
    printf("│ ├──┴───────────────────────────┴─────────────────────────────────────┤ │\n");
    printf("└─┴────────────────────────────────────────────────────────────────────┴─┘\n");
}

void *produzirPatins()
{
    int j;
    for (int i = 0; i <= INTERATIONS; i++)
    {
        sem_wait(&mutex);
        if (patins < maxPatins)
        {
            patins++;
            totalProduzidos++;
        }
        imprimir();
        sem_post(&mutex);

        sleep(2);
    }
}

void *pegarPatins()
{
    for (int i = 0; i <= INTERATIONS; i++)
    {
        sem_wait(&mutex);
        if (patins > 0)
        {
            patins--;
            totalVendidos++;
        }
        imprimir();
        sem_post(&mutex);

        sleep(3);
    }
}

int main()
{
    sem_init(&mutex, 0, 1);
    int i = 0;
    pthread_create(&threads1, NULL, produzirPatins, NULL);
    pthread_create(&threads2, NULL, pegarPatins, NULL);
    pthread_join(threads1, NULL);
    pthread_join(threads2, NULL);

    return 0;
}