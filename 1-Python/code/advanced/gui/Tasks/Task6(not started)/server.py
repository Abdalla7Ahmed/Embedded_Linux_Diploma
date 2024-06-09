#!/usr/bin/python    

#https://www.dunebook.com/creating-a-python-socket-server-with-multiple-clients/



import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ip = socket.gethostbyname(socket.gethostname())
print("your ip is ", ip)
server.bind((ip,5000))
server.listen(5)


while True:
    client , address = server.accept()
    rodata = client.recv(1024)
    print(f"{address} is sending to you this message {rodata.decode('UTF-8')}")
    msg = input("please Enter your message to send : ")
    msg_encoded = msg.encode('UTF-8')
    client.send(msg_encoded)
    client.close()
