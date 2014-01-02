This demo directory contains files for building two a2b2c1 kits. The sequence for running or displaying the demo is as follows:
1) Load the initial database with the command:
   mysql -u root -p OWL < demo_01_a_backup.sql
2) You can now display the state of the initial world with the command
   objectGen -t
3) The first kit may be built with the command file crcl_demo_01_a.txt
4) The state of the completed kit may be loaded with the command
   mysql -u root -p OWL < demo_01_b_backup.sql
5) The kit may be removed from the world by loading the file:
   mysql -u root -p OWL < demo_01_c_backup.sql
6) The second kit may be built with the command file crcl_demo_01_b.txt
7) The state showing the second kit may be loaded with the command:
   mysql -u root -p OWL < demo_01_d_backup.sql

At any time, the state of the world may be displayed with the command:
   objectGen -t

The following screen shots exist:
demo_01_Initial.JPG : Initial state of the world
demo_01_Build1.JPG  : Result of first pallet build
demo_01_Reset.JPG   : Pallet removed from world
demo_01_Build2.JPG  : Result of second pallet build
