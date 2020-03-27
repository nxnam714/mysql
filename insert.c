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
        
        res = mysql_query(&my_connection, "INSERT INTO children(fname,age) VALUES('Ann', 3)");

        if (!res)
        {
            printf("Inserted %lu rows\n", (unsigned long) mysql_affected_rows(&my_connection));
        }
        else
        {
            printf("Insert error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
        }

        res = mysql_query(&my_connection, "INSERT INTO children(fname,age) VALUES('Ann', 4)");

        if (!res)
        {
            printf("Inserted %lu rows\n", (unsigned long) mysql_affected_rows(&my_connection));
        }
        else
        {
            printf("Insert error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
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