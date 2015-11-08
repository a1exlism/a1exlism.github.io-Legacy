//-------思路简单-------
/*
*		正则过滤space
*/
function Palindrome(str) { 
	str = str.replace(/[\s]/g,'');
	var revStr = '';
	for( var i = str.length-1 ; i > -1 ;i--)
		revStr += str[i];
	return (revStr === str);
}

//----------Others'1-----------
function Palindrome(str) {
  modified = str.replace(/\W/g,"");
  var arr1 = modified.split("");
  var arr2 = arr1;
  arr2 = arr2.reverse();
  str2 = arr2.join("");
  
  return modified == str2;
/*  \w 表示匹配所有的字母数字和下划线
  	没想到reverse逆序的功能函数被js封装好了
	arr.reverse();	数组专用
*/          
}