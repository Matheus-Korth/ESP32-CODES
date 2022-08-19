# SD CARD
__Bibliotéca para utilização SD Card - ESP32__


# Componentes e ligações
<table>
<thead>
  <tr>
    <td colspan="1" align="center"><img src="https://cdn.awsli.com.br/1000x1000/468/468162/produto/103347624/9ef0318f0a.jpg" width="150"></td>
    <td colspan="1" align="center"><img src="https://cdn.awsli.com.br/600x700/95/95881/produto/94057618/059e114f7f.jpg" width="200"></td>
    <td colspan="1" align="center"><img src="https://www.baudaeletronica.com.br/media/catalog/product/cache/1/image/9df78eab33525d08d6e5fb8d27136e95/1/0/10k.png" width="200"></td>
  </tr>
    <th align="center"> ESP32 DevKitC </th>
    <th align="center"> Módulo Micro SD</th>
    <th align="center">Resistor 10k Ω</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td align="center">GPIO 5</td> 
    <td align="center">CS</td>
    <td align="center">Pull UP</td>
  </tr>
    <tr>
    <td align="center">GPIO 18</td>
    <td align="center">SCK</td>
    <td align="center">Pull UP</td>
  </tr>
    <tr>
    <td align="center">GPIO 19</td>
    <td align="center">MISO</td>
    <td align="center">Pull UP</td>
  </tr>
  <tr>
    <td align="center">GPIO 23</td>
    <td align="center">MOSI</td>
    <td align="center">Pull UP</td>
  </tr>
  <tr>
    <td align="center">5v</td>
    <td align="center">VCC</td>
    <td align="center"> - </td>
  </tr>
    <tr>
    <td align="center">GND</td>
    <td align="center">GND</td>
    <td align="center"> - </td>
  </tr>
</tbody>
</table>

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