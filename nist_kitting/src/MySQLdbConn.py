import sys, MySQLdb

class MySQLdbConn(object):

    def __init__(self):
        self.server = None
        self.user = None
        self.passwd = None
        self.db = None
        self.cursor = None

    def except_info(self):
        exc_type, exc_value = sys.exc_info()[:2]
        return str(exc_type.__name__) + ": " + str(exc_value)

    def disconnect(self):
        try: self.db.close()
        except: pass
        self.__init__()
        
    def connect(self, server, user, passwd, db):
        try:
            if self.db != None: self.db.close()
            self.db = MySQLdb.connect(server, user, passwd, db)
            self.cursor = self.db.cursor()
        except:
            print self.except_info()
            self.db = None
            self.cursor = None
            return False
        self.server = server
        self.user = user
        self.passwd = passwd
        return True

    def read(self, query):
        try:
            self.cursor.execute(query)
            return self.cursor.fetchall()
        except:
            print self.except_info()
        return ()

    def update(self, request):
        try:
            self.cursor.execute(request)
            self.db.commit()
            return True
        except:
            self.db.rollback()
        return False

