#ifndef SD_CARD_H_
#define SD_CARD_H_

static const char *TAG = "[SD-CARD] --> ";

#define PIN_NUM_MISO GPIO_NUM_19 // Master In Slave Out
#define PIN_NUM_MOSI GPIO_NUM_23 // Master Out Slave In
#define PIN_NUM_CLK GPIO_NUM_18  // Clock
#define PIN_NUM_CS GPIO_NUM_5    // Chip Select

#define ARQUIVO "/sdcard/arquivo.txt"

#include "esp_err.h"

/**
 * @brief Inicia e faz a montagem do SD Card
 * @return ESP_OK no êxito.
*/
esp_err_t sdcard_init();

/**
 * @brief Lista todos os arquivos do SD Card
 * @return Arquivos encontrados.
*/
void sdcard_list();

/**
 * @brief Escreve em um arquivo.
*/
void sdcard_write();

/**
 * @brief Exibe oque tem dentro de um arquivo.
*/
void sdcard_read();

/**
 * @brief Formata todos os arquivos do SD Card
 * @return Arquivos que foram apagados.
*/
void sdcard_format();

#endif