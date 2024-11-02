#include <exception>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

using namespace std;

#ifndef __CALC_ERROR
#define __CALC_ERROR

#define MESSAGE_BUFFER_LEN                  4096

class calc_error : public exception
{
    private:
        string          message;

    public:
        const char * getTitle() {
            return "Calc error: ";
        }

        calc_error() {
            this->message.assign(getTitle());
        }

        calc_error(const char * msg) : calc_error() {
            this->message.append(msg);
        }

        calc_error(const char * msg, const char * file, int line) : calc_error() {
            char lineNumBuf[8];

            snprintf(lineNumBuf, 8, ":%d", line);

            this->message.append(msg);
            this->message.append(" at ");
            this->message.append(file);
            this->message.append(lineNumBuf);
        }

        virtual const char * what() const noexcept {
            return this->message.c_str();
        }

        static char * buildMsg(const char * fmt, ...) {
            va_list     args;
            char *      buffer;

            va_start(args, fmt);
            
            buffer = (char *)malloc(MESSAGE_BUFFER_LEN);
            
            vsnprintf(buffer, MESSAGE_BUFFER_LEN, fmt, args);
            
            va_end(args);

            return buffer;
        }
};

class calc_fatal : public calc_error {
    public:
        const char * getTitle() {
            return "Fatal error: ";
        }

        calc_fatal() : calc_error() {}
        calc_fatal(const char * msg) : calc_error(msg) {}
        calc_fatal(const char * msg, const char * file, int line) : calc_error(msg, file, line) {}
};

class calc_validation_error : public calc_error {
    public:
        const char * getTitle() {
            return "Validation error: ";
        }

        calc_validation_error() : calc_error() {}
        calc_validation_error(const char * msg) : calc_error(msg) {}
        calc_validation_error(const char * msg, const char * file, int line) : calc_error(msg, file, line) {}
};

#endif
