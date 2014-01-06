You can read out information on objects in USARSim by connecting as a client to TCP socket port 3989 and sending a message indicating the type of object you want to see. The location of every object of that type in USARSim will be send back in a format like this:
{Name P3AT_0} {Class P3AT} {Time 29.9739} {Location 0.67,2.30,1.86} {Rotation -0.00,0.46,0.00}
A program that does this is provided in the Tools\USARTruth folder. The source code is located mostly in the "USARTruth.c" file, with an executable "USARTruth.exe" already compiled in the Debug folder.
By default, a particular instance of a "part_c" is printed. Odds are that your map will not contain this part. 
You can pass arguments with the dash-s option and the bracketed type you want, e.g.,
USARTruth.exe -s {class USARPhysObj.partc}
USARTruth.exe -s {name part_c_5}
USARTruth.exe -s {class USARPhysObj.partc} {name part_c_5}
You can use the code in USARTruth.exe as the starting point for another application that does more with the truth data.