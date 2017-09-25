#define MYSQL_SERVER 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <mysql_version.h>
#include <mysql.h>
#include <sql_class.h>

extern "C" {
    
    my_bool aip_erf_init( UDF_INIT* initid, UDF_ARGS* args, char* message );
    void aip_erf_deinit( UDF_INIT* initid );
    double aip_erf( UDF_INIT* initid, UDF_ARGS* args, char* is_null, char* error );
    
}

my_bool aip_erf_init( UDF_INIT* initid, UDF_ARGS* args, char* message ) {
    if(args->arg_count != 1) {
        strcpy(message, "wrong number of arguments: aipsf_erf() requires one parameter");
        return 1;
    }
    
    if(args->arg_type[0] != DECIMAL_RESULT && args->arg_type[0] != REAL_RESULT && args->arg_type[0] != INT_RESULT) {
        strcpy(message, "aipsf_erf() requires an integer or real as parameter one");
        return 1;
    }

    //no limits on number of decimals
    initid->decimals = 31;
    initid->maybe_null = 0;
    initid->max_length = 17 + 31;
    
    return 0;
}

void aip_erf_deinit( UDF_INIT* initid ) {
        
}

double aip_erf( UDF_INIT* initid, UDF_ARGS* args, char* is_null, char* is_error ) {
    // from Handbook of Mathematical Functions, formula 7.1.26
    double p = 0.3275911;
    double a1 = 0.254829592;
    double a2 = -0.284496763;
    double a3 = 1.421413741;
    double a4 = -1.453152027;
    double a5 = 1.061405429;
    double x;

    if(args->arg_type[0] == REAL_RESULT) {
        x = *(double*)args->args[0];
    }
    else {
        x = atof(args->args[0]);
    }

    double t = 1.0 / (1.0 + p * x); 
    double erf = 1.0 - (a1 * t +
                        a2 * t * t +
                        a3 * t * t * t +
                        a4 * t * t * t * t +
                        a5 * t * t * t * t * t
                       ) * exp( -x * x );

    return erf;
}
