function LongestWord(sen){
	var longestWord = "";
	var longestLength = 0;
	sen = sen.replace(/[^a-zA-Z0-9\s]/g,"");	//^取反 g 表示globe
	//正则只保留字母和数字	可以尝试用while循环直接continue
	sen = sen.split(" ");	//以' '为分隔符将sen变成字符串数组
	for( var i = 0; i < sen.length ; i++){
		if( sen[i].length > longestLength){
			longestLength = sen[i].length;
			longestWord = sen[i];
		}
	}
	return longestWord;
}
LongestWord(readline());





//------------failed----------
function LongestWord(sen) { 
	
	function obj(){
		this.position,
		this.length
	}	//定义obj类
	var obj[] = new obj;
	obj[0].position = 0;		//定义默认位置
	for(var j = i = 0;i < sen.length ;i++){
		if(sen[i] > 96 && sen[i] < 123){
			obj[j].length ++;
		}
		else if(sen[i-1 < 97 || sen[i-1] > 122]){
			continue;
		} 
		else{
			j++;
			obj[j].position = i;	//存入位置参数
		}
	}
	var max = obj[0].length;
	var posI = 0;	//记录最长单词位置的obj[]位置
	for(var i = 1;i < obj.length ; i++){
		if(max < obj[i].length){
			max = obj[i].length;
			posI = i;
		}
	}
	var longestStr = new String();
	i = posI;	
	do{
		longestStr += sen[i++];
	}while( sen[i] < 97 || sen[i] > 122)
  // code goes here  
  return longestStr; 
         
}
   
// keep this function call here 
// to see how to enter arguments in JavaScript scroll down
LongestWord(readline());

//------------failed----------
