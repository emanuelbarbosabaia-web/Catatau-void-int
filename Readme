# Biblioteca para controlar um visor de 7 segmentos

---

## Comandos

### adicionando a biblioteca

```cpp
#include "visor7seg.h"
```

### Criando instância

```cpp
// Instancia o objeto definindo os pinos de A até G e se é anodo comum (true) ou catodo comum (false)
visor7seg display(pin_A, pin_B, pin_C, pin_D, pin_E, pin_F, pin_G, bool);
```

### Para imprimir um número ou letra

```cpp
write(int num);    // Imprime números de 0 a 9
write(char num);   // Imprime caracteres e letras (A, b, C, d, E, F, H, L, P, U, -)
writeHex(int num);        // Recebe de 0 a 15 e converte de 10 a 15 para as letras de A a F
```

### Configurações de inicialização

```cpp
begin();                  // Configura todos os pinos do visor como saídas (OUTPUT)
pinoPonto(int pin); // Opcional: Configura um pino para controlar o ponto decimal do visor
```

### Controles de estado do visor

```cpp
clear();                  // Apaga completamente todos os segmentos do visor
test();            // Acende absolutamente todos os segmentos para teste de hardware
decimalPoint(bool estado);// Liga (true) ou desliga (false) o ponto decimal de forma independente
```

### Efeitos visuais

```cpp
loadingAnimation(int vel);// Cria uma animação com os segmentos girando na velocidade definida
```
