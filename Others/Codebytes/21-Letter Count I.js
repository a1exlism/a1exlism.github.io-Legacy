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
	str = str.toLowerCase();
	var arr = str.split(/[\s]/);
	//匹配大于等于一个的非space字符串
	//or var arr = str.match(/[\S]{1,}/g);
	var longest =new Array(arr.length);
	var alphabet = new Array(26);
	for( var i = 0; i < arr.length; i++){	//每一层遍历一次字符串
		for( var j = 0; j < arr[i].length; j++){
			alphabet[arr[i][j].charCodeAt() - 97] ++;
		}	//Letter Count
		for( var k = 0; k < 26; k++){
			longest[i] = longest[i] - alphabet[k] ? longest[i] : alphabet[k]; 
function LetterCountI(str){
		}	//Compare to longest
	}
	var flag = 0;
	for( var count = 0; count < longest.length; count++){
		if( longest[count] != 1)
			break;
		flag ++;
	}
	alert( flag );
	if( flag == longest.length )
		return -1;
	var tmp = 0;
	for( var x = 1 ; x < longest.length; x++){
		if( longest[tmp] < longest[x])
			tmp = x;
	}
	return arr[tmp];
}