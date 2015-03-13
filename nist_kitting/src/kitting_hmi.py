#!/usr/bin/python

import sys, getopt, socket, time, threading, ConfigParser
from Tkinter import *
from MySQLdbConn import *

class ToolTip(object):

    def __init__(self, widget):
        self.widget = widget
        self.tipwindow = None
        self.id = None
        self.x = self.y = 0

    def showtip(self, text):
        "Display text in tooltip window"
        self.text = text
        if self.tipwindow or not self.text:
            return
        x, y, cx, cy = self.widget.bbox("insert")
        x = x + self.widget.winfo_rootx() + 27
        y = y + cy + self.widget.winfo_rooty() +27
        self.tipwindow = tw = Toplevel(self.widget)
        tw.wm_overrideredirect(1)
        tw.wm_geometry("+%d+%d" % (x, y))
        try:
            # For Mac OS
            tw.tk.call("::tk::unsupported::MacWindowStyle",
                       "style", tw._w,
                       "help", "noActivates")
        except TclError:
            pass
        label = Label(tw, text=self.text, justify=LEFT,
                      background="#ffffe0", relief=SOLID, borderwidth=1,
                      font=("tahoma", "8", "normal"))
        label.pack(ipadx=1)

    def hidetip(self):
        tw = self.tipwindow
        self.tipwindow = None
        if tw:
            tw.destroy()

def createToolTip(widget, text):
    toolTip = ToolTip(widget)
    def enter(event):
        toolTip.showtip(text)
    def leave(event):
        toolTip.hidetip()
    widget.bind('<Enter>', enter)
    widget.bind('<Leave>', leave)

INIFILE = ""
WS_PORT = ""
EMOVE_PORT = ""
HOST = ""

DB_SERVER = ""
DB_USER = ""
DB_PASSWD = ""
DB_NAME = ""

DEBUG = False

class BrowseDialog(object):
    def __init__(self, parent, _ents):
        self.ents = _ents
        self.pick = None
        self.top = Toplevel(parent)
        f = Frame(self.top)
        sf = Frame(f)
        bf = Frame(f)
        xscrollbar = Scrollbar(sf, orient=HORIZONTAL)
        yscrollbar = Scrollbar(sf, orient=VERTICAL)
        self.listbox = Listbox(sf, xscrollcommand=xscrollbar.set, yscrollcommand=yscrollbar.set)
        xscrollbar.config(command=self.listbox.xview)
        xscrollbar.pack(side=BOTTOM, fill=X)
        yscrollbar.config(command=self.listbox.yview)
        yscrollbar.pack(side=RIGHT, fill=Y)
        for item in self.ents:
            self.listbox.insert(END, item)
        self.listbox.pack()
        sf.pack()
        b = Button(bf, text="OK", command=self.ok)
        b.pack()
        bf.pack()
        f.pack()

    def get(self):
        return self.pick

    def ok(self):
        items = self.listbox.curselection()
        if len(items) > 0:
            item = self.ents[int(items[0])]
            if len(item) > 0:
                self.pick = item[0]
                print "value is", item[0]
        self.top.destroy()
    
