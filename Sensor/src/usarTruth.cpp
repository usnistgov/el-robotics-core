#include "usarTruth.hh"
#include "parseUtils.h"
#include <iostream>
#include <stdlib.h>
#define BUILDMAX 1024
#define BUFFERLEN 256
#define DELIMITER '\n'


UsarTruth::UsarTruth(const std::string &hostname, int port)
{
	this->hostname = hostname;
	this->port = port;
	connected = false;
}
void UsarTruth::connect()
{
	socket_id = ulapi_socket_get_client_id(port, hostname.c_str());
	connected = true;
}
bool UsarTruth::getData(std::vector<UsarData> &data, const std::string &className, const std::string &objectName) const
{
	char buffer[BUFFERLEN];
	int buildlen = BUFFERLEN;
	char *build = NULL;
	char *build_ptr;
	char *build_end;
	char *buffer_ptr;
	char *buffer_end;
	std::ptrdiff_t offset;
	
	data.clear();
	
	if(!connected)
		return false;
	std::string outString = "";
	//build message to send on socket and send it
	if(className != "")
	{
		outString += "{class " + className + "}";
	}
	if(objectName != "")
	{
		outString += "{name " + objectName + "}";
	}
	outString += "\r\n";
	if(outString == "\r\n")
	{
		outString = "{class Engine.Actor}\r\n";
	}
	ulapi_socket_write(socket_id, outString.c_str(), outString.size());
	//copied from USARTruth.c
	int done = 0;
	int nchars;
	
	build = (char *) realloc(build, buildlen * sizeof(*build));
	build_ptr = build;
	build_end = build + buildlen;
	
	while (!done) {
		
		nchars = ulapi_socket_read(socket_id, buffer, sizeof(buffer) - 1);
		if (-1 == nchars) {
			fprintf(stderr, "connection closed\n");
			done = 1;
		} else if (0 == nchars) {
			fprintf(stderr, "end of file\n");
			done = 1;
		} else {
			buffer_ptr = buffer;
			buffer_end = buffer + nchars;
			while (buffer_ptr != buffer_end) {
				if (build_ptr == build_end) {
					if (buildlen > BUILDMAX) {
						fprintf(stderr, "message overrun in reader\n");
						build_ptr = build;
						break;
					}
					offset = build_ptr - build;
					buildlen *= 2;
					build = (char *) realloc(build, buildlen * sizeof(*build));
					build_ptr = build + offset;
					build_end = build + buildlen;
				}
				*build_ptr++ = *buffer_ptr;
				if (*buffer_ptr++ == DELIMITER) {
					offset = build_ptr - build;
					build_ptr = build;
					build[offset] = 0;
					UsarData object;
					done = handle_message(build, object);
					if(!done)
					{
						data.push_back(object);
					}
					else
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
//mostly copied from USARTruth.c
int UsarTruth::handle_message(const char* msg, UsarData &data) const
{
	const char *nextptr;
	char token[MAX_TOKEN_LEN];
	const char *ptr = msg;
	double dbl[3];
	if (! strncmp(ptr, "{End}", strlen("{End}"))) {
		return 1;
	}

	while (1)
	{
		nextptr = getKey(ptr, token);
		if(nextptr == ptr ) return 0;
		ptr = nextptr;
		if( !strcmp(token, "Name"))
		{
			nextptr = getValue(ptr, token);
			if(nextptr == ptr ) return 0;
			ptr = nextptr;
			data.objectName = std::string(token);
		}
		else if( !strcmp(token, "Class"))
		{
			nextptr = getValue(ptr, token);
			if(nextptr == ptr ) return 0;
			ptr = nextptr;
			data.className = std::string(token);
		}
		else if( !strcmp(token, "Time"))
		{
			nextptr = getDouble(ptr, &dbl[0] );
			if(nextptr == ptr ) return 0;
			ptr = nextptr;
			data.time = dbl[0];
		}
		else if( !strcmp(token, "Location"))
		{
			nextptr = getVector(ptr, dbl, 3 );
			if(nextptr == ptr ) return 0;
			ptr = nextptr;
			data.location[0] = dbl[0];
			data.location[1] = dbl[1];
			data.location[2] = dbl[2];
		}
		else if( !strcmp(token, "Rotation"))
		{
			nextptr = getVector(ptr, dbl, 3 );
			if(nextptr == ptr ) return 0;
			ptr = nextptr;
			data.rotation[0] = dbl[0];
			data.rotation[1] = dbl[1];
			data.rotation[2] = dbl[2];
		}
		else
		{
			printf("Not reading token %s", token);
		}
	}
}
