#pragma once

extern "C" {
#include "wa.h"
}

namespace wasm {

class Module {
public:
    Module(char *path, Options opts, HostExportCallback host_export=0);
    ~Module();

    bool invoke(char *entry, int argc, char **argv);

    StackValue& stacktop() const {return m->stack[m->sp];}
    int get_sp() const {return m->sp;}
    int get_fp() const {return m->sp;}
    int get_csp() const {return m->sp;}

    void set_sp(int sp)     {m->sp = sp;}
    void set_fp(int fp)     {m->fp = fp;}
    void set_csp(int csp)     {m->csp = csp;}

    char *get_exception() {return exception;}
private:
    ::Module *m;
};

}
