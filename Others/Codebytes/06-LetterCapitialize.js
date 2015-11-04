/*
*------1.遇到一个非常好的问题:-----
*/
//-------------------------------
	var str = " Argument goes here";
	strArr = str.split(' ');
	strArr[1][0] = strArr[1][0].toLowerCase();
	alert(strArr[1][0]);	//弹出的是A而不是a
	strArr[1][0].toLowerCase();	//提示为a
//-----2.substring(start,stop)的使用 !!s小写!!---------------
//-----split()	jion()函数的使用--------
//-------substring()函数的使用----------

function LetterCapitalize(str) {
//思路 split jion函数--数组 字符串互换 
	var strArr = str.split(' ');
	var res = [];		//高估了javascript的弱类型,明确一下res是一个数组
	for(var i = 0;i < strArr.length; i++){
		res[i] = strArr[i][0].toUpperCase() + strArr[i].substring(1);	//为什么这个一放到函数里面就不行了..
	}
  // code goes here  
  return res.join(' '); 
         
}
   
// keep this function call here 
// to see how to enter arguments in JavaScript scroll down
LetterCapitalize("Argument goes here");


//-----------Others'1---------

function LetterCapitalize(str) { 
  var words = str.split(/ /);	//这里居然用了正则	
  str = '';
  for (var i=0; i < words.length; i++) {
    var word = words[i][0].toUpperCase() + words[i].substring(1);
    if (str != '') str += ' ';
    str += word;
  }
  // code goes here  
  return str; 
}	//想法居然跟我一样然而他只做了3分钟23333
//---------Others'2--------
function LetterCapitalize(str) { 
  var words = str.match(/\w+/g);	//\w 字母+num	+ 一个或以上
  //她用这个将其分组 match()
  for(i = 0; i < words.length; i++) {
    words[i] = words[i].substring(0,1).toUpperCase() + words[i].substring(1,words[i].length);
  }
  return words.join(' ');
}