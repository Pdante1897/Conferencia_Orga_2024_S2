#import threading
import serial
import time

# Configura el puerto serial para que coincida con la configuración mostrada en tu monitor serial.
ser = serial.Serial('COM1', 9600)
time.sleep(2)  # Espera a que se establezca la conexión serial

def toggle_led(command):
    """
    Envia el comando al Arduino para controlar el LED.
    '1, 2 o 3' para encender, 'o' para apagar.
    """
    ser.write(command.encode())  # Envía el comando al Arduino

# Función que lee el puerto serial
def read_serial():
    """
    Lee el puerto serial y retorna True si se presionó el botón.
    """
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').rstrip()
        print(line)
        return True
    return False

try:
    print("Esperando a que presione el botón Para iniciar...")
    
    # Espera a que se presione el botón en el Arduino
    while not read_serial():
        pass

    print("Se presionó el botón. Ahora puedes ingresar la numero.")

    while True:
        cmd = input("Ingrese '1' para encender el LED1, '2' encender el LED2, '3' encender ambos leds  o 'o' para apagarlos(Ingrese 'salir' para terminar): ")
        if cmd in ['1', '2', '3', 'o']:
            toggle_led(cmd)
            ser.flush()
            print("Esperando a que presione el botón...")
            # Espera a que se presione el botón en el Arduino antes de continuar
            while not read_serial():
                pass
            print("Se presionó el botón. Ahora puedes ingresar la letra.")

        elif cmd == 'salir':
            print("Saliendo...")
            break
        else:
            print("Comando no reconocido. Intente nuevamente.")
finally:
    ser.close()  # Cierre de conexión con el Arduino
    print("Conexión serial cerrada.")
