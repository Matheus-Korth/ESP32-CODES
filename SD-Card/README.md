# SD CARD
__Bibliotéca para utilização SD Card - ESP32__


_`sdcard_init()`_
```
 * @brief Inicia e faz a montagem do SD Card
 * @return ESP_OK no êxito.
```
`sdcard_list();`
```
 * @brief Lista todos os arquivos do SD Card
 * @return Arquivos encontrados.
```
`sdcard_write();`
```
 * @brief Escreve em um arquivo.
```
`sdcard_read();`
```
 * @brief Exibe oque tem dentro de um arquivo.
```
`sdcard_format();`
```
 * @brief Formata todos os arquivos do SD Card
 * @return Arquivos que foram apagados.
```