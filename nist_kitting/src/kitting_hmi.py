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

    def __init__(self, master):
        self.connected = False
        self.nameVar = StringVar()
        self.portVar = StringVar()
        self.kitVar = StringVar()
        self.cmdVar = StringVar()
        self.statusVar = StringVar()
        self.hbVar = StringVar()
        self.nameVar.set("localhost")
        self.portVar.set("6006")
        self.kitVar.set("kit.kit")
        self.cmdVar.set("(none)")
        self.statusVar.set("(none)")
        self.hbVar.set("0")

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
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.recvThread = threading.Thread(target=self.recvFunc)
        self.recvThread.daemon = True
        self.recvThread.start()

    def old(self, master):
        self.topFrame = Frame(master)
        self.topFrame.pack(anchor=N,side=LEFT)
        self.commFrame = Frame(self.topFrame)
        self.commFrame.pack(side=LEFT)
        self.hostEntry = Entry(self.commFrame)
        self.hostEntry.insert(0, "localhost")
        self.hostEntry.pack()
        self.portEntry = Entry(self.commFrame)
        self.portEntry.insert(0, 12345)
        self.portEntry.pack()
        self.connectButton = Button(self.commFrame, text="Connect", command=self.connect)
        self.connectButton.pack()
        self.kitFrame = Frame(self.topFrame)
        self.kitFrame.pack(anchor=N,side=LEFT)
        self.kitName = StringVar()
        self.kitName.set("kit.kit")
        self.kitEntry = Entry(self.kitFrame, textvariable=self.kitName)
        self.kitEntry.pack()
        self.kitBrowse = Button(self.kitFrame, text="Kit...", command=self.browse)
        self.kitBrowse.pack()
        self.quitFrame = Frame(self.topFrame)
        self.quitFrame.pack(anchor=N,side=LEFT)
        self.quitButton = Button(self.quitFrame, text="Quit", command=self.topFrame.quit)
        self.quitButton.pack()
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.recvThread = threading.Thread(target=self.recvFunc)
        self.recvThread.daemon = True
        self.recvThread.start()

    def connect(self):
        try:
            self.sock.connect((self.nameVar.get(), int(self.portVar.get())))
            self.connected = True
        except IOError as err:
            print "kitting_hmi:", str(err)

    def disconnect(self):
        try:
            self.sock.shutdown(socket.SHUT_RDWR)
            self.connected = False
        except IOError as err:
            print "kitting_hmi:", str(err)

    def recvFunc(self):
        while True:
            if self.connected == True:
                try:
                    msg = self.sock.recv(MSG_LEN)
                except IOError as err:
                    print "kitting_hmi:", str(err)
                    time.sleep(PERIOD)

    def browse(self):
        filename = askopenfilename()
        self.kitVar.set(filename)

root = Tk()

app1 = App(root)

root.mainloop()
