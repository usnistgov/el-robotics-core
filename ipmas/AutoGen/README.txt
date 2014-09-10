To avoid having a specific DAO.cpp file for everybody, assigne these environment variables :
MysqlDefaultSchema=yourDBName
MysqlDefaultHost=localhost
MysqlDefaultUser=yourUsername
MysqlDefaultPassword=yourPassword

Exemple in bash : 
open the ~/.bashrc
add that :
export MysqlDefaultSchema=yourDBName
export MysqlDefaultHost=localhost
export MysqlDefaultUser=yourUsername
export MysqlDefaultPassword=yourPassword
save
execute in a terminal : source ~/.bashrc
