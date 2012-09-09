/////////////////////////////////////////////////////////////////////////////////////////////////////
function  replace(string, substring1, substring2 , scope )
{
if(!scope){scope='1'}
if(scope!='ALL'){scope='1'}
re = '/'+substring1
if(scope=='1'){re += '/'} 
else{re +='/g'}
new_string = string.replace(eval(re),substring2)
return new_string
}
//////////////////////////////////////////////////////////
function arrayappend(array,value){
eval(array)[eval(array).length] = value
}
////////////////////////////////////////
function compare(a,b){
return a-b;
}
//////////////////////////////////////////////////////////////////////
function left(string,count) {
	return string.substr(0,count);
}
//////////////////////////////////////////////////////////////////////
function right(mystring,count)  {
	return mystring.substring(mystring.length-count,mystring.length);
}
/////////////////////////////////////////////////////////////////////
function mid(myString,start,count) {
	return myString.substr(start-1,count)
}
/////////////////////////////////////////
function len(mystring)  {
	return mystring.length;
	}
/////////////////////////////////////////
function ucase(mystring)  {
return mystring.toUpperCase()
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
function IsEmail(f, elm) 
{
	var Temp     = document.forms[f].elements[elm];
	var AtSym    = Temp.value.indexOf('@');
	var Period   = Temp.value.lastIndexOf('.');
	var Space    = Temp.value.indexOf(' ');
	var Length   = Temp.value.length - 1;   // Array is from 0 to length-1

	//if(Temp.value != '')//email is not a required field.
	//{
	  if (Temp.value.substr(0,1)== "'" && Temp.value.substring(Temp.value.length-1,Temp.value.length)=="'")
	  {
	  	alert('Please remove the begin and end quote ' + '" ' + "'" + ' ".');
	  	Temp.focus();
	  	return false;
	  }
	  else if ((AtSym < 1) ||                     // '@' cannot be in first position
    	(Period <= AtSym+1) ||             // Must be atleast one valid char btwn '@' and '.'
    	(Period == Length ) ||             // Must be atleast one valid char after '.'
    	(Space  != -1))                    // No empty spaces permitted
   	  {  
      	alert('Please enter a valid e-mail address.');
      	Temp.focus();
		return false;
   	  }
	  return true;
	//}
}
//////////////////////////////////////////////////////////////////////
function openWindow(filePath,winName,toolbar,menubar,height,width) {
	if (!filePath) filePath = '';
	if (!winName) winName = 'newWin';
	if (!height) height = (window.screen.availHeight * 0.85);
	if (!width) width = (window.screen.availWidth * 0.85);		
	xPos = (window.screen.availHeight * 0.015);
	yPos = (window.screen.availWidth * 0.015);
	attribs='height='+height+','+'width='+width;
	if ((toolbar) && (!toolbar == '')) attribs=attribs+','+toolbar;
	if ((menubar) && (!menubar == '')) attribs=attribs+','+menubar;
	attribs=attribs+',scrollbars';
	newWindow=window.open(filePath,winName,attribs);		
	newWindow.moveTo(xPos,yPos) 
	newWindow.focus();		
}
//////////////////////////////////////////////////////////////////////