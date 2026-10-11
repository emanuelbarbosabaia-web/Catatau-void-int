#include "visor7seg.h"

visor7seg::visor7seg(int a, int b, int c, int d, int e, int f, int g, bool tipo) {
    //definido pinos
        _pinos[0] = a;
        _pinos[1] = b;
        _pinos[2] = c;
        _pinos[3] = d;
        _pinos[4] = e;
        _pinos[5] = f;
        _pinos[6] = g;

    _tipo = tipo; 
    _pinoPonto = -1; // não é um decimal valido, logo também não é um pino
}

void visor7seg::pinoPonto(int i){
    _pinoPonto = i;    
}
void visor7seg::begin(){
    for (int i = 0; i < 7; i++){
        pinMode(_pinos[i], OUTPUT);
    }
    if (_pinoPonto != -1){
        pinMode(_pinoPonto, OUTPUT);
    }
}
void visor7seg::clear(){ // aqui serve para desativar os pinos com base se eles estiverem em LOW, colocando no HIGH, e um else caso for o contrario.
    for (int i = 0; i < 7; i++) {
        if (_tipo == false) {
            digitalWrite(_pinos[i], 0);
        }
        else {
            digitalWrite(_pinos[i], 1);
        }
    }
}
void visor7seg::teste(){ // aqui ele acende os pinos com base na mesma logica do clear, só que ao contrario.
     for (int i = 0; i < 7; i++) {
        if (_tipo == false) {
            digitalWrite(_pinos[i], 1);
        }
        else {
            digitalWrite(_pinos[i], 0);
        }
    }
}
void visor7seg::decimalPoint(bool i){
   if (i == true) digitalWrite(_pinoPonto, _tipo == false ? 1 : 0);
   else digitalWrite(_pinoPonto, _tipo == false ? 0 : 1);
}
void visor7seg::loadingAnimation(int v){
  for (int i = 0; i < 6; i++){
    if (_tipo == false) {
            digitalWrite(_pinos[i], 1);
                delay(v);
        }
        else {
            digitalWrite(_pinos[i], 0);
                delay(v);
        }
    }
                delay(v);
    for (int i = 0; i < 6; i++){
    if (_tipo == false) {
            digitalWrite(_pinos[i], 0);
                delay(v);
        }
        else {
            digitalWrite(_pinos[i], 1);
                delay(v);
        }
    }
}

void visor7seg::write(int n){
    if (n < 0 || n > 9) return;
    
            switch (n)
    {
    case 0: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[0][i]:!_numeros[0][i]); break;
    case 1: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[1][i]:!_numeros[1][i]); break;
    case 2: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[2][i]:!_numeros[2][i]); break;
    case 3: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[3][i]:!_numeros[3][i]); break;
    case 4: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[4][i]:!_numeros[4][i]); break;
    case 5: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[5][i]:!_numeros[5][i]); break;
    case 6: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[6][i]:!_numeros[6][i]); break;
    case 7: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[7][i]:!_numeros[7][i]); break;
    case 8: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[8][i]:!_numeros[8][i]); break;
    case 9: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[9][i]:!_numeros[9][i]); break; 
    default:
        break;
    }
}
void visor7seg::write(char n){
    
        switch (n)
    {
    case 'a': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[0][i]:!_letras[0][i]); break;
        case 'A': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[0][i]:!_letras[0][i]); break;
    case 'b': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[1][i]:!_letras[1][i]); break;
        case 'B': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[1][i]:!_letras[1][i]); break;    
    case 'c': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[2][i]:!_letras[2][i]); break;
        case 'C': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[2][i]:!_letras[2][i]); break;    
    case 'd': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[3][i]:!_letras[3][i]); break;
        case 'D': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[3][i]:!_letras[3][i]); break;
    case 'e': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[4][i]:!_letras[4][i]); break;
        case 'E': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[4][i]:!_letras[4][i]); break;
    case 'f': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[5][i]:!_letras[5][i]); break;
        case 'F': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[5][i]:!_letras[5][i]); break;    
    case 'h': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[6][i]:!_letras[6][i]); break;
        case 'H': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[6][i]:!_letras[6][i]); break;
    case 'l': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[7][i]:!_letras[7][i]); break;
        case 'L': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[7][i]:!_letras[7][i]); break;
    case 'p': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[8][i]:!_letras[8][i]); break;
        case 'P': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[8][i]:!_letras[8][i]); break;
    case 'u': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[9][i]:!_letras[9][i]); break;
        case 'U': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[9][i]:!_letras[9][i]); break;
    case '-': for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[10][i]:!_letras[10][i]); break;
    default:
        break;
    }
}

void visor7seg::writeHex(int n){
        if (n < 0 || n > 15) return;

            switch (n)
    {
    case 0: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[0][i]:!_numeros[0][i]); break;
    case 1: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[1][i]:!_numeros[1][i]); break;
    case 2: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[2][i]:!_numeros[2][i]); break;
    case 3: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[3][i]:!_numeros[3][i]); break;
    case 4: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[4][i]:!_numeros[4][i]); break;
    case 5: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[5][i]:!_numeros[5][i]); break;
    case 6: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[6][i]:!_numeros[6][i]); break;
    case 7: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[7][i]:!_numeros[7][i]); break;
    case 8: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[8][i]:!_numeros[8][i]); break;
    case 9: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _numeros[9][i]:!_numeros[9][i]); break; 
    case 10: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[0][i]:!_letras[0][i]); break;
    case 11: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[1][i]:!_letras[1][i]); break;
    case 12: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[2][i]:!_letras[2][i]); break;
    case 13: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[3][i]:!_letras[3][i]); break;
    case 14: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[4][i]:!_letras[4][i]); break;
    case 15: for (int i = 0; i < 7; i++) digitalWrite(_pinos[i],_tipo == false ? _letras[5][i]:!_letras[5][i]); break;
    default:
        break;
    }
}


