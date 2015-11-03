/*-----学到了字符串相加的方法-----------
*	字符转unicode码：用charCodeAt();
*	unicode码转字符：用String.fromCharCode();
* http://www.lezhu99.com/1714.html
*/

//-----failed1---
function LetterChanges(str) { 
	for( var i = 0;i < str.length; i++){
		if(str[i] == 'z')
			str[i] = 'a';
		else
			str[i] = String.fromCharCode(str[i].charCodeAt() + 1);	//转换为unicode
		}
		if(str[i] == ('a' || 'e' || 'i' || 'o' || 'u'))
			str[i].toUpperCase();

	}
  // code goes here  
  return str;
}
   
// keep this function call here 
// to see how to enter arguments in JavaScript scroll down
LetterChanges(readline());

//-------2Start--------
function LetterChange(str){
	var arrStr = str.split("");//先转化为数组
	for( var i = 0;i < arrStr.length; i++){
		if(arrStr[i] == 'z')
			arrStr[i] = 'a';
		else
			arrStr[i] = String.fromCharCode(arrStr[i] + 1);		//终究是这里出错
	}

}

//--------answer-------
function LetterChanges(str) {
	var alpha = "abcdefghijklmnopqrstuvwxyz";
	var newAlpha = "bcdEfghIjklmnOpqrstUvwxyzA";
	var outPut = "";
	for(var i = 0; i < str.length;i++){
		if(alpha.indexOf(str[i]) !== -1){	//indexOf()首次出现的位置  -1时表示字符不存在
			var pos = alpha.indexOf(str[i]);
			outPut += newAlpha.charAt(pos);
		}else{
			outPut += str[i];	//直接输出空格
		}
	}
	return outPut;
}

//------Others'-------
function LetterChanges(str) { 
  var res ="";
  var rev;
  for(var i=0; i