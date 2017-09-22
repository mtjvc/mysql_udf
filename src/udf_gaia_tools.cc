#define MYSQL_SERVER 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <mysql_version.h>
#include <mysql.h>
#include <sql_class.h>

extern "C" {
    
    my_bool gaia_healpix_init( UDF_INIT* initid, UDF_ARGS* args, char* message );
    void gaia_healpix_deinit( UDF_INIT* initid );
    long long gaia_healpix( UDF_INIT* initid, UDF_ARGS* args, char* is_null, char* error );
    
}

my_bool gaia_healpix_init( UDF_INIT* initid, UDF_ARGS* args, char* message ) {
    //checking stuff to be correct
    if(args->arg_count != 2) {
        strcpy(message, "wrong number of arguments: gaia_healpix() requires two parameters");
        return 1;
    }
    
    if(args->arg_type[0] != INT_RESULT) {
        strcpy(message, "gaia_healpix() requires an integer as parameter one");
        return 1;
    }

    if(args->arg_type[1] != INT_RESULT) {
        strcpy(message, "gaia_healpix() requires an integer as parameter one");
        return 1;
    }

    if(args->args[0] != NULL && (*(long long*)args->args[0] < 1 || *(long long*)args->args[0] > 12)) {
        strcpy(message, "gaia_healpix() requires parameter one to be between 1 and 12");
        return 1;
    }
    
    //no limits on number of decimals
    initid->decimals = 31;
    initid->maybe_null = 0;
    initid->max_length = 17 + 31;
    
    return 0;
}

void gaia_healpix_deinit( UDF_INIT* initid ) {
        
}

long long gaia_healpix( UDF_INIT* initid, UDF_ARGS* args, char* is_null, char* is_error ) {
    int64_t healpix;

    int32_t level = (int32_t)*(long long*)args->args[0];
    int64_t source_id= (int64_t)*(long long*)args->args[1];

    healpix = floor(source_id) / (34359738368 * pow(4, 12 - level));

    return (long long)healpix;
}
