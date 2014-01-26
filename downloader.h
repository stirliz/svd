#ifndef DOWNLOADER_H
#define DOWNLOADER_H

class Downloader
{
    public:
    public:
        Downloader( const char *link );
        ~Downloader();
        const char* download( void );
        const char* fileName( void );
        bool isSucceed();

    private:
    public:
        char *link;
        const char *file;
        bool success;
        const char *errorMessage;
};

#endif // DOWNLOADER_H
