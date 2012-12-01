function MM_findObj(n, d) 
{ //v4.01
  var p,i,x;  
  if(!d) d=document; 
  
  if((p=n.indexOf("?"))>0&&parent.frames.length) 
  {
    d=parent.frames[n.substring(p+1)].document; n=n.substring(0,p);
  }
  
  if (navigator.appName != "Microsoft Internet Explorer")
  {
  	if(!(x = d[n]) && d.all) x = d.all[n]; 
	
	if (navigator.appName != "Netscape")
	{
  	  for (i=0; !x && i<d.forms.length; i++) x = d.forms[i][n];
	  for(i=0; !x && d.layers && i<d.layers.length; i++) x=MM_findObj(n,d.layers[i].document);
	}
  }
  
  if(!x && d.getElementById) x=d.getElementById(n); 
  
  return x;
}

function SHL_N() { //v6.0
  var i,p,v,obj,args=SHL_N.arguments;
  for (i=0; i<(args.length-2); i+=3) 
  
  	if ((obj=MM_findObj(args[i]))!=null) 
	//if (obj != null) 
	{ 
	  v=args[i+2];
      if (obj.style) 
	  { obj=obj.style; v=(v=='show')?'visible':(v=='hide')?'hidden':v; }
      obj.visibility=v; 
	}
}


function SHL(objName, v) { //v6.0
items = document.getElementsByName(objName);
var obj;
for(i=0; i<items.length; i++) {
obj=items[i];

      if (obj.style) 
	  { obj=obj.style; v=(v=='show')?'visible':(v=='hide')?'hidden':v; }
      obj.visibility=v; 
}
}


function CP_N(objName,x,theProp,theValue) {
 var obj= MM_findObj(objName);
 
 if (obj && (theProp.indexOf("style.")==-1 || obj.style))
  {
    if (theValue == true || theValue == false)
      eval("obj."+theProp+"="+theValue);
    else eval("obj."+theProp+"='"+theValue+"'");
  }
}

function CP(obj,index,theProp,theValue) {
 if (theProp == "")
 	theProp='style.backgroundColor';
//alert(obj);
if (index != '') {
	obj=document.getElementsByName(obj);
	obj=obj[index];
}

 if (obj && (theProp.indexOf("style.")==-1 || obj.style))
  {
    if (theValue == true || theValue == false)
      eval("obj."+theProp+"="+theValue);
    else eval("obj."+theProp+"='"+theValue+"'");
  }
}

function hideSelectBox()
{
  var elmID='SELECT';
  if (navigator.appName == "Microsoft Internet Explorer")
  for(var i=0; i<document.all.tags(elmID).length; i++)
  	if (document.all.tags(elmID)[i].NoHide != 1) // not to hide the select box that have property "NoHide=1"
  	document.all.tags(elmID)[i].style.visibility='hidden';
}

function showSelectBox()
{
  var elmID='SELECT';
  if (navigator.appName == "Microsoft Internet Explorer")
  for(var i=0; i<document.all.tags(elmID).length; i++)
  	document.all.tags(elmID)[i].style.visibility='';
}

function OnclickEvent(Url,NewWindow,EventItem)
{
	ntptEventTag('ev=Toolbar&Item='+EventItem);
	if (NewWindow == 1)
		window.open(Url);
	else
		location.href=Url;
}

if (navigator.appName=="Netscape") {
		document.write("<LINK rel='StyleSheet' href='/common/ToolbarStyleNS.css'>");}
else {   
		document.write("<LINK rel='StyleSheet' href='/common/ToolbarStyleIE.css'>");}
		
		
/*
function MM_findObj(n, d) 
{ //v4.01
  var p,i,x;  
  if(!d) d=document; 
  if((p=n.indexOf("?"))>0&&parent.frames.length) 
  {
    d=parent.frames[n.substring(p+1)].document; n=n.substring(0,p);
  }
  if(!(x=d[n])&&d.all) x=d.all[n]; 
  for (i=0;!x&&i<d.forms.length;i++) x=d.forms[i][n];
  for(i=0;!x&&d.layers&&i<d.layers.length;i++) x=MM_findObj(n,d.layers[i].document);
  if(!x && d.getElementById) x=d.getElementById(n); return x;
}

function SHL() { //v6.0
  var i,p,v,obj,args=SHL.arguments;
  for (i=0; i<(args.length-2); i+=3) 
  	if ((obj=MM_findObj(args[i]))!=null) 
	{ 
	  v=args[i+2];
      if (obj.style) 
	  { obj=obj.style; v=(v=='show')?'visible':(v=='hide')?'hidden':v; }
      obj.visibility=v; 
	}
}

*/