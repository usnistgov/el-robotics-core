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
    print "kitting_hmi: getopt:", str(err)
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

    def __init__(self, master):
        #
        self.sock = -1
        self.nameVar = StringVar()
        self.portVar = StringVar()
        self.kitVar = StringVar()
        self.cmdVar = StringVar()
        self.statusVar = StringVar()
        self.hbVar = StringVar()
        self.diagsVar = StringVar()
        #
        self.nameVar.set(HOST)
        self.portVar.set(str(PORT))
        self.kitVar.set("kit.kit")
        self.cmdVar.set("")
        self.statusVar.set("")
        self.hbVar.set("")
        self.diagsVar.set("")

        #
        Label(master, text="Host").grid(row=0,column=0,columnspan=2)
        # #
        Label(master, text="Name:").grid(row=1,column=0)
        self.nameEntry = Entry(master, textvariable=self.nameVar, state=NORMAL)
        self.nameEntry.grid(row=1,column=1)
        # #
        Label(master, text="Port:").grid(row=2,column=0)
        self.portEntry = Entry(master, textvariable=self.portVar, state=NORMAL)
        self.portEntry.grid(row=2,column=1)
        # #
        self.connectButton = Button(master, text="Connect", command=self.connect, state=NORMAL)
        self.connectButton.grid(row=3,column=0)
        self.disconnectButton = Button(master, text="Disconnect", command=self.disconnect, state=DISABLED)
        self.disconnectButton.grid(row=3,column=1)

        #
        Label(master, text="Kit").grid(row=0, column=2, columnspan=2)
        # #
        Label(master, text="Name:").grid(row=1, column=2)
        Entry(master, textvariable=self.kitVar).grid(row=1, column=3)
        # #
        Button(master, text="Browse...", command=self.browse).grid(row=3,column=2)
        self.makeButton = Button(master, text="Make", command=self.make, state=DISABLED)
        self.makeButton.grid(row=3,column=3)

        #
        Label(master, text="Status").grid(row=0, column=4, columnspan=2)
        # #
        Label(master, text="Command:").grid(row=1, column=4)
        self.cmdEntry = Entry(master, textvariable=self.cmdVar)
        self.cmdEntry.grid(row=1, column=5)
        # #
        Label(master, text="Status:").grid(row=2, column=4)
        self.statusEntry = Entry(master, textvariable=self.statusVar)
        self.statusEntry.grid(row=2, column=5)
        # #
        Label(master, text="Heartbeat:").grid(row=3, column=4)
        self.hbEntry = Entry(master, textvariable=self.hbVar)
        self.hbEntry.grid(row=3, column=5)

        #
        Entry(master, textvariable=self.diagsVar).grid(row=4, column=0, columnspan=6, sticky=W+E)

        #
        self.recvThread = threading.Thread(target=self.recvFunc)
        self.recvThread.daemon = True
        self.recvThread.start()

    def connect(self):
        self.disconnect()
        try:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.sock.connect((self.nameVar.get(), int(self.portVar.get())))
            self.makeConnected()
            self.diagsVar.set("")
        except IOError as err:
            self.sock = -1
            self.diagsVar.set(str(err))
            print "kitting_hmi: connect:", str(err)

    def disconnect(self):
        if self.sock < 0: 
            return
        try:
            self.sock.shutdown(socket.SHUT_RDWR)
            self.sock.close()
            self.diagsVar.set("")
        except IOError as err:
            self.diagsVar.set(str(err))
            print "kitting_hmi: disconnect:", str(err), self.sock
        self.makeDisconnected()

    def recvFunc(self):
        while True:
            if self.sock < 0:
                time.sleep(self.PERIOD)
            else:
                try:
                    msg = self.sock.recv(self.MSG_LEN)
                    msglist = msg.split()
                    if len(msglist) >= 5:
                        self.cmdVar.set(msglist[0])
                        self.statusVar.set(msglist[3])
                        self.hbVar.set(msglist[4])
                except IOError as err:
                    self.diagsVar.set(str(err))
                    print "kitting_hmi: recv:", str(err)

    def browse(self):
        filename = askopenfilename()
        self.kitVar.set(filename)

    def make(self):
        if self.sock < 0: return
        msg = self.kitVar.get()
        try: 
            self.sock.send(msg)
            self.diagsVar.set("")
        except IOError as err:
            self.diagsVar.set(str(err))
            print "kitting_hmi: make:", str(err)

    def makeConnected(self):
        self.nameEntry.config(state=DISABLED)
        self.portEntry.config(state=DISABLED)
        self.connectButton.config(state=DISABLED)
        self.disconnectButton.config(state=NORMAL)
        self.makeButton.config(state=NORMAL)
        self.cmdEntry.config(state=NORMAL)
        self.statusEntry.config(state=NORMAL)
        self.hbEntry.config(state=NORMAL)

    def makeDisconnected(self):
        self.sock = -1
        self.nameEntry.config(state=NORMAL)
        self.portEntry.config(state=NORMAL)
        self.connectButton.config(state=NORMAL)
        self.disconnectButton.config(state=DISABLED)
        self.makeButton.config(state=DISABLED)
        self.cmdEntry.config(state=DISABLED)
        self.statusEntry.config(state=DISABLED)
        self.hbEntry.config(state=DISABLED)

root = Tk()

app1 = App(root)

root.mainloop()
