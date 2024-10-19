int led = 13; // Define el pin del LED en el pin 13
int led2 = 12; // Define el pin del LED en el pin 13

char DATO;

void setup() {
  Serial1.begin(9600); // Inicializa la comunicación serial en el puerto Serial1 a 9600 bps
  Serial1.println("Bienvenido");
  pinMode(led, OUTPUT); // Configura el pin del LED como salida
  pinMode(led2, OUTPUT); // Configura el pin del LED como salida
  pinMode(11, INPUT); // Configura el pin 11 como entrada
}

void loop() {
  //envia un mensaje por el puerto serial si se presiono el boton
  if (digitalRead(11) == HIGH) {
    Serial1.println("Boton presionado");
    //limpia el estado del boton
    digitalWrite(11, LOW);
    //espera un segundo para evitar el rebote
    delay(1000);
  }
  if (Serial1.available() > 0) { // Verifica si hay datos disponibles en el puerto serial Serial1
    //ss
    DATO = Serial1.read(); // Lee el dato recibido
    Serial1.println(DATO);
    if (DATO == '1') { // Si el dato es 'A'
      digitalWrite(led, HIGH); // Enciende el LED
      digitalWrite(led2, LOW); // Enciende el LED

      Serial1.println("LED1 on"); // Envía un mensaje por el puerto serial Serial1

    }
    if (DATO == '2') { // Si el dato es 'a'
      digitalWrite(led, LOW); // Apaga el LED
      digitalWrite(led2, HIGH); // Enciende el LED
      Serial1.println("LED2 on"); // Envía un mensaje por el puerto serial Serial1
    }
    if (DATO == '3') { // Si el dato es 'B'
      digitalWrite(led, HIGH); // Enciende el LED
      digitalWrite(led2, HIGH); // Enciende el LED
      Serial1.println("LED1 y LED2 on"); // Envía un mensaje por el puerto serial Serial1
    }
    if (DATO == 'o') { // Si el dato es 'B'
      digitalWrite(led, LOW); // Apaga el LED
      digitalWrite(led2, LOW); // Apaga el LED
      Serial1.println("LED1 y LED2 off"); // Envía un mensaje por el puerto serial Serial1
    }
    delay(1000);
  }
}