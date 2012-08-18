begin_metric
0
end_metric
begin_variables
35
var0 3 -1
var1 3 -1
var2 3 -1
var3 3 -1
var4 3 -1
var5 3 -1
var6 2 -1
var7 2 -1
var8 2 -1
var9 2 -1
var10 2 -1
var11 2 -1
var12 2 -1
var13 2 -1
var14 2 -1
var15 2 -1
var16 2 -1
var17 2 -1
var18 2 -1
var19 2 -1
var20 2 -1
var21 2 -1
var22 2 -1
var23 2 -1
var24 2 -1
var25 2 -1
var26 2 -1
var27 2 -1
var28 2 -1
var29 2 -1
var30 2 -1
var31 2 -1
var32 2 -1
var33 2 -1
var34 2 -1
end_variables
begin_state
1
1
2
1
1
0
0
1
1
1
1
1
1
1
1
1
1
1
1
1
0
1
0
1
1
1
1
1
0
0
1
1
1
1
0
end_state
begin_goal
6
9 0
14 0
19 0
21 0
32 0
33 0
end_goal
23
begin_operator
attach-eff robot_1 part_gripper part_gripper_holder
0
4
0 0 1 2
0 2 2 1
0 3 1 2
0 16 -1 0
0
end_operator
begin_operator
attach-eff robot_1 tray_gripper tray_gripper_holder
0
4
0 1 1 2
0 2 2 0
0 4 1 2
0 16 -1 0
0
end_operator
begin_operator
remove-eff robot_1 part_gripper part_gripper_holder
1
16 0
3
0 0 2 1
0 2 1 2
0 3 2 1
0
end_operator
begin_operator
remove-eff robot_1 part_gripper tray_gripper_holder
1
16 0
3
0 1 2 0
0 2 1 2
0 3 2 0
0
end_operator
begin_operator
remove-eff robot_1 tray_gripper part_gripper_holder
1
16 0
3
0 0 2 0
0 2 0 2
0 4 2 0
0
end_operator
begin_operator
remove-eff robot_1 tray_gripper tray_gripper_holder
1
16 0
3
0 1 2 1
0 2 0 2
0 4 2 1
0
end_operator
begin_operator
take-kit-tray robot_1 kit_tray_1 empty_kit_tray_supply tray_gripper work_table_1
3
2 0
4 2
5 0
4
0 10 -1 0
0 16 0 1
0 17 -1 0
0 29 0 1
0
end_operator
begin_operator
attach-eff robot_1 part_gripper tray_gripper_holder
0
4
0 1 0 2
0 2 2 1
0 3 0 2
0 16 -1 0
0
end_operator
begin_operator
attach-eff robot_1 tray_gripper part_gripper_holder
0
4
0 0 0 2
0 2 2 0
0 4 0 2
0 16 -1 0
0
end_operator
begin_operator
put-kit-tray robot_1 kit_tray_1 work_table_1
0
5
0 5 0 2
0 10 0 1
0 13 -1 0
0 16 -1 0
0 17 0 1
0
end_operator
begin_operator
create-kit kit_a2b2c1 kit_tray_1 work_table_1
0
2
0 5 2 1
0 12 -1 0
0
end_operator
begin_operator
take-kit robot_1 kit_a2b2c1 work_table_1 tray_gripper
1
4 2
5
0 5 1 0
0 8 -1 0
0 12 0 1
0 16 0 1
0 27 -1 0
0
end_operator
begin_operator
take-part robot_1 part_a_1 part_a_tray part_gripper work_table_1 kit_a2b2c1
4
2 1
3 2
5 1
12 0
4
0 6 0 1
0 11 -1 0
0 16 0 1
0 23 -1 0
0
end_operator
begin_operator
take-part robot_1 part_a_2 part_a_tray part_gripper work_table_1 kit_a2b2c1
4
2 1
3 2
5 1
12 0
4
0 16 0 1
0 18 -1 0
0 22 0 1
0 24 -1 0
0
end_operator
begin_operator
take-part robot_1 part_b_1 part_b_tray part_gripper work_table_1 kit_a2b2c1
4
2 1
3 2
5 1
12 0
4
0 16 0 1
0 28 0 1
0 30 -1 0
0 31 -1 0
0
end_operator
begin_operator
take-part robot_1 part_b_2 part_b_tray part_gripper work_table_1 kit_a2b2c1
4
2 1
3 2
5 1
12 0
4
0 15 -1 0
0 16 0 1
0 25 -1 0
0 34 0 1
0
end_operator
begin_operator
take-part robot_1 part_c_1 part_c_tray part_gripper work_table_1 kit_a2b2c1
4
2 1
3 2
5 1
12 0
4
0 7 -1 0
0 16 0 1
0 20 0 1
0 26 -1 0
0
end_operator
begin_operator
put-kit robot_1 kit_a2b2c1 finished_kit_receiver
0
4
0 8 0 1
0 16 -1 0
0 19 -1 0
0 27 0 1
0
end_operator
begin_operator
put-part robot_1 part_a_1 kit_a2b2c1 work_table_1
2
5 1
12 0
4
0 11 0 1
0 16 -1 0
0 23 0 1
0 32 -1 0
0
end_operator
begin_operator
put-part robot_1 part_a_2 kit_a2b2c1 work_table_1
2
5 1
12 0
4
0 16 -1 0
0 18 0 1
0 21 -1 0
0 24 0 1
0
end_operator
begin_operator
put-part robot_1 part_b_1 kit_a2b2c1 work_table_1
2
5 1
12 0
4
0 16 -1 0
0 30 0 1
0 31 0 1
0 33 -1 0
0
end_operator
begin_operator
put-part robot_1 part_b_2 kit_a2b2c1 work_table_1
2
5 1
12 0
4
0 14 -1 0
0 15 0 1
0 16 -1 0
0 25 0 1
0
end_operator
begin_operator
put-part robot_1 part_c_1 kit_a2b2c1 work_table_1
2
5 1
12 0
4
0 7 0 1
0 9 -1 0
0 16 -1 0
0 26 0 1
0
end_operator
0
