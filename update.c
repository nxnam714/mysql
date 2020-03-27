#include <stdio.h>
#include <stdio.h>

#include "mysql/mysql.h"

int main(int argc, char *argv[])
{
    MYSQL my_connection;
    int res = -1;

    mysql_init(&my_connection);

    if (mysql_real_connect(&my_connection, "localhost", "rick", "bar", "rick", 0, NULL, 0))
    {
        printf("Connection success\n");
        
        res = mysql_query(&my_connection, "UPDATE children SET AGE = 4 WHERE fname = 'Ann'");

        if (!res)
        {
            printf("Updated %lu rows\n", (unsigned long) mysql_affected_rows(&my_connection));
        }
        else
        {
            printf("Update error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
        }

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
}