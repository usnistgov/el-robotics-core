This folder contains the data necessary to run demos of the kitting system. The file classes are:
demo_xx__a_backup.sql - first mysql backup file in sequence made with the command "mysqldump -u root -p OWL > demo_xx_a_backup.sql
crcl_demo_xx_a.txt - first file in sequence from executor. Rest of the sequence will be 'b', 'c', ...


To reload mysql database, use mysql -u root -p OWL < demo_xx_a_backup.sql
