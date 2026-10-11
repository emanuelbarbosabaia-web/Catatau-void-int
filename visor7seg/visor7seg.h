#ifndef VISOR7SEG_H
#define VISOR7SEG_H

#include <Arduino.h>

class visor7seg {
  private:
    int _pinos[7];         // Armazena os pinos de A até G
    bool _tipo;            // true para Anodo Comum, false para Catodo Comum
    int _pinoPonto = -1;   // Armazena o pino do ponto decimal (-1 significa desativado)

    const byte _numeros[10][7] = {
      {1,1,1,1,1,1,0}, // 0
      {0,1,1,0,0,0,0}, // 1
      {1,1,0,1,1,0,1}, // 2
      {1,1,1,1,0,0,1}, // 3
      {0,1,1,0,0,1,1}, // 4
      {1,0,1,1,0,1,1}, // 5
      {1,0,1,1,1,1,1}, // 6
      {1,1,1,0,0,0,0}, // 7
      {1,1,1,1,1,1,1}, // 8
      {1,1,1,1,0,1,1}  // 9
    };
    const byte _letras[11][7] = {
      {1,1,1,0,1,1,1}, // A
      {0,0,1,1,1,1,1}, // b
      {1,0,0,1,1,1,0}, // c
      {0,1,1,1,1,0,1}, // d
      {1,0,0,1,1,1,1}, // E
      {1,0,0,0,1,1,1}, // F
      {0,1,1,0,1,1,1}, // H
      {0,0,0,1,1,1,0}, // L
      {1,1,0,0,1,1,1}, // P
      {0,1,1,1,1,1,0}, // U
      {0,0,0,0,0,0,1}  // -
    };

  public:
    /**
     * @brief Construtor do visor de 7 segmentos. Define a ordem dos pinos (A até G) e o tipo do visor.
     * @param tipo true para Anodo Comum (VCC), false para Catodo Comum (GND). Padrão é true.
     */
    visor7seg(int a, int b, int c, int d, int e, int f, int g, bool tipo = true);

    /**
     * @brief Inicializa os pinos configurados no visor como saídas (OUTPUT). Deve ser chamado no setup().
     */
    void begin();

    /**
     * @brief Define qual pino será utilizado para controlar o ponto decimal (Opcional).
     */
    void pinoPonto(int pino);

    /**
     * @brief Imprime um número inteiro de 0 a 9 no visor.
     */
    void write(int n);

    /**
     * @brief Imprime um caractere/letra suportada (A, b, C, d, E, F, H, L, P, U ou -).
     */
    void write(char n);

    /**
     * @brief Recebe um valor de 0 a 15 e exibe em formato Hexadecimal (0-9 e A-F).
     */
    void writeHex(int n);

    /**
     * @brief Limpa o visor, apagando todos os segmentos de forma segura de acordo com o tipo do display.
     */
    void clear();

    /**
     * @brief Acende absolutamente todos os segmentos para teste de hardware.
     */
    void teste();

    /**
     * @brief Liga ou desliga o ponto decimal de forma independente.
     * @param estado true para ligar, false para desligar.
     */
    void decimalPoint(bool estado);

    /**
     * @brief Cria um efeito visual de carregamento com os segmentos girando na velocidade definida.
     * @param vel Tempo de atraso (delay) em milissegundos para cada passo da animação.
     */
    void loadingAnimation(int vel);
};

#endif
