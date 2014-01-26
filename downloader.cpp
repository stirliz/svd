#include "downloader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>


/// TODO link here, delete in destructor
Downloader::Downloader( const char *_link )
{
    link = strdup( _link );
    file = NULL;
}

Downloader::~Downloader()
{
    if ( file != NULL )
        unlink( file );
    free( link );
}

const char* Downloader::download( void )
{
    if ( file == NULL )
    {
        file = tempnam( NULL, NULL );
        FILE *fp = fopen( file, "wb" );

        success = false;

        CURL *curl;
        CURLcode res;

        curl = curl_easy_init();

        if ( !curl )
        {
            errorMessage = "Cannot init curl library!";
            return NULL;
        }

        curl_easy_setopt( curl, CURLOPT_URL, link );
        curl_easy_setopt( curl, CURLOPT_FOLLOWLOCATION, 1L );
        curl_easy_setopt( curl, CURLOPT_WRITEDATA, fp );

        res = curl_easy_perform( curl );

        if ( res != CURLE_OK )
        {
            errorMessage = curl_easy_strerror(res);
            return NULL;
        }

        curl_easy_cleanup( curl );
        success = true;
    }

    return file;
}

const char* Downloader::fileName( void )
{
    return file;
}

bool Downloader::isSucceed()
{
    return success;
}
