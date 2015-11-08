/*-----学习了正则表达式,坑------
*---Nice-->http://www.regexr.com/
*-----字母从小到大排列-------
*/
//---------failed1-------
function AlphabetSoup(str) { 
	str = str.replace(/[^a-z+A-Z]/,'');	//这个可以好好看看
//正则写错 应该为[^a-zA-Z]
  // code goes here
  return str; 
         
}
//----------2------
function AlphabetSoup(str){
	var newStr = '';
	for(var i = 0 ;i < str.length; i++){
		if( str[i] >= 'a'&& str[i] <= 'z'="" ||="" str[i]="">= 'A' && str[i] <= 'z')="" newstr="" +="str[i];" }="" 去除了其他元素="" 下面进行分组排序="" var="" result="" ;="" unicode="97;" for(="" j="0;j" <="" 26;="" j++){="" i="0;i" newstr.length;="" i++){="" if(="" newstr[i].charcodeat()="=" unicode)="" ++;="" return="" result;="" alphabetsoup('readline()');="" -----others'="" 1---------="" *="" ----got----="" arr.push()方法添加一个或多个元素到数组的末尾,并返回数组新的长度(length="" 属性值)="" function="" alphabetsoup(str)="" {="" sorting="[];" for="" (var="" i<str.length;="" sorting.push(str[i]);="" 化为数组,有一个方法可以简化="" yourstring.split()="" array.prototype.sort()="" sorting.sort();="" str="" for(var="" i<sorting.length;="" sorting[i];="" code="" goes="" here="" str;="" ---修改版-----="" 发现其他人都这么写,新技能get="" alphabetsoup="" (str)="" alert(str);="" str-="">arr
	sorting.sort();
	str = sorting.join('');		//arr->str
	return str;
}</=></=>