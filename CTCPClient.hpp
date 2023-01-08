#include <string>

class CTCPClient {
/// @brief Class to create a TCP Client socket.
public:
  // createClientSocket();
  CTCPClient();
  CTCPClient(std::string ip, int port);
  connectToServer(std::string ip, int port);
protected:
private:
  std::string ip;
  int port;
  /// @brief
  /// @return
  std::string getIP();
  int getPort();
  int setIP(std::string ip);
  int setPort(int port);
};