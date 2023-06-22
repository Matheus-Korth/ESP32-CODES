# __Task Creation__

## __TaskHandle_t__
Tipo pelo qual as taréfas são referêciadas. Por exemplo, ao criar uma taréfa xTaskCreate retorna (através de um parâmetro de ponteiro) uma variável TaskHandle_t que pode ser usado como um parâmetro para vTaskDelete para excluir a tarefa.


## __xTaskCreate__
``` C
  BaseType_t xTaskCreate( TaskFunction_t pvTaskCode,
                          const char * const pcName,
                          configSTACK_DEPTH_TYPE  usStackDepth,
                          void *pvParameters,
                          UBaseType_t uxPriority,
                          TaskHandle_t *pxCreatedTask
                          );
```
Crie uma nova tarefa e adicione-a à lista de tarefas prontas para execução.

__Parêmetros__:
* __pvTaskCode__ - Ponteiro para a função de entrada de tarefa  
* __pcName__ - Um nome descritivo para a tarefa  
* __usStackDepth__ - Tamanho da pilha que será alocada em palavras
* __pvParameters__ - Um valor que é passado como parâmetro para a tarefa
* __uxPriority__ - A prioridade na qual a tarefa criada será executada
* __pxCreatedTask__ - Usado para passar um identificador para a tarefa  

__Retorno__:  
* Se a tarefa foi criada com sucesso, __pdPASS__ é retornado. 
* Caso contrário, __errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY__ é retornado.