class App(object):
    global WS_PORT, EMOVE_PORT, HOST, DB_SERVER, DB_USER, DB_PASSWD, DB_NAME
    MSG_LEN = 1000
    PERIOD = 5

    def __init__(self, master):
        #
        self.wsSock = -1
        self.emoveSock = -1
        self.nameVar = StringVar()
        self.wsPortVar = StringVar()
        self.emovePortVar = StringVar()
        self.kitVar = StringVar()
        self.cmdVar = StringVar()
        self.statusVar = StringVar()
        self.hbVar = StringVar()
        self.emoveVar = StringVar()
        self.diagsVar = StringVar()
        #
        self.nameVar.set(HOST)
        self.wsPortVar.set(str(WS_PORT))
        self.emovePortVar.set(str(EMOVE_PORT))
        self.kitVar.set("kit_design_GearBox")
        self.cmdVar.set("")
        self.statusVar.set("")
        self.hbVar.set("")
        self.emoveVar.set("")
        self.diagsVar.set("")
        #
        self.AprsDB = None

        #
        Label(master, text="Host").grid(row=0,column=0,columnspan=2)
        # #
        Label(master, text="Name:").grid(row=1,column=0)
        self.nameEntry = Entry(master, textvariable=self.nameVar, state=NORMAL)
        self.nameEntry.grid(row=1,column=1)
        # #
        Label(master, text="WS Port:").grid(row=2,column=0)
        self.wsPortEntry = Entry(master, textvariable=self.wsPortVar, state=NORMAL)
        self.wsPortEntry.grid(row=2,column=1)
        # #
        Label(master, text="Emove Port:").grid(row=3,column=0)
        self.emovePortEntry = Entry(master, textvariable=self.emovePortVar, state=NORMAL)
        self.emovePortEntry.grid(row=3,column=1)
        # #
        self.connectButton = Button(master, text="Connect", command=self.connect, state=NORMAL)
        self.connectButton.grid(row=4,column=0)
        self.disconnectButton = Button(master, text="Disconnect", command=self.disconnect, state=DISABLED)
        self.disconnectButton.grid(row=4,column=1)

        #
        Label(master, text="Kit").grid(row=0, column=2, columnspan=2)
        # #
        Label(master, text="Name:").grid(row=1, column=2)
        Entry(master, textvariable=self.kitVar).grid(row=1, column=3)
        # #
        Button(master, text="Browse...", command=self.browse).grid(row=3,column=2)
        self.makeButton = Button(master, text="Make", command=self.make, state=DISABLED)
        self.makeButton.grid(row=3,column=3)
        createToolTip(self.makeButton, "Send a 'make kit' request")

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

        # #
        Label(master, text="Emove:").grid(row=4, column=4)
        self.emoveEntry = Entry(master, textvariable=self.emoveVar)
        self.emoveEntry.grid(row=4, column=5)

        #
        Entry(master, textvariable=self.diagsVar).grid(row=5, column=0, columnspan=6, sticky=W+E)

        #
        Button(master, text="Quit", command=self.quit).grid(row=6,columnspan=6)

        #
        self.wsRecvThread = threading.Thread(target=self.wsRecvFunc)
        self.wsRecvThread.daemon = True
        self.wsRecvThread.start()

        #
        self.emoveRecvThread = threading.Thread(target=self.emoveRecvFunc)
        self.emoveRecvThread.daemon = True
        self.emoveRecvThread.start()
                
    def sockconnect(self):
        self.sockdisconnect()
        try:
            self.wsSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.wsSock.connect((self.nameVar.get(), int(self.wsPortVar.get())))
            self.emoveSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.emoveSock.connect((self.nameVar.get(), int(self.emovePortVar.get())))
        except IOError as err:
            self.wsSock = -1
            self.emoveSock = -1
            self.diagsVar.set(str(err))
            print "kitting_hmi: connect:", str(err)
            return False
        self.makeConnected()
        self.diagsVar.set("")
        return True

    def sockdisconnect(self):
        if self.wsSock != -1:
            try:
                self.wsSock.shutdown(socket.SHUT_RDWR)
                self.wsSock.close()
                self.diagsVar.set("")
            except IOError as err:
                self.diagsVar.set(str(err))
                print "kitting_hmi: disconnect:", str(err), self.wsSock
        if self.emoveSock != -1: 
            try:
                self.emoveSock.shutdown(socket.SHUT_RDWR)
                self.emoveSock.close()
                self.diagsVar.set("")
            except IOError as err:
                self.diagsVar.set(str(err))
                print "kitting_hmi: disconnect:", str(err), self.emoveSock
        self.makeDisconnected()
        return True

    def dbconnect(self):
        self.AprsDB = MySQLdbConn()
        if not self.AprsDB.connect(DB_SERVER, DB_USER, DB_PASSWD, DB_NAME):
            return False
        return True

    def dbdisconnect(self):
        if self.AprsDB != None:
            self.AprsDB.disconnect()
        return True

    def connect(self):
        if self.sockconnect() and self.dbconnect():
            return True
        return False

    def disconnect(self):
        self.sockdisconnect()
        self.dbdisconnect()
        return True

    def wsRecvFunc(self):
        while True:
            if self.wsSock < 0:
                time.sleep(self.PERIOD)
            else:
                try:
                    msg = self.wsSock.recv(self.MSG_LEN)
                    msglist = msg.split()
                    if len(msglist) >= 5:
                        self.cmdVar.set(msglist[0])
                        self.statusVar.set(msglist[3])
                        self.hbVar.set(msglist[4])
                except IOError as err:
                    self.diagsVar.set(str(err))
                    print "kitting_hmi: recv:", str(err)

    def emoveRecvFunc(self):
        while True:
            if self.emoveSock < 0:
                time.sleep(self.PERIOD)
            else:
                try:
                    msg = self.emoveSock.recv(self.MSG_LEN)
                    msglist = msg.split()
                    if len(msglist) >= 6:
                        stuff = msglist[0] + " " + msglist[3] + " " + msglist[5]
                        self.emoveVar.set(stuff)
                except IOError as err:
                    self.diagsVar.set(str(err))
                    print "kitting_hmi: recv:", str(err)

    def browse(self):
        try:
            ret = self.AprsDB.read("select hadByPartRefAndPose_KitDesign from PartRefAndPose")
        except:
            return False
        d = BrowseDialog(root, ret)
        root.wait_window(d.top)
        if d.get() != None:
            self.kitVar.set(d.get())
        return True

    def make(self):
        if self.wsSock < 0: return
        msg = self.kitVar.get()
        try: 
            self.wsSock.send(msg)
            self.diagsVar.set("")
        except IOError as err:
            self.diagsVar.set(str(err))
            print "kitting_hmi: make:", str(err)

    def makeConnected(self):
        self.nameEntry.config(state=DISABLED)
        self.wsPortEntry.config(state=DISABLED)
        self.emovePortEntry.config(state=DISABLED)
        self.connectButton.config(state=DISABLED)
        self.disconnectButton.config(state=NORMAL)
        self.makeButton.config(state=NORMAL)
        self.cmdEntry.config(state=NORMAL)
        self.statusEntry.config(state=NORMAL)
        self.hbEntry.config(state=NORMAL)

    def makeDisconnected(self):
        self.wsSock = -1
        self.emoveSock = -1
        self.nameEntry.config(state=NORMAL)
        self.wsPortEntry.config(state=NORMAL)
        self.emovePortEntry.config(state=NORMAL)
        self.connectButton.config(state=NORMAL)
        self.disconnectButton.config(state=DISABLED)
        self.makeButton.config(state=DISABLED)
        self.cmdEntry.config(state=DISABLED)
        self.statusEntry.config(state=DISABLED)
        self.hbEntry.config(state=DISABLED)

    def quit(self):
        self.disconnect()
        sys.exit(0)

