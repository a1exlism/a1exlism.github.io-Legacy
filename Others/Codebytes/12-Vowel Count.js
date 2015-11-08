function VowelCount(str) { 
  var num = 0;
  for( var i = 0; i < str.length ; i++){
  	if(/([aeiou])/g.test(str[i]))
  	//正则的确好用,再次推荐 www.regexr.com
  		num ++ ;
  }
  // code goes here  
  return num; 
}





//-------Others'1---------
/*
*	正则真的很常见
*/
function VowelCount(str) { 
	//arr = str.match(RegObj);	字符串匹配 并返回为数组类型
  var vowels = str.match(/[aeiou]/g);
  return vowels.length;
}