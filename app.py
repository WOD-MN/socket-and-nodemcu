import socket

server_socket = socket.socket()
port = 5055
ip = "192.168.1.67"

server_socket.connect((ip, port))

while True:
    msg = server_socket.recv(3000).decode()
    print(msg)
    
    server_socket.send(input("Your Message? ").encode())