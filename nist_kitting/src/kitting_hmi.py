#!/usr/bin/python

import sys, getopt, socket, time, threading
from Tkinter import *
from tkFileDialog import askopenfilename

PORT = 0
HOST = "localhost"
DEBUG = False

try:
    opts, args = getopt.getopt(sys.argv[1:], "p:h:d", ["port=", "host="])
except getopt.GetoptError, err:
    print "kitting_hmi:", str(err)
    sys.exit(1)

for o, a in opts:
    if o in ("-p", "--port"):
        PORT = a
    elif o in ("-h", "--host"):
        HOST = a
    elif o in ("-d"):
        DEBUG = True

if DEBUG:
    print "kitting_hmi: port:", PORT
    print "kitting_hmi: host:", HOST
    
class App:
    MSG_LEN = 1000
    PERIOD = 5
    HOST = "localhost"
    PORT = 6066

    def __init__(self, master):
        #
        self.connected = False
        self.nameVar = StringVar()
        self.portVar = StringVar()
        self.kitVar = StringVar()
        self.cmdVar = StringVar()
        self.statusVar = StringVar()
        self.hbVar = StringVar()
        self.diagsVar = StringVar()
        #
        self.nameVar.set(self.HOST)
        self.portVar.set(str(self.PORT))
        self.kitVar.set("kit.kit")
        self.cmdVar.set("(none)")
        self.statusVar.set("(none)")
        self.hbVar.set("0")
        self.diagsVar.set("")

        #
        Label(master, text="Host").grid(row=0,column=0,columnspan=2)
        # #
        Label(master, text="Name:").grid(row=1,column=0)
        Entry(master, textvariable=self.nameVar).grid(row=1,column=1)
        # #
        Label(master, text="Port:").grid(row=2,column=0)
        Entry(master, textvariable=self.portVar).grid(row=2,column=1)
        # #
        Button(master, text="Connect", command=self.connect).grid(row=3,column=0)
        Button(master, text="Disconnect", command=self.disconnect).grid(row=3,column=1)

        #
        Label(master, text="Kit").grid(row=0, column=2, columnspan=2)
        # #
        Label(master, text="Name:").grid(row=1, column=2)
        Entry(master, textvariable=self.kitVar).grid(row=1, column=3)
        # #
        Button(master, text="Browse...", command=self.browse).grid(row=3,column=2)
        Button(master, text="Make", command=self.make).grid(row=3,column=3)

        #
        Label(master, text="Status").grid(row=0, column=4, columnspan=2)
        # #
        Label(master, text="Command:").grid(row=1, column=4)
        Entry(master, textvariable=self.cmdVar).grid(row=1, column=5)
        # #
        Label(master, text="Status:").grid(row=2, column=4)
        Entry(master, textvariable=self.statusVar).grid(row=2, column=5)
        # #
        Label(master, text="Heartbeat:").grid(row=3, column=4)
        Entry(master, textvariable=self.hbVar).grid(row=3, column=5)

        #
        Entry(master, textvariable=self.diagsVar).grid(row=4, column=0, columnspan=6, sticky=W+E)

        #
        self.recvThread = threading.Thread(target=self.recvFunc)
        self.recvThread.daemon = True
        self.recvThread.start()

    def disconnect(self):
        try:
            self.sock.close()
            self.sock.shutdown(socket.SHUT_RDWR)
        except IOError as err:
            pass
        self.connected = False
        self.diagsVar.set("Disconnected")

    def connect(self):
        if self.connected == True:
            self.disconnect()
        try:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.sock.connect((self.nameVar.get(), int(self.portVar.get())))
            self.connected = True
            self.diagsVar.set("Connected")
        except IOError as err:
            self.diagsVar.set(str(err))
            print "kitting_hmi: connect:", str(err)

    def recvFunc(self):
        while True:
            if self.connected == True:
                try:
                    msg = self.sock.recv(self.MSG_LEN)
                    msglist = msg.split()
                    if len(msglist) >= 5:
                        self.cmdVar.set(msglist[0])
                        self.statusVar.set(msglist[3])
                        self.hbVar.set(msglist[4])
                except IOError as err:
                    self.diagsVar.set(str(err))
                    print "kitting_hmi:", str(err)
                    time.sleep(self.PERIOD)

    def browse(self):
        filename = askopenfilename()
        self.kitVar.set(filename)

    def make(self):
        if self.connected == True:
            msg = self.kitVar.get()
            try: 
                self.sock.send(msg)
            except IOError as err:
                self.diagsVar.set(str(err))
                print "kitting_hmi:", str(err)

root = Tk()

app1 = App(root)

root.mainloop()
