#include <stdio.h>
#include "freertos/FreeRTOS.h" /* Cabeçalho principal para utilizar FreeRTOS no ESP-IDF */
#include "freertos/Task.h"     /* Cabeçalho especifico para tarefas */

/* Tarefa a ser criada. */
void vTaskCode(void *pvParameters)
{
    for (;;)
    {
        /* O código da tarefa vai aqui. */
    }
}

void app_main(void)
{
    /* Identificador da tarefa  */
    TaskHandle_t xHandle = NULL;

    /* Cria a tarefa, armazenando o identificador. */
    BaseType_t xReturned = xTaskCreate(vTaskCode, "NAME", 2048, NULL, 5, &xHandle);
    if (xReturned == pdPASS)
    {
        /* Tarefa criada com sucesso */
    }
    else
    {
        /* Falha ao criar tarefa */
    }
    
    /* A tarefa foi criada. Use o identificador da tarefa para excluí-la. */
    vTaskDelete(xHandle);
}
