import speech_recognition as sr
import os
import playsound
from gtts import gTTS
import pywhatkit
import wikipedia
import pyjokes
import datetime


listner = sr.Recognizer()


def Bixby_Speak(audios):
    tts = gTTS(text=audios, lang='en', slow=False)
    # tts = gTTS(text=audios, lang='en')
    audioF = 'audio.mp3'
    tts.save(audioF)
    playsound.playsound(audioF)
    #print(audios)
    os.remove(audioF)
def record():
    try:
        with sr.Microphone() as source:
            print("Listening.........")
            voice = listner.listen(source)
            command = listner.recognize_google(voice)
            command = command.lower()
            if 'alexa' in command:
                command = command.replace('alexa','')
            return command

    except:
        print("Somthing is wrong !!!!!!!")

def run_alexa():
    command =record()
    if 'play' in command:
        song = command.replace('play','')
        pywhatkit.playonyt(song)
        print(command)
        Bixby_Speak(command)
    elif 'joke' in command:
        joke = pyjokes.get_joke()
        print(joke)
        Bixby_Speak(joke)
    elif 'search' in command :
        command = command.replace('search on','')
        info = wikipedia.summary(command,1)
        print(info)
        Bixby_Speak(info)

    elif 'time' in command:
        date = datetime.datetime.now().strftime('%I:%M %P')
        print(f'the current time is {date}')
        Bixby_Speak("the current time is "+date)



Bixby_Speak('hi i am alexa')
while True:
    run_alexa()
