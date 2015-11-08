//---------简单到死--------
function ABCheck(str) { 
  for( var i  = 0; i < str.length -3 ; i++){
  	if( str[i] == "a" && str[i+3] == "b")
  	  	return true; 
  }
  // code goes here  
  return false; 
}
ABCheck(readline());


//-------Others' 1----------
/*
*	特么又是一句话,正则够吊,不过感觉这个正则好像有点小问题
*	space 含有tabs spaces linebreaks
*/
function ABCheck(str) { 
  // code goes here  
  //[\s\S]		空白符\非空白符
  return str.match(/(a[\s\S][\s\S][\s\S]b)|(b[\s\S][\s\S][\s\S]a)/i)!==null; 
}
//-------Others'1-----------
/*
*	这个也是溜的不行也是用的正则
*/
function ABCheck(str) { 
	//Boolean regexObj.test(str)	检索str,返回值为boolean型
  return /a...b/g.test(str);
}