#ifndef TRACKING_STATE_HPP
#define TRACKING_STATE_HPP

#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

void showErrorExit(void);
enum track_state_t {UPPERCASE, LOWERCASE, PUNCTUATION};

class Decoder {
    std::string input;
    std::string output;
    track_state_t state = UPPERCASE;
    void produceNewMessage(void);
    std::string getToken(void);
    void selectState(int n);
    void uppercase(int n);
    void lowercase(int n);
    void punctuation(int n);
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
    int n, res;
    std::string token;
    while ( (token = getToken()).length() ) {
        res = std::sscanf(token.c_str(), "%d", &n);
        if (res > 0)
            selectState(n);
        else if (res == EOF)
            showErrorExit();
        else
            break;
    }
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

void Decoder::selectState(int n)
{
    switch (state) {
        case track_state_t::UPPERCASE: uppercase(n); break;
        case track_state_t::LOWERCASE: lowercase(n); break;
        case track_state_t::PUNCTUATION: punctuation(n); break;
    }
}

void Decoder::uppercase(int n)
{

}

void Decoder::lowercase(int n)
{

}

void Decoder::punctuation(int n)
{

}

void showErrorExit(void)
{
    std::fprintf(stderr, "Error %d: %s", errno, strerror(errno));
    std::exit(errno);
}

#endif // TRACKING_STATE_HPP