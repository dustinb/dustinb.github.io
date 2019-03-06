Crack station provides a way to test hashes against a 1.5 billion word database.  I wanted a
way to test many md5 hashes against this word database. 

Attempted to use COPY to get the data into a postgreSQL database but couldn't get the encoding
to work with UTF-8 or an SQL_ASCII database. 

With mySQL there is load file but the file has to be in the /var/lib/mysql-files/ directory

```mysql> load data infile '/var/lib/mysql-files/crackstation.txt' into table md5hash;```

[1]: https://crackstation.net/