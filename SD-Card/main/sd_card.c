#include "stdio.h"
#include "sdmmc_cmd.h"
#include "esp_vfs_fat.h"
#include "esp_log.h"
#include "dirent.h"
#include <sys/unistd.h>
#include "sd_card.h"

/**
 * @brief Inicia e faz a montagem do SD Card
 * @return ESP_OK no êxito.
*/
esp_err_t sdcard_init(void)
{
    esp_err_t ret;

    /* Montagem do cartão SD */
    esp_vfs_fat_sdmmc_mount_config_t mount_config = {
        .format_if_mount_failed = true,     // Caso ocorra falha a partição será formatada
        .max_files = 5,                     // Numéro maximo de arquivos simultâneos
        .allocation_unit_size = 16 * 1024}; // Tamanho da partição

    sdmmc_card_t *card;
    const char mount_point[] = "/sdcard";

    sdmmc_host_t host = SDSPI_HOST_DEFAULT();
    host.max_freq_khz = 5000;

    spi_bus_config_t bus_cfg = {
        .mosi_io_num = PIN_NUM_MOSI,
        .miso_io_num = PIN_NUM_MISO,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 4000,
    };
    ret = spi_bus_initialize(host.slot, &bus_cfg, 1);
    if (ret != ESP_OK)
    {
        ESP_LOGE(TAG, "SD Card ja Inicializado");
        return ret;
    }

    sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
    slot_config.gpio_cs = PIN_NUM_CS;
    slot_config.host_id = host.slot;

    ret = esp_vfs_fat_sdspi_mount(mount_point, &host, &slot_config, &mount_config, &card);

    if (ret != ESP_OK)
    {
        if (ret == ESP_FAIL)
        {
            ESP_LOGE(TAG, "Falha ao montar o sistema de arquivos."
                          "If you want the card to be formatted, set the EXAMPLE_FORMAT_IF_MOUNT_FAILED menuconfig option.");
        }
        else
        {
            ESP_LOGE(TAG, "(%s)\n"
                          "Falha na inicialização\n"
                          "Certifique-se de que o cartão está no slot\n"
                          "E que as linhas do cartão SD tenham resistores de pull-up.",
                     esp_err_to_name(ret));
        }
        return ret;
    }
    sdmmc_card_print_info(stdout, card); // Informações do SD Card
    
    ESP_LOGI(TAG, "SD Card foi iniciado com sucesso");
    return ret;
}

/**
 * @brief Lista todos os arquivos do SD Card
 * @return Arquivos encontrados.
*/
void sdcard_list()
{
    ESP_LOGI(TAG, "\x1b[34mListando arquivos");
    DIR *dir;
    struct dirent *lsdir;
    dir = opendir("/sdcard");
    if ((lsdir = readdir(dir)) != NULL)
    {
        rewinddir(dir);
        while ((lsdir = readdir(dir)) != NULL)
        {
            ESP_LOGI(TAG, "\x1b[37;4m%s", lsdir->d_name);
            vTaskDelay(pdMS_TO_TICKS(200));
        }
    }
    closedir(dir);
}

/**
 * @brief Escreve em um arquivo.
*/
void sdcard_write()
{
    ESP_LOGI(TAG, "\x1b[34mEscrevendo no arquivo");
    // Abre para escrita o arquivo informado caso ele não exista será criado
    FILE *f = fopen(ARQUIVO, "w");
    if (f == NULL)
    {
        ESP_LOGE(TAG, "Falha na abertura do arquivo para a escrita");
        return;
    }

    // Faz a escrita no arquivo aberto
    fprintf(f, "Olá Mundo!");

    // Fecha o arquivo para evitar bugs e liberar memória
    fclose(f);
    return;
}

/**
 * @brief Exibe oque tem dentro de um arquivo.
*/
void sdcard_read()
{
    ESP_LOGI(TAG, "\x1b[34mLendo arquivo");
    /*  Abre o log Principal para leitura.  */
    FILE *arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao tentar abrir arquivo_binario.bin.\n");
        return;
    }

    char line[50];
    while (fgets(line, sizeof(line), arquivo) != NULL)
    {
        ESP_LOGI(TAG, "\x1b[37;4m%s", line);
    }
    fclose(arquivo);
    return;
}

/**
 * @brief Formata todos os arquivos do SD Card
 * @return Arquivos que foram apagados.
*/
void sdcard_format()
{
    ESP_LOGI(TAG, "\x1b[31;1mFormatando SD card");
    char dirDoArquivo[300];
    DIR *dir;
    struct dirent *lsdir;
    dir = opendir("/sdcard");
    if ((lsdir = readdir(dir)) != NULL)
    {
        rewinddir(dir);
        while ((lsdir = readdir(dir)) != NULL)
        {
            ESP_LOGI(TAG, "\x1b[37;4m%s", lsdir->d_name);
            sprintf(dirDoArquivo, "/sdcard/%s", lsdir->d_name);
            unlink(dirDoArquivo);
            vTaskDelay(pdMS_TO_TICKS(200));
        }
    }
    closedir(dir);
}
