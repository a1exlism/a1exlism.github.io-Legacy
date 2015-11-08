/*       		1.Regex
*	/([a-z])\1	中 \1为反向引用,简单地说就是第一个匹配了a后面一定要是a
*	例如 上面那条语句能匹配aa 而不能匹配到ab,而去掉\1则均能匹配到
*	{0,}表示匹配大于等于0个的regex对象
*			2.array.prototype.map()
*			有点烦人
*	https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Array/map
*/
function RunLength(str) { 
	var num = 1;
	var result = '';
	for( var i = 0; i < str.length ; i++){
		if( str[i] == str[i+1]){
			num++;
		}else{
			result = result + num + str[i];
			num = 1;
		}
	}
	// code goes here  
	return str;  
}


//-------Others'1------------
//-----------------大神,本来想自己定义一个函数在外面,发现运行失败,只能用匿名函数???----------
function RunLength(str) {
  var res = str.match(/([a-zA-Z])\1{0,}/gi).map(function(a) {
    return a.length + a[0]
  }).join('');
//	str.match(/([a-zA-Z])\1{0,}/gi)	返回的是数组
//	arr.map(func())	func()先将map()传入的参数进行运算,之后重新依次返还给arr
}