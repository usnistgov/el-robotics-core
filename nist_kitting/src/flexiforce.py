#!/usr/bin/python

import sys, getopt, socket, json, threading, socket, time

DEBUG = False

def except_info():
    exc_type, exc_value = sys.exc_info()[:2]
    return str(exc_type.__name__) + ": " + str(exc_value)

class FlexiForce(object):
    example = '{"sensor_values": [ {"FSR_finger_A_distal" : 0}, {"FSR_finger_B_distal" : 0}, {"FSR_finger_C_distal" : 0} ] }'

    def __init__(self):
        try: self.obj = json.loads(self.example)
        except: print "FlexiForce:", except_info()
        self._connected = False

    def set(self, vals):
        '''
        Assumes the object is a dictionary of key-list entries, where
        each list is a key-value dictionary
        '''
        for key in self.obj:
            for fs, val in zip(self.obj[key], vals):
                for kk in fs:
                    fs[kk] = val

    def get(self):
        ret = []
        for key in self.obj:
            for fs in self.obj[key]:
                for kk in fs:
                    ret.append(fs[kk])
        return ret

    def write(self):
        return json.dumps(self.obj)

    def read(self, jin):
        try: self.obj = json.loads(jin)
        except: print "FlexiForce:", except_info()

    def _serve_client(self, conn):
        while True:
            try: conn.send(self.write())
            except: break
            time.sleep(1)

    def _server_thr(self, s):
        global DEBUG
        while True:
            if DEBUG: print "FlexiForce:", "waiting for connection"
            try: conn, addr = s.accept()
            except: break
            if DEBUG: print "FlexiForce:", "connected by", addr
            r = threading.Thread(target=self._serve_client, args=(conn,))
            r.daemon = True
            r.start()

    def server(self, port):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        s.bind(("", int(port)))
        s.listen(1)
        r = threading.Thread(target=self._server_thr, args=(s,))
        r.daemon = True
        r.start()

    def _client_thr(self, conn):
        size = 1024
        while True:
            try: data = conn.recv(size)
            except: break
            if not data: break
            self.read(data)
        self._connected = False

    def client(self, host, port):
        try:
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.connect((host, int(port)))
        except IOError as err:
            print "FlexiForce:", "can't connect to", host, "on port", port, ":", str(err)
            return False
        r = threading.Thread(target=self._client_thr, args=(s,))
        r.daemon = True
        r.start()
        self._connected = True
        return True

    def connected(self):
        return self._connected

if __name__ == "__main__":

    HOST = ""
    PORT = 1234

    try:
        opts, args = getopt.getopt(sys.argv[1:], "h:p:d", ["host=", "port=", "debug"])
    except getopt.GetoptError, err:
        print "FlexiForce:", str(err)
        sys.exit(1)

    for o, a in opts:
        if o in ("-h", "--host"):
            HOST = a
        if o in ("-p", "--port"):
            PORT = a
        elif o in ("-d", "--debug"):
            DEBUG = True

    ff = FlexiForce()

    if HOST == "":
        # we're the server
        ff.server(PORT)
        done = False
        while not done:
            try:
                sys.stdout.write("> ")
                line = sys.stdin.readline()
            except KeyboardInterrupt:
                break
            if not line:
                break
            toks = line.split()

            if len(toks) == 0:
                continue

            if toks[0] == "q":
                break

            try:
                ff.set([float(toks[0]), float(toks[1]), float(toks[2])])
            except:
                print "?", line

    else:
        # we're the client
        if not ff.client(HOST, PORT):
            sys.exit(1)

        while ff.connected():
            try:
                print ff.get()
                time.sleep(1)
            except KeyboardInterrupt:
                break
