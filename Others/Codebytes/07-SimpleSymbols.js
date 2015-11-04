//-------myAnswser--------
function SimpleSymbols(str) { 
	var flag = true;
	for(var i = 0;i < str.length; i++){
		var tmp = str[i].charCodeAt();
		if( tmp > 64 && tmp < 91 || tmp > 96 && tmp < 123)
			if(str[i-1] != '+' || str[i + 1] != '+')
				flag = false;				
	}
  return flag; 
         
}
SimpleSymbols(readline());
//-------Others'1---------
function SimpleSymbols(str) { 
  return ('='+str+'=').match(/([^\+][a-z])|([a-z][^\+])/gi)===null;          
}		//佩服!		// '\+' 是转义

//-------Others'2---------
function SimpleSymbols(str) {
  str = str.toLowerCase();
  var ok = true;
  for (var i = 0; i < str.length; i++) {
    if(str.charCodeAt(i) >= 'a'.charCodeAt(0) && str.charCodeAt(i) <= 1="" 'z'.charcodeat(0))="" {="" ok="ok" &&="" i="" -="">= 0 && i + 1 < str.length && str[i-1] == '+' && str[i+1] == '+';
    }
  }
  return ok; 
}			//没啥特色 跟我差不多
//-------Others'3---------
/*
*			Got .test() 返回true/false 匹配括号内的字符
*/
function SimpleSymbols(str) { 

  if (/^[a-zA-Z]/.test(str) || /[a-zA-Z]$/.test(str)) {
      return false;	//判断头尾
  }
  else if (/[^\+][a-zA-Z]/.test(str) || /[a-zA-Z][^\+]/.test(str)) {
      return false;	//排除一个+的情况
  }
  else {
   return true; 
  }
}</=>