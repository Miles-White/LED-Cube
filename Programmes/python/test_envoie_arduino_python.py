import serial
arduinoData = serial.Serial('COM10',9600)

def led_on():
    arduinoData.write('1')
    
def led_off():
    arduinoData.write('0')
    
t=0
while(t<2000):
    if(t % 10 ==0):
        print(t)
    t+=1
led_on()
print("done")