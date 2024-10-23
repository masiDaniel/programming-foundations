import socket

s = socket.socket()
print("socket created successfully")

port = 40674

s.bind(('', port))
print("socket is binded to %s" %(port))

s.listen(5)
print("socket is listenning ")


while True:

    c, addr = s.accept()
    print("got connection from", addr)

    c.send(b"thank you for connecting")

    c.close()