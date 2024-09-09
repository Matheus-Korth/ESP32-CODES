#include <stdio.h>
#include "freertos/FreeRTOS.h" /* Cabeçalho principal para utilizar FreeRTOS no ESP-IDF */
#include "freertos/Task.h"     /* Cabeçalho especifico para tarefas */

/* Tarefa a ser criada. */
void vTaskCode(void *pvParameters)
{
    for (;;)
    {
        /* Código da tafera */

        /* Passando NULL como parâmetro, a tarefa que faz a chamada é deletada */
        vTaskDelete(NULL);
    }
}

void app_main(void)
{
    /* Cria a tarefa, armazenando o identificador. */
    BaseType_t xReturned = xTaskCreate(vTaskCode, "NAME", 2048, NULL, 1, NULL);
    if (xReturned == pdPASS)
    {
        /* Tarefa criada com sucesso */
    }
    else
    {
        /* Falha ao criar tarefa */
    }
}
