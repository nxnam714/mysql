# mysql

## Prerequisites
Install MySQL by following guideline at this [site](https://www.digitalocean.com/community/tutorials/how-to-install-mysql-on-ubuntu-16-04)\\
Create a account with name = rick and password = bar. And then set full permission on rick database to it.
```
  mysql> CREATE USER 'rick'@"%" IDENTIFIED BY 'bar';
  mysql> GRANT ALL PRIVILEGES ON rick.* TO 'rick'@"%" IDENTIFIED BY 'bar';
 ```
Follwing these command to create children table:
```
  mysql> quit
  $ mysql -u rick -p
  <* Enter the password here, password = bar *>
  mysql> create databse rick;
  mysql> use rick
  mysql> create table children (childno INTEGER AUTO_INCREMENT NOT NULL PRIMARY KEY,
                                fname VARCHAR(30),
                                age INTEGER
                                );
  mysql> insert to children(fname, age) values("Jenny", 14);
  mysql> insert to children(fname, age) values("Jenny", 14);
  
 ```
## Conpile
```
  $ gcc -Iusr/include/mysql connect1.c -o connect1 -L/usr/lib/msql -lmysqlclient
  $ gcc connect2.c -o connect2 -L/usr/lib/msql -lmysqlclient
  $ gcc insert.c -o insert -L/usr/lib/msql -lmysqlclient
  $ gcc update.c -o update -L/usr/lib/msql -lmysqlclient
  $ gcc select.c -o select -L/usr/lib/msql -lmysqlclient
 ```
