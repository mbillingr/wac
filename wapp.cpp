#include "wapp.h"


namespace wasm {

Module::Module(char *path, Options opts, HostExportCallback host_export) {
    m = load_module(path, opts, host_export);
}

Module::~Module() {
    free_module(m);
}

bool Module::invoke(char *entry, int argc, char **argv) {
    ::invoke(m, entry, argc, argv);
}

}
