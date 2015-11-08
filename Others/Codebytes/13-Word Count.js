//--------逐渐掌握了Regex的使用方法,很爽------
function WordCount(str) { 
	var arr = new Array;
	arr = str.split(/[\s]/g);
	return arr.length;
}
//-------Others'1---------
function WordCount(str) { 
  return str.split(' ').length;	
  //这个的话和我差不多 不过还是有些缺点,比如两个空格
}