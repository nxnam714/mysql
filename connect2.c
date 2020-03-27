#include <stdlib.h>
#include <stdio.h>

#include "mysql/mysql.h"

int main(int argc, char *argv[])
{
    MYSQL my_connection;

    mysql_init(&my_connection);

    if (mysql_real_connect(&my_connection, "localhost", "rick", "XXbar", "rick", 0, NULL, 0))
    {
        printf("Connection success\n");
        mysql_close(&my_connection);
    }
    else
    {
        printf("Connection failed\n");
        if (mysql_errno(&my_connection))
        {
            printf("Connection error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
        }
    }

    return EXIT_SUCCESS;
    
    return 0;
}