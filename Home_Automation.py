import RPi.GPIO as GPIO
import bluetooth

Light = 13
Fan = 19
Tv = 26
GPIO.setmode(GPIO.BCM)
GPIO.setup(Light, GPIO.OUT)
GPIO.setup(Fan, GPIO.OUT)
GPIO.setup(Tv, GPIO.OUT)
GPIO.output(Light, 0)
GPIO.output(Fan, 0)
GPIO.output(Tv, 0)
server_socket = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
port = 1
server_socket.bind(("", port))
server_socket.listen(1)

client_socket, address = server_socket.accept()
print
"Accepted connection from ", address


def Light_ON():
    GPIO.output(Light, 1)


def Light_OFF():
    GPIO.output(Light, 0)


def Fan_ON():
    print
    "FAN ON"
    GPIO.output(Fan, 1)


def Fan_OFF():
    GPIO.output(Fan, 0)


def Tv_ON():
    GPIO.output(Tv, 1)


def Tv_OFF():
    GPIO.output(Tv, 0)


def ALL_ON():
    GPIO.output(Light, 1)
    GPIO.output(Fan, 1)
    GPIO.output(Tv, 1)


def ALL_OFF():
    GPIO.output(Light, 0)
    GPIO.output(Fan, 0)
    GPIO.output(Tv, 0)


data = ""
while 1:
    data = client_socket.recv(1024)
    print
    "Received: %s" % data
    if (data == "A"):
        Light_ON()
    elif (data == "B"):
        Light_OFF()
    elif (data == "C"):
        print
        "c.........."
        Fan_ON()
    elif (data == "D"):
        Fan_OFF()
    elif (data == "E"):
        Tv_ON()
    elif (data == "F"):
        Tv_OFF()
    elif data == "G":
        ALL_ON()
    elif (data == "H"):
        ALL_OFF()
client_socket.close()
server_socket.close()
