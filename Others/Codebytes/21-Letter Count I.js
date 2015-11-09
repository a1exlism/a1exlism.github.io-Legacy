//-----------Wrong1-----------
function LetterCountI(str) { 
	var arr = str.match(/[^\s]{1,}/g);
	//匹配大于等于一个的非space字符串
	var reg1 = new RegExp(/([a-z])\1{1}/gi);
				//		/[a-z]\1{2}/gi 错误写法
	var reg2 = new RegExp(/([a-z])\1{2}/gi);
	for( var i = 0; i < arr.length; i++){
		if( reg2.test(arr[i]))
			return arr[i];
	}
	for( var i = 0; i < arr.length; i++){
		if( reg1.test(arr[i]))
			return arr[i];
	}
	return -1;
}
//----------Version2--------------
function LetterCountl(str){
	var arr = str.match(/[\S]{1,}/g);
	//匹配大于等于一个的非space字符串
	flag = true;
	for( var i = 0; i < arr.length; i++){
		if( arr[i] )
	}
}