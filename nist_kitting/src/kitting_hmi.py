#!/usr/bin/python

import sys, getopt, socket
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

    def __init__(self, master):
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
        self.kitName = StringVar();
        self.kitName.set("kit.kit")
        self.kitEntry = Entry(self.kitFrame, textvariable=self.kitName)
        self.kitEntry.pack()
        self.kitBrowse = Button(self.kitFrame, text="Kit...", command=self.browse)
        self.kitBrowse.pack()
        self.quitFrame = Frame(self.topFrame)
        self.quitFrame.pack(anchor=N,side=LEFT)
        self.quitButton = Button(self.quitFrame, text="Quit", command=self.topFrame.quit)
        self.quitButton.pack()

    def connect(self):
        try:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.sock.connect((self.hostEntry.get(), int(self.portEntry.get())))
        except IOError as err:
            print "hitting_hmi:", str(err)

    def browse(self):
        filename = askopenfilename()
        self.kitName.set(filename)

root = Tk()

app1 = App(root)
# app2 = App(root)

root.mainloop()
root.destroy()
