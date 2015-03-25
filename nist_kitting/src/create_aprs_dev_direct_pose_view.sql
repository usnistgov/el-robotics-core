use `aprs-dev`;
drop view IF exists DirectPose;
create view DirectPose(name,X,Y,Z,VXX,VXY,VXZ,VZX,VZY,VZZ) as 
	select SO._NAME,PT.hasPoint_X,PT.hasPoint_Y,PT.hasPoint_Z, 
			VX.hasVector_I,VX.hasVector_J,VX.hasVector_K,
            VZ.hasVector_I,VX.hasVector_J,VX.hasVector_K
    from SolidObject SO, PoseLocation PL, Point PT, Vector VX, Vector VZ 
    where 
    SO.hasSolidObject_PrimaryLocation = PL._NAME and
    PT._NAME = PL.hasPoseLocation_Point and
    VX._NAME = PL.hasPoseLocation_XAxis and
    VZ._NAME = PL.hasPoseLocation_ZAxis;
    
# update DirectPose set Z = 100 where name = "changing_station_1";

select * from DirectPose order by name;

