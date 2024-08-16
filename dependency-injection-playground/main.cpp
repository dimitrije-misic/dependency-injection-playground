#include "implementations.h"

int main()
{
    using namespace cisim;

    IVehicle auto new_mustang = FordMustang{ V6Turbo{ Garrett{} }, Automatic{} };
    IVehicle auto old_mustang = FordMustang{ V8{}, Manual{} };
}