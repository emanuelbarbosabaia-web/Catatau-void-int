#ifndef VISOR7SEG_H
#define VISOR7SEG_H

#include <Arduino.h>

class visor7seg {
  private:
    int _pinos[7];   
    bool _tipo;     // anodo (true) ou catodo (false)
    int _pinoPonto = -1;   

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
    //{a,b,c,d,e,f,g}
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
  
visor7seg (int a, int b, int c, int d, int e, int f, int g, bool tipo = true);

void write(int n);
void write(char n);
void writeHex(int n);

void begin();
void pinoPonto(int _pinoPonto);
void clear();
void teste();
void decimalPoint(bool estado);
void loadingAnimation(int vel);

};

#endif
