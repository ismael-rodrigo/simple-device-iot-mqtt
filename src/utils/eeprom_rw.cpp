#include "utils/eeprom_rw.h"

void gravar(int addr, String a) {
  int tamano = a.length(); 
  char inchar[25]; 
  a.toCharArray(inchar, tamano+1);
  for (int i = 0; i < tamano; i++) {
    EEPROM.write(addr+i, inchar[i]);
  }
  for (int i = tamano; i < 25; i++) {
    EEPROM.write(addr+i, 255);
  }
  EEPROM.commit();
}

String ler(int addr) {
   byte lectura;
   String strlectura;
   for (int i = addr; i < addr+25; i++) {
      lectura = EEPROM.read(i);
      if (lectura != 255) {
        strlectura += (char)lectura;
      }
   }
   return strlectura;
}