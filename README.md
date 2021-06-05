# PRÁCTICA 6.1: LECTURA/ESCRITURA DE MEMORIA SD

## CÓDIGO

```ruby
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
```

## FUNCIONAMENTO

Primero incluimos las siguientes tres librerías, la segunda nos permite comunicarnos con los dispositivos SPI y la librería SD nos permite leer y escribir en tarjetas SD:

```ruby
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
```

Después empieza el `void setup()`, este en la primera línea inicializa una comunicación en serie a una velocidad de 9600 bauds, y en la segunda se hace una impresión por pantalla.

```ruby
Serial.begin(9600);
Serial.print("Iniciando SD ...");
```

A continuación tenemos que indicar los pines de conexión para el bus SPI.

```ruby
SPI.begin(18,19,23,4);
```
Aqui creamos un *if* donde si no se inicia la función `SD.begin()` en el pin 4, se imprime por pantalla "No se pudo inicializar".

```ruby
if (!SD.begin(4)) {
    Serial.println("No se pudo inicializar");
    return;
  }
```

En la siguiente línea imprimimos lo siguiente:

```ruby
Serial.println("inicializacion exitosa");
```

Después abrimos un archivo con `SD.open()`. En caso de que no exista el fichero, el parámetro `FILE_WRITE` permite que se cree el archivo y se abra immediatamente.

```ruby
myFile = SD.open("/archivo.txt",FILE_WRITE);
```

Escribimos algo en este archivo con `myFile.println()` y seguidamente lo cerramos.

```ruby
myFile.println("Hola mundo!!");
myFile.close();
```

Ahora hacemos otro *if* que lo que hace es: si el archivo mencionado anteriormente se ha abierto imprimiremos por pantalla lo que este tenga escrito, esto lo haremos utilizando un `while (myFile.available())`, y al final de todo este *if* cerraremos el archivo con  `myFile.close()`, el código es el siguiente:

```ruby
 if (myFile) {
    Serial.println("archivo.txt:");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close(); 
```

Y para acabar haremos un *else* que cuando no se habrá el archivo impimirá un mensaje por pantalla:

```ruby
else {
    Serial.println("Error al abrir el archivo");
}
```

## SALIDA POR EL TERMINAL

Si no hay ningún error, por el terminal se ve el siguiente texto:

```
Iniciando SD ...sd init ok
inicializacion exitosa
Hola mundo!!
```