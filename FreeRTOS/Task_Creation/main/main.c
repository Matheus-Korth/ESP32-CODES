#include <stdio.h>
#include "freertos/FreeRTOS.h" /* Cabeçalho principal para utilizar FreeRTOS no ESP-IDF */
#include "freertos/Task.h"     /* Cabeçalho especifico para tarefas */

/* Identificador da tarefa  */
TaskHandle_t xHandle = NULL;

/* Tarefa a ser criada. */
void vTaskCode(void *pvParameters)
{
    /* Espera-se que o valor do parâmetro seja 10, pois 10 é passado no
    valor pvParameters na chamada para xTaskCreate() abaixo. */
    configASSERT(((uint32_t)pvParameters) == 10);

    for (;;)
    {
        /* Código da tafera */
    }
}

void app_main(void)
{
    /* Cria a tarefa, armazenando o identificador. */
    BaseType_t xReturned = xTaskCreate(vTaskCode, "NAME", 2048, (void *)10, 5, &xHandle);
    if (xReturned == pdPASS)
    {
        /* Tarefa criada com sucesso */
    }
    else
    {
        /* Falha ao criar tarefa */
    }

    /* Deleta a tarefa utilizando seu identificador */
    vTaskDelete(xHandle);
}