try:
    opts, args = getopt.getopt(sys.argv[1:], "i:w:e:h:d", ["inifile=", "ws_port=", "emove_port=", "host=", "debug=", "dbserver=", "dbuser=", "dbpasswd=", "dbname="])
except getopt.GetoptError as err:
    print "kitting_hmi: getopt:", str(err)
    sys.exit(1)

for o, a in opts:
    if o in ("-i", "--inifile"):
        INIFILE = a
    elif o in ("-w", "--ws_port"):
        WS_PORT = a
    elif o in ("-e", "--emove_port"):
        EMOVE_PORT = a
    elif o in ("-h", "--host"):
        HOST = a
    elif o in ("-d", "--debug"):
        DEBUG = True
# args with long form only go here
    elif o in ("--dbserver"):
        DB_SERVER = a
    elif o in ("--dbuser"):
        DB_USER = a
    elif o in ("--dbpasswd"):
        DB_PASSWD = a
    elif o in ("--dbname"):
        DB_NAME = a

defdict = {
    "ws_port" : "",
    "emove_port" : "",
    "host" : "",
    "server" : "",
    "user" : "",
    "passwd" : "",
    "name" : ""
    }

if INIFILE != "":
    try:
        with open(INIFILE, "rb") as f:
            config = ConfigParser.ConfigParser(defdict)
            config.read(INIFILE)
            if WS_PORT == "":
                WS_PORT = config.get("hmi", "ws_port")
            if EMOVE_PORT == "":
                EMOVE_PORT = config.get("hmi", "emove_port")
            if HOST == "":
                HOST = config.get("hmi", "host")
            if DB_SERVER == "":
                DB_SERVER = config.get("mysql", "server")
            if DB_USER == "":
                DB_USER = config.get("mysql", "user")
            if DB_PASSWD == "":
                DB_PASSWD = config.get("mysql", "passwd")
            if DB_NAME == "":
                DB_NAME = config.get("mysql", "name")
    except IOError as err:
        print "planning_app: open inifile:", str(err)
        sys.exit(1)
    except (ConfigParser.NoSectionError, ConfigParser.NoOptionError) as err:
        print "planning_app: read inifile:", str(err)
        sys.exit(1)

if WS_PORT == "": WS_PORT = 6066
if EMOVE_PORT == "": EMOVE_PORT = 6067
if HOST == "": HOST = "localhost"

if DB_SERVER == "": DB_SERVER = "aprs-dev"
if DB_USER == "" : DB_USER = "wills"
if DB_PASSWD == "" : DB_PASSWD = "ElsaIsdDb!"
if DB_NAME == "" : DB_NAME = "aprs-dev"

if DEBUG:
    print "kitting_hmi: WS port:", WS_PORT
    print "kitting_hmi: Emove port:", EMOVE_PORT
    print "kitting_hmi: host:", HOST
    print "kitting_hmi: MySQL options are:", DB_SERVER, DB_USER, DB_PASSWD, DB_NAME

root = Tk()

app1 = App(root)

root.mainloop()
