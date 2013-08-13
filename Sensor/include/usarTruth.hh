#include <vector>
#include <string>
#include "ulapi.hh"

/**
	\brief Struct to hold data for a single object retrieved from USARTruth
	
	Ignores bone data
*/
typedef struct
{
	std::string objectName;
	std::string className;
	double time;
	double location[3];
	double rotation[3];
} UsarData;

/**
	\brief class to handle USARTruth connection and querying
*/
class UsarTruth
{
public:
	UsarTruth(const std::string &hostname, ulapi_integer port);
	void connect();
	bool getData(std::vector<UsarData> &data, const std::string &className="", const std::string &objectName="") const;
private:
	std::string hostname;
	ulapi_integer port;
	ulapi_integer socket_id;
	bool connected;
	int handle_message(const char *msg, UsarData &data) const;
};
