
// --- Lwgeom Includes --- //
extern "C"
{
#include <liblwgeom.h>
}

// --- Standard Includes --- //
#include <iostream>
#include <string>

////////////////////////////////////////////////////////////////////////////////
int main(
    int argc,
    char** argv )
{
    int has_bbox = 0;
    int precision = DBL_DIG;
    char* srs = nullptr;
    LWGEOM* gin = nullptr;
    LWGEOM* gout = nullptr;
    std::string geojson = argv[ 1 ];

    try
    {
        gin = lwgeom_from_geojson( geojson.c_str(), &srs );
        gout = lwgeom_make_valid( gin );
        geojson = lwgeom_to_geojson( gout, srs, precision, has_bbox );
        std::cout << geojson;
    }
    catch( std::exception const& e )
    {
        std::cerr << "*** std::exception caught: "
            << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    lwfree( srs );
    lwfree( gin );
    lwfree( gout );

    return EXIT_SUCCESS;
}
////////////////////////////////////////////////////////////////////////////////
