#ifndef TRACKING_STATE_HPP
#define TRACKING_STATE_HPP

#include <string>
#include <cstring>

enum track_state_t {UPPERCASE, LOWERCASE, PUNCTUATION};

class Decoder {
    std::string input;
    std::string output;
    void produceNewMessage(void);
    std::string getToken(void);
public:
    Decoder(std::string i): input{i} {};
    std::string& decode(void);
};

std::string& Decoder::decode(void) {
    produceNewMessage();
    return output;
}

void Decoder::produceNewMessage(void)
{
    std::string token;
    do {
        token = getToken();
        output += token + "\n";
    }
    while ( token.length() );

    token.pop_back();
}

std::string Decoder::getToken(void)
{
    static bool init = true;
    static char* buff;
    std::string token;

    if (init) {
        buff = new char[input.length()];
        std::strcpy(buff, input.c_str());
        token.append( strtok(buff, ",") );
        init = false;
    } else {
        char* tokptr = strtok(NULL, ",");
        if (tokptr)
            token.append(tokptr);
        else {
            delete buff;
            init = true;
        }
    }

    return token;
}

#endif // TRACKING_STATE_HPP