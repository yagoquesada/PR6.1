#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

File myFile;

void setup(){

Serial.begin(9600);
Serial.print("Iniciando SD ...");

SPI.begin(18,19,23,4);

if(! SD.begin(4)){
  Serial.println("No se pudo inicializar");
  return;
}
  
Serial.println("inicializacion exitosa");

// Escribimos en el fichero
myFile = SD.open("/archivo.txt",FILE_WRITE); 
myFile.println("Hola mundo!!");
myFile.close();

myFile=SD.open("/archivo.txt"); //Abrimos, mostramos y leemos
  if (myFile) {
    Serial.println("archivo.txt:");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close(); 
  }
  
  else {
    Serial.println("Error al abrir el archivo");
  }
}

void loop(){}