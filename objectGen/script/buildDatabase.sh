#!/bin/sh

#run this script to create a database from the kittingInstances.owl file in one step
#mysql environment variables must be set in order for this to work

IPMAS_DIRECTORY=../../

if [ $# = 1 ]
then
	java -jar $IPMAS_DIRECTORY/Generator/generator_no_gui.jar -owl $1 -sql ./
	echo Done generating sql.
	echo Resetting database...
	mysql -u $MysqlDefaultUser -h $MysqlDefaultHost --password=$MysqlDefaultPassword -e "DROP DATABASE $MysqlDefaultSchema;"
	mysql -u $MysqlDefaultUser -h $MysqlDefaultHost --password=$MysqlDefaultPassword -e "CREATE DATABASE $MysqlDefaultSchema;"
	echo Database reset.
	echo Creating tables...
	mysql -u $MysqlDefaultUser -h $MysqlDefaultHost --password=$MysqlDefaultPassword $MysqlDefaultSchema < $1CreateTable.sql
	echo Inserting table data...
	mysql -u $MysqlDefaultUser -h $MysqlDefaultHost --password=$MysqlDefaultPassword $MysqlDefaultSchema < $1InsertInto.sql
	echo Done.
else
	echo "buildDatabase.sh:\ncreates a database using mysql environment variables and populates it using an owl instance file"
	echo usage:
	echo ./buildDatabase.sh path/to/owl.owl
fi
