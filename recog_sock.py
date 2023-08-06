from vosk import Model, KaldiRecognizer
import pyaudio

import socket
s = socket.socket()
print('socket created')
s.bind(('localhost',9999))
s.listen(2)
print('waiting for connections')
c,addr = s.accept()
print("Connected with",addr)

model = Model(r"C:\Users\samya\Documents\HALProject\Working_files\vosk-model-en-in-0.5")
recognizer = KaldiRecognizer(model,16000)

mic = pyaudio.PyAudio()
stream = mic.open(format=pyaudio.paInt16, channels=1, rate= 16000, input=True, frames_per_buffer=8192 )
stream.start_stream()

while True:
    data = stream.read(4096)
    # if len(data) == 0;
    # break
    if recognizer.AcceptWaveform(data):
        text = recognizer.Result()
        print(text[14:-3])
        c.send(bytes(text[14:-3],'utf-8'))
        
        
