function LongestWord(sen) { 
	var obj[] = {
		position,
		length
	}	//定义obj类
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
	var longestStr = 	
  // code goes here  
  return sen; 
         
}
   
// keep this function call here 
// to see how to enter arguments in JavaScript scroll down
LongestWord(readline());