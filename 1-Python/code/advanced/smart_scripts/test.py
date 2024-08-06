import speech_recognition as sr

listner = sr.Recognizer()


if True:
    with sr.Microphone() as source:
        print("Listening.........")
        voice = listner.listen(source)
        command = listner.recognize_google(voice)
        print(command)